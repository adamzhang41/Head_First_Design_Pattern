#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::make_shared;

class State{
public:
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
};

class GumballMachine{
    shared_ptr<State> soldOutState;
    shared_ptr<State> noQuarterState;
    shared_ptr<State> hasQuarterState;
    shared_ptr<State> soldState;

    shared_ptr<State> state = soldOutState;
    int count = 0;
public:
    GumballMachine(int numberGumballs);
    void ejectQuarter(){
        state->ejectQuarter();
    }
    void turnCrank(){
        state->turnCrank();
        state->dispense();
    }
    void insertQuarter(){
        state->insertQuarter();
    }
    void setState(shared_ptr<State> state){
        this->state = state;
    }
    shared_ptr<State> getHasQuarterState(){
        return hasQuarterState;
    }
    shared_ptr<State> getNoQuarterState(){
        return noQuarterState;
    }
    shared_ptr<State> getSoldOutState(){
        return soldOutState;
    }
    shared_ptr<State> getSoldState(){
        return soldState;
    }
    void releaseBall(){
        cout << "A gumball comes rolling out the slot..." << endl;
        if(count != 0){
            count -= 1;
        }
    }
    int getCount(){
        return count;
    }
};

class NoQuarterState : public State{
    GumballMachine* gumballMachine;
public:
    NoQuarterState(GumballMachine* gumballMachine){
        this->gumballMachine = gumballMachine;
    }
    void insertQuarter(){
        cout << "You inserted a quarter" << endl;
        gumballMachine->setState(gumballMachine->getHasQuarterState());
    }
    void ejectQuarter(){
        cout << "You haven't inserted a quarter" << endl;
    }
    void turnCrank(){
        cout << "you turned, but there is no quarter" << endl;
    }
    void dispense(){
        cout << "you need to pay first" << endl;
    }
};

class HasQuarterState : public State{
    GumballMachine* gumballMachine;
public:
    HasQuarterState(GumballMachine* gumballMachine){
        this->gumballMachine = gumballMachine;
    }
    void insertQuarter(){
        cout << "you can't insert another quarter" << endl;
    }
    void ejectQuarter(){
        cout << "quarter returned" << endl;
        gumballMachine->setState(gumballMachine->getNoQuarterState());
    }
    void turnCrank(){
        cout << "you turned ..." << endl;
        gumballMachine->setState(gumballMachine->getSoldState());
    }
    void dispense(){
        cout << "no gumball dispense" << endl;
    }
};

class SoldState : public State{
    GumballMachine* gumballMachine;
public:
    SoldState(GumballMachine* gumballMachine){
        this->gumballMachine = gumballMachine;
    }
    void insertQuarter(){
        cout << "Please wait, we're already giving you a gumball" << endl;
    }
    void ejectQuarter(){
        cout << "Sorry, you already turned the crank" << endl;
    }
    void turnCrank(){
        cout << "turning twice doesn't give you another gumball" << endl;
    }
    void dispense(){
        gumballMachine->releaseBall();
        if(gumballMachine->getCount() > 0){
            gumballMachine->setState(gumballMachine->getNoQuarterState());
        }else{
            cout << "Oops, out of gumballs" << endl;
            gumballMachine->setState(gumballMachine->getSoldOutState());
        }
    }
};

class SoldOutState : public State{
    GumballMachine* gumballMachine;
public:
    SoldOutState(GumballMachine* gumballMachine){
        this->gumballMachine = gumballMachine;
    }
    void insertQuarter(){
        cout << "You can't insert a quarter, the machine is sold out" << endl;
    }
    void ejectQuarter(){
        cout << "you can't eject a quarter, you haven't inserted a quarter yet" << endl;
    }
    void turnCrank(){
        cout << "you turn crank, there is no gumball" << endl;
    }
    void dispense(){
        cout << "No gumball dispense" << endl;
    }
};

#endif
