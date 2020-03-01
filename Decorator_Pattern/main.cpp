#include <iostream>
#include <memory>
#include "main.h"

using namespace std;

int main()
{
    shared_ptr<Beverage> beverage (new Espresso());
    cout << beverage->getDescription() << "$" << beverage->cost() << endl;
    shared_ptr<Beverage> beverage2 (new HouseBlend());
    shared_ptr<Beverage> beverage3 (new Mocha(beverage2));
    shared_ptr<Beverage> beverage4 (new Mocha(beverage3));
    cout << beverage4->getDescription() << "$" << beverage4->cost() << endl;
    cout << "Hello world!" << endl;











    return 0;
}
