#include <iostream>

#include "debug_print.hpp"
#include "order_book.hpp"

void OrderBook::add_limit_order(Order* order) {
    if (order->is_buy) {
        auto& level = asks[order->price];
        level.price = order->price;
        appand_order(level, order);
    } else {
        auto& level = bids[order->price];
        level.price = order->price;
        appand_order(level, order);
    }
}

void OrderBook::debug_print() {
    std::cout << "\n============== ORDER BOOK ==============\n";

    std::cout << "\nASK:\n";
    for (const auto& [price, level] : asks) {
        std::cout << price << "  :  " << total_quantity(level) << "\n";
    }
    
    std::cout << "\n========================================\n";

    std::cout << "\nBID:\n";
    for (const auto& [price, level] : bids) {
        std::cout << price << "  :  " << total_quantity(level) << "\n";
    }
    
    std::cout << "\n========================================\n";
}