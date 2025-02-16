#include "Student.h"
#include <string>
#include <iostream>

student::student(std::string name, int age) : name(name), age(age) {}

void student::setName(std::string name) {
    this->name = name;
}

void student::setAge(int age) {
    this->age = age;
}

std::string student::getName() const {
    return name;
}

int student::getAge() const {
    return age;
}

void student::printStudentInfo() const {
    std::cout << "Student " << name << " Age " << age << std::endl;
}
