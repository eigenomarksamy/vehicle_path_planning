/* Common TOPology */

#pragma once

#include <vector>
#include <string>
#include <map>
#include <memory>

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
struct Dimensions_2D_S
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
     * @brief construct a new Dimensions_2D_S object
     * 
     * @param length - length given to object
     * @param width - width given to object
     */
    Dimensions_2D_S (const double length, const double width)
        : length(length), width(width) {};
};

/**
 * @brief structure for the quadrangle computations and properties
 */
struct Quadrangle_S
{

    /**
     * @brief enum type to identify the point of a quadrangle
     */
    enum Quad_Point_Type_E
    {
        Mid, Mid_Right, Top_Right,
        Mid_Top, Top_Left, Mid_Left,
        Bot_Left, Mid_Bot, Bot_Right,
        Quad_Points_Num
    };

    /**
     * @brief construct a new Quadrangle_S object
     * 
     * @param initType - the type of the point that should be considered in initialization
     * @param initFrame - the frame of initialization (x, y, angle)
     * @param dim - dimensions of quad
     */
    Quadrangle_S(Quad_Point_Type_E initType, Frame_S initFrame, Dimensions_2D_S dim)
        : init_type(initType), init_frame(initFrame), dimensions(dim) {}

    /**
     * @brief function to construct the quadrangle
     */
    void construct();

    /**
     * @brief get array of points
     * @param points - reference to array of points to be filled
     */
    void getPoints(Point_S (&points)[Quad_Points_Num]) const;

private:

    /**
     * @brief attribute identifies the type of the initial point
     */
    Quad_Point_Type_E init_type;

    /**
     * @brief attribute identifies the initialization frame
     */
    Frame_S init_frame;

    /**
     * @brief attribute identifies the scalar dimensions
     */
    Dimensions_2D_S dimensions;

    /**
     * @brief attribute stores the array of points in a quad
     */
    Point_S points_quad[Quad_Points_Num];

};