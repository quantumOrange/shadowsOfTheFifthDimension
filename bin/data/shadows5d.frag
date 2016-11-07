#version 150

// Created by David Crooks
// License Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.

uniform float time;
uniform vec4 origin_a;
uniform float origin_v;
uniform vec2 resolution;

out vec4 outputColor;

struct vec5 {
    vec4 a;
    float v;
};

vec5 plane5(vec5 origin, vec5 u, vec5 v, vec2 p){
    return vec5(origin.a + p.x*u.a + p.y*v.a,
                origin.v + p.x*u.v + p.y*v.v);
}

vec5 mult5(vec5 p, float multiplier) {
    p.a *=  multiplier;
    p.v *= multiplier;
    return p;
}

vec5 mod5(vec5 p, float m) {
    return vec5(mod(p.a,m),mod(p.v,m));
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

bool dualTileZoneTest(vec5 p , float value){
    bool down  = all(lessThanEqual(vec4(value),p.a)) && value <= p.v && all(lessThanEqual(vec4(value),vec4(1.0)-p.a)) && value <= (1.0-p.v);
    bool up  = all(greaterThanEqual(vec4(value),p.a)) && value >= p.v && all(greaterThanEqual(vec4(value),vec4(1.0)-p.a)) && value >= (1.0-p.v);
    return down || up;
}

vec3 pattern(vec5 p ){
    
    float hueDelta = 1.0/24.0;
    
    p = mod5(p,1.0);
    
    if(dualTileZoneTest(p , p.a.x)){
        return  hsv2rgb(vec3(0.0, 0.7, 0.75));
    }
    else if(dualTileZoneTest(p,  p.a.y)){
        return hsv2rgb(vec3(hueDelta, 0.3,0.8));
    }
    else if(dualTileZoneTest(p, p.a.z)){
        return hsv2rgb(vec3(2.0*hueDelta, 0.2, 0.95));
    }
    else if(dualTileZoneTest(p, p.a.w)){
        return hsv2rgb(vec3(1.0-hueDelta, 0.5, 0.7));
    }
    else if(dualTileZoneTest(p,  p.v)){
        
        return hsv2rgb(vec3(1.0-2.0*hueDelta,0.3, 0.4));
    }
    else {
        return vec3(0.0);
    }
}
/*

vec3 patternOld(vec4 p , float p5){
    
    float hueDelta = 1.0/24.0;
    float lightness = 1.0;
    float saturation = 0.;
    
    
    vec4 q = mod(p,1.0);
    float v = mod(p5,1.0);
    
    vec3 black = vec3(0.0);
    vec3 white =  vec3(1.0);
    float dt = 0.3;
    float end = 8.0;
    
    if(dualTileZoneTest(q, v,  q.x)){
        if(time<dt) return black;
        if(time>end-dt) return white;
        return  hsv2rgb(vec3(0.0, 0.7, 0.75));
    }
    else if(dualTileZoneTest(q,  v,  q.y)){
        if(time<4*dt) return black;
        if(time>end-4*dt) return white;
         return hsv2rgb(vec3(hueDelta, 0.3,0.8));
    }
    else if(dualTileZoneTest(q, v, q.z)){
        if(time<5*dt) return black;
        if(time>end-5*dt) return white;
         return hsv2rgb(vec3(2*hueDelta, 0.2, 0.95));
    }
    else if(dualTileZoneTest(q,  v, q.w)){
        if(time<2*dt) return black;
        if(time>end-2*dt) return white;
         return hsv2rgb(vec3(1.0-hueDelta, 0.5, 0.7));
    }
    else if(dualTileZoneTest(q,  v,  v)){
        if(time<3*dt) return black;
        if(time>end-3*dt) return white;
         return hsv2rgb(vec3(1.0-2*hueDelta,0.3, 0.4));
    }
    else {
          return vec3(0.0);
    }
    
}
*/


void main()
{
    //centered cartiesan coords
    vec2 p = (gl_FragCoord.xy)/resolution.y - vec2(0.5*resolution.x/resolution.y,0.5);
    
    //This is the origin of our plane in 5d space.
   	
    //vec5 origin = vec5(vec4(time),-time);
    vec5 origin = vec5(origin_a,origin_v);
    
    
    //We need two directions to form a plane.
    //In 3d we can define a plane from a point on the plane (the origin) and a normal, using the cross product to find our two directions.
    
    //But this won't work in 5d. There is no cross product!
   	//There are many plane normal to vector, becasue there are four directions normal to a given vector.
    //This is why there is no cross product in higher dimensions!
    
    //In analogy with the 3d case, we get interesting patterns in a plane normal to (1,1,1,1,1). (the long diagonal of a hypercube.)
    //We can find a set of four vectors normal to (1,1,1,1,1) using the Gram Schmidt process
    //https://en.wikipedia.org/wiki/Gram%E2%80%93Schmidt_process
    //Any two will do:
    
    vec5 u = vec5(vec4(-0.511667,0.19544,0.19544,-0.511667),0.632456) ;
    vec5 v = vec5(vec4(-0.371748,0.601501,-0.601501,0.371748), 0.0);
    
    
    /*
    //the other two vectors:
    float a =  sqrt(5.0);
    float b = sqrt(5+a);
    float d = sqrt(5-a);
    
    vec5 u2 = vec5((1.0/4.0)*vec4(-1.0+a,-1.0-a,-1.0-a,-1.0+a),1.0);
    vec5 v2 =vec5( (1.0/sqrt(8.0)) * vec4(b,d,-d,-b),0.0);
    */
    
    
    vec5 plane = plane5(origin,u,v,p);
    plane = mult5(plane,5.0);
    
    
    //Now we have mapped points in the image plane to 5d space we can color pixels based on whe=re thy are in 5d.
    //We divide the space into a 5d lattice of hypercubes. For each point we find the closest face in the hypercube.
    //We pair opposite faces to get 5 colors, corresponding to the 5 dimensions.
    vec3 color = pattern(plane);
    outputColor =  vec4(color, 1.0);
}