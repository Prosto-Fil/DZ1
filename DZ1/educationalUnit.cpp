#include "educationalUnit.h"

EducationalUnit::EducationalUnit()
{
    this->title = "Empty";
    this->director = "Empty";
    this->graduate_student = 0;
    this->employee = 0;
    this->studentsprice = { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };
}

EducationalUnit::EducationalUnit(string title, string director, int graduate_student, int employee, unordered_multimap<int, int> studentsprice)
{
    this->title = title;
    this->director = director;
    this->graduate_student = graduate_student;
    this->employee = employee;
    this->studentsprice = studentsprice;
}

void EducationalUnit::Print()
{
    cout << "Title of company is: " << this->title << endl;
    cout << "Name of the director is: " << this->director << endl;
    cout << "Number of graduate students is: " << this->graduate_student << endl;
    cout << "Number of employees is: " << this->employee << endl;
    cout << "Number of students on each course with price is: " << endl;
    int i = 1;
    cout << "Course\t\t" << "Number of students\t\t" << "Price for education" << endl;
    for (auto it = this->studentsprice.begin(); it != this->studentsprice.end(); it++)
    {
        cout << i << "\t\t\t" << it->first << "\t\t\t\t" << it->second << endl;
        i++;
    }
}

string EducationalUnit::gettitle()
{
    return this->title;
}

string EducationalUnit::getdirector()
{
    return this->director;
}

int EducationalUnit::getgraduate_student()
{
    return this->graduate_student;
}

int EducationalUnit::getemployee()
{
    return this->employee;
}

unordered_multimap<int, int> EducationalUnit::getstudentsprice()
{
    return this->studentsprice;
}

unordered_multimap<string, int> EducationalUnit::getprojects()
{
    return { {"0", 0} };
}