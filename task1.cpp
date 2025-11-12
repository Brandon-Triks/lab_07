#include "header.h"
void saveToFile1(const std::string& filename, const std::vector<std::string>& data) {
    std::fstream out;          // поток для записи
    out.open(filename);
    for (int i = 0; i < data.size(); i++) {
        out << data[i] << '\n';
    }
    out.close();
}

void loadFromFile1(const std::string& filename, std::vector<std::string>& outData) {
    std::fstream in;          // поток для чтения
    in.open(filename);
    std::string line;
    while (std::getline(in, line)) {
        outData.push_back(line);
    }
}