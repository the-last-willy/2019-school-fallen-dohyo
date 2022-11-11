#pragma once

#include<ostream>

class ratio;
class vector;

/**
 * @name Debugging
 * @{
 */

/**
 * @brief antecedent:consequent
 * @relates ratio
 */
std::ostream& operator<<(std::ostream&, ratio const&);

/**
 * @brief (x, y)
 * @relates vector
 */
std::ostream& operator<<(std::ostream&, vector const&);

/// @}
