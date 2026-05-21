#pragma once

#include <map>
#include <unordered_map>

#include "./price_level.hpp"

class OrderBook {
public:
    void add_limit_order(Order* order);
    void debug_print();

// private:
    std::map<int, PriceLevel, std::greater<int> > bids;
    std::map<int, PriceLevel> asks;
    std::unordered_map<uint64_t, Order*> orders;

};