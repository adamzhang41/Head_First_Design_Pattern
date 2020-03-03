#include <iostream>
#include "main.h"

using namespace std;

GumballMachine::GumballMachine(int numberGumballs){
    soldOutState = make_shared<SoldOutState>(this);
    noQuarterState = make_shared<NoQuarterState>(this);
    hasQuarterState = make_shared<HasQuarterState>(this);
    soldState = make_shared<SoldState>(this);
    this->count = numberGumballs;
    if(numberGumballs > 0){
        state = noQuarterState;
    }
}

int main()
{
    GumballMachine gumballMachine(5);
    cout << gumballMachine.getCount() << endl;
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    cout << gumballMachine.getCount() << endl;

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    cout << gumballMachine.getCount() << endl;

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    cout << gumballMachine.getCount() << endl;

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    cout << gumballMachine.getCount() << endl;

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    cout << gumballMachine.getCount() << endl;

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    cout << gumballMachine.getCount() << endl;

    return 0;
}
