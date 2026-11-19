#include "Calc.h"
#include <cmath>
#include <iostream>
#include <string>

// Простой тестовый механизм на стандартном C++ без сторонних библиотек.
namespace {
int checks = 0;
int failedChecks = 0;
int testCases = 0;
int failedTests = 0;

void expectNear(double actual, double expected, double tolerance,
                const std::string& expression) {
    ++checks;
    if (!std::isfinite(actual) || std::fabs(actual - expected) > tolerance) {
        ++failedChecks;
        std::cout << "    ОШИБКА: " << expression
                  << ", ожидалось " << expected << ", получено " << actual << '\n';
    }
}

void expectEqual(unsigned long long actual, unsigned long long expected,
                 const std::string& expression) {
    ++checks;
    if (actual != expected) {
        ++failedChecks;
        std::cout << "    ОШИБКА: " << expression
                  << ", ожидалось " << expected << ", получено " << actual << '\n';
    }
}

#define EXPECT_NEAR(actual, expected) \
    expectNear((actual), (expected), 1e-9, #actual " == " #expected)
#define EXPECT_EQUAL(actual, expected) \
    expectEqual((actual), (expected), #actual " == " #expected)

void runTest(const std::string& name, void (*testFunction)()) {
    ++testCases;
    const int failuresBefore = failedChecks;
    std::cout << "Тест: " << name << '\n';
    testFunction();
    if (failedChecks == failuresBefore) {
        std::cout << "    ПРОЙДЕН\n";
    } else {
        ++failedTests;
        std::cout << "    НЕ ПРОЙДЕН\n";
    }
}

void testAddition() { EXPECT_NEAR(add(2.5, 3.5), 6.0); }
void testSubtraction() { EXPECT_NEAR(subtract(10.0, 4.0), 6.0); }
void testMultiplication() { EXPECT_NEAR(multiply(-3.0, 4.0), -12.0); }
void testDivision() { EXPECT_NEAR(divide(15.0, 3.0), 5.0); }
void testDivisionByZero() { EXPECT_NEAR(divide(7.0, 0.0), 0.0); }
void testPower() { EXPECT_NEAR(power(2.0, 3.0), 8.0); }
void testSquareRoot() { EXPECT_NEAR(square_root(81.0), 9.0); }
void testSquareRootOfZero() { EXPECT_NEAR(square_root(0.0), 0.0); }
void testNegativeSquareRoot() { EXPECT_NEAR(square_root(-9.0), 0.0); }
void testFactorialZero() { EXPECT_EQUAL(factorial(0), 1ULL); }
void testFactorialPositive() { EXPECT_EQUAL(factorial(5), 120ULL); }
void testFactorialMaximum() { EXPECT_EQUAL(factorial(20), 2432902008176640000ULL); }
void testFactorialOverflowBoundary() { EXPECT_EQUAL(factorial(21), 0ULL); }
void testNegativeFactorial() { EXPECT_EQUAL(factorial(-3), 0ULL); }

void testMemoryStoreAndRecall() {
    memory_store(12.5);
    EXPECT_NEAR(memory_recall(), 12.5);
}

void testMemoryAdd() {
    memory_clear();
    memory_store(10.0);
    memory_add(2.5);
    EXPECT_NEAR(memory_recall(), 12.5);
}

void testMemoryClear() {
    memory_store(99.0);
    memory_clear();
    EXPECT_NEAR(memory_recall(), 0.0);
}
} // namespace

int main() {
    std::cout << "=== Модульные тесты калькулятора ===\n";
    runTest("Сложение", testAddition);
    runTest("Вычитание", testSubtraction);
    runTest("Умножение", testMultiplication);
    runTest("Деление", testDivision);
    runTest("Деление на ноль", testDivisionByZero);
    runTest("Возведение в степень", testPower);
    runTest("Извлечение квадратного корня", testSquareRoot);
    runTest("Корень из нуля", testSquareRootOfZero);
    runTest("Корень из отрицательного числа", testNegativeSquareRoot);
    runTest("Факториал нуля", testFactorialZero);
    runTest("Факториал положительного числа", testFactorialPositive);
    runTest("Максимальный факториал без переполнения", testFactorialMaximum);
    runTest("Защита от переполнения факториала", testFactorialOverflowBoundary);
    runTest("Факториал отрицательного числа", testNegativeFactorial);
    runTest("Сохранение и чтение памяти", testMemoryStoreAndRecall);
    runTest("Добавление к памяти", testMemoryAdd);
    runTest("Очистка памяти", testMemoryClear);

    std::cout << "\nИТОГ: " << (testCases - failedTests) << " из "
              << testCases << " тестов пройдено. Проверок: " << checks
              << ", ошибок: " << failedChecks << ".\n";
    return failedTests == 0 ? 0 : 1;
}
