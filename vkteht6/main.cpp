#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

int main() {
    int selection = 0;
    std::vector<student> studentList;

    do {
        std::cout << "\nSelect\n" << std::endl;
        std::cout << "Add students = 0\n" << std::endl;
        std::cout << "Print all students = 1\n" << std::endl;
        std::cout << "Sort and print students according to Name = 2\n" << std::endl;
        std::cout << "Sort and print students according to Age = 3\n" << std::endl;
        std::cout << "Find and print student = 4\n" << std::endl;
        std::cin >> selection;

        switch (selection) {
        case 0: {
            std::string name;
            int age;
            std::cout << "Enter student name: ";
            std::cin >> name;
            std::cout << "Enter student age: ";
            std::cin >> age;
            studentList.push_back(student(name, age));
            break;
        }
        case 1: {
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 2: {
            std::sort(studentList.begin(), studentList.end(), [](const student& a, const student& b) {
                return a.getName() < b.getName();
            });
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 3: {
            std::sort(studentList.begin(), studentList.end(), [](const student& a, const student& b) {
                return a.getAge() < b.getAge();
            });
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 4: {
            std::string searchName;
            std::cout << "Student to be found name = ? ";
            std::cin >> searchName;

            auto it = std::find_if(studentList.begin(), studentList.end(), [&searchName](const student& student) {
                return student.getName() == searchName;
            });

            if (it != studentList.end()) {
                std::cout << "Student found:" << std::endl;
                it->printStudentInfo();
            } else {
                std::cout << "Student not found." << std::endl;
            }
            break;
        }
        default:
            std::cout << "Wrong selection, stopping..." << std::endl;
            break;
        }
    } while (selection < 5);

    return 0;
}

