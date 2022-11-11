#pragma once

#include"vector.hpp"

/**
 * @relates vector
 */
constexpr vector& operator+=(vector& l, vector const& r) {
    l.x += r.x;
    l.y += r.y;
    return l;
}

/**
 * @relates vector
 */
constexpr vector operator+(vector l, vector const& r) {
    return l += r;
}

/**
 * @relates vector
 */
constexpr vector& operator*=(vector& l, int r) {
    l.x *= r;
    l.y *= r;
    return l;
}

/**
 * @relates vector
 */
constexpr vector operator*(vector l, int r) {
    return l *= r;
}

/**
 * @relates vector
 */
constexpr vector& operator/=(vector& l, int r) {
    l.x /= r;
    l.y /= r;
    return l;
}

/**
 * @relates vector
 */
constexpr vector operator/(vector l, int r) {
    return l /= r;
}

/**
 * @relates vector
 */
constexpr vector& operator%=(vector& l, int r) {
    l.x %= r;
    l.y %= r;
    return l;
}

/**
 * @relates vector
 */
constexpr vector operator%(vector l, int r) {
    return l %= r;
}
