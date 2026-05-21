#pragma once

#include <cstdint>

struct Order {
    uint64_t order_id;

    bool is_buy;

    int price;
    int quantity;

    Order* next;
    Order* prev;
};