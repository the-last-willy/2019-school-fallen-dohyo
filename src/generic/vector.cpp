#include"vector.hpp"

vector const vector::null = {0, 0};

bool null(vector const& v) {
    return !(v.x or v.y);
}
