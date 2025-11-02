#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <cmath>

class vec2
{
    public:
        double e[2];

        vec2() : e{0.0, 0.0} {}
        vec2(double e1, double e2) : e{e1, e2} {}

        double x() const {return e[0];}
        double y() const {return e[1];}

        double operator[] (int i) const {return e[i];}
        double& operator[] (int i) {return e[i];}

        vec2 operator-() const {return vec2(-e[0],-e[1]);}

        vec2& operator+=(const vec2& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            return *this;
        }

        vec2& operator+=(double t) {
            e[0] += t;
            e[1] += t;
            return *this;
        }

        vec2& operator-=(const vec2& v) {
            return *this += -v;
        }

        vec2& operator-=(double t) {
            return *this += -t;
        }

        vec2& operator*=(const vec2& v) {
            e[0] *= v.e[0];
            e[1] *= v.e[1];
            return *this;
        }

        vec2& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            return *this;
        }

        vec2& operator/=(const vec2& v) {
            e[0] /= v.e[0];
            e[1] /= v.e[1];
            return *this;
        }

        vec2& operator/=(double t) {
            return *this *= 1.0/t;
        }
};

inline std::ostream& operator<<(std::ostream& out, const vec2& v) {
    return out << v.e[0] << ' ' << v.e[1];
}

inline vec2 operator+(const vec2& u, const vec2& v) {
    return vec2( u.e[0] + v.e[0],
                 u.e[1] + v.e[1] );
}

inline vec2 operator+(const vec2& v, double t) {
    return vec2( v.e[0] + t,
                 v.e[1] + t );
}

inline vec2 operator+(double t, const vec2& v) {
    return v + t;
}

inline vec2 operator-(const vec2& u, const vec2& v) {
    return u + -v;
}

inline vec2 operator-(const vec2& v, double t) {
    return v + -t;
}

inline vec2 operator-(double t, const vec2& v) {
    return t + -v;
}

inline vec2 operator*(const vec2& u, const vec2& v) {
    return vec2( u.e[0] * v.e[0],
                 u.e[1] * v.e[1] );
}

inline vec2 operator*(const vec2& v, double t) {
    return vec2( v.e[0] * t,
                 v.e[1] * t );
}

inline vec2 operator*(double t, const vec2& v) {
    return v * t;
}

inline vec2 operator/(const vec2& u, const vec2& v) {
    return vec2( u.e[0] / v.e[0],
                 u.e[1] / v.e[1] );
}

inline vec2 operator/(const vec2& v, double t) {
    return v * (1.0/t);
}

inline vec2 operator/(double t, const vec2& v) {
    return vec2( t / v.e[0],
                 t / v.e[1] );
}

inline double dot(const vec2& u, const vec2& v) {
    return u.e[0] * v.e[0] + 
           u.e[1] * v.e[1];
}

inline double dot2(const vec2& v) {
    return dot(v,v);
}

inline double hypot(const vec2& v) {
    return std::sqrt( v.e[0] * v.e[0] + 
                      v.e[1] * v.e[1] );
}

inline double sum(const vec2& v) {
    return v.e[0] +
           v.e[1];
}

#endif