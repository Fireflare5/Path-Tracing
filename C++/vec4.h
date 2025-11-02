#ifndef VEC4_H
#define VEC4_H

#include <iostream>
#include <cmath>
#include "vec3.h"

class vec4
{
    public:
        double e[4];

        vec4() : e{0.0, 0.0, 0.0, 0.0} {}
        vec4(double e1, double e2, double e3, double e4) : e{e1, e2, e3, e4} {}

        double x() const {return e[0];}
        double y() const {return e[1];}
        double z() const {return e[2];}
        double d() const {return e[3];}
        vec3 xyz() const {return vec3(e[0],e[1],e[2]);}

        double operator[] (int i) const {return e[i];}
        double& operator[] (int i) {return e[i];}

        vec4 operator-() const {return vec4(-e[0],-e[1],-e[2],-e[3]);}

        vec4& operator+=(const vec4& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            e[3] += v.e[3];
            return *this;
        }

        vec4& operator+=(double t) {
            e[0] += t;
            e[1] += t;
            e[2] += t;
            e[3] += t;
            return *this;
        }

        vec4& operator-=(const vec4& v) {
            return *this += -v;
        }

        vec4& operator-=(double t) {
            return *this += -t;
        }

        vec4& operator*=(const vec4& v) {
            e[0] *= v.e[0];
            e[1] *= v.e[1];
            e[2] *= v.e[2];
            e[3] *= v.e[3];
            return *this;
        }

        vec4& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            e[3] *= t;
            return *this;
        }

        vec4& operator/=(const vec4& v) {
            e[0] /= v.e[0];
            e[1] /= v.e[1];
            e[2] /= v.e[2];
            e[3] /= v.e[3];
            return *this;
        }

        vec4& operator/=(double t) {
            return *this *= 1.0/t;
        }
};

using point4 = vec4;

inline std::ostream& operator<<(std::ostream& out, const vec4& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
}

inline vec4 operator+(const vec4& u, const vec4& v) {
    return vec4( u.e[0] + v.e[0],
                 u.e[1] + v.e[1],
                 u.e[2] + v.e[2],
                 u.e[3] + v.e[3] );
}

inline vec4 operator+(const vec4& v, double t) {
    return vec4( v.e[0] + t,
                 v.e[1] + t,
                 v.e[2] + t,
                 v.e[3] + t );
}

inline vec4 operator+(double t, const vec4& v) {
    return v + t;
}

inline vec4 operator-(const vec4& u, const vec4& v) {
    return u + -v;
}

inline vec4 operator-(const vec4& v, double t) {
    return v + -t;
}

inline vec4 operator-(double t, const vec4& v) {
    return t + -v;
}

inline vec4 operator*(const vec4& u, const vec4& v) {
    return vec4( u.e[0] * v.e[0],
                 u.e[1] * v.e[1],
                 u.e[2] * v.e[2],
                 u.e[3] * v.e[3] );
}

inline vec4 operator*(const vec4& v, double t) {
    return vec4( v.e[0] * t,
                 v.e[1] * t,
                 v.e[2] * t,
                 v.e[3] * t );
}

inline vec4 operator*(double t, const vec4& v) {
    return v * t;
}

inline vec4 operator/(const vec4& u, const vec4& v) {
    return vec4( u.e[0] / v.e[0],
                 u.e[1] / v.e[1],
                 u.e[2] / v.e[2],
                 u.e[3] / v.e[3] );
}

inline vec4 operator/(const vec4& v, double t) {
    return v * (1.0/t);
}

inline vec4 operator/(double t, const vec4& v) {
    return vec4( t / v.e[0],
                 t / v.e[1],
                 t / v.e[2],
                 t / v.e[3] );
}

inline double dot(const vec4& u, const vec4& v) {
    return u.e[0] * v.e[0] + 
           u.e[1] * v.e[1] +
           u.e[2] * v.e[2] +
           u.e[3] * v.e[3];
}

inline double dot2(const vec4& v) {
    return dot(v,v);
}

inline vec3 cross(const vec4& u, const vec4& v) {
    return vec3( u.e[1] * v.e[2] - u.e[2] * v.e[1],
                 u.e[2] * v.e[0] - u.e[0] * v.e[2],
                 u.e[0] * v.e[1] - u.e[1] * v.e[0] );
}

inline double hypot(const vec4& v) {
    return std::sqrt( v.e[0] * v.e[0] + 
                      v.e[1] * v.e[1] + 
                      v.e[2] * v.e[2] );
}

inline double sum(const vec4& v) {
    return v.e[0] +
           v.e[1] +
           v.e[2] +
           v.e[3];
}

#endif