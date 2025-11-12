//
// Created by user on 11.11.2025.
//

#ifndef UNTITLED3_HEADER_H
#define UNTITLED3_HEADER_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>


struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};
enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

using Groups = std::map<std::string, std::vector<Student>>;

void saveToFile1(const std::string& filename, const std::vector<std::string>& data);
void loadFromFile1(const std::string& filename, std::vector<std::string>& outData);

void saveToFile2(const std::string& filename, const std::vector<Book>& data);
void loadFromFile2(const std::string& filename, std::vector<Book>& outData);

void saveToFile3(const std::string& filename, const Groups& groups);
void loadFromFile3(const std::string& filename, Groups& outGroups);

#endif //UNTITLED3_HEADER_H