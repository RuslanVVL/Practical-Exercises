#include <iostream>
#include <windows.h>

int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double num1, num2;
    char operation;

    std::cout << "Введите первое число: ";
    if (!(std::cin >> num1)) {
        std::cout << "Ошибка: введено не число!\n";
        return 1;
    }

    std::cout << "Введите оператор (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Введите второе число: ";
    if (!(std::cin >> num2)) {
        std::cout << "Ошибка: введено не число!\n";
        return 1;
    }

    switch (operation) {
        case '+':
            std::cout << "Результат: " << num1 + num2 << '\n';
            break;
        case '-':
            std::cout << "Результат: " << num1 - num2 << '\n';
            break;
        case '*':
            std::cout << "Результат: " << num1 * num2 << '\n';
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Ошибка: деление на ноль невозможно!\n";
            } else {
            std::cout << "Результат: " << num1 / num2 << '\n';
            }
            break;
        default:
            std::cout << "Ошибка: неверный оператор!\n";
            break;    
    }

    return 0;
}