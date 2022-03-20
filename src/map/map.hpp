#pragma once

#include <stdint.h>
#include <vector>
#include <map>
#include <memory>

#include "veh_conf.hpp"
#include "ctop.hpp"

/**
 * @brief namespace for all map functionalities
 */
namespace map
{

/**
 * @brief struct for the obstacle properties
 */
struct Obstacle_S
{
    /**
     * @brief obstacle position (center)
     */
    Frame_S obs_pos_ori;
    /**
     * @brief obstacle dimensions
     */
    Dimensions_3D_S obs_dim;
    /**
     * @brief is obstacle dynamic
     */
    bool is_dynamic;
};


/**
 * @brief class addressing the grid map
 */
class Grid_Map_C
{
public:

    /** @brief type for the grid map data structure */
    typedef std::map<Point_S, bool> GridMap_t;

    /**
     * @brief enum class for map errors
     */
    enum class Map_Error_Code_EC {
        Err_None,
        Err_KeyNotFound,
        Err_InvalidCfg,
        Err_MapFailed
    };

    /**
     * @brief map origin type enum class
     */
    enum class Map_Origin_Type_EC {
        Rel_Veh,
        Rel_Origin
    };

    /**
     * @brief construct a new Grid_Map_C object
     * 
     * @param size - size of grid map in number of grids per side
     * @param resolution - resolution of grid map in mellimeters per grid cell
     * @param mapType - indicates the type of the map will be used (origin or vehicle)
     */
    Grid_Map_C (int16_t size=20, double resolution=50.0,
                Map_Origin_Type_EC mapType=Map_Origin_Type_EC::Rel_Veh)
        : size_(size), resolution_(resolution), origin_type_(mapType) {}

    /**
     * @brief set the Obstacles vector object
     * 
     * @param v_obstacles - vector of obstacles
     */
    void setObstaclesVector(std::vector<Obstacle_S>& v_obstacles) { v_obstacles_ = v_obstacles; }

    /**
     * @brief get the grid map object
     * 
     * @return GridMap_t& - the grid map class member
     */
    GridMap_t getGridMap() const { return grid_map_; }

    /**
     * @brief interface to create grid map
     */
    void createGridMap();

    /**
     * @brief get the collision at a given point
     * 
     * @param point - point of x and y
     * @return true - collision
     * @return false - no collision
     */
    bool getCollisionAtPoint(Point_S point);

    /**
     * @brief get the collision's confidence at a given point
     * 
     * @param point - point to check for collision
     * @return double - confidence of collision at point
     */
    double getCollisionConfidenceAtPoint(Point_S point);

    /**
     * @brief get the map type object
     * 
     * @return Map_Origin_Type_EC 
     */
    Map_Origin_Type_EC getMapType() const { return origin_type_; }

protected:
    /** @brief grid map */
    GridMap_t grid_map_;

    /**
     * @brief static function to free up the map points inside the vehicle's contour
     * 
     * @param gridMap - the grid map used
     * @param vehPos - actual vehicle's position
     * @param vehCfg - configuration of the vehicle
     * @return true - successful
     * @return false - error
     */
    static bool freeVehPosInMap(GridMap_t& gridMap, const Frame_S& vehPos, const Veh_Cfg_S& vehCfg);

private:
    /** @brief number of mellimeters per grid point */
    double resolution_;

    /**
     * @brief grid size, since it's square size so we need one side,
     * the size is measured in the number of grid points
     */
    int16_t size_;

    /** @brief vector of obstacles */
    std::vector<Obstacle_S> v_obstacles_;

    /**
     * @brief vehicle's configuration
     */
    std::shared_ptr<Veh_Cfg_S> veh_cfg_;

    /**
     * @brief frame of the vehicle's position
     */
    Frame_S veh_pos {Point_S{0.0, 0.0}, 0.0};

    /**
     * @brief error code
     */
    Map_Error_Code_EC error_code_{Map_Error_Code_EC::Err_None};

    /**
     * @brief type of map used
     */
    Map_Origin_Type_EC origin_type_{Map_Origin_Type_EC::Rel_Veh};
};

} // namespace map