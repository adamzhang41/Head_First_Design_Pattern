#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Duck{
public:
    virtual void quack(){
        cout << "Quack" << endl;
    }
    virtual void fly(){
        cout << "I'm flying" << endl;
    }
};

class Turkey{
public:
    virtual void gobble(){
        cout << "gobble gobble" << endl;
    }
    virtual void fly(){
        cout << "I'm flying a short distance" << endl;
    }
};

class TurkeyAdapter : public Duck, public Turkey{
public:
    void quack(){
        gobble();
    }
    void fly(){
        for(unsigned int i =0; i < 5; i++)
            Turkey::fly();
    }
};

