#pragma once

#include <stdint.h>
#include <vector>
#include <map>

#include "ctop.hpp"

namespace map
{

struct Obstacle_S
{
    Frame_S obs_pos_ori;
    Dimensions_3D_S obs_dim;
    bool is_dynamic;
};


class Grid_Map_C
{
public:
    Grid_Map_C () {}
protected:
    std::map<Point_S, bool> grid_map_;
    int64_t resolution_;
private:
    std::vector<Obstacle_S> vec_obstacles_;
};

} // namespace map