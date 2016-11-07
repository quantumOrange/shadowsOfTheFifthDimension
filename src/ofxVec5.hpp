#pragma once

class ofVec2f;
class ofVec3f;
class ofVec4f;
#include "ofConstants.h"

class ofxVec5f {
public:
    /// \cond INTERNAL
    static const int DIM = 5;
    /// \endcond
    
    float x;
    float y;
    float z;
    float w;
    float v;
    
    //---------------------
    /// \name Construct a 4D vector
    /// \{
    
    ofxVec5f();
    explicit ofxVec5f( float _scalar );
    ofxVec5f( float _x, float _y, float _z, float _w, float _v);
    ofxVec5f( const ofVec2f& vec);
    ofxVec5f( const ofVec3f& vec);
    ofxVec5f( const ofVec4f& vec);
    
    /// \}
    
    //---------------------
    /// \name Access components
    /// \{
    
    
    float * getPtr() {
        return (float*)&x;
    }
    const float * getPtr() const {
        return (const float *)&x;
    }
    
    float& operator[]( int n ){
        return getPtr()[n];
    }
    
    float operator[]( int n ) const {
        return getPtr()[n];
    }
    
    void set( float _scalar );
    void set( float _x, float _y, float _z, float _w, float _v);
    void set( const ofxVec5f& vec );
    
    
    /// \}
    
    //---------------------
    /// \name Comparison
    /// \{
    
    
    bool operator==( const ofxVec5f& vec ) const;
    bool operator!=( const ofxVec5f& vec ) const;
    bool match( const ofxVec5f& vec, float tolerance = 0.0001f) const;
    
    /// \}
    
    //---------------------
    /// \name Operators
    /// \{
    
    ofxVec5f  operator+( const ofxVec5f& vec ) const;
    ofxVec5f  operator+( const float f ) const;
    ofxVec5f& operator+=( const ofxVec5f& vec );
    ofxVec5f& operator+=( const float f );
    ofxVec5f  operator-( const float f ) const;
    ofxVec5f  operator-( const ofxVec5f& vec ) const;
    ofxVec5f  operator-() const;
    ofxVec5f& operator-=( const float f );
    ofxVec5f& operator-=( const ofxVec5f& vec );
    
    
    ofxVec5f  operator*( const ofxVec5f& vec ) const;
    ofxVec5f  operator*( const float f ) const;
    ofxVec5f& operator*=( const ofxVec5f& vec );
    ofxVec5f& operator*=( const float f );
    ofxVec5f  operator/( const ofxVec5f& vec ) const;
    ofxVec5f  operator/( const float f ) const;
    ofxVec5f& operator/=( const ofxVec5f& vec );
    ofxVec5f& operator/=( const float f );
    
    /// \cond INTERNAL
    friend ostream& operator<<(ostream& os, const ofxVec5f& vec);
    friend istream& operator>>(istream& is, const ofxVec5f& vec);
    /// \endcond
    
    /// \}
    
    //---------------------
    /// \name Simple manipulations
    /// \{
    
    /// \brief Returns a new ofxVec5f that is the result of scaling this vector up or down so that it has the requested length.
    ///
    /// \param length The desired length of the new ofxVec5f object.
    /// \returns The result of scaling the this vector up or down.
    ofxVec5f  getScaled( const float length ) const;
    
    /// \brief Scales this vector up or down so that it has the requested length.
    ///
    /// \param length The desired length of the vector.
    ofxVec5f& scale( const float length );
    
    /// \}
    
    
    //---------------------
    /// \name Distance
    /// \{
    
    /// \brief Treats this vector and 'pnt' as points in 4D space and calculates the distance between them.
    ///
    /// \param pnt The vector used in the distance calculation with the current vector.
    /// \returns The distance between the two vectors in 4D space.
    float distance( const ofxVec5f& pnt) const;
    float squareDistance( const ofxVec5f& pnt ) const;
    
    /// \}
    
    //---------------------
    /// \name Interpolation
    /// \{
    
    
    /// \brief Performs a linear interpolation of this vector towards 'pnt'.
    ///
    /// \param pnt The vector the interpolation will be performed on.
    /// \param p The amount to move towards 'pnt'; 'p' is normally between 0 and 1 and where 0 means stay the original position and 1 means move all the way to 'pnt', but you can also have 'p' greater than 1 overshoot 'pnt', or less than 0 to move backwards away from 'pnt'.
    /// \returns The interpolation as an ofxVec5f.
    ofxVec5f   getInterpolated( const ofxVec5f& pnt, float p ) const;
    
