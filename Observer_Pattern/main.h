#include <list>
#include <iostream>
#include<memory>

using std::list;
using std::shared_ptr;
using std::cout;
using std::cin;
using std::endl;

class Observer{
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
    virtual ~Observer() = default;
};

class Subject{
public:
    virtual void registerObserver(shared_ptr<Observer> o) = 0;
    virtual void removeObserver(shared_ptr<Observer> o) = 0;
    virtual void notifyObserver() = 0;
    virtual ~Subject() = default;
};

class DisplayElement{
public:
    virtual void display() = 0;
    virtual ~DisplayElement() = default;
};

class WeatherData : public Subject{
private:
    list<shared_ptr<Observer>> observers;
    float temperature;
    float humidity;
    float pressure;
public:
    void registerObserver(shared_ptr<Observer> o){
        observers.push_back(o);
    }
    void removeObserver(shared_ptr<Observer> o){
        for(auto temp = observers.begin(); temp != observers.end(); temp++)
        {
            if((*temp) == o)
            {
                observers.erase(temp);
                break;
            }
        }
    }
    void notifyObserver(){
        for(auto temp = observers.begin(); temp != observers.end(); temp++)
        {
            (*temp)->update(temperature, humidity, pressure);
        }
    }
    void measurementsChanged(){
        notifyObserver();
    }
    void setMeasurements(float temperature, float humidity, float pressure){
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }
};

class CurrentConditionsDisplay : public Observer, public DisplayElement{
private:
    float temperature;
    float humidity;
//    shared_ptr<Subject> weatherData;
public:
//    CurrentConditionsDisplay(shared_ptr<Subject> weatherData_input){
//        this->weatherData = weatherData_input;
//        weatherData->registerObserver(this);
//    }
    void update(float temperature, float humidity, float pressure){
        this->temperature = temperature;
        this->humidity = humidity;
        display();
    }
    void display(){
        cout << "Current conditions: " << temperature << "F degrees and" << humidity << "% humidity" << endl;
    }
};

class FutureConditionsDisplay : public Observer, public DisplayElement{
private:
    float temperature;
    float humidity;
public:
    void update(float temperature, float humidity, float pressure){
        this->temperature = temperature + 10;
        this->humidity = humidity + 10;
        display();
    }
    void display(){
        cout << "Future conditions: " << temperature << "F degrees and" << humidity << "% humidity" << endl;
    }
};
