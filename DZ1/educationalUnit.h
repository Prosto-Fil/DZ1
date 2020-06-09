#pragma once

#include "organization.h"

class EducationalUnit : public Organization
{
private:
    unordered_multimap<int, int> studentsprice;
public:
    EducationalUnit();
    EducationalUnit(string title, string director, int graduate_student, int employee, unordered_multimap<int, int> studentsprice);
    void Print() override;
    string gettitle() override;
    string getdirector() override;
    int getgraduate_student() override;
    int getemployee() override;
    unordered_multimap<int, int> getstudentsprice() override;
    unordered_multimap<string, int> getprojects() override;
};