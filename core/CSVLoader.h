#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <string>
#include <vector>

class CSVLoader {
public:
    bool load(const std::string& filename);
    void summary() const;
    std::vector<double> getColumn(size_t col) const;
    size_t columns() const;

private:
    std::vector<std::vector<double>> data_;
};

#endif
