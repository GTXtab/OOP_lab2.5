// Pair.cpp
#include "Pair.h"
#include <sstream>
#include <stdexcept>

// --- Реалізація конструкторів і операторів присвоєння ---
Pair::Pair() : first(0), second(0), size(MAX_SIZE), count(2) {}
Pair::Pair(int a, int b) : first(a), second(b), size(MAX_SIZE), count(2) {}
Pair::Pair(const Pair& other)
    : first(other.first), second(other.second),
    size(other.size), count(other.count) {}

Pair& Pair::operator=(const Pair& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
        size = other.size;
        count = other.count;
    }
    return *this;
}

// --- Методи доступу ---
int Pair::getFirst()    const { return first; }
int Pair::getSecond()   const { return second; }
void Pair::setFirst(int v) { first = v; }
void Pair::setSecond(int v) { second = v; }

bool Pair::Init(int a, int b) {
    first = a;
    second = b;
    return true;
}

// --- Індексація ---
int Pair::operator[](int index) const {
    if (index == 0)      return first;
    if (index == 1)      return second;
    throw std::out_of_range("Pair: індекс має бути 0 або 1");
}

// --- Приведення до рядка та вивід/читання ---
std::string Pair::toString() const {
    std::ostringstream oss;
    oss << "(" << first << ", " << second << ")";
    return oss.str();
}

Pair::operator std::string() const {
    return toString();
}

void Pair::Read() {
    std::cin >> first >> second;
}

void Pair::Display() const {
    std::cout << toString() << std::endl;
}

// ===== Дружні функції =====

Pair operator+(const Pair& lhs, const Pair& rhs) {
    return Pair(lhs.first + rhs.first,
        lhs.second + rhs.second);
}

Pair multiply(const Pair& p, int n) {
    return Pair(p.first * n,
        p.second * n);
}

Pair operator*(const Pair& p, int n) {
    return multiply(p, n);
}

Pair operator*(int n, const Pair& p) {
    return multiply(p, n);
}

Pair& operator++(Pair& p) {
    ++p.first;
    ++p.second;
    return p;
}

Pair operator++(Pair& p, int) {
    Pair tmp = p;
    ++p;
    return tmp;
}

Pair& operator--(Pair& p) {
    --p.first;
    --p.second;
    return p;
}

Pair operator--(Pair& p, int) {
    Pair tmp = p;
    --p;
    return tmp;
}

std::ostream& operator<<(std::ostream& out, const Pair& p) {
    return out << p.toString();
}

std::istream& operator>>(std::istream& in, Pair& p) {
    in >> p.first >> p.second;
    return in;
}
