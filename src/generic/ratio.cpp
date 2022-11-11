#include"ratio.hpp"

ratio::ratio()
    : antecedent(1)
    , consequent(1)
{}

ratio::ratio(int antecedent, int consequent)
    : antecedent(antecedent)
    , consequent(consequent)
{}

ratio& operator*=(ratio& l, int r) {
    if(l.consequent % r == 0)
        l.consequent /= r;
    else
        l.antecedent *= r;
    return l;
}

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
