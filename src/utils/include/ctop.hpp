#pragma once

struct Point_S
{
    /**
     * @brief x of point in meters
     */
    double x_m_;
    /**
     * @brief y of point in meters
     */
    double y_m_;

    Point_S () {}

    Point_S (const double x, const double y)
        : x_m_(x), y_m_(y) {};
};

struct Frame_S
{
    /**
     * @brief point of x and y
     */
    Point_S xy_point_;
    /**
     * @brief angle of point in radians
     */
    double ang_rad_;

    /**
     * @brief default constructor
     */
    Frame_S () {}

    /**
     * @brief explicit constructor uses the point
     */
    explicit Frame_S (const Point_S xy_point, const double ang_rad)
        : xy_point_(xy_point), ang_rad_(ang_rad) {};

    /**
     * @brief explicit constructor to initialize point parameters
     * @param x_m - x value
     * @param y_m - y value
     * @param ang_rad - angle value
     */
    explicit Frame_S (const double x_m, const double y_m, const double ang_rad)
    {
        xy_point_.x_m_ = x_m;
        xy_point_.y_m_ = y_m;
        ang_rad_ = ang_rad;
    }

    /**
     * @brief overloading operator + for struct
     * @param p - frame
     * @return frame with current frame's and input frame p's values added
     */
    Frame_S operator+(const Frame_S& p) const;

    /**
     * @brief overloading operator - for struct
     * @param p - frame
     * @return frame with current frame's and input frame p's values subtracted
     */
    Frame_S operator-(const Frame_S& p) const;

    /**
     * @brief overloading operator == for struct
     * @param p - frame
     * @return bool whether current frame equals input frame
     */
    bool operator==(const Frame_S& p) const;
};

struct Dimensions_3D_S
{
    double length;
    double width;
    double height;

    Dimensions_3D_S (const double length, const double width, const double height)
        : length(length), width(width), height(height) {};
};
