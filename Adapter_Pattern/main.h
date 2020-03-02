#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Duck{
public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class MallardDuck : public Duck{
public:
    void quack(){
        cout << "Quack" << endl;
    }
    void fly(){
        cout << "I'm flying" << endl;
    }
};

class Turkey{
public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey : public Turkey{
public:
    void gobble(){
        cout << "gobble gobble" << endl;
    }
    void fly(){
        cout << "I'm flying a short distance" << endl;
    }
};

class TurkeyAdapter : public Duck{
private:
    Turkey* turkey;
public:
    TurkeyAdapter(Turkey* turkey){
        this->turkey = turkey;
    }
    void quack(){
        turkey->gobble();
    }
    void fly(){
        for(unsigned int i =0; i < 5; i++)
            turkey->fly();
    }
};
