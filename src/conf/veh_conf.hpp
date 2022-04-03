/* VEHicle CONFiguration */

#pragma once

struct Veh_Geo_Cfg_S
{
    double wheel_base;
    double track_width;
    double dist_to_front;
    double dist_to_rear;
    double dist_to_right;
    double dist_to_left;

    Veh_Geo_Cfg_S() {}

    Veh_Geo_Cfg_S (double wheel_base, double track_width,
                   double dist_to_front, double dist_to_rear,
                   double dist_to_right, double dist_to_left)
        : wheel_base(wheel_base), track_width(track_width),
          dist_to_front(dist_to_front), dist_to_rear(dist_to_rear),
          dist_to_right(dist_to_right), dist_to_left(dist_to_left) {}
};

struct Veh_Cfg_S
{
    Veh_Geo_Cfg_S veh_geo;
    double safety_dist;
};