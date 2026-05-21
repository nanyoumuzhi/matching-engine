#pragma once

#include "order.hpp"

struct PriceLevel {
    int price;

    Order* head = nullptr;
    Order* tail = nullptr;
};

void appand_order(PriceLevel& level, Order* order) {
    order->prev = nullptr;
    order->next = nullptr;

    if (level.head == nullptr) {
        level.head = order;
        level.tail = order;

        return;
    }

    level.tail->next = order;
    order->prev = level.tail;
    level.tail = order;
}

void remove_order(PriceLevel& level, Order* order) {
    if (level.head == order) {
        level.head = order->next;
    }
    if (level.tail == order) {
        level.tail = order->prev;
    }
    if (order->next) {
        order->next->prev = order->prev;
    }
    if (order->prev) {
        order->prev->next = order->next;
    }

    order->prev = nullptr;
    order->next = nullptr;
}