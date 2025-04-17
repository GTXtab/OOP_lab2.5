#include <iostream>
#include <windows.h>
#include "Pair.h"
#include "Money.h"

#pragma pack(push, 1)
class PackedMoney {
    Pair pair;
};
#pragma pack(pop)

int main() {
    // Налаштування кодування консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "=== Демонстрація Pair та Money ===\n\n";

    // === Pair ===
    Pair p1(5, 10), p2;
    std::cout << "Введіть пару p2 (два цілі числа): ";
    std::cin >> p2;

    Pair p3 = p1 + p2;        // оператор+
    Pair p4 = p2 * 3;         // оператор* (friend)

    std::cout << "Pair p1: " << p1
        << ", p2: " << p2 << "\n";
    std::cout << "p3 = p1 + p2: " << p3 << "\n";
    std::cout << "p4 = p2 * 3: " << p4 << "\n";

    ++p1;  // префіксний інкремент (friend)
    std::cout << "Після ++p1: " << p1 << "\n\n";

    // === Money ===
    Money m1(10, 50), m2;
    std::cout << "Введіть суму m2 (грн та коп.): ";
    std::cin >> m2;

    Money m3 = m1 + m2;             // оператор+ (friend)
    Money m4 = sub(m1, m2);         // субтракція (friend free function)
    double r = div(m1, m2);         // ділення (friend free function)

    std::cout << "Money m1: " << m1
        << ", m2: " << m2 << "\n";
    std::cout << "m3 = m1 + m2: " << m3 << "\n";
    std::cout << "m4 = m1 - m2: " << m4 << "\n";
    if (r < 0)
        std::cout << "m1 / m2 = ділення на 0\n";
    else
        std::cout << "m1 / m2 = " << r << "\n";

    // Пакована структура для демонстрації #pragma pack(1)
    std::cout << "\nsizeof(Pair): " << sizeof(Pair) << "\n";
    std::cout << "sizeof(PackedMoney) з #pragma pack(1): "
        << sizeof(PackedMoney) << "\n";

    return 0;
}
