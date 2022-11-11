#pragma once

class ratio;
class rectangle;
class vector;

/**
 * @brief Extend until a given width:height ratio.
 * @post center_x, center_y
 * @relates rectangle
 * @todo postcondition width:height ratios are equivalent
 */
rectangle& extend(rectangle&, ratio const&);

/**
 * @copydoc extend(rectangle&, ratio const&)
 * @relates rectangle
 */
rectangle extended(rectangle, ratio const&);

/**
 * @relates rectangle
 */
rectangle& extend(rectangle&, vector const&);

/**
 * @relates rectangle
 */
rectangle extended(rectangle, vector const&);

/**
 * @relates rectangle
 */
rectangle& move(rectangle&, vector const&);

/**
 * @relates rectangle
 */
rectangle moved(rectangle, vector const&);
