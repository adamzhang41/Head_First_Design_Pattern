#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    Tea *myTea = new Tea();
    myTea->prepareRecipe();
    cout << endl;

    Coffee *myCoffee = new Coffee();
    myCoffee->prepareRecipe();
    cout << endl;

    return 0;
}
