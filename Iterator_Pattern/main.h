#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <list>
#include <memory>
#include <array>
#include <vector>

using std::list;
using std::shared_ptr;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;
using std::vector;

class MenuItem{
    string name;
    string description;
    bool vegetarian;
    double price;
public:
    MenuItem(string name, string description, bool vegetarian, double price):name(name),description(description),vegetarian(vegetarian),price(price){
    }
    //要有一个空的构造函数，因为MenuItem menuItems[MAX_ITEMS];这里需要一个这样的构造函数。
    MenuItem(){
    }
    string getName(){
        return name;
    }
    string getDescription(){
        return description;
    }
    double getPrice(){
        return price;
    }
    bool isVegetarian(){
        return vegetarian;
    }
};

class Iterator{
public:
    virtual bool hasNext() = 0;
    virtual MenuItem next() = 0;
};

class PancakeHouseIterator : public Iterator{
    list<MenuItem> items;
    list<MenuItem>::iterator iter;

public:
    PancakeHouseIterator(list<MenuItem>items){
        this->items = items;
        iter = this->items.begin();
    }
    MenuItem next(){
        MenuItem menuItem = *iter;
        iter++;
        return menuItem;
    }
    bool hasNext(){
        return(iter != items.end());
    }
};

class DinnerMenuIterator : public Iterator{
    vector<MenuItem> items;
    vector<MenuItem>::iterator iter;

public:
    DinnerMenuIterator(vector<MenuItem>items){
        this->items = items;
        iter = this->items.begin();
    }
    MenuItem next(){
        MenuItem menuItem = *iter;
        iter++;
        return menuItem;
    }
    bool hasNext(){
        return(iter != items.end());
    }
};

class Menu{
public:
    virtual shared_ptr<Iterator> creatIterator() = 0;
};

class PancakeHouseMenu : public Menu{
    list<MenuItem> menuItems;
public:
    PancakeHouseMenu(){
        addItem("K&B's Pancake Breakfast",
                "Pancakes with scrambled eggs, and toast",
                true,
                2.99);
        addItem("Regular Pancake Breakfast",
                "Pancakes with fried eggs, sausage",
                false,
                2.99);
        addItem("Blueberry Pancakes",
                "Pancakes made with fresh blueberries",
                true,
                3.49);
        addItem("Waffles",
                "Waffles, with your choice of blueberries or strawberries",
                true,
                3.59);
    }
    shared_ptr<Iterator> creatIterator(){
        shared_ptr<Iterator> iter(new PancakeHouseIterator(menuItems));
        return iter;
    }
    void addItem(string name, string description, bool vegetarian, double price){
        MenuItem menuItem(name, description, vegetarian, price);
        menuItems.push_back(menuItem);
    }
};

class DinerMenu : public Menu{
    vector<MenuItem> menuItems;
public:
    DinerMenu(){
        addItem("Vegetarian BLT",
                "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
        addItem("BLT",
                "Bacon with lettuce & tomato on whole wheat", false, 2.99);
        addItem("Soup of the day",
                "Soup of the day, with a side of potato salad", false, 3.29);
        addItem("Hotdog",
                "A hot dog, with saurkraut, relish, onions, topped, with chees", false, 3.05);
    }
    shared_ptr<Iterator> creatIterator(){
        shared_ptr<Iterator> iter(new DinnerMenuIterator(menuItems));
        return iter;
    }

    void addItem(string name, string description, bool vegetarian, double price){
        MenuItem menuItem(name, description, vegetarian, price);
        menuItems.push_back(menuItem);
    }
};

class Waitress{
    shared_ptr<Menu> pancakeHouseMenu;
    shared_ptr<Menu> dinnerMenu;
public:
    Waitress(shared_ptr<Menu> pancakeHouseMenu, shared_ptr<Menu> dinnerMenu){
        this->pancakeHouseMenu = pancakeHouseMenu;
        this->dinnerMenu = dinnerMenu;
    }
    void printMenu(){
        shared_ptr<Iterator> pancakeHouseIterator = pancakeHouseMenu->creatIterator();
        cout << "breakfast menu:" << endl;
        printMenu(pancakeHouseIterator);
        shared_ptr<Iterator> dinnerIterator = dinnerMenu->creatIterator();
        cout << "dinner menu:" << endl;
        printMenu(dinnerIterator);
    }
private:
    void printMenu(shared_ptr<Iterator> iter){
        while(iter->hasNext()){
            MenuItem menuItem = iter->next();
            cout << menuItem.getName() + ", " << menuItem.getPrice() << "--" << menuItem.getDescription() << endl;
        }
    }
};

#endif // MAIN_H
