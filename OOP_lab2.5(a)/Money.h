// Money.h
#pragma once
#include "Pair.h"
#include <string>
#include <iostream>

class Money {
private:
    Pair amount;

public:
    static const int MAX_SIZE = 1;
    int size;
    int count;

    Money();
    Money(int grn, int kop);
    Money(const Money& other);

    Money& operator=(const Money& other);

    Pair getAmount() const;
    void setAmount(const Pair& p);
    bool Init(int grn, int kop);

    int operator[](int index) const;

    void Read();
    void Display() const;
    std::string toString() const;
    explicit operator std::string() const;

    friend Money operator+(const Money& lhs, const Money& rhs);
    friend Money sub(const Money& lhs, const Money& rhs);
    friend double div(const Money& lhs, const Money& rhs);

    friend Money& operator++(Money& m);       // ++m
    friend Money operator++(Money& m, int);   // m++
    friend Money& operator--(Money& m);       // --m
    friend Money operator--(Money& m, int);   // m--

    friend std::ostream& operator<<(std::ostream& out, const Money& m);
    friend std::istream& operator>>(std::istream& in, Money& m);
};
