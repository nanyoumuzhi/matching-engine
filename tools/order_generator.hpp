#pragma once

#include "order.hpp"

inline uint64_t next_order_id() {
    static uint64_t id = 1;
    return id++;
}

inline Order* make_buy_order(int price, int qty) {
    auto* order = new Order;
    order->order_id = next_order_id();
    order->is_buy = true;
    order->price = price;
    order->quantity = qty;
    return order;
}

inline Order* make_sell_order(int price, int qty) {
    auto* order = new Order;
    order->order_id = next_order_id();
    order->is_buy = false;
    order->price = price;
    order->quantity = qty;
    return order;
}