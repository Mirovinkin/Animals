// Animals.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <vector>

using namespace std;

class Animal
{
public:
    virtual void FoodAmountADayCounter() abstract;
    virtual string GetName() abstract;
    virtual void SetName(const string& Name) abstract;
    virtual void SetWeight(const double& Weight) abstract;
    virtual double GetFoodAmount() abstract;
    
    virtual ~Animal() {};
};

class Predators : public Animal
{
private:
    string _name;
    double _weight;
    string _foodType = "мясо";
    double _foodAmount;


public:
    Predators() {};

    void SetName(const string& Name) override{
        _name = Name;
    }
    void SetWeight(const double& Weight) override{
        _weight = Weight;
    }

    string GetName () override {
        return _name;
    }

    double GetFoodAmount() override {
        return _foodAmount;
    }

    void FoodAmountADayCounter() override
    {
        if (_name == "lion") {
            if (_weight <= 190) {
                _foodAmount = 15;
                
            }
            else {
                _foodAmount = 20;
            }
        }
        else if (_name == "тигр") {
            if (_weight <= 145) {
                _foodAmount = 10;

            }
            else {
                _foodAmount = 15;
            }
        }
        else {
            cout << "Такого животного нет в списке";
        }
    }
};

class Omnivores : public Animal
{
private:
    string _name;
    double _weight;
    string foodType = "Они всеядные, можно давать все";
    double _foodAmount;

public:
    Omnivores() {};
;

    void SetName(const string& Name) {
        _name = Name;
    }
    void SetWeight(const double& Weight) {
        _weight = Weight;
    }

    string GetName() override {
        return _name;
    }

    double GetFoodAmount() override{
        return _foodAmount;
    }

    void FoodAmountADayCounter() override
    {
        if (_name == "свинья") {
            if (_weight <= 150) {
                _foodAmount = 2.1;

            }
            else {
                _foodAmount = 3;
            }
        }
        else if (_name == "шимпанзе") {
            if (_weight <= 61) {
                _foodAmount = 2;

            }
            else {
                _foodAmount = 4;
            }
        }
        else {
            cout << "Такого животного нет в списке";
        }
    }
};

class Herbivores : public Animal
{
private:
    string _name;
    double _weight;
    string foodType = "трава";
    double _foodAmount;

public:
    Herbivores() {};
    Herbivores(const string& Name, const double& Weight) :
        _name(Name),
        _weight(Weight) {};

    void SetName(const string& Name) {
        _name = Name;
    }
    void SetWeight(const double& Weight) {
        _weight = Weight;
    }

    string GetName() override {
        return _name;
    }

    double GetFoodAmount() override{
        return _foodAmount;
    }

    void FoodAmountADayCounter() override
    {
        if (_name == "заяц") {
            if (_weight <= 6) {
                _foodAmount = 0.5;

            }
            else {
                _foodAmount = 1;
            }
        }
        else if (_name == "корова") {
            if (_weight <= 720) {
                _foodAmount = 50;

            }
            else {
                _foodAmount = 60;
            }
        }
        else {
            cout << "Такого животного нет в списке";
        }
    }
};
int main()
{

    vector<Animal*> animals;
    
    Animal* pred = new Predators;
    pred->SetName("lion");
    pred->SetWeight(190);
    animals.push_back(pred);

    int count = 0;
    for (auto item : animals) {//Вывод первых 5 животных
       
        if (count == 5) {
            break;
        }
        cout << item->GetName()<<endl;
        item->FoodAmountADayCounter();
        cout << item->GetFoodAmount();
        count++;
    }

    for (int i = animals.size(); i < animals.size() - 4; i++)//Вывод последних 5 животных
    {
        cout << animals[i]->GetName() << endl;
        animals[i]->FoodAmountADayCounter();
        cout << animals[i]->GetFoodAmount();
    }

    for (auto item : animals) {//Вывод всех животных
        cout << item->GetName() << endl;
        item->FoodAmountADayCounter();
        cout << item->GetFoodAmount();
    }
}