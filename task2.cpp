#include "header.h"
void saveToFile2(const std::string& filename, const std::vector<Book>& data) {
    std::fstream out;
    out.open(filename);
    for (int i = 0; i < data.size(); i++) {
        if (i == data.size() - 1) {
            out << data[i].Author << ',' << data[i].Title
         << ',' << data[i].Year;
        }
        else {
            out << data[i].Author << ',' << data[i].Title
         << ',' << data[i].Year << '\n';
        }
    }
    out.close();
}
Book stringToStruct(std::string& str) {
    Book result;
    str += ',';
    std::string buf;
    int k = 0;
    for (int i = 0; i < size(str); i++) {
        if (str[i]!=',') {
            buf+=str[i];
        }
        else {
            k++;
            if (k==1) {
                result.Author = buf;
            }
            if (k==2) {
                result.Title = buf;
            }
            if (k==3) {
                result.Year = std::stoi(buf);
            }
            buf.clear();
        }
    }
    return result;
}

void loadFromFile2(const std::string& filename, std::vector<Book>& outData) {
    std::fstream in;
    in.open(filename);
    std::string line;
    while (getline(in,line)) {
        outData.push_back(stringToStruct(line));
    }
    in.close();
}