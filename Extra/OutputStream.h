#pragma once
#include <iostream>
#include <string>

//ISP
class OutputStream {
public:
    virtual ~OutputStream() = default;
    virtual void write(const std::string& data) = 0;
};

class ConsoleOutputStream : public OutputStream {
public:
    void write(const std::string& data) override {
        std::cout << data << "\n";
    }
};