    /// \brief Performs a linear interpolation of this vector towards 'pnt'. This modifies the current vector to the interpolated value.
    ///
    /// \param pnt The vector the interpolation will be performed on.
    /// \param p The amount to move towards 'pnt'; 'p' is normally between 0 and 1 and where 0 means stay the original position and 1 means move all the way to 'pnt', but you can also have 'p' greater than 1 overshoot 'pnt', or less than 0 to move backwards away from 'pnt'.
    ofxVec5f&  interpolate( const ofxVec5f& pnt, float p );
    
    /// \brief Calculates and returns the midpoint (as a vector) between this vector and 'pnt'.
    ///
    /// \param pnt The vector used in the midpoint calculation with this vector.
    /// \returns The midpoint between this vector and 'pnt' as an ofxVec5f.
    ofxVec5f   getMiddle( const ofxVec5f& pnt ) const;
    
    /// \brief Calculates and returns the midpoint (as a vector) between this vector and 'pnt'. This modifies the current vector to the midpoint value.
    ///
    /// \param pnt The vector used in the midpoint calculation with this vector.
    /// \returns The midpoint between this vector and 'pnt' as an ofxVec5f.
    ofxVec5f&  middle( const ofxVec5f& pnt );
    
    /// \brief Sets this vector to be the average (center of gravity or centroid) of a given array of 'ofxVec5f's.
    ///
    /// \param points The array of 'ofxVec5f's used in the average calculation.
    /// \param num The number of ofxVec5f objects in the array.
    ofxVec5f&  average( const ofxVec5f* points, int num );
    
    /// \}
    
    //---------------------
    /// \name Limit
    /// \{
    
    /// \brief Returns a normalized copy of this vector.
    ///
    /// Normalization means to scale the vector so that its length (magnitude) is exactly 1,
    /// at which stage all that is left is the direction. A normalized vector is usually called
    /// a unit vector, and can be used to represent a pure direction (heading).
    ///
    /// \returns The normalized copy of the current vector.
    ofxVec5f  getNormalized() const;
    
    /// \brief Normalizes the vector. This changes the current vector to its normalized value.
    ///
    /// Normalization means to scale the vector so that its length (magnitude) is exactly 1,
    /// at which stage all that is left is the direction. A normalized vector is usually called
    /// a unit vector, and can be used to represent a pure direction (heading).
    ofxVec5f& normalize();
    
    
    /// \brief Returns a copy of this vector with its length (magnitude) restricted to a maximum of 'max' units by scaling down if necessary.
    ///
    /// \param max The maximum length of the new vector.
    /// \returns A copy of the current vector that is at most 'max' units long.
    ofxVec5f  getLimited(float max) const;
    /// \brief Restrict the length (magnitude) of this vector to a maximum of 'max' units by scaling down if necessary.
    ///
    /// \param max The maximum length of the current vector.
    ofxVec5f& limit(float max);
    
    /// \}
    
    //---------------------
    /// \name Measurement
    /// \{
    
    /// \brief Returns the length (magnitude) of this vector.
    ///
    /// \returns The magnitude of the current vector.
    float length() const;
    float lengthSquared() const;
    
    
    /// \}
    
    //---------------------
    /// \name Calculations
    /// \{
    
    
    /// \brief Calculates and returns the dot product of this vector with 'vec'.
    ///
    /// Dot product (less commonly known as Euclidean inner product) expresses the angular
    /// relationship between two vectors. In other words it is a measure of how parallel two vectors
    /// are. If they are completely perpendicular the dot product is 0; if they are completely parallel
    /// their dot product is either 1 if they are pointing in the same direction, or -1 if they are pointing
    /// in opposite directions.
    ///
    /// \param vec The vector used in the dot product calculation with this vector.
    /// \returns The dot product of this vector with 'vec'.
    float dot( const ofxVec5f& vec ) const;
    
    /// \}
    
    
    
    
    //---------------------------------------
    // this methods are deprecated in 006 please use:
    /// \cond INTERNAL
    
    // getScaled
    OF_DEPRECATED_MSG("Use member method getScaled() instead.", ofxVec5f rescaled( const float length ) const);
    
    // scale
    OF_DEPRECATED_MSG("Use member method scale() instead.", ofxVec5f& rescale( const float length ));
    
    // getNormalized
    OF_DEPRECATED_MSG("Use member method getNormalized() instead.", ofxVec5f normalized() const);
    
    // getLimited
    OF_DEPRECATED_MSG("Use member method getLimited() instead.", ofxVec5f limited(float max) const);
    
    // use squareDistance
    OF_DEPRECATED_MSG("Use member method squareDistance() instead.", float  distanceSquared( const ofxVec5f& pnt ) const);
    
