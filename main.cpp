#include "header.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    //task1
    std::vector<std::string> v1{"efx", "Kvarz", "Lexa", "Панч"};
    std::vector<std::string> v2;
    std::string filename = "file.txt";
    //saveToFile1(filename, v1);
    //loadFromFile1(filename,v2);

    //task2
    Book book1;
    book1 = Book{"author1", "title1", 1};
    Book book2;
    book2 = Book{"author2", "title2", 2025};
    std::vector<Book> v3 {book1,book2};
    std::vector<Book> v4;
    //saveToFile2(filename, v3);
    //loadFromFile2(filename,v4);

    //task2
    Student student1,student2,student3,student4;
    student1 = {"Alex",2,{
                {"Math",Excellent},{"IT",Excellent},{"Phys",Excellent}}
    };
    student2 = {"Michael",2,{
                    {"Math",Satisfactorily},{"IT",Unsatisfactorily},{"Phys",Good}}
    };
    student3 = {"John",2,{
                    {"Math",Good},{"IT",Good},{"Phys",Good}}
    };
    student4 = {"Bob",2,{
                    {"Math",Unsatisfactorily},{"IT",Unsatisfactorily},{"Phys",Unsatisfactorily}}
    };
    Groups groups, outGroups;
    groups.clear();
    groups["A"] = {student1};
    groups["B"] = {student2,student3};
    groups["C"] = {student4};

    saveToFile3(filename,groups);

    loadFromFile3(filename,outGroups);
    std::cout << outGroups["C"][0].RecordBook["IT"];
}