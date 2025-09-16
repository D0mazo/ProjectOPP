// extra/SimpleData.h
#pragma once
#include <string>
#include <iostream>

// Simple class to illustrate the concept of "Class"
class SimpleData {
public:
    std::string name;
    int value;

    SimpleData(const std::string& n, int v) : name(n), value(v) {}

    void print() const {
        std::cout << "SimpleData -> Name: " << name << ", Value: " << value << "\n";
    }
};