    // use getInterpolated
    OF_DEPRECATED_MSG("Use member method getInterpolated() instead.", ofxVec5f interpolated( const ofxVec5f& pnt, float p ) const);
    
    // use getMiddle
    OF_DEPRECATED_MSG("Use member method getMiddle() instead.", ofxVec5f middled( const ofxVec5f& pnt ) const);
    
    // return all zero vector
    static ofxVec5f zero() { return ofxVec5f(0, 0, 0, 0, 0); }
    
    // return all one vector
    static ofxVec5f one() { return ofxVec5f(1, 1, 1, 1, 1); }
    /// \endcond
};


/// \cond INTERNAL


// Non-Member operators
//
//
ofxVec5f operator+( float f, const ofxVec5f& vec );
ofxVec5f operator-( float f, const ofxVec5f& vec );
ofxVec5f operator*( float f, const ofxVec5f& vec );
ofxVec5f operator/( float f, const ofxVec5f& vec );







/////////////////
// Implementation
/////////////////

inline ofxVec5f::ofxVec5f(): x(0), y(0), z(0), w(0),v(0) {}
inline ofxVec5f::ofxVec5f(float _s): x(_s), y(_s), z(_s), w(_s),v(_s) {}
inline ofxVec5f::ofxVec5f( float _x,
                        float _y,
                        float _z,
                        float _w,
                        float _v):x(_x), y(_y), z(_z), w(_w) ,v(_v) {}

// Getters and Setters.
//
//
inline void ofxVec5f::set( float _scalar) {
    x = _scalar;
    y = _scalar;
    z = _scalar;
    w = _scalar;
    v = _scalar;
}

inline void ofxVec5f::set( float _x, float _y, float _z, float _w, float _v) {
    x = _x;
    y = _y;
    z = _z;
    w = _w;
    v = _v;
}

inline void ofxVec5f::set( const ofxVec5f& vec ) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = vec.w;
    v = vec.v;
}


// Check similarity/equality.
//
//
inline bool ofxVec5f::operator==( const ofxVec5f& vec ) const {
    return (x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w) && (v == vec.v);
}

inline bool ofxVec5f::operator!=( const ofxVec5f& vec ) const {
    return (x != vec.x) || (y != vec.y) || (z != vec.z) || (w != vec.w) ||(v != vec.v)  ;
}

inline bool ofxVec5f::match( const ofxVec5f& vec, float tolerance) const {
    return (fabs(x - vec.x) < tolerance)
    && (fabs(y - vec.y) < tolerance)
    && (fabs(z - vec.z) < tolerance)
    && (fabs(w - vec.w) < tolerance)
    && (fabs(v - vec.v) < tolerance);
}




// Additions and Subtractions.
//
//
inline ofxVec5f ofxVec5f::operator+( const ofxVec5f& vec ) const {
    return ofxVec5f( x+vec.x, y+vec.y, z+vec.z, w+vec.w, v+vec.v);
}

inline ofxVec5f& ofxVec5f::operator+=( const ofxVec5f& vec ) {
    x += vec.x;
    y += vec.y;
    z += vec.z;
    w += vec.w;
     v += vec.v;
    return *this;
}

inline ofxVec5f ofxVec5f::operator-( const float f ) const {
    return ofxVec5f( x-f, y-f, z-f, w-f ,v-f);
}

inline ofxVec5f& ofxVec5f::operator-=( const float f ) {
    x -= f;
    y -= f;
    z -= f;
    w -= f;
    v -= f;
    return *this;
}

inline ofxVec5f ofxVec5f::operator-( const ofxVec5f& vec ) const {
    return ofxVec5f( x-vec.x, y-vec.y, z-vec.z, w-vec.w ,v-vec.v);
}

inline ofxVec5f& ofxVec5f::operator-=( const ofxVec5f& vec ) {
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    w -= vec.w;
     v -= vec.v;
    return *this;
}

inline ofxVec5f ofxVec5f::operator+( const float f ) const {
    return ofxVec5f( x+f, y+f, z+f, w+f,v+f );
}

inline ofxVec5f& ofxVec5f::operator+=( const float f ) {
    x += f;
    y += f;
    z += f;
    w += f;
    v += f;
    return *this;
}

inline ofxVec5f ofxVec5f::operator-() const {
    return ofxVec5f( -x, -y, -z, -w ,-v);
}


// Scalings
//
//
inline ofxVec5f ofxVec5f::operator*( const ofxVec5f& vec ) const {
    return ofxVec5f( x*vec.x, y*vec.y, z*vec.z, w*vec.w ,v*vec.v);
}

