#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Singleton{
public:
    static Singleton *Instance(){
        static Singleton instance;
        return &instance;
    }

private:
    Singleton(){
        cout << "only instance once" << endl;
    };
};
