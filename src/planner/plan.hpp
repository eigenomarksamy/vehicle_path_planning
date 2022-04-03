/* PLANner */

#pragma once

#include <stdint.h>
#include <vector>

#include "ctop.hpp"

namespace planner
{

class GM_Planner_C
{
public:
    GM_Planner_C(std::vector<std::vector<int64_t>> grid)
        : grid_original_(std::move(grid)), grid_size_(grid_original_.size()) { };

    /**
     * @brief copy constructor
     * @return no return
     * @details default
     */
    GM_Planner_C(const GM_Planner_C&) = default;

    /**
     * @brief move constructor
     * @return no return value
     * @details default
     */
    GM_Planner_C(GM_Planner_C&&) = default;

    /**
     * @brief copy assignment
     * @return no return value
     * @details operator overloading
     */
    GM_Planner_C& operator=(const GM_Planner_C&) = default;

    /**
     * @brief move assignment
     * @return no return value
     * @details operator overloading
     */
    GM_Planner_C& operator=(GM_Planner_C&&) = default;

    /**
     * @brief virtual destructor
     * @return no return value
     * @details destructor
     */
    virtual ~GM_Planner_C() = default;

    /**
     * @brief pure virtual function, overloaded by each of planners' implementations
     * @param start - start point
     * @param goal - goal point
     * @return tuple containing bool, if there is a path, path
     */
    virtual std::tuple<bool, std::vector<Point_S>> plan(const Point_S& start, const Point_S& goal) = 0;

protected:
    /**
     * @brief the grid passed
     */
    std::vector<std::vector<int64_t>> grid_ = {};
    /**
     * @brief the original grid (before planning)
     */
    const std::vector<std::vector<int64_t>> grid_original_;
    /**
     * @brief the grid size
     */
    const int64_t grid_size_;
};

} // namespace planner