inline ofxVec5f& ofxVec5f::operator*=( const ofxVec5f& vec ) {
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
    w *= vec.w;
    v *= vec.v;
    return *this;
}

inline ofxVec5f ofxVec5f::operator*( const float f ) const {
    return ofxVec5f( x*f, y*f, z*f, w*f ,v*f);
}

inline ofxVec5f& ofxVec5f::operator*=( const float f ) {
    x *= f;
    y *= f;
    z *= f;
    w *= f;
    v *= f;
    return *this;
}

inline ofxVec5f ofxVec5f::operator/( const ofxVec5f& vec ) const {
    return ofxVec5f( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z, vec.w!=0 ? w/vec.w : w   ,vec.v!=0 ? v/vec.v : v  );
}

inline ofxVec5f& ofxVec5f::operator/=( const ofxVec5f& vec ) {
    vec.x!=0 ? x/=vec.x : x;
    vec.y!=0 ? y/=vec.y : y;
    vec.z!=0 ? z/=vec.z : z;
    vec.w!=0 ? w/=vec.w : w;
    vec.v!=0 ? v/=vec.v : v;
    return *this;
}

inline ofxVec5f ofxVec5f::operator/( const float f ) const {
    if(f == 0) return ofxVec5f(x, y, z, w, v);
    
    return ofxVec5f( x/f, y/f, z/f, w/f, v/f );
}

inline ofxVec5f& ofxVec5f::operator/=( const float f ) {
    if(f == 0)return *this;
    
    x /= f;
    y /= f;
    z /= f;
    w /= f;
    v /= f;
    return *this;
}


inline ostream& operator<<(ostream& os, const ofxVec5f& vec) {
    os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ", " << vec.v ;
    return os;
}

inline istream& operator>>(istream& is, ofxVec5f& vec) {
    is >> vec.x;
    is.ignore(2);
    is >> vec.y;
    is.ignore(2);
    is >> vec.z;
    is.ignore(2);
    is >> vec.w;
    is.ignore(2);
    is >> vec.v;
    return is;
}


inline ofxVec5f ofxVec5f::rescaled( const float length ) const {
    return getScaled(length);
}

inline ofxVec5f ofxVec5f::getScaled( const float length ) const {
    float l = (float)sqrt(x*x + y*y + z*z + w*w + v*v);
    if( l > 0 )
        return ofxVec5f( (x/l)*length, (y/l)*length,
                       (z/l)*length, (w/l)*length ,(v/l)*length );
    else
        return ofxVec5f();
}

inline ofxVec5f& ofxVec5f::rescale( const float length ) {
    return scale(length);
}

inline ofxVec5f& ofxVec5f::scale( const float length ) {
    float l = (float)sqrt(x*x + y*y + z*z + w*w + v*v);
    if (l > 0) {
        x = (x/l)*length;
        y = (y/l)*length;
        z = (z/l)*length;
        w = (w/l)*length;
        v = (v/l)*length;
    }
    return *this;
}



// Distance between two points.
//
//
inline float ofxVec5f::distance( const ofxVec5f& pnt) const {
    float vx = x-pnt.x;
    float vy = y-pnt.y;
    float vz = z-pnt.z;
    float vw = w-pnt.w;
    float vv = v-pnt.v;
    return (float)sqrt( vx*vx + vy*vy + vz*vz + vw*vw  + vv*vv);
}

inline float ofxVec5f::distanceSquared( const ofxVec5f& pnt ) const {
    return squareDistance(pnt);
}

inline float ofxVec5f::squareDistance( const ofxVec5f& pnt ) const {
    float vx = x-pnt.x;
    float vy = y-pnt.y;
    float vz = z-pnt.z;
    float vw = w-pnt.w;
    float vv = v-pnt.v;
    return vx*vx + vy*vy + vz*vz + vw*vw + vv*vv;
}



// Linear interpolation.
//
//
/**
 * p==0.0 results in this point, p==0.5 results in the
 * midpoint, and p==1.0 results in pnt being returned.
 */
inline ofxVec5f ofxVec5f::interpolated( const ofxVec5f& pnt, float p ) const{
    return getInterpolated(pnt,p);
}

inline ofxVec5f ofxVec5f::getInterpolated( const ofxVec5f& pnt, float p ) const {
    return ofxVec5f(x*(1-p) + pnt.x*p,
                    y*(1-p) + pnt.y*p,
                    z*(1-p) + pnt.z*p,
                    w*(1-p) + pnt.w*p ,
                    v*(1-p) + pnt.v*p );
}

