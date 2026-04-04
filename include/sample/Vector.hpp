#include "./constants/types.hpp"
#include <cmath>
#include <ostream>

using std::ostream;
class Vector
{
public:
    Vector(ReadOnly<double> a, ReadOnly<double> b, ReadOnly<double> c) : x(a), y(b), z(c) {}

    Vector operator-() const { return Vector(-x, -y, -z); }
    Vector operator+(ReadOnly<Vector> v) const { return Vector(x + v.x, y + v.y, z + v.z); }
    Vector operator-(ReadOnly<Vector> v) const { return (*this) + (-v); }

    Vector operator*(ReadOnly<double> s) const { return Vector(s * x, s * y, s * z); }
    Vector operator/(ReadOnly<double> s) const { return (*this) * (1 / s); }

    double operator*(ReadOnly<Vector> v) const { return (x * v.x) + (y * v.y) + (z * v.z); }
    Vector cross(ReadOnly<Vector> v) const
    {
        return Vector((y * v.z - z * v.y),
                      (z * v.x - x * v.z),
                      (x * v.y - y * v.x));
    }

    double magnitude() const { return sqrt(sq(x) + sq(y) + sq(z)); }
    Vector unitVector() const { return (*this) / magnitude(); }

    double comp(ReadOnly<Vector> v) { return (*this) * v / magnitude(); }
    Vector proj(ReadOnly<Vector> v) { return unitVector() * comp(v); }

    friend ostream &operator<<(Ref<ostream> o, ReadOnly<Vector> v) { return o << "(" << v.x << ", " << v.y << ", " << v.z << ")"; }

private:
    const double x;
    const double y;
    const double z;

    double sq(ReadOnly<double> x) const { return pow(x, 2); }
};