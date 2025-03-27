#include <iostream>
#include "Item.h"
#include "Inventory.h"
using namespace std;

Item* DropItem()
{
    if (rand() % 2 == 0)
    {
        Weapon* weapon = new Weapon();
        return weapon;
    }
    else
    {
        Armor* armor = new Armor();
        return armor;
    }
}



int main()
{
    srand((unsigned)time(0));

    for (int i = 0; i < 50; i++)
    {
        Item* item = DropItem();
        item->PrintInfo();


        if (Inventory::GetInstance()->AddItem(item))
        {
            cout << "Added Item to Inventory" << endl;
        }
        else
        {
            cout << "Failed to add item" << endl;
            delete item;
        }

        //ItemType itemType = item->GetItemType();
        //if (itemType == IT_Weapon)
        //{
        //    Weapon* weapon = (Weapon*)item;
        //    weapon->GetDamage();
        //}
        //else if (itemType == IT_Armor)
        //{
        //    Armor* armor = (Armor*)item;
        //    armor->GetDefence();
        //}
    }

    for (int i = 0; i < 20; i++)
    {
        int randIndex = rand() % MAX_SLOT;
        Item* item = Inventory::GetInstance()->GetItemAtSlot(randIndex);
        if (item != nullptr and Inventory::GetInstance()->RemoveItem(item))
        {
            cout << "Removed Item" << endl;
        }
    }
}

