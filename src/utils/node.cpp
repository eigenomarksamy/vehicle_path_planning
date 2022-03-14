#include "node.hpp"

Node_S Node_S::operator+(const Node_S& p) const
{
    Node_S tmp;
    tmp.x_ = this->x_ + p.x_;
    tmp.y_ = this->y_ + p.y_;
    tmp.cost_ = this->cost_ + p.cost_;
    return tmp;
}

Node_S Node_S::operator-(const Node_S& p) const
{
  Node_S tmp;
  tmp.x_ = this->x_ - p.x_;
  tmp.y_ = this->y_ - p.y_;
  return tmp;
}

bool Node_S::operator==(const Node_S& p) const
{
    return this->x_ == p.x_ && this->y_ == p.y_;
}