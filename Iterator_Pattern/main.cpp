#include <iostream>
#include <vector>
#include "main.h"

using namespace std;

int main()
{
    shared_ptr<Menu> pancakeHouseMenu (new PancakeHouseMenu());
    shared_ptr<Menu> dinerMenu (new DinerMenu());
    Waitress waitress(pancakeHouseMenu, dinerMenu);

    waitress.printMenu();

    return 0;
}
