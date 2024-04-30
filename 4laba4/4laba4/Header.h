#pragma once
#include <iostream>
#include <string>
#include <map> // Контейнер переменного размера

using namespace System;
using namespace std;

class spehalDish {
private:
    string name;
    string ingridient;

public:

      string Display() {
        return ingridient;
    }
};

class Dish {
public:
    string name;
    double price;

    Dish(const string& n, double p) : name(n), price(p) {}
};

class Restaurant {
private:
    map<string, Dish> menu;

public:
    void addDish(const string& name, double price) { // добавление блюда в меню
        menu.insert({ name, Dish(name, price) });
    }

    double calculateTotalCost(const string* selected_dishes, int num_dishes) { // ввод блюд и их кол-во
        double total_cost = 0.0;

        for (int i = 0; i < num_dishes; i++) {
            double cost = findPrice(selected_dishes[i]);
            total_cost += cost;

            cout << "Цена для " << selected_dishes[i] << ": " << cost << " рублей" << endl;
        }

        return total_cost;
    }

    void findDishesForPrice(double budget) { // Найти блюда за цену
        cout << "Блюда, которые можно взять на " << budget << " рублей:" << endl;

        for (const auto& item : menu) {
            if (item.second.price <= budget) {
                cout << item.second.name << " :" << " " << item.second.price << endl;
            }
        }
    }

private:
    double findPrice(const string& dish) { // поиск цены блюда в меню
        auto it = menu.find(dish);
        if (it != menu.end()) {
            return it->second.price;
        }

        return 0.0; // Возвращаем 0, если блюдо не найдено
    }
};