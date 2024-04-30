#include "pch.h"
#include "Header.h"


/*int main(array<System::String^>^ args)
{
    return 0;
}*/

int main() {
    setlocale(LC_ALL, "Russian");
    Restaurant restaurant; // Создаем объект ресторана
    // Меню
    cout << "Menu" << endl << endl << "Borsch - 300 руб" << endl << "Salad - 150 руб" << endl << "Pork shish kebab - 350 руб" << endl;
    cout << "Lamb shish kebab - 350 руб" << endl << "French fries - 150 руб" << endl << "Lemonade - 100 руб" << endl << "Wine - 250 руб" << endl << "Dessert - 250 руб" << endl << endl;

    restaurant.addDish("Borsch", 300.0);
    restaurant.addDish("Salad", 150.0);
    restaurant.addDish("Pork shish kebab", 350.0);
    restaurant.addDish("Lamb shish kebab", 350.0);
    restaurant.addDish("French fries", 150.0);
    restaurant.addDish("Lemonade", 100.0);
    restaurant.addDish("Wine", 250.0);
    restaurant.addDish("Dessert", 250.0);

    // Заказываете выбранные блюда
    const int max_selected_dishes = 8; // Максимальное количество выбранных блюд
    string selected_dishes[max_selected_dishes];
    int num_dishes = 0;

    cout << "Введите блюда, которые вы хотите заказать (пустая строка для завершения):" << endl;
    string dish;
    while (getline(cin, dish) && !dish.empty()) {
        selected_dishes[num_dishes] = dish;
        num_dishes++;
    }

    double total_cost = restaurant.calculateTotalCost(selected_dishes, num_dishes);
    cout << "Общая стоимость заказа: " << total_cost << " рублей" << endl;

    // Ищем набор блюд на указанную сумму
    double budget;
    cout << "Введите сумму, на которую хотите найти блюда: ";
    cin >> budget;

    restaurant.findDishesForPrice(budget);

    return 0;
}