#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    Duck *duck = new Duck();
    Turkey *turkey = new Turkey();
    TurkeyAdapter *turkeyadapter = new TurkeyAdapter();

    cout << "duck:" << endl;
    duck->fly();
    duck->quack();

    cout << "turkey:" << endl;
    turkey->fly();
    turkey->gobble();

    cout << "turkeyadapter:" << endl;
    turkeyadapter->fly();
    turkeyadapter->quack();

    turkeyadapter->Duck::quack();
    turkeyadapter->Duck::fly();

    return 0;
}
