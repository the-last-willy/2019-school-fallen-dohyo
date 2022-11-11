#pragma once

#include<ostream>

/**
 * @brief Signed 32-bit integer vecotr.
 * @ingroup generic
 */
struct vector {
    // @brief x = 0, y = 0
    constexpr vector() : x(0), y(0) {}

    constexpr vector(vector const&) = default;

    constexpr vector(int x, int y) : x(x), y(y) {}

    constexpr vector& operator=(vector const&) = default;

    int x;
    int y;

    static vector const null;
};

constexpr vector null_value() {
    return vector{0, 0};
}

bool null(vector const&);
