#pragma once

#include <cstdint>

struct Order {
    uint64_t order_id = 0;

    bool is_buy = true;

    int price = 0;
    int quantity = 0;

    Order* next = nullptr;
    Order* prev = nullptr;
};