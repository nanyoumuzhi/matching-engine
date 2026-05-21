#include <cassert>

#include "order_book.hpp"

int main() {
    OrderBook book;

    Order buyorder;
    buyorder.is_buy = true;
    book.add_limit_order(&buyorder);
    assert(book.asks.size() == 1);

    for (int i = 0; i < 10; i++) {
        Order* order = new Order;
        order->is_buy = true;
        order->price = 10;
        order->order_id = i;
        order->quantity = 1;
        book.add_limit_order(order);
    }
    assert(book.asks[10].head->order_id == 0);
    assert(book.asks[10].tail->order_id == 9);

    for (int i = 11; i <= 20; i++) {
        Order* order = new Order;
        order->is_buy = false;
        order->price = i;
        order->order_id = i;
        order->quantity = 1;
        book.add_limit_order(order);
    }
    for (int i = 11; i <= 20; i++) {
        assert(book.bids[i].head->order_id == i);
        assert(book.bids[i].tail->order_id == i);
    }

    book.debug_print();
    return 0;
}