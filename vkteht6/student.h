#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class student {
private:
    std::string name;
    int age;

public:
    student(std::string name, int age);

    void setName(std::string name);
    void setAge(int age);

    std::string getName() const;
    int getAge() const;

    void printStudentInfo() const;
};

#endif
