#pragma once

/**
 * @brief a point in space structure
 */
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

    /**
     * @brief default constructor
     */
    Point_S () {}

    /**
     * @brief explicit constructor uses the point
     * @param x - x
     * @param y - y
     */
    explicit Point_S (const double x, const double y)
        : x_m_(x), y_m_(y) {};
};

/**
 * @brief structure for the xyangle-frame
 */
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
     * @param xy_point - struct of type of point
     * @param ang_rad - angle in radians
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

/**
 * @brief struct for dimensions of a 3D object
 */
struct Dimensions_3D_S
{
    /**
     * @brief length
     */
    double length;
    /**
     * @brief width
     */
    double width;
    /**
     * @brief height
     */
    double height;

    /**
     * @brief construct a new Dimensions_3D_S object
     * 
     * @param length - length given to object
     * @param width - width given to object
     * @param height - height given to object
     */
    Dimensions_3D_S (const double length, const double width, const double height)
        : length(length), width(width), height(height) {};
};
