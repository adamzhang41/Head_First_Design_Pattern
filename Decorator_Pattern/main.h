#include <string>
#include <memory>
#include <iostream>

using std::string;
using std::shared_ptr;
using std::cout;
using std::cin;
using std::endl;

class Beverage{
protected:
    string description = "Unknown Beverage";
public:
    virtual string getDescription(){
        return description;
    }
    virtual double cost() = 0;
};

/*
class CondimentDecorator: public Beverage{
public:
    virtual string getDescription() = 0;
};
*/

class Espresso: public Beverage{
public:
    Espresso(){
        description = "Espresso";
    }
    double cost(){
        return 1.99;
    }
};

class HouseBlend: public Beverage{
public:
    HouseBlend(){
        description = "House Blend Coffee";
    }
    double cost(){
        return 0.89;
    }
};

class Decorator: public Beverage{
protected:
    shared_ptr<Beverage> beverage;
};

class Mocha: public Decorator{
public:
    Mocha(shared_ptr<Beverage> beverage_input){
        this->beverage = beverage_input;
    }
    string getDescription(){
        return beverage->getDescription() + ", Mocha";
    }
    double cost(){
        return 0.20 + beverage->cost();
    }
};





