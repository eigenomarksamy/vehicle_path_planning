#include "ctop.hpp"

Point_S Point_S::operator+(const Point_S& p) const
{
    Point_S tmp;
    tmp.x_m_ = this->x_m_ + p.x_m_;
    tmp.y_m_ = this->y_m_ + p.y_m_;
    return tmp;
}

Point_S Point_S::operator-(const Point_S& p) const
{
    Point_S tmp;
    tmp.x_m_ = this->x_m_ - p.x_m_;
    tmp.y_m_ = this->y_m_ - p.y_m_;
  return tmp;
}

bool Point_S::operator==(const Point_S& p) const
{
    return (this->x_m_ == p.x_m_ && this->y_m_ == p.y_m_);
}

Frame_S Frame_S::operator+(const Frame_S& p) const
{
    Frame_S tmp;
    tmp.xy_point_ = this->xy_point_ + p.xy_point_;
    tmp.ang_rad_ = this->ang_rad_ + p.ang_rad_;
    return tmp;
}

Frame_S Frame_S::operator-(const Frame_S& p) const
{
    Frame_S tmp;
    tmp.xy_point_ = this->xy_point_ - p.xy_point_;
    tmp.ang_rad_ = this->ang_rad_ - p.ang_rad_;
  return tmp;
}

bool Frame_S::operator==(const Frame_S& p) const
{
    return (this->xy_point_ == p.xy_point_ && this->ang_rad_ == p.ang_rad_);
}

void Quadrangle_S::construct()
{
    /* transform init frame to the starting corner (bot-right) */
    auto botRightFrame = transformTypeFrameToFrame(init_frame_, init_type_, Bot_Right);
}

Frame_S Quadrangle_S::transformTypeFrameToFrame(const Frame_S& frame,
                                                const Quad_Point_Type_E current,
                                                const Quad_Point_Type_E required)
{
    Frame_S newFrame;

    if (current == required)
    {
        newFrame = frame;
    }

    return newFrame;
}