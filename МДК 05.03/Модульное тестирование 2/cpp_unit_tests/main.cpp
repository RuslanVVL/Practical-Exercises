#include "Calc.h"
#include <iostream>
#include <clocale>

int main() {
    int choice;
    double num1, num2;

    std::setlocale(LC_ALL, "Russian");

    while (true) {
        show_menu();
        std::cout << "Выберите операцию (1-11) или 0 для выхода: ";
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода. Программа завершена." << std::endl;
            break;
        }

        if (choice == 0) {
            std::cout << "Программа завершена." << std::endl;
            break;
        }

        switch (choice) {
            case 1:
                std::cout << "Введите два числа: ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << add(num1, num2) << std::endl;
                break;
            case 2:
                std::cout << "Введите два числа (уменьшаемое и вычитаемое): ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << subtract(num1, num2) << std::endl;
                break;
            case 3:
                std::cout << "Введите два числа: ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << multiply(num1, num2) << std::endl;
                break;
            case 4:
                std::cout << "Введите два числа (делимое и делитель): ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << divide(num1, num2) << std::endl;
                break;
            case 5:
                std::cout << "Введите основание и показатель степени: ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << power(num1, num2) << std::endl;
                break;
            case 6:
                std::cout << "Введите число: ";
                std::cin >> num1;
                std::cout << "Результат: " << square_root(num1) << std::endl;
                break;
            case 7: {
                int n;
                std::cout << "Введите целое неотрицательное число: ";
                std::cin >> n;
                std::cout << "Результат: " << factorial(n) << std::endl;
                break;
            }
            case 8:
                std::cout << "Введите число для сохранения в память: ";
                std::cin >> num1;
                memory_store(num1);
                break;
            case 9:
                std::cout << "Значение в памяти: " << memory_recall() << std::endl;
                break;
            case 10:
                std::cout << "Введите число для добавления к памяти: ";
                std::cin >> num1;
                memory_add(num1);
                break;
            case 11:
                memory_clear();
                break;
            default:
                std::cout << "Неверный ввод. Попробуйте еще раз." << std::endl;
        }
        std::cout << "--------------------------------" << std::endl;
    }

    return 0;
}
