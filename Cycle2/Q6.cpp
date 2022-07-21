#include <iostream>

class student
{
    int roll;

public:
    student(){};
    student(int x) : roll(x) {}
    int get_roll()
    {
        std::cout << "Roll no: " << roll << '\n';
        return roll;
    }
};

class test : virtual public student
{
    int num_subs;
    float *marks;

public:
    test(){};
    test(int x, int subs) : student(x), num_subs(subs) {}
    void set_marks()
    {
        std::cout << "Enter marks: ";
        marks = new float[num_subs];
        for (int i = 0; i < num_subs; i++)
            std::cin >> marks[i];
    }
    float *get_marks()
    {
        std::cout << "Marks obtained in subjects: ";
        for (int i = 0; i < num_subs; i++)
            std::cout << marks[i] << ' ';
        std::cout << '\n';
        return marks;
    }

    int get_num_subs()
    {
        return num_subs;
    }
};

class sports : virtual public student
{
    float marks;

public:
    sports(){};
    sports(int x) : student(x) {}
    void set_marks()
    {
        std::cout << "Enter marks in sports: ";
        std::cin >> marks;
    }

    float get_marks()
    {
        std::cout << "Marks obtained in sports: " << marks << '\n';
        return marks;
    }
};

class report : public sports, public test
{
    float total;

public:
    report(){};
    report(int x, int subs) : test(x, subs), sports(x), student(x){};
    void show()
    {
        std::cout << "\nREPORT\n";
        std::cout << "-------------------------------------------------------------------------------\n";
        student::get_roll();
        int num_subs = test::get_num_subs();
        float *marks = test::get_marks();
        total = sports::get_marks();
        for (int i = 0; i < num_subs; i++)
            total += marks[i];
        std::cout << "Total marks obtained: " << total << '\n';
        std::cout << "-------------------------------------------------------------------------------\n";
    }
};

int main()
{
    int num;
    std::cout << "Enter number of students: ";
    std::cin >> num;
    report *reports = new report[num];
    for (int i = 0; i < num; i++)
    {
        int roll, num_subs;
        std::cout << "\nEnter roll no: ";
        std::cin >> roll;
        std::cout << "Enter number of subjects: ";
        std::cin >> num_subs;
        reports[i] = report(roll, num_subs);
        reports[i].test::set_marks();
        reports[i].sports::set_marks();
    }
    for (int i = 0; i < num; i++)
    {
        reports[i].show();
    }
}
