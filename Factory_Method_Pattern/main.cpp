#include <iostream>
#include "main.h"
#include <memory>

using namespace std;

int main()
{
    NYPizzaStore store;
    string pizza_type = "cheese";
    shared_ptr<Pizza> pizza(store.orderPizza(pizza_type));
    cout << pizza->getName() << endl;

    cout << endl;

    ChicagoPizzaStore store1;
    pizza_type = "cheese";
    shared_ptr<Pizza> pizza1(store1.orderPizza(pizza_type));
    cout << pizza1->getName() << endl;

    return 0;
}
