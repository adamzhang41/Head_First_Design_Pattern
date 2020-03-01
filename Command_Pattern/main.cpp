#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    SimpleRemoteControl remote;
    Light light;
    LightOnCommand * lightOn = new LightOnCommand(light);

    remote.setCommand(lightOn);
    remote.buttonWasPressed();
    cout << "Hello world!" << endl;
    return 0;
}
