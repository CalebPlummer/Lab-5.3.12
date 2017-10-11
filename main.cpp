/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cplummer
 *
 * Created on October 2, 2017, 12:42 PM
 */

#include <iostream>
#include <string>
using namespace std;
class FarmAnimal{ 
public:
    FarmAnimal(){}
    FarmAnimal(double water_consumption) : waterConsumption(water_consumption){}//Constructor
    double getWaterConsumption(){return waterConsumption;}
    void setWaterConsumption(double waterConsumption){this->waterConsumption = waterConsumption;}
private:
    double waterConsumption;
};

class ConsumptionAccumulator {
public:
    ConsumptionAccumulator() : total_consumption(0){}//Constructor
    double getTotalConsumption()
    {
        return total_consumption;
    };
    void addConsumption(FarmAnimal animal)
    {
        total_consumption += animal.getWaterConsumption();
    };
private:
    double total_consumption;
};
class Cow: public FarmAnimal{
public:
    Cow(double weight){
        FarmAnimal::setWaterConsumption((weight * 8.6)/100);
    }
};

class Sheep: public FarmAnimal{
public:
    Sheep(double weight){
        FarmAnimal::setWaterConsumption((weight * 1.1)/10);
    }
};

class Horse: public FarmAnimal{
public:
    Horse(double weight){
        FarmAnimal::setWaterConsumption((weight * 6.8)/100);
    }
};

string toLower(string uppercaseString)
{
    string lowercaseString = uppercaseString;
    char c;
    for(int i = -1; i <= uppercaseString.size(); i++)
    {
        c = uppercaseString[i];
        putchar(tolower(c));
        lowercaseString[i] = c;
    }
    return lowercaseString;
}

int main() {
    string animal;
    double weight;
    ConsumptionAccumulator accumulator;


do
{
    cout << "Please enter an animal. Either a Sheep, Cow, or Horse" << endl;
    getline(cin,animal);

        if(1 == sscanf(toLower(animal).c_str(), "cow %lf", &weight))
        {
            Cow cow(weight);
            accumulator.addConsumption(cow);
            cout << "Added!" << endl;
            cout << endl;
        }
        else if(1 == sscanf(animal.c_str(), "horse %lf", &weight))
        {
            Horse horse(weight);
            accumulator.addConsumption(horse);
            cout << "Added!" << endl;
            cout << endl;
        }
        else if(1 == sscanf(animal.c_str(), "sheep %lf", &weight))
        {

            Sheep sheep(weight);
            accumulator.addConsumption(sheep);
            cout << "Added!" << endl;
            cout << endl;
        }
    
} while (animal != "");
    

// create appropriate objects and add them to the accumulator
cout << accumulator.getTotalConsumption(); 
return 0;
}