#include"rectangle.hpp"

#include"ratio.hpp"
#include"vector.hpp"

#include<algorithm>

rectangle::rectangle() : bottom(0), left(0), right(0), top(0) {}

rectangle rectangle::lbrt(int l, int b, int r, int t) {
    return {b, l, r, t};
}

rectangle rectangle::lbwh(int l, int b, int w, int h) {
    auto r = l + w - 1;
    auto t = b + h - 1;
    return {b, l, r, t};
}

rectangle::rectangle(int b, int l, int r, int t)
    : bottom(b), left(l), right(r), top(t)
{}

bool valid(rectangle const& r) {
    return r.bottom <= r.top and r.left <= r.right;
}

int center_x(rectangle const& r) {
    return (r.right + r.left) / 2;
}

int center_y(rectangle const& r) {
    return (r.top + r.bottom) / 2;
}

int height(rectangle const& r) {
    return r.top - r.bottom + 1;
}

int width(rectangle const& r) {
    return r.right - r.left + 1;
}

bool overlap(rectangle const& a, rectangle const& b) {
    return a.bottom <= b.top
        and a.left <= b.right
        and a.right >= b.left
        and a.top >= b.bottom;
}

rectangle bounding_rectangle(rectangle const& l, rectangle const& r) {
    auto bottom = std::min(l.bottom, r.bottom);
    auto left = std::min(l.left, r.left);
    auto right = std::max(l.right, r.right);
    auto top = std::max(l.top, r.top);
    return rectangle::lbrt(left, bottom, right, top);
}

rectangle bottom_side(rectangle r) {
    r.top = r.bottom;
    r.bottom -= 1;
    return r;
}

rectangle left_side(rectangle r) {
    r.right = r.left;
    r.left -= 1;
    return r;
}

rectangle right_side(rectangle r) {
    r.left = r.right;
    r.right += 1;
    return r;
}

rectangle top_side(rectangle r) {
    r.bottom = r.top;
    r.top += 1;
    return r;
}
