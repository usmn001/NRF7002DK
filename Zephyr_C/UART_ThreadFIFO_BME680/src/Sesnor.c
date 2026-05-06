/*#include "Sensor.hpp"
#include<iostream>
using std::cout; 


Sensor::Sensor(int sens_init_val): sensorValue(sens_init_val)
{
cout<<"Default Constructor called. Sensor Value initialized to "<<sensorValue<<"\n";
}

Sensor::~Sensor()
{
cout<<"Destructor called. Sensor Object destroyed\n";
}


int Sensor::readValue()
{
    // Simulating reading a sensor value
    sensorValue = rand() % 100; // Random value between 0 and 99
    cout<<"Sensor Value read: "<<sensorValue<<"\n";
    return sensorValue;
}
*/