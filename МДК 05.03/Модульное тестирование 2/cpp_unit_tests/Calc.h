#ifndef CALC_H
#define CALC_H

// Глобальная переменная памяти калькулятора.
extern double memory;

// Арифметические операции.
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double square_root(double a);
unsigned long long factorial(int n);

// Операции с памятью.
void memory_store(double value);
double memory_recall();
void memory_add(double value);
void memory_clear();

// Отображение меню.
void show_menu();

#endif
