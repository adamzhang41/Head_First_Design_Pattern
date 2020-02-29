#include <iostream>
#include <memory>
#include "main.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    shared_ptr<Duck> mallard(new MallardDuck());
    mallard->performQuack();
    mallard->performFly();
    mallard->swim();
    mallard->display();
    return 0;
}
