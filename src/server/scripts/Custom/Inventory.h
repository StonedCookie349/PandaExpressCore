#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory
{
private:
    std::vector<Item*> items;

public:
    void AddItem(Item* item);
    void RemoveItem(Item* item);
    Item* GetItemByEntry(uint32 entry);
    // Additional functions and members for inventory management
};

#endif // INVENTORY_H
