#include <iostream>
#include <string>

class Student
{
    std::string name;
    int roll_no;
    int marks[3];

public:
    void input();
    char calcGrade();
    void display();
};

void Student::input()
{
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter roll no: ";
    std::cin >> roll_no;
    std::cout << "Enter marks (seperated by space): ";
    int i = 0;
    do
    {
        std::cin >> marks[i];
        i++;
    } while (i < 3);
}

char Student::calcGrade()
{
    float avg = 0;
    for (int i = 0; i < 3; i++)
    {
        avg += marks[i];
    }
    avg /= 3;

    if (avg >= 90)
        return 'A';
    else if (avg >= 80)
        return 'B';
    else if (avg >= 70)
        return 'C';
    else if (avg >= 60)
        return 'D';
    else if (avg >= 50)
        return 'E';
    else if (avg >= 40)
        return 'F';
    else
        return 'G';
}

void Student::display()
{
    std::cout << '\n'
              << "Name: " << name << '\n';
    std::cout << "Roll no: " << roll_no << '\n';
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Marks in subject " << i + 1 << ": " << marks[i] << '\n';
    }
    std::cout << "Grade: " << calcGrade() << '\n';
}

int main()
{
    int N;
    std::cout << "Enter number of students: ";
    std::cin >> N;

    Student *student_list = new Student[N];

    for (int i = 0; i < N; i++)
    {
        student_list[i].input();
    }

    for (int i = 0; i < N; i++)
    {
        student_list[i].display();
    }

    delete student_list;
}
