#include<iostream>
#include<memory>

using std::cout;
using std::endl;
using std::shared_ptr;

class FlyBehavior{
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior{
public:
    void fly(){
        cout << "I'm flying!!" << endl;
    }
};

class FlyNoWay : public FlyBehavior{
public:
    void fly(){
        cout << "I can't fly" << endl;
    }
};

class QuackBehavior{
public:
    virtual void quack() = 0;
};

class MuteQuack : public QuackBehavior{
public:
    void quack(){
        cout << "Silence" << endl;
    }
};

class Quack : public QuackBehavior{
public:
    void quack(){
        cout << "Quack" << endl;
    }
};

class Squeak : public QuackBehavior{
public:
    void quack(){
        cout << "Squeak" << endl;
    }
};

class Duck{
protected:
    shared_ptr<FlyBehavior> m_flyBehavior;
    shared_ptr<QuackBehavior> m_quackBehavior;
public:
    Duck(){
    }
    void setFlyBehavior(shared_ptr<FlyBehavior> flyBehavior)
    {
        m_flyBehavior = flyBehavior;
    }
    void setQuackBehavior(shared_ptr<QuackBehavior> quackBehavior)
    {
        m_quackBehavior = quackBehavior;
    }
    virtual void display() = 0;
    void performFly(){
        m_flyBehavior->fly();
    }
    void performQuack(){
        m_quackBehavior->quack();
    }
    void swim(){
        cout << "All ducks float, even decoys!" << endl;
    }
};

class MallardDuck : public Duck{
public :
    MallardDuck(){
        shared_ptr<FlyWithWings> flyB(new FlyWithWings());
        setFlyBehavior(flyB);
        shared_ptr<QuackBehavior> quackB(new Squeak());
        setQuackBehavior(quackB);
    }
    void display(){
        cout << "I'm a real Mallard duck" << endl;
    }
};
