#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    MallardDuck duck;
    WildTurkey* turkey = new WildTurkey();
    Duck* turkeyAdapter = new TurkeyAdapter(turkey);
    turkeyAdapter->fly();
    turkeyAdapter->quack();
    return 0;
}
