#include "map.hpp"

namespace map
{

void Grid_Map_C::createGridMap()
{
    size_t obstLen = v_obstacles_.size();

    
}

bool Grid_Map_C::getCollisionAtPoint(Point_S point)
{
    const auto& mapItr = grid_map_.find(point);
    if (grid_map_.end() != mapItr)
    {
        return mapItr->second;
    }
    error_code_ = Map_Error_Code_EC::Err_KeyNotFound;
    return false;
}

double Grid_Map_C::getCollisionConfidenceAtPoint(Point_S point)
{

}

} // namespace map