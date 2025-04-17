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

    // ������������
    Pair();
    Pair(int a, int b);
    Pair(const Pair& other);

    // ���������
    Pair& operator=(const Pair& other);

    // ������
    int getFirst() const;
    int getSecond() const;
    void setFirst(int value);
    void setSecond(int value);
    bool Init(int a, int b);

    // ����������
    int operator[](int index) const;

    // ���������� �� �����
    std::string toString() const;
    explicit operator std::string() const;

    // ���/����
    void Read();
    void Display() const;

    // ����� �������
    friend Pair operator+(const Pair& lhs, const Pair& rhs);
    friend Pair multiply(const Pair& p, int n);
    friend Pair operator*(const Pair& p, int n);
    friend Pair operator*(int n, const Pair& p);

    friend Pair& operator++(Pair& p);      // ���������� ++p
    friend Pair operator++(Pair& p, int);  // ����������� p++
    friend Pair& operator--(Pair& p);      // ���������� --p
    friend Pair operator--(Pair& p, int);  // ����������� p--

    friend std::ostream& operator<<(std::ostream& out, const Pair& p);
    friend std::istream& operator>>(std::istream& in, Pair& p);
};
