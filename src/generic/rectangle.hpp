#pragma once

class vector;

/**
 * @brief 32-bit signed integer axis-aligned rectangle.
 * @ingroup generic
 */
struct rectangle {
    /// bottom = 0, left = 0, right = 0, top = 0
    rectangle();

    rectangle(rectangle const&) = default;

    /**
     * @pre left <= right, bottom <= top
     * @post valid
     * @sa valid(rectangle const&)
     */
    static rectangle lbrt(int left, int bottom, int right, int top);

    /**
     * @pre width >= 1, height >= 1
     * @post valid
     * @sa valid(rectangle const&)
     */
    static rectangle lbwh(int left, int bottom, int width, int height);

    rectangle& operator=(rectangle const&) = default;

    /// top - height + 1
    int bottom;

    /// right - width + 1
    int left;

    /// left + width - 1
    int right;

    /// bottom + height - 1
    int top;

private:
    rectangle(int bottom, int left, int right, int top);
};

/**
 * @brief bottom <= top and left <= right
 * @relates rectangle
 */
bool valid(rectangle const&);

/**
 * @brief (right + left) / 2
 * @relates rectangle
 */
int center_x(rectangle const&);

/**
 * @brief (top + bottom) / 2
 * @relates rectangle
 */
int center_y(rectangle const&);

/**
 * @brief top - down + 1
 * @relates rectangle
 */
int height(rectangle const&);

/**
 * @brief right - left + 1
 * @relates rectangle
 */
int width(rectangle const&);

/**
 * @relates rectangle
 */
bool overlap(rectangle const&, rectangle const&);

/**
 * @brief Minimal bounding rectangle.
 * @relates rectangle
 */
rectangle bounding_rectangle(rectangle const&, rectangle const&);

/**
 * @name Sides
 * @relates rectangle
 */
/// @{

//
rectangle bottom_side(rectangle r);
rectangle left_side(rectangle r);
rectangle right_side(rectangle r);
rectangle top_side(rectangle r);

/// @}
