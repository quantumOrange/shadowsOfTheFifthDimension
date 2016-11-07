#version 150
uniform float time;


uniform vec4 lambda;
uniform float lambda5;


uniform sampler2DRect tex0;

out vec4 outputColor;

#define TWO_PI 6.283185

vec3 checker(vec2 p)
{
    if ((int(floor(p.x) + floor(p.y)) & 1) == 0)
        return vec3(1.0);
    else
        return vec3(0.0);
}
vec3 checker3D(vec3 p)
{
    // float gray = 0.5 + (0.5/3.0)*(cos(TWO_PI * p.x) + cos(TWO_PI * p.y) + cos(TWO_PI * p.z));
    //return vec3(gray);
    vec3 v = mod(p,1.0);
    
    if ((int(floor(p.x) + floor(p.y) + floor(p.z)) & 1) == 0){
        
        float   l = length(v-vec3(0.5));
        float c = 0.5+ 0.5*cos(11*TWO_PI*l);
        return vec3(1.0 -0.66*c);
    }
    else
    {
        
        float   l = length(v);
        float c = 0.5+ 0.5*cos(9*TWO_PI*l);
        // return vec3(1.0,c,l);
        return vec3(0.0 +0.66*c);
    }
}

vec3 checker5D(vec4 p , float fithDim)
{
    if ((int(floor(p.x) + floor(p.y) + floor(p.z) + floor(p.w) + floor(fithDim)) & 1) == 0){
        
        
        return vec3(1.0);
    }
    else
    {
        
        return vec3(0.0);
    }
}

float HueToRGB(float f1, float f2, float hue)
{
    if (hue < 0.0)
        hue += 1.0;
    else if (hue > 1.0)
        hue -= 1.0;
    float res;
    if ((6.0 * hue) < 1.0)
        res = f1 + (f2 - f1) * 6.0 * hue;
    else if ((2.0 * hue) < 1.0)
        res = f2;
    else if ((3.0 * hue) < 2.0)
        res = f1 + (f2 - f1) * ((2.0 / 3.0) - hue) * 6.0;
    else
        res = f1;
    return res;
}

vec3 HSLToRGB(vec3 hsl)
{
    vec3 rgb;
    
    if (hsl.y == 0.0)
        rgb = vec3(hsl.z); // Luminance
    else
    {
        float f2;
        
        if (hsl.z < 0.5)
            f2 = hsl.z * (1.0 + hsl.y);
        else
            f2 = (hsl.z + hsl.y) - (hsl.y * hsl.z);
        
        float f1 = 2.0 * hsl.z - f2;
        
        rgb.r = HueToRGB(f1, f2, hsl.x + (1.0/3.0));
        rgb.g = HueToRGB(f1, f2, hsl.x);
        rgb.b = HueToRGB(f1, f2, hsl.x - (1.0/3.0));
    }
    
    return rgb;
}


vec3 rgb2hsv(vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));
    
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}



bool dualTileZoneTest(vec4 p , float p5, float value){
    bool down  = all(lessThanEqual(vec4(value),p)) && value <= p5 && all(lessThanEqual(vec4(value),vec4(1.0)-p)) && value <= (1.0-p5);
    bool up  = all(greaterThanEqual(vec4(value),p)) && value >= p5 && all(greaterThanEqual(vec4(value),vec4(1.0)-p)) && value >= (1.0-p5);
    return down || up;
}


vec3 penrose(vec4 p , float p5){
    
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
    
        
        
        
    
  /*  if (x < y && x < z && x < w && x < v && x < (1 - y) && x < (1 - z) && x < (1 - w) && x < (1 - v))
        vec4 q = mod(p,1.0);
    float x = q.x;
    float y = q.y;
    float z = q.z;
    float w = q.w;
    float v = mod(p5,1.0);*/
    
}



void main()
{
    //centered cartiesan coords
    vec2 p = (gl_FragCoord.xy)/768 - vec2(0.5*1024/768,0.5);
    
    
   //// float lamba0 = time;
   // vec4 n = vec4(lamba0 + 0.125);
  //  float n5 = -4*lamba0;
    
   //vec5 u =  (-0.511667,0.19544,0.19544,-0.511667,0.632456);
    //vec5 v = (-0.371748,0.601501,-0.601501,0.371748,0);
    
    vec4 u = vec4(-0.511667,0.19544,0.19544,-0.511667);
    float u5 = 0.632456;
    
    vec4 v = vec4(-0.371748,0.601501,-0.601501,0.371748);
    float v5 = 0;
    
    float a =  sqrt(5.0);
    float b = sqrt(5+a);
    float d = sqrt(5-a);
    
   // vec4 u = (1.0/4.0)*vec4(-1.0+a,-1.0-a,-1.0-a,-1.0+a);
   // float u5 = 1.0;
    
    //vec4 v = (1.0/sqrt(8.0)) * vec4(b,d,-d,-b);
    //float v5 = 0;
    
    vec4 plane =  lambda + p.x*u + p.y*v;
    float plane5 = lambda5 + p.x*u5 +p.y*v5;
    
    
    float factor = 5;
    
    vec3 color = penrose(factor*plane,factor*plane5);
    
    outputColor =  vec4(color, 1.0);
}