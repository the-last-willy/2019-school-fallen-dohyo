#include"transform.hpp"

#include"ratio.hpp"
#include"rectangle.hpp"
#include"vector.hpp"

#include<algorithm>

rectangle& extend(rectangle& rect, ratio const& r) {
    auto h = height(rect), w = width(rect);
    // extend horizontally
    if(w * r.consequent < h * r.antecedent) {
        auto delta = std::abs(w - h * r.antecedent / r.consequent);
        rect.left -= delta / 2;
        rect.right += delta / 2;
    }
    // extend vertically
    else {
        auto delta = std::abs(h - w * r.consequent / r.antecedent);
        rect.bottom -= delta / 2;
        rect.top += delta / 2;
    }
    return rect;
}

rectangle extended(rectangle rect, ratio const& r) {
    return extend(rect, r);
}

rectangle& extend(rectangle& r, vector const& v) {
    if(v.x > 0) r.right += v.x;
    else r.left += v.x;
    if(v.y > 0) r.top += v.y;
    else r.bottom += v.y;
    return r;
}

rectangle& move(rectangle& r, vector const& v) {
    r.bottom += v.y;
    r.left += v.x;
    r.right += v.x;
    r.top += v.y;
    return r;
}

rectangle extended(rectangle r, vector const& v) {
    return extend(r, v);
}
