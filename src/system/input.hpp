#pragma once

#include"state.hpp"

#include<entt/entt.hpp>

/**
 * @brief Checks then forwards inputs in real time.
 * 
 * Used components:
 * - controls (read-only)
 * - player
 * .
 * @ingroup system
 */
class Input {
public:
    void operator()(Context&);
};
