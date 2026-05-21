#include <map>
#include <unordered_map>
#include <cstdint>
#include <cassert>

#include "../include/order.hpp"
#include "../include/price_level.hpp"

int main() {
    PriceLevel level;
    assert(level.head == nullptr);
    assert(level.tail == nullptr);

    std::unordered_map<uint64_t, Order* > mp;
    for (int i = 0; i < 10; i ++) {
        Order* order = new Order;
        order->order_id = i;
        mp[i] = order;
        appand_order(level, order);
    }
    assert(level.head != nullptr);
    assert(level.head->order_id == 0);

    assert(level.tail != nullptr);
    assert(level.tail->order_id == 9);

    assert(mp[4]->next == mp[5]);
    assert(mp[6]->prev == mp[5]);
    
    remove_order(level, mp[5]);
    assert(mp[4]->next == mp[6]);
    assert(mp[6]->prev == mp[4]);
    return 0;
}