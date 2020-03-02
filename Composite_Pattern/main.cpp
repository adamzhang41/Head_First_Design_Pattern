#include <iostream>
#include <exception>
#include "main.h"

using namespace std;

int main()
{
    shared_ptr<MenuComponent> pancakeHouseMenu (new Menu("PANCAKE HOUSE MENU", "Breakfast"));
    shared_ptr<MenuComponent> dinerMenu (new Menu("DINER MENU", "Lunch"));
    shared_ptr<MenuComponent> cafeMenu (new Menu("CAFE MENU", "Dinner"));
    shared_ptr<MenuComponent> dessertMenu (new Menu("DESSERT MENU", "Dessert of course!"));

    shared_ptr<MenuComponent> allMenus (new Menu("ALL MENUS", "All menu combined!"));

    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    allMenus->add(cafeMenu);

    shared_ptr<MenuComponent> menuItem = make_shared<MenuItem>("Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
    shared_ptr<MenuComponent> menuItem1 = make_shared<MenuItem>("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
    shared_ptr<MenuComponent> menuItem2 = make_shared<MenuItem>("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
    shared_ptr<MenuComponent> menuItem3 = make_shared<MenuItem>("Hotdog", "A hot dog, with saurkraut, relish, onions, topped, with chees", false, 3.05);
    dinerMenu->add(menuItem);
    dinerMenu->add(menuItem1);
    dinerMenu->add(menuItem2);
    dinerMenu->add(menuItem3);
    dinerMenu->add(dessertMenu);

    shared_ptr<MenuComponent> menuItem4 (new MenuItem("Apple Pie", "Apple pie with a flakey crust, topped with vanilla ice cream", true, 1.59));
    dessertMenu->add(menuItem4);

    allMenus->print();

    return 0;
}
