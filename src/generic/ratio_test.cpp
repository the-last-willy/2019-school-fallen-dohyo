#include<catch.hpp>

#include"ratio.hpp"

TEST_CASE(
    "'ratio's can be default constructed", 
    "[ratio][default-constructor]"
) {
    auto r = ratio{};
    REQUIRE(valid(r))
    REQUIRE(r.antecedent == 1);
    REQUIRE(r.consequent == 1);
}
