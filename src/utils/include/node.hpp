#pragma once

#include <stdint.h>

struct Node_S
{
    /**
     * @brief x-coordinate
     */
    int64_t x_;
    /**
     * @brief y-coordinate
     */
    int64_t y_;
    /**
     * @brief id
     */
    int64_t id_;
    /**
     * @brief parent's id
     */
    int64_t parent_id_;
    /**
     * @brief cost to reach
     */
    double cost_;
    /**
     * @brief heuristic cost to reach
     */
    double h_cost_;

    /**
     * @brief constructor for node struct
     * @param x - x value
     * @param y - y value
     * @param id - node id
     * @param parent_id - parent id
     * @param cost - cost to get to node
     * @param h_cost - heuristic cost
     */
    Node_S(const int64_t x = 0, const int64_t y = 0,
           const int64_t id = 0, const int64_t parent_id = 0,
           const double cost = 0, const double h_cost = 0)
           : x_(x), y_(y), id_(id), parent_id_(parent_id), cost_(cost), h_cost_(h_cost) { };

    /**
     * @brief overloading operator + for struct
     * @param p - node
     * @return node with current node's and input node p's values added
     */
    Node_S operator+(const Node_S& p) const;

    /**
     * @brief overloading operator - for struct
     * @param p - node
     * @return node with current node's and input node p's values subtracted
     */
    Node_S operator-(const Node_S& p) const;

    /**
     * @brief overloading operator == for struct
     * @param p - node
     * @return bool whether current node equals input node
     */
    bool operator==(const Node_S& p) const;
};