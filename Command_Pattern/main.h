#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Light{
public:
    void on(){
        cout << "light is on" << endl;
    }
    void off(){
        cout << "light is off" << endl;
    }
};

class Command{
public:
    virtual void execute() = 0;
};

class LightOnCommand : public Command{
private:
    Light light;
public:
    LightOnCommand(Light light){
        this->light = light;
    }
    void execute(){
        light.on();
    }
};

class SimpleRemoteControl{
    Command * slot;
public:
    SimpleRemoteControl()
    {
        ;
    }
    void setCommand(Command * command)
    {
        slot = command;
    }
    void buttonWasPressed(){
        slot->execute();
    }
};
