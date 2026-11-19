#include "Calc.h"
#include <iostream>
#include <cmath>

// Переменная для хранения значения в памяти.
double memory = 0.0;

// Арифметические операции.
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return 0;
    }
    return a / b;
}

double power(double base, double exponent) {
    return std::pow(base, exponent);
}

double square_root(double a) {
    if (a < 0) {
        std::cout << "Ошибка: нельзя извлечь корень из отрицательного числа!" << std::endl;
        return 0;
    }
    return std::sqrt(a);
}

unsigned long long factorial(int n) {
    // 20! помещается в unsigned long long, а 21! уже вызывает переполнение.
    if (n < 0 || n > 20) {
        std::cout << "Ошибка: факториал можно вычислить для чисел от 0 до 20!" << std::endl;
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= static_cast<unsigned long long>(i);
    }
    return result;
}

// Операции с памятью.
void memory_store(double value) {
    memory = value;
    std::cout << "Число " << value << " успешно сохранено в память." << std::endl;
}

double memory_recall() {
    return memory;
}

void memory_add(double value) {
    memory += value;
    std::cout << "Число " << value << " добавлено к значению в памяти." << std::endl;
}

void memory_clear() {
    memory = 0.0;
    std::cout << "Память очищена." << std::endl;
}

void show_menu() {
    std::cout << "=== Меню Калькулятора ===" << std::endl;
    std::cout << "1. Сложение (+)" << std::endl;
    std::cout << "2. Вычитание (-)" << std::endl;
    std::cout << "3. Умножение (*)" << std::endl;
    std::cout << "4. Деление (/)" << std::endl;
    std::cout << "5. Возведение в степень" << std::endl;
    std::cout << "6. Извлечение квадратного корня" << std::endl;
    std::cout << "7. Факториал" << std::endl;
    std::cout << "8. Сохранить число в память (MS)" << std::endl;
    std::cout << "9. Прочитать значение из памяти (MR)" << std::endl;
    std::cout << "10. Добавить к числу в памяти (M+)" << std::endl;
    std::cout << "11. Очистить память (MC)" << std::endl;
    std::cout << "0. Выход" << std::endl;
}
