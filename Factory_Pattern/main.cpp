#include <iostream>
#include "main.h"
#include <memory>

using namespace std;

int main()
{
    SimplePizzaFactory factory;
    PizzaStore store(factory);

    string pizza_type = "cheese";
    shared_ptr<Pizza> pizza1(store.orderPizza(pizza_type));
    cout << pizza1->getName() << endl;

    cout << endl;

    pizza_type = "pepperoni";
    shared_ptr<Pizza> pizza2(store.orderPizza(pizza_type));
    cout << pizza2->getName() << endl;
    return 0;
}
