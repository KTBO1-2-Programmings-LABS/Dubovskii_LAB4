#include "pch.h"
#include "Header.h"


/*int main(array<System::String^>^ args)
{
    return 0;
}*/

int main() {
    setlocale(LC_ALL, "Russian");
    Restaurant restaurant; // ������� ������ ���������
    // ����
    cout << "Menu" << endl << endl << "Borsch - 300 ���" << endl << "Salad - 150 ���" << endl << "Pork shish kebab - 350 ���" << endl;
    cout << "Lamb shish kebab - 350 ���" << endl << "French fries - 150 ���" << endl << "Lemonade - 100 ���" << endl << "Wine - 250 ���" << endl << "Dessert - 250 ���" << endl << endl;

    restaurant.addDish("Borsch", 300.0);
    restaurant.addDish("Salad", 150.0);
    restaurant.addDish("Pork shish kebab", 350.0);
    restaurant.addDish("Lamb shish kebab", 350.0);
    restaurant.addDish("French fries", 150.0);
    restaurant.addDish("Lemonade", 100.0);
    restaurant.addDish("Wine", 250.0);
    restaurant.addDish("Dessert", 250.0);

    // ����������� ��������� �����
    const int max_selected_dishes = 8; // ������������ ���������� ��������� ����
    string selected_dishes[max_selected_dishes];
    int num_dishes = 0;

    cout << "������� �����, ������� �� ������ �������� (������ ������ ��� ����������):" << endl;
    string dish;
    while (getline(cin, dish) && !dish.empty()) {
        selected_dishes[num_dishes] = dish;
        num_dishes++;
    }

    double total_cost = restaurant.calculateTotalCost(selected_dishes, num_dishes);
    cout << "����� ��������� ������: " << total_cost << " ������" << endl;

    // ���� ����� ���� �� ��������� �����
    double budget;
    cout << "������� �����, �� ������� ������ ����� �����: ";
    cin >> budget;

    restaurant.findDishesForPrice(budget);

    return 0;
}