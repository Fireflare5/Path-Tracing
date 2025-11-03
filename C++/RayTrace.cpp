#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

inline double sdSphere(const vec3& p, const vec4& s) {
    return hypot(s.xyz() - p) - s.d();
}

inline vec3 normalize(const vec3& u, const vec3& v) {
    vec3 uv = u - v;
    return rsqrt(dot2(uv)) * uv;
}

inline vec3 normalize(const vec3& v) {
    return rsqrt(dot2(v)) * v;
}

inline double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    return min + (max-min)*random_double();
}

inline double march(const vec4& obj, const vec3& cam, const vec3& id, const vec2& res, const vec3& light) {
    vec3 ray_d = vec3(35.0 * ((id[0] + random_double() - 0.5) - res[0]/2.0)/(res[0] * 1000.0), id[2]/1000.0, -35.0 * ((id[1] + random_double() - 0.5) - res[1]/2.0)/(res[0] * 1000.0)) - cam;
    double r;
    vec3 pos = cam;
    double epsilon = 0.00001;
    double tmp = sdSphere(pos,obj);
    vec3 ray = normalize(ray_d,cam);
    for(int i = 0; i < 300; i++) {
        r = sdSphere(pos,obj);
        if (r <= epsilon) {
            pos += r * ray;
            vec3 normal = normalize(vec3(sdSphere(pos + vec3(epsilon,0.0,0.0),obj) - sdSphere(pos - vec3(epsilon,0.0,0.0),obj),
                                           sdSphere(pos + vec3(0.0,epsilon,0.0),obj) - sdSphere(pos - vec3(0.0,epsilon,0.0),obj),
                                           sdSphere(pos + vec3(0.0,0.0,epsilon),obj) - sdSphere(pos - vec3(0.0,0.0,epsilon),obj)));
            return -dot(normal, light);
        } else if (r > tmp) {
            return 0.0;
        } else {
            tmp = r;
            pos += r * ray;
        }
    }
    return 0.0;
}

int main() {
    vec4 sphere(0.0,4.0,0.0,1.0);
    vec2 res;
    int samples;
    vec3 cam(0.0,0.0,0.0);
    vec3 light(3.0,2.0,3.0);
    vec3 light_norm = normalize(sphere.xyz(),light);
    cin >> res[0] >> res[1] >> samples;
    for (int i = 0; i < res.x(); i++) {
        for (int ii = 0; ii < res.y(); ii++) {
            vec3 id(i,ii,25.0);
            double n = 0.0;
            for (int sample = 0; sample < samples; sample++) {
                n += march(sphere,cam,id,res,light_norm);
            }
            cout << ((sign(n) < 0.0) ? 0.0 : (n * (1.0/samples))) << ' ';
        }
        cout << endl;
    }
    return 0;
}