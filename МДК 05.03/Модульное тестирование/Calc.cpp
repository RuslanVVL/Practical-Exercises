#include <iostream>
#include <cmath>

// Переменная для хранения значения в памяти
double memory = 0.0;

// Прототипы функций
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double square_root(double a);
unsigned long long factorial(int n);

void memory_store(double value);
double memory_recall();
void memory_add(double value);
void memory_clear();

void show_menu();

int main() {
    int choice;
    double num1, num2;

    std::setlocale(LC_ALL, "Russian");

    while (true) {
        show_menu();
        std::cout << "Выберите операцию (1-13) или 0 для выхода: ";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Программа завершена." << std::endl;
            break;
        }

        switch (choice) {
            case 1: // Сложение
                std::cout << "Введите два числа: ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << add(num1, num2) << std::endl;
                break;
            case 2: // Вычитание
                std::cout << "Введите два числа (уменьшаемое и вычитаемое): ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << subtract(num1, num2) << std::endl;
                break;
            case 3: // Умножение
                std::cout << "Введите два числа: ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << multiply(num1, num2) << std::endl;
                break;
            case 4: // Деление
                std::cout << "Введите два числа (делимое и делитель): ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << divide(num1, num2) << std::endl;
                break;
            case 5: // Возведение в степень
                std::cout << "Введите основание и показатель степени: ";
                std::cin >> num1 >> num2;
                std::cout << "Результат: " << power(num1, num2) << std::endl;
                break;
            case 6: // Извлечение квадратного корня
                std::cout << "Введите число: ";
                std::cin >> num1;
                std::cout << "Результат: " << square_root(num1) << std::endl;
                break;
            case 7: // Факториал
                int n;
                std::cout << "Введите целое неотрицательное число: ";
                std::cin >> n;
                std::cout << "Результат: " << factorial(n) << std::endl;
                break;
            case 8: // Сохранение в память
                std::cout << "Введите число для сохранения в память: ";
                std::cin >> num1;
                memory_store(num1);
                break;
            case 9: // Чтение из памяти
                std::cout << "Значение в памяти: " << memory_recall() << std::endl;
                break;
            case 10: // Добавление к числу в памяти
                std::cout << "Введите число для добавления к памяти: ";
                std::cin >> num1;
                memory_add(num1);
                break;
            case 11: // Очистка памяти
                memory_clear();
                break;
            default:
                std::cout << "Неверный ввод. Попробуйте еще раз." << std::endl;
        }
        std::cout << "--------------------------------" << std::endl;
    }

    return 0;
}

// Реализация функций для арифметических операций
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
        std::cout << "Ошибка: деление на ноль! " << std::endl;
        return 0;
    }
    return a / b;
}

double power(double base, double exponent) {
    return std::pow(base, exponent);
}

double square_root(double a) {
    if (a < 0) {
        std::cout << "Ошибка: нельзя извлечь корень из отрицательного числа! " << std::endl;
        return 0;
    }
    return std::sqrt(a);
}

unsigned long long factorial(int n) {
    if (n < 0) {
        std::cout << "Ошибка: факториал определен только для неотрицательных чисел! " << std::endl;
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Реализация функций для работы с памятью
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

// Отображение меню
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
    std::cout << "9. Вычесть/Прочитать из памяти (MR)" << std::endl;
    std::cout << "10. Добавить к числу в памяти (M+)" << std::endl;
    std::cout << "11. Очистить память (MC)" << std::endl;
    std::cout << "0. Выход" << std::endl;
}