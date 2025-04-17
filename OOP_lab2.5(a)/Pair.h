// Pair.h
#pragma once
#include <string>
#include <iostream>

class Pair {
private:
    int first;
    int second;
    static const int MAX_SIZE = 2;

public:
    int size;
    int count;

    // Конструктори
    Pair();
    Pair(int a, int b);
    Pair(const Pair& other);

    // Присвоєння
    Pair& operator=(const Pair& other);

    // Доступ
    int getFirst() const;
    int getSecond() const;
    void setFirst(int value);
    void setSecond(int value);
    bool Init(int a, int b);

    // Індексація
    int operator[](int index) const;

    // Приведення до рядка
    std::string toString() const;
    explicit operator std::string() const;

    // Ввід/вивід
    void Read();
    void Display() const;

    // Дружні функції
    friend Pair operator+(const Pair& lhs, const Pair& rhs);
    friend Pair multiply(const Pair& p, int n);
    friend Pair operator*(const Pair& p, int n);
    friend Pair operator*(int n, const Pair& p);

    friend Pair& operator++(Pair& p);      // префіксний ++p
    friend Pair operator++(Pair& p, int);  // постфіксний p++
    friend Pair& operator--(Pair& p);      // префіксний --p
    friend Pair operator--(Pair& p, int);  // постфіксний p--

    friend std::ostream& operator<<(std::ostream& out, const Pair& p);
    friend std::istream& operator>>(std::istream& in, Pair& p);
};
