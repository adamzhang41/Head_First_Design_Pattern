#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class CaffeineBeverage{
public:
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    void boilWater(){
        cout << "Boiling water" << endl;
    }
    void pourInCup(){
        cout << "Pouring into cup" << endl;
    }
    void prepareRecipe() {
    boilWater();
    brew();
    pourInCup();
    addCondiments();
    }
};

class Coffee : public CaffeineBeverage{
public:
    void brew() override {
        cout << "Dripping Coffee through filter" << endl;
    }
    void addCondiments() override {
        cout << "Adding Sugar and Milk" << endl;
    }
};

class Tea : public CaffeineBeverage{
public:
    void brew() override {
        cout << "Steeping the tea" << endl;
    }
    void addCondiments() override {
        cout << "Adding Lemon" << endl;
    }
};