inline ofxVec5f& ofxVec5f::interpolate( const ofxVec5f& pnt, float p ) {
    x = x*(1-p) + pnt.x*p;
    y = y*(1-p) + pnt.y*p;
    z = z*(1-p) + pnt.z*p;
    w = w*(1-p) + pnt.w*p;
    v = v*(1-p) + pnt.v*p;
    return *this;
}

inline ofxVec5f ofxVec5f::middled( const ofxVec5f& pnt ) const {
    return getMiddle(pnt);
}

inline ofxVec5f ofxVec5f::getMiddle( const ofxVec5f& pnt ) const {
    return ofxVec5f( (x+pnt.x)/2.0f, (y+pnt.y)/2.0f,
                   (z+pnt.z)/2.0f, (w+pnt.w)/2.0f, (v+pnt.v)/2.0f );
}

inline ofxVec5f& ofxVec5f::middle( const ofxVec5f& pnt ) {
    x = (x+pnt.x)/2.0f;
    y = (y+pnt.y)/2.0f;
    z = (z+pnt.z)/2.0f;
    w = (w+pnt.w)/2.0f;
    v = (v+pnt.v)/2.0f;
    return *this;
}


// Average (centroid) among points.
// (Addition is sometimes useful for calculating averages too)
//
//
inline ofxVec5f& ofxVec5f::average( const ofxVec5f* points, int num ) {
    x = 0.f;
    y = 0.f;
    z = 0.f;
    w = 0.f;
    v = 0.f;
    for( int i=0; i<num; i++) {
        x += points[i].x;
        y += points[i].y;
        z += points[i].z;
        w += points[i].w;
        v += points[i].v;
    }
    x /= num;
    y /= num;
    z /= num;
    w /= num;
     v /= num;
    return *this;
}



// Normalization
//
//
inline ofxVec5f ofxVec5f::normalized() const {
    return getNormalized();
}

inline ofxVec5f ofxVec5f::getNormalized() const {
    float length = (float)sqrt(x*x + y*y + z*z + w*w + v*v);
    if( length > 0 ) {
        return ofxVec5f( x/length, y/length, z/length, w/length ,v/length);
    } else {
        return ofxVec5f();
    }
}

inline ofxVec5f& ofxVec5f::normalize() {
    float lenght = (float)sqrt(x*x + y*y + z*z + w*w +v*v);
    if( lenght > 0 ) {
        x /= lenght;
        y /= lenght;
        z /= lenght;
        w /= lenght;
        v /= lenght;
    }
    return *this;
}



// Limit length.
//
//
inline ofxVec5f ofxVec5f::limited(float max) const {
    return getLimited(max);
}

inline ofxVec5f ofxVec5f::getLimited(float max) const {
    ofxVec5f limited;
    float lengthSquared = (x*x + y*y + z*z + w*w +v*v);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        float ratio = max/(float)sqrt(lengthSquared);
        limited.set( x*ratio, y*ratio, z*ratio, w*ratio ,v*ratio);
    } else {
        limited.set(x,y,z,w,v);
    }
    return limited;
}

inline ofxVec5f& ofxVec5f::limit(float max) {
    float lengthSquared = (x*x + y*y + z*z + w*w +v*v);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        float ratio = max/(float)sqrt(lengthSquared);
        x *= ratio;
        y *= ratio;
        z *= ratio;
        w *= ratio;
        v *= ratio;
    }
    return *this;
}



// Length
//
//
inline float ofxVec5f::length() const {
    return (float)sqrt( x*x + y*y + z*z + w*w +v*v);
}

inline float ofxVec5f::lengthSquared() const {
    return (float)(x*x + y*y + z*z + w*w +v*v);
}




/**
 * Dot Product.
 */
inline float ofxVec5f::dot( const ofxVec5f& vec ) const {
    return x*vec.x + y*vec.y + z*vec.z + w*vec.w +v*vec.v;
}





// Non-Member operators
//
//
inline ofxVec5f operator+( float f, const ofxVec5f& vec ) {
    return ofxVec5f( f+vec.x, f+vec.y, f+vec.z, f+vec.w ,f+vec.v );
}

inline ofxVec5f operator-( float f, const ofxVec5f& vec ) {
    return ofxVec5f( f-vec.x, f-vec.y, f-vec.z, f-vec.w,f-vec.v );
}

inline ofxVec5f operator*( float f, const ofxVec5f& vec ) {
    return ofxVec5f( f*vec.x, f*vec.y, f*vec.z, f*vec.w ,f*vec.v);
}

inline ofxVec5f operator/( float f, const ofxVec5f& vec ) {
    return ofxVec5f( f/vec.x, f/vec.y, f/vec.z, f/vec.w,f/vec.v);
}


/// \endcond

