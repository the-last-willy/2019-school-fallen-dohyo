#pragma once

/**
 * @brief 32-bit signed integer ratio.
 * @ingroup generic
 */
struct ratio {
    /// antecedent = consequent = 1
    ratio();

    ratio(ratio const&) = default;

    /**
     * @pre antecedent != 0, consequent != 0
     * @post valid
     * @sa valid(ratio const&)
     */
    ratio(int antecedent, int consequent);

    ratio& operator=(ratio const&) = default;

    /// left term
    int antecedent;
    /// right term
    int consequent;
};

/**
 * @brief antecedent != 0, consequent != 0
 * @relates ratio
 */
bool valid(ratio const& r);

/**
 * @pre left operand is valid
 * @post valid
 * @sa valid(ratio const&, int)
 * @relates ratio
 */
ratio& operator*=(ratio&, int);

/**
 * @copydoc operator*=(ratio&, int)
 * @relates ratio
 */
ratio operator*(ratio, int);

/**
 * @pre left operand is valid
 * @post valid
 * @sa valid(ratio const&, int)
 * @relates ratio
 */
ratio& operator/=(ratio&, int);

/**
 * @copydoc operator/=(ratio&, int)
 * @relates ratio
 */
ratio& operator/(ratio&, int);
