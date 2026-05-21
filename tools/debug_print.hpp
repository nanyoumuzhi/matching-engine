#pragma once

#include "price_level.hpp"

inline int total_quantity(const PriceLevel& level) {
    int total = 0;
    
    auto* now = level.head;

    while (now) {
        total += now->quantity;
        now = now->next;
    }

    return total;
}