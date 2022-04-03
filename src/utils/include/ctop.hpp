/* Common TOPology */

#pragma once

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <math.h>

#define _USE_MATH_DEFINES

#define ANG_90_RAD 90.0
#define ANG_180_DEG 180.0
#define ANG_270_DEG 270.0
#define ANG_360_DEG 360.0
#define ANG_90_DEG M_PI / 2
#define ANG_180_RAD M_PI
#define ANG_360_RAD M_PI * 2
#define ANG_270_RAD 3 * M_PI / 2

#define CONV_RAD_TO_DEG(R) R * ANGLE_180_DEG / M_PI
#define CONV_DEG_TO_RAD(D) D * M_PI / ANGLE_180_DEG

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

    /**
     * @brief overloading operator + for struct
     * @param p - point
     * @return point with current point's and input point p's values added
     */
    Point_S operator+(const Point_S& p) const;

    /**
     * @brief overloading operator - for struct
     * @param p - point
     * @return point with current point's and input point p's values subtracted
     */
    Point_S operator-(const Point_S& p) const;

    /**
     * @brief overloading operator == for struct
     * @param p - point
     * @return bool whether current point equals input point
     */
    bool operator==(const Point_S& p) const;
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
        : init_type_(initType), init_frame_(initFrame), dimensions_(dim) {}

    /**
     * @brief function that transforms the frame to the initiale position
     * @param frame - frame to be transformed
     * @param current - current type
     * @param required - required type
     * @return Frame_S - transformed frame
     */
    static Frame_S transformTypeFrameToFrame(const Frame_S& frame,
                                             const Quad_Point_Type_E current,
                                             const Quad_Point_Type_E required);

    /**
     * @brief function to construct the quadrangle
     */
    void construct();

    /**
     * @brief get array of points
     * @param a_points - reference to array of points to be filled from attribute
     */
    inline void getPoints(Point_S (&a_points)[Quad_Points_Num]) const {
        for (uint8_t i = 0; i < Quad_Points_Num; i++)
        {
            a_points[i] = points_quad_[i];
        }
    }

private:

    /**
     * @brief attribute identifies the type of the initial point
     */
    Quad_Point_Type_E init_type_;

    /**
     * @brief attribute identifies the initialization frame
     */
    Frame_S init_frame_;

    /**
     * @brief attribute identifies the scalar dimensions
     */
    Dimensions_2D_S dimensions_;

    /**
     * @brief attribute stores the array of points in a quad
     */
    Point_S points_quad_[Quad_Points_Num];

};