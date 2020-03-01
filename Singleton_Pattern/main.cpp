#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    Singleton *intance1 = Singleton::Instance();
    Singleton *intance2 = Singleton::Instance();
    cout << "Hello world!" << endl;
    return 0;
}
