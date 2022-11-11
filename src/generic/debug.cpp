#include"debug.hpp"

#include"ratio.hpp"
#include"rectangle.hpp"
#include"vector.hpp"

std::ostream& operator<<(std::ostream& stream, ratio const& r) {
    return stream << r.antecedent << ':' << r.consequent;
}

std::ostream& operator<<(std::ostream& stream, vector const& v) {
    return stream << '(' << v.x << ", " << v.y << ')';
}
