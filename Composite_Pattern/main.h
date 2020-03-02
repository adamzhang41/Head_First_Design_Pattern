#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::shared_ptr;

class MenuComponent{
public:
    virtual void add(shared_ptr<MenuComponent> menucomponent){
        try{
            throw "undefined operation!" ;
        }
        catch(const char *msg){
            cerr << msg << endl;
        }
    }
    virtual void comremove(shared_ptr<MenuComponent> menucomponent){
        try{
            throw "undefined operation!" ;
        }
        catch(const char *msg){
            cerr << msg << endl;
        }
    }
    virtual shared_ptr<MenuComponent> getChild(int i){
        try{
            throw "undefined operation!" ;
        }
        catch(const char *msg){
            cerr << msg << endl;
        }
    }
    virtual string getName(){
        try{
            throw "undefined operation!" ;
        }
        catch(const char *msg){
            cerr << msg << endl;
        }
    }
    virtual string getDescription(){
        try{
            throw "undefined operation!" ;
        }
        catch(const char *msg){
            cerr << msg << endl;
        }
    }
    virtual double getPrice(){
        try{
            throw "undefined operation!" ;
        }
        catch(const char *msg){
            cerr << msg << endl;
        }
    }
    virtual bool isVegetarian(){
        try{
            throw "undefined operation!" ;
        }
        catch(const char *msg){
            cerr << msg << endl;
        }
    }
    virtual void print(){
        try{
            throw "undefined operation!" ;
        }
        catch(const char *msg){
            cerr << msg << endl;
        }
    }
};

class MenuItem : public MenuComponent{
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
    string getName()override{
        return name;
    }
    string getDescription()override{
        return description;
    }
    double getPrice()override{
        return price;
    }
    bool isVegetarian()override{
        return vegetarian;
    }
    void print()override{
        cout << getName() + "," << getPrice() << "----" + getDescription() << endl;
    }
};

bool operator==(MenuComponent a, MenuComponent b){
    if((a.getName() == b.getName())&&(a.getDescription() == b.getDescription()))
        return true;
    else
        return false;
}

class Menu : public MenuComponent{
    vector<shared_ptr<MenuComponent>> menuComponents;
    string name;
    string description;
public:
    Menu(string name, string description){
        this->name = name;
        this->description = description;
    }
    void add(shared_ptr<MenuComponent> menucomponent)override{
        menuComponents.push_back(menucomponent);
    }
    void comremove(shared_ptr<MenuComponent> menucomponent)override{
        auto iter = menuComponents.begin();
        while(iter != menuComponents.end()){
            if(**iter == *menucomponent)
                menuComponents.erase(iter);
            iter++;
        }
    }
    shared_ptr<MenuComponent> getChild(int i)override{
        return menuComponents[i];
    }
    string getName(){
        return name;
    }
    string getDescription(){
        return description;
    }
    void print()override{
        cout << endl;
        cout << getName() + "," + getDescription() << endl;
        cout << "------------------" << endl;

        auto iter = menuComponents.begin();
        while(iter != menuComponents.end()){
            (*iter)->print();
            iter++;
        }
    }
};

class Waitress{
    MenuComponent allMenus;
public:
    Waitress(shared_ptr<MenuComponent> menuComponent){
        this->allMenus = *menuComponent;
    }
    void printMenu(){
        allMenus.print();
    }
};

#endif // MAIN_H
