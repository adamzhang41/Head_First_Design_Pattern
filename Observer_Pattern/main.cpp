#include <iostream>
#include <memory>
#include "main.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    shared_ptr<WeatherData> weatherData(new WeatherData());
    shared_ptr<CurrentConditionsDisplay> currentDisplay (new CurrentConditionsDisplay());
    shared_ptr<FutureConditionsDisplay> futureConditionsDisplay (new FutureConditionsDisplay());

    weatherData->registerObserver(currentDisplay);
    weatherData->registerObserver(futureConditionsDisplay);

    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(10, 10, 30.4f);

    weatherData->removeObserver(futureConditionsDisplay);
    cout << endl;
    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(10, 10, 30.4f);

    return 0;
}
