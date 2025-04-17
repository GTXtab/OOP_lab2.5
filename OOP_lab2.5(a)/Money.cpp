#include "Money.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>

Money::Money() : size(MAX_SIZE), count(1) {
    Init(0, 0);
}

Money::Money(int grn, int kop) : size(MAX_SIZE), count(1) {
    Init(grn, kop);
}

Money::Money(const Money& other)
    : amount(other.amount), size(other.size), count(other.count) {}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        amount = other.amount;
        size = other.size;
        count = other.count;
    }
    return *this;
}

Pair Money::getAmount() const {
    return amount;
}

void Money::setAmount(const Pair& p) {
    amount = p;
}

bool Money::Init(int grn, int kop) {
    return amount.Init(grn, kop);
}

int Money::operator[](int index) const {
    if (index == 0)      return amount.getFirst();
    if (index == 1)      return amount.getSecond();
    throw std::out_of_range("Money: ≥Ì‰ÂÍÒ Ï‡∫ ·ÛÚË 0 ‡·Ó 1");
}

std::string Money::toString() const {
    std::ostringstream oss;
    oss << amount.getFirst() << " „Ì, " << amount.getSecond() << " ÍÓÔ.";
    return oss.str();
}

Money::operator std::string() const {
    return toString();
}

void Money::Read() {
    int grn, kop;
    std::cout << "¬‚Â‰≥Ú¸ ÒÛÏÛ („Ì ≥ ÍÓÔ.): ";
    std::cin >> grn >> kop;
    Init(grn, kop);
}

void Money::Display() const {
    std::cout << toString() << std::endl;
}


// ===== ƒ–”∆Õ≤ ‘”Õ ÷≤Ø =====

Money operator+(const Money& lhs, const Money& rhs) {
    long long total = lhs.amount.getFirst() * 100LL + lhs.amount.getSecond()
        + rhs.amount.getFirst() * 100LL + rhs.amount.getSecond();
    return Money(static_cast<int>(total / 100),
        static_cast<int>(total % 100));
}

Money sub(const Money& lhs, const Money& rhs) {
    long long total1 = lhs.amount.getFirst() * 100LL + lhs.amount.getSecond();
    long long total2 = rhs.amount.getFirst() * 100LL + rhs.amount.getSecond();
    long long diff = total1 - total2;
    int grn = static_cast<int>(diff / 100);
    int kop = static_cast<int>(std::abs(diff % 100));
    return Money(grn, kop);
}

double div(const Money& lhs, const Money& rhs) {
    long long total1 = lhs.amount.getFirst() * 100LL + lhs.amount.getSecond();
    long long total2 = rhs.amount.getFirst() * 100LL + rhs.amount.getSecond();
    if (total2 == 0) return -1.0;
    return static_cast<double>(total1) / total2;
}

Money& operator++(Money& m) {
    long long total = m.amount.getFirst() * 100LL + m.amount.getSecond() + 1;
    m.amount.Init(static_cast<int>(total / 100),
        static_cast<int>(total % 100));
    return m;
}

Money operator++(Money& m, int) {
    Money tmp = m;
    ++m;
    return tmp;
}

Money& operator--(Money& m) {
    long long total = m.amount.getFirst() * 100LL + m.amount.getSecond() - 1;
    m.amount.Init(static_cast<int>(total / 100),
        static_cast<int>(std::abs(total % 100)));
    return m;
}

Money operator--(Money& m, int) {
    Money tmp = m;
    --m;
    return tmp;
}

std::ostream& operator<<(std::ostream& out, const Money& m) {
    return out << m.toString();
}

std::istream& operator>>(std::istream& in, Money& m) {
    int grn, kop;
    in >> grn >> kop;
    m.Init(grn, kop);
    return in;
}
