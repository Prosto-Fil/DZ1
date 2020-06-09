#include "educationalUnit.h"
#include "scientificUnit.h"

#include <fstream>
#include <algorithm>
#include <filesystem>
namespace sf = filesystem;

void filewritesu(string filename, int num)
{
    string type = "SU";
    ofstream filewrite;
    int choice = num;
    filewrite.open(filename, ios::app);
    if (!filewrite.is_open())
    {
        cout << "Error creating file " << filename << endl;
    }
    else
    {
        for (unsigned int i = 0; i < choice; i++)
        {
            filewrite << type << endl;
            cout << "Enter the title of company: " << endl;
            cin.ignore();
            string titlecomp;
            getline(cin, titlecomp);
            cout << "Enter the name of the director: " << endl;
            string directorcomp;
            getline(cin, directorcomp);
            cout << "Enter the number of graduate students: " << endl;
            int numbergs;
            cin >> numbergs;
            cout << "Enter the number of employees: " << endl;
            int emp;
            cin >> emp;
            cout << "Enter the number of the projects of this company: " << endl;
            int num;
            cin >> num;
            filewrite << titlecomp << endl;
            filewrite << directorcomp << endl;
            filewrite << numbergs << endl;
            filewrite << emp << endl;
            for (unsigned int i = 0; i < num; i++)
            {
                cout << i + 1 << " project" << endl;
                cout << "Enter the name of this project: " << endl;
                cin.ignore();
                string projectname;
                getline(cin, projectname);
                cout << "Enter the price of this project: " << endl;
                int price;
                cin >> price;
                filewrite << "{" << projectname << "," << price << "}" << " ";
            }
            cout << endl;
            filewrite << endl << endl;
        }
    }
    filewrite.close();
}

void filewriteeu(string filename, int num)
{
    string type = "EU";
    ofstream filewrite;
    int choice = num;
    filewrite.open(filename, ios::app);
    if (!filewrite.is_open())
    {
        cout << "Error creating file " << filename << endl;
    }
    else
    {
        for (unsigned int i = 0; i < choice; i++)
        {
            filewrite << type << endl;
            cout << "Enter the title of company: " << endl;
            cin.ignore();
            string titlecomp;
            getline(cin, titlecomp);
            cout << "Enter the name of the director: " << endl;
            string directorcomp;
            getline(cin, directorcomp);
            cout << "Enter the number of graduate students: " << endl;
            int numbergs;
            cin >> numbergs;
            cout << "Enter the number of employees: " << endl;
            int emp;
            cin >> emp;
            cout << "Enter the number of the courses of this company: " << endl;
            int num;
            cin >> num;
            cout << "Enter the number of students on each course with price: " << endl;
            filewrite << titlecomp << endl;
            filewrite << directorcomp << endl;
            filewrite << numbergs << endl;
            filewrite << emp << endl;
            for (unsigned int i = 0; i < num; i++)
            {
                cout << i + 1 << " course" << endl;
                cout << "Enter the number of students: " << endl;
                int numstud;
                cin >> numstud;
                cout << "Enter the price of this course studying: " << endl;
                int price;
                cin >> price;
                filewrite << "{" << numstud << "," << price << "}" << " ";
            }
            cout << endl;
            filewrite << endl << endl;
        }
    }
    filewrite.close();
}

void filewrite(string input)
{
    int found1 = input.rfind(' ');
    string type = input.substr(found1 + 1, input.size() - found1);
    cout << endl;
    if (type != "EU" & type != "SU" & type != "SU+EU" & type != "EU+SU")
    {
        cout << "Error creating DB" << endl;
        cout << "Wrong type of DB" << endl;
    }
    else
    {
        string dbname = input.substr(10, input.size() - type.size() - 11);
        string path = "/Users/HP37RTC/source/repos/DZ1/DZ1/Databases/" + dbname;
            if (type == "SU")
            {
                cout << "How many organizations of this type do you want to create?" << endl;
                int choice;
                cin >> choice;
                ofstream filewrite;
                filewrite.open(path);
                filewrite << choice << endl << endl;
                filewrite.close();
                cout << endl;
                filewritesu(path, choice);
            }
            if (type == "EU")
            {
                cout << "How many organizations of this type do you want to create?" << endl;
                int choice;
                cin >> choice;
                ofstream filewrite;
                filewrite.open(path);
                filewrite << choice << endl << endl;
                filewrite.close();
                cout << endl;
                filewriteeu(path, choice);
            } 
            if (type == "EU+SU" | type == "SU+EU")
            {
                cout << "How many organizations do you want to create?" << endl;
                int choiceall;
                cin >> choiceall;
                ofstream filewrite;
                filewrite.open(path);
                filewrite << choiceall << endl << endl;
                filewrite.close();
                string choicetype;
                for (unsigned int i = 0; i < choiceall; i++)
                {
                    cout << endl << "What organization do you want to create?" << endl;
                    cout << "You have " << choiceall - i << " slots now" << endl;
                    cin.ignore();
                    getline(cin, choicetype);
                    cout << endl;
                    if (choicetype == "SU")
                    {
                        filewritesu(path, 1);
                    }
                    if (choicetype == "EU")
                    {
                        filewriteeu(path, 1);
                    }
                }
            }
    }
}

void filewritemap(vector<pair<Organization*, string>> alltypes, string filename)
{
    string path = "/Users/HP37RTC/source/repos/DZ1/DZ1/Databases/" + filename;
    ofstream filewrite;
    filewrite.open(path);
    if (!filewrite.is_open())
    {
        cout << "Error creating file " << filename << endl;
    }
    else
    {
        filewrite << alltypes.size() << endl;
        for (auto it = alltypes.begin(); it != alltypes.end(); it++)
        {
            if (it->second == "EU")
            {
                filewrite << endl;
                filewrite << it->second << endl;
                filewrite << it->first->gettitle() << endl;
                filewrite << it->first->getdirector() << endl;
                filewrite << it->first->getgraduate_student() << endl;
                filewrite << it->first->getemployee() << endl;
                unordered_multimap<int, int> students = it->first->getstudentsprice();
                for (auto iter = students.begin(); iter != students.end(); iter++)
                {
                    int price = iter->first;
                    int stud = iter->second;
                    filewrite << "{" << price << "," << stud << "}" << " ";
                } 
                filewrite << endl;
            }

            if (it->second == "SU")
            {
                filewrite << endl;
                filewrite << it->second << endl;
                filewrite << it->first->gettitle() << endl;
                filewrite << it->first->getdirector() << endl;
                filewrite << it->first->getgraduate_student() << endl;
                filewrite << it->first->getemployee() << endl;
                unordered_multimap<string, int> projects = it->first->getprojects();
                for (auto iter = projects.begin(); iter != projects.end(); iter++)
                {
                    string prname = iter->first;
                    int price = iter->second;
                    filewrite << "{" << prname << "," << price << "}" << " ";
                } 
                filewrite << endl;
            }
        }
        cout << "Successfully done" << endl;
    }
    filewrite.close();
}

vector<pair<Organization*, string>> fileshow(string dbname)
{
    string path = "/Users/HP37RTC/source/repos/DZ1/DZ1/Databases/" + dbname;
    string type;
    cout << endl;
    ifstream fileshow;
    fileshow.open(path);
    if (!fileshow.is_open())
    {
        cout << "Error opening file" << endl;
    }
    else
    {
        cout << "Succesfully opened " << dbname << " file" << endl;
        cout << "Trying to read data..." << endl;
        string choice;
        getline(fileshow, choice);
        int number = stoi(choice);
        
        vector<pair<Organization*, string>> cltypes;
        for (unsigned int i = 0; i < number; i++)
        {
            string empty;
            getline(fileshow, empty);
            string type1;
            getline(fileshow, type1);
            if (type1 == "SU")
            {
                string str1, str2, str3, str4, str5, str6;
                getline(fileshow, str1);
                getline(fileshow, str2);
                getline(fileshow, str3);
                int num1 = stoi(str3);
                getline(fileshow, str4);
                int num2 = stoi(str4);
                getline(fileshow, str6);
                unordered_multimap<string, int> project;
                int size = str6.size();
                while (str6.size() != 0)
                {
                    int finder1 = str6.find('}');
                    string sub = str6.substr(0, finder1 + 1);
                    sub.erase(sub.size() - 1, 1);
                    int found1 = sub.find(',');
                    string projectname = sub.substr(1, found1 - 1);
                    string price = sub.substr(found1 + 1, sub.size());
                    int prprice = stoi(price);
                    project.emplace(projectname, prprice);
                    str6.erase(0, sub.size() + 2);
                }
                cltypes.push_back(pair<Organization*, string>(new ScientificUnit(str1, str2, num1, num2, project), type1));
            }

            if (type1 == "EU")
            {
                string str1, str2, str3, str4, str5, str6;
                getline(fileshow, str1);
                getline(fileshow, str2);
                getline(fileshow, str3);
                int num1 = stoi(str3);
                getline(fileshow, str4);
                int num2 = stoi(str4);
                getline(fileshow, str6);
                unordered_multimap<int, int> course;

                while (str6.size() != 0)
                {
                    int finder1 = str6.find('}');
                    string sub = str6.substr(0, finder1 + 1);
                    sub.erase(sub.size() - 1, 1);
                    int found1 = sub.find(',');
                    string num = sub.substr(1, found1 - 1);
                    int students = stoi(num);
                    string price = sub.substr(found1 + 1, sub.size());
                    int stprice = stoi(price);
                    course.emplace(students, stprice);
                    str6.erase(0, sub.size() + 2);
                }
                cltypes.push_back(pair<Organization*, string>(new EducationalUnit(str1, str2, num1, num2, course), type1));
            }
        }
        return cltypes;

        fileshow.close();
    }
}

void editor(string dbname)
{
    vector<pair<Organization*, string>> alltypes = fileshow(dbname);
    vector<pair<Organization*, string>> copy = alltypes;
    cout << "Data read succesfully" << endl << endl;
    for (auto it = alltypes.begin(); it != alltypes.end(); it++)
    {
        it->first->Print();
        cout << endl;
    }

    int num = 0;

    while (num != -1)
    {
        cout << "Enter what organization do you want to edit (from 0 to size of DB - 1)" << endl;
        cout << "Enter -1 to stop" << endl;
        cin >> num;
        if (num != -1)
        {
            int i = 0;

            for (auto it = alltypes.begin(); it != alltypes.end(); it++)
            {
                if (i == num)
                {
                    string answereditor;
                    while (answereditor != "stop")
                    {
                        cout << "What do you want to edit?" << endl;
                        cout << "Enter |title| or |director| or |graduate| or |employee| or |projects| or |students| or |stop|" << endl;

                        cin >> answereditor;

                        if (answereditor != "stop")
                        {
                            Organization* buf = it->first;
                            string titlecomp = buf->gettitle();
                            string directorcomp = buf->getdirector();
                            int numbergs = buf->getgraduate_student();
                            int emp = buf->getemployee();
                            unordered_multimap<int, int> studentsprice = buf->getstudentsprice();
                            unordered_multimap<string, int> projects = buf->getprojects();

                            if (answereditor == "title")
                            {
                                cout << "Enter the title of company: " << endl;
                                cin.ignore();
                                getline(cin, titlecomp);
                            }

                            else if (answereditor == "director")
                            {
                                cout << "Enter the name of the director: " << endl;
                                cin.ignore();
                                getline(cin, directorcomp);
                            }

                            else if (answereditor == "graduate")
                            {
                                cout << "Enter the number of graduate students: " << endl;
                                cin >> numbergs;
                            }

                            else if (answereditor == "employee")
                            {
                                cout << "Enter the number of employees: " << endl;
                                cin >> emp;
                            }

                            else if (answereditor == "projects" || answereditor == "students")
                            {
                                string dbedittype;
                                while (dbedittype != "stop")
                                {
                                    cout << "What do you want to do with it?" << endl;
                                    cout << "Enter |edit all|(reenter data) or |edit one| or |delete one| or |add one| or |stop|" << endl;

                                    cin.ignore();
                                    getline(cin, dbedittype);

                                    cout << "ANSWER IS:   " << dbedittype << endl;

                                    if (dbedittype == "edit all")
                                    {
                                        if (it->second == "EU")
                                        {
                                            studentsprice.clear();
                                            cout << "Enter the number of the courses in this educational unit: " << endl;
                                            int num;
                                            cin >> num;
                                            for (unsigned int i = 0; i < num; i++)
                                            {
                                                cout << i + 1 << " course" << endl;
                                                cout << "Enter the number of students: " << endl;
                                                int numstud;
                                                cin >> numstud;
                                                cout << "Enter the price of this course studying: " << endl;
                                                int price;
                                                cin >> price;
                                                studentsprice.emplace(numstud, price);
                                            }
                                        }

                                        if (it->second == "SU")
                                        {
                                            projects.clear();
                                            cout << "Enter the number of the projects of this company: " << endl;
                                            int num;
                                            cin >> num;
                                            for (unsigned int i = 0; i < num; i++)
                                            {
                                                cout << i + 1 << " project" << endl;
                                                cout << "Enter the name of this project: " << endl;
                                                cin.ignore();
                                                string projectname;
                                                getline(cin, projectname);
                                                cout << "Enter the price of this project: " << endl;
                                                int price;
                                                cin >> price;
                                                projects.emplace(projectname, price);
                                            }
                                        }
                                    }
                                    else if (dbedittype == "edit one")
                                    {
                                        if (it->second == "EU")
                                        {
                                            unordered_multimap<int, int> copystudentsprice = studentsprice;
                                            cout << "Course\t\t" << "Number of students\t\t" << "Price for education" << endl;
                                            for (auto it = studentsprice.begin(); it != studentsprice.end(); it++)
                                            {
                                                cout << i << "\t\t\t" << it->first << "\t\t\t\t" << it->second << endl;
                                                i++;
                                            }

                                            cout << "Enter what course do you want to edit (from 0 to number of courses - 1)" << endl;
                                            cout << "Enter -1 to stop" << endl;
                                            int prnum;
                                            cin >> prnum;
                                            if (prnum != -1)
                                            {
                                                int counter = 0;
                                                for (auto iter = studentsprice.begin(); iter != studentsprice.end(); iter++)
                                                {
                                                    if (counter == prnum)
                                                    {
                                                        cout << "Enter the number of students: " << endl;
                                                        int numstud;
                                                        cin >> numstud;
                                                        cout << "Enter the price of this course studying: " << endl;
                                                        int price;
                                                        cin >> price;

                                                        auto iter3 = copystudentsprice.begin();
                                                        for (unsigned int j = 0; j < counter; j++)
                                                        {
                                                            iter3++;
                                                        }
                                                        iter3 = copystudentsprice.erase(iter3);

                                                        copystudentsprice.insert(iter3, { numstud, price });
                                                    }

                                                    counter++;
                                                }

                                                studentsprice = copystudentsprice;
                                            }
                                        }

                                        if (it->second == "SU")
                                        {
                                            unordered_multimap<string, int> copyprojects = projects;
                                            cout << "Project's name\t\t" << "Project's price" << endl;
                                            for (auto it = projects.begin(); it != projects.end(); it++)
                                            {
                                                cout << it->first << "\t\t\t" << it->second << endl;
                                            }

                                            cout << "Enter what project do you want to edit (from 0 to number of courses - 1)" << endl;
                                            cout << "Enter -1 to stop" << endl;
                                            int prnum;
                                            cin >> prnum;
                                            if (prnum != -1)
                                            {
                                                int counter = 0;
                                                for (auto iter = projects.begin(); iter != projects.end(); iter++)
                                                {
                                                    if (counter == prnum)
                                                    {
                                                        cout << "Enter the name of this project: " << endl;
                                                        cin.ignore();
                                                        string projectname;
                                                        getline(cin, projectname);
                                                        cout << "Enter the price of this project: " << endl;
                                                        int price;
                                                        cin >> price;

                                                        auto iter3 = copyprojects.begin();
                                                        for (unsigned int j = 0; j < counter; j++)
                                                        {
                                                            iter3++;
                                                        }
                                                        iter3 = copyprojects.erase(iter3);

                                                        copyprojects.insert(iter3, { projectname, price });
                                                    }

                                                    counter++;
                                                }

                                            }

                                            projects = copyprojects;
                                        }
                                    }
                                    else if (dbedittype == "delete one")
                                    {
                                        if (it->second == "EU")
                                        {
                                            cout << "Course\t\t" << "Number of students\t\t" << "Price for education" << endl;
                                            for (auto it = studentsprice.begin(); it != studentsprice.end(); it++)
                                            {
                                                cout << i << "\t\t\t" << it->first << "\t\t\t\t" << it->second << endl;
                                                i++;
                                            }

                                            cout << "Enter what course do you want to delete (from 0 to number of courses - 1)" << endl;
                                            cout << "Enter -1 to stop" << endl;
                                            int prnum;
                                            cin >> prnum;
                                            if (prnum != -1)
                                            {
                                                int counter = 0;
                                                for (auto iter = studentsprice.begin(); iter != studentsprice.end(); iter++)
                                                {
                                                    if (counter == prnum)
                                                    {
                                                        iter = studentsprice.erase(iter);
                                                    }
                                                    counter++;
                                                }
                                            }
                                        }

                                        if (it->second == "SU")
                                        {
                                            cout << "Project's name\t\t" << "Project's price" << endl;
                                            for (auto it = projects.begin(); it != projects.end(); it++)
                                            {
                                                cout << it->first << "\t\t\t" << it->second << endl;
                                            }

                                            cout << "Enter what project do you want to delete (from 0 to number of courses - 1)" << endl;
                                            cout << "Enter -1 to stop" << endl;
                                            int prnum;
                                            cin >> prnum;
                                            if (prnum != -1)
                                            {
                                                int counter = 0;
                                                for (auto iter = projects.begin(); iter != projects.end(); iter++)
                                                {
                                                    if (counter == prnum)
                                                    {
                                                        iter = projects.erase(iter);
                                                    }
                                                    counter++;
                                                }
                                            }
                                        }
                                    }
                                    else if (dbedittype == "add one")
                                    {
                                        if (it->second == "EU")
                                        {
                                            cout << "Enter the number of students: " << endl;
                                            int numstud;
                                            cin >> numstud;
                                            cout << "Enter the price of this course studying: " << endl;
                                            int price;
                                            cin >> price;
                                            studentsprice.insert(studentsprice.end(), { numstud, price });
                                        }

                                        if (it->second == "SU")
                                        {
                                            cout << "Enter the name of this project: " << endl;
                                            string projectname;
                                            getline(cin, projectname);
                                            cout << "Enter the price of this project: " << endl;
                                            int price;
                                            cin >> price;
                                            projects.insert(projects.end(), { projectname, price });
                                        }
                                    }
                                }
                            }

                            auto iter2 = copy.begin();
                            for (unsigned int j = 0; j < i; j++)
                            {
                                iter2++;
                            }
                            iter2 = copy.erase(iter2);

                            if (it->second == "EU")
                            {
                                copy.emplace(iter2, pair<Organization*, string>(new EducationalUnit(titlecomp, directorcomp, numbergs, emp, studentsprice), it->second));
                            }

                            if (it->second == "SU")
                            {
                                copy.emplace(iter2, pair<Organization*, string>(new ScientificUnit(titlecomp, directorcomp, numbergs, emp, projects), it->second));
                            }

                            cout << endl;
                            for (auto it1 = copy.begin(); it1 != copy.end(); it1++)
                            {
                                it1->first->Print();
                                cout << endl;
                            }

                        }

                    }
                }
                i++;
            }
        }
    }

    filewritemap(copy, dbname);
}

void adderdata(string dbname)
{
    vector<pair<Organization*, string>> alltypes = fileshow(dbname);
    cout << "Data read succesfully" << endl << endl;
    for (auto it = alltypes.begin(); it != alltypes.end(); it++)
    {
        it->first->Print();
        cout << endl;
    }

    int counter = 0;
    while (counter != -1)
    {
        cout << "Enter to what place do you want to add organization (from 0 to size of DB)" << endl;
        cout << "Enter -1 to stop" << endl;
        cin >> counter;
        if (counter != -1)
        {
            cout << "Enter what type of organization do you want to add" << endl;
            cin.ignore();
            string choicetype;
            getline(cin, choicetype);

            cout << "Enter the title of company: " << endl;
            string titlecomp;
            getline(cin, titlecomp);
            cout << "Enter the name of the director: " << endl;
            string directorcomp;
            getline(cin, directorcomp);
            cout << "Enter the number of graduate students: " << endl;
            int numbergs;
            cin >> numbergs;
            cout << "Enter the number of employees: " << endl;
            int emp;
            cin >> emp;

            if (choicetype == "EU")
            {
                unordered_multimap<int, int> studentsprice;
                cout << "Enter the number of the courses in this educational unit: " << endl;
                int num;
                cin >> num;
                for (unsigned int i = 0; i < num; i++)
                {
                    cout << i + 1 << " course" << endl;
                    cout << "Enter the number of students: " << endl;
                    int numstud;
                    cin >> numstud;
                    cout << "Enter the price of this course studying: " << endl;
                    int price;
                    cin >> price;
                    studentsprice.emplace(numstud, price);
                }
                alltypes.insert(alltypes.begin() + counter, pair<Organization*, string>(new EducationalUnit(titlecomp, directorcomp, numbergs, emp, studentsprice), "EU"));
            }

            if (choicetype == "SU")
            {
                unordered_multimap<string, int> projects;
                cout << "Enter the number of the projects of this company: " << endl;
                int num;
                cin >> num;
                for (unsigned int i = 0; i < num; i++)
                {
                    cout << i + 1 << " project" << endl;
                    cout << "Enter the name of this project: " << endl;
                    cin.ignore();
                    string projectname;
                    getline(cin, projectname);
                    cout << "Enter the price of this project: " << endl;
                    int price;
                    cin >> price;
                    projects.emplace(projectname, price);
                }
                alltypes.insert(alltypes.begin() + counter, pair<Organization*, string>(new ScientificUnit(titlecomp, directorcomp, numbergs, emp, projects), "SU"));
            }
        }
    }

    filewritemap(alltypes, dbname);
}

void deleterdata(string dbname)
{
    vector<pair<Organization*, string>> alltypes = fileshow(dbname);
    vector<pair<Organization*, string>> copy = alltypes;
    cout << "Data read succesfully" << endl << endl;
    for (auto it = alltypes.begin(); it != alltypes.end(); it++)
    {
        it->first->Print();
        cout << endl;
    }

    int num = 0;

    while (num != -1)
    {
        cout << "Enter what organization do you want to delete (from 0 to size of DB - 1)" << endl;
        cout << "Enter -1 to stop" << endl;
        cin >> num;
        if (num != -1)
        {
            if ((num >= alltypes.size()) | (num < 0))
            {
                cout << alltypes.size() << endl;
                cout << "Wrong number" << endl;
            }

            int i = 0;

            for (auto it = alltypes.begin(); it != alltypes.end(); it++)
            {
                if (i == num)
                {
                    auto iter2 = copy.begin();
                    for (unsigned int j = 0; j < i; j++)
                    {
                        iter2++;
                    }
                    iter2 = copy.erase(iter2);
                    for (auto it1 = copy.begin(); it1 != copy.end(); it1++)
                    {
                        it1->first->Print();
                        cout << endl;
                    }
                }
                i++;
            }
        }
    }

    filewritemap(copy, dbname);
}

void renamer(string oldname)
{
    cout << "To what name do you want to rename this file?" << endl;
    string newname;
    getline(cin, newname);
    sf::rename(oldname, newname);
    cout << "Succesfully renamed " << oldname << " file to " << newname << endl;
}

void deleter(string filename)
{
    sf::remove(filename);
    cout << "Succesfully deleted " << filename << " file" << endl;
}

void sortdb(string dbname)
{
    vector<pair<Organization*, string>> alltypes = fileshow(dbname);
    vector<pair<Organization*, string>> copy;

    cout << "How do you want to sort your DB? (by <title of organization> or <number of employess>)" << endl;
    string sorttype;
    getline(cin, sorttype);

    if (sorttype == "title of organization")
    {
        vector<string> titles;
        vector<int> numbers;

        int counter = 0;
        for (auto it = alltypes.begin(); it != alltypes.end(); it++)
        {
            titles.push_back(it->first->gettitle());
            numbers.push_back(counter + 1);
            counter++;
        }

        for (int i = 0; i < alltypes.size(); i++) {
            for (int j = 0; j < alltypes.size() - i - 1; j++) {
                if (titles[j] > titles[j + 1]) {
                    swap(titles[j], titles[j + 1]);
                    swap(numbers[j], numbers[j + 1]);
                }
            }
        }

        int checker = 0;
        for (int i = 0; i < alltypes.size(); i++)
        {
            auto iter = alltypes.begin();
            for (int j = 0; j < numbers[checker] - 1; j++)
                iter++;
            iter->first->Print();
            cout << endl;
            copy.push_back(pair<Organization*, string>(iter->first, iter->second));
            checker++;
        }

        cout << endl;
        filewritemap(copy, dbname);
    }
    
    if (sorttype == "number of employess")
    {
        vector<int> empnum;
        vector<int> numbers;

        int counter = 0;
        for (auto it = alltypes.begin(); it != alltypes.end(); it++)
        {
            empnum.push_back(it->first->getemployee());
            numbers.push_back(counter + 1);
            counter++;
        }

        for (int i = 0; i < alltypes.size(); i++) {
            for (int j = 0; j < alltypes.size() - i - 1; j++) {
                if (empnum[j] > empnum[j + 1]) {
                    swap(empnum[j], empnum[j + 1]);
                    swap(numbers[j], numbers[j + 1]);
                }
            }
        }

        int checker = 0;
        for (int i = 0; i < alltypes.size(); i++)
        {
            cout << "checker: " << checker << endl;
            auto iter = alltypes.begin();
            for (int j = 0; j < numbers[checker] - 1; j++)
                iter++;
            iter->first->Print();
            cout << endl;
            copy.push_back(pair<Organization*, string>(iter->first, iter->second));
            checker++;
        }

        cout << endl;

        filewritemap(copy, dbname);
    }

    if ((sorttype != "number of employess") & (sorttype != "title of organization"))
    {
        cout << "Wrong command" << endl;
    }
}

void finddata(string dbname)
{
    vector<pair<Organization*, string>> alltypes = fileshow(dbname);
    vector<pair<Organization*, string>> copy;

    cout << "Via what rule do you want to find data in this DB? (by <average pay >n> or <number of employess <n>)" << endl;
    string findtype;
    getline(cin, findtype);

    cout << "Enter n" << endl;
    double n;
    cin >> n;

    if (findtype == "average pay >n")
    {
        for (auto it = alltypes.begin(); it != alltypes.end(); it++)
        {
            if (it->second == "EU")
            {
                unordered_multimap<int, int> studentsprice = it->first->getstudentsprice();
                int sum = 0;
                for (auto iter = studentsprice.begin(); iter != studentsprice.end(); iter++)
                    sum = sum + iter->second;
                if ((sum / it->first->getemployee()) > n)
                {
                    copy.push_back(pair<Organization*, string>(it->first, it->second));
                }
            }

            if (it->second == "SU")
            {
                unordered_multimap<string, int> projects = it->first->getprojects();
                int sum = 0;
                for (auto iter = projects.begin(); iter != projects.end(); iter++)
                    sum = sum + iter->second;
                if ((sum / it->first->getemployee()) > n)
                {
                    copy.push_back(pair<Organization*, string>(it->first, it->second));
                }
            }
        }
    }

    if (findtype == "number of employess <n")
    {
        for (auto it = alltypes.begin(); it != alltypes.end(); it++)
        {
            if (it->first->getemployee() <= n)
                copy.push_back(pair<Organization*, string>(it->first, it->second));
        }
    }

    if ((findtype != "average pay >n") | (findtype == "number of employess <n"))
    {
        cout << "Wrong command" << endl;
    }


    cout << "Result is: " << endl;
    for (auto it = copy.begin(); it != copy.end(); it++)
    {
        it->first->Print();
        cout << endl;
    }

    cout << "Do you want to save this as a new DB? (<yes> or <no>)" << endl;
    cin.ignore();
    string answer;
    getline(cin, answer);
    if (answer == "yes")
    {
        cout << "Enter the name of new DB" << endl;
        string newname;
        getline(cin, newname);
        filewritemap(copy, newname);
    }
}

void findFIO(string dbname)
{
    vector<pair<Organization*, string>> alltypes = fileshow(dbname);
    vector<string> alldirectors;
    for (auto it = alltypes.begin(); it != alltypes.end(); it++)
    {
        alldirectors.push_back(it->first->getdirector());
    }

    cout << "Enter FIO of the director, which organization you want to find" << endl;
    string FIO;
    getline(cin, FIO);

    vector<string> alltitles;
    for (int i = 0; i < alldirectors.size(); i++)
    {
        if (alldirectors[i] == FIO)
        {
            auto iter = alltypes.begin() + i;
            alltitles.push_back(iter->first->gettitle());
        }
    }

    if (alltitles.size() == 0)
    {
        cout << "There isnt any organizations with this director" << endl;
    }
    else
    {
        cout << "Titles of organizations with director: " << FIO << " is:" << endl;
        for (int i = 0; i < alltitles.size(); i++)
            cout << alltitles[i] << " ";
        cout << endl;
    }
}

void findnumstudents(string dbname)
{
    vector<pair<Organization*, string>> alltypes = fileshow(dbname);

    vector<int> allstudents;
    for (auto it = alltypes.begin(); it != alltypes.end(); it++)
    {
        if (it->second == "EU")
        {
            unordered_multimap<int, int> studentsprice = it->first->getstudentsprice();
            int sum = 0;
            for (auto iter = studentsprice.begin(); iter != studentsprice.end(); iter++)
            {
                sum += iter->first;
            }
            allstudents.push_back(it->first->getgraduate_student() + sum);
        }
        else if (it->second == "SU")
        {
            allstudents.push_back(it->first->getgraduate_student());
        }
    }

    cout << "Organizations's title\t\t" << "Number of students" << endl;
    for (int i = 0; i < allstudents.size(); i++)
    {
        auto iter = alltypes.begin() + i;
        cout << iter->first->gettitle() << "\t\t\t\t" << allstudents[i] << endl;
    }
}

int main()
{
    cout << "########      #####            #########   ########    #####   ##########     ######      ######  " << endl;
    cout << " ########   ##########         #########    ########    ###     ###### #     ## #####    ######## " << endl;
    cout << " ###   ##    ###   ###          ###         ###   ##    ###    ##  ##  #    ## ##  ##     ##   ## " << endl;
    cout << " ###   ##    ###   ###          ###         ###   ##    ###        ##       ## #   ###    ##   ## " << endl;
    cout << " ###   ##    ###  ###           ###         ###   ##    ###        ##       ## #   ###    ##  ### " << endl;
    cout << " ###   ##   ########           ######       ###   ##    ###        ##       ## #   ###   ######   " << endl;
    cout << " ###   ##    #########        #######       ###   ##    ###        ##       ## #   ###    ##  #   " << endl;
    cout << " ###   ##    ###   ###          ###         ###   ##    ###        ##        # #   ###   ###  ##  " << endl;
    cout << " ###  ##     ###   ###          ###  ##     ###  ##     ###        ##        ###  ###     ##  ##  " << endl;
    cout << "########    ##########         ####### #   ########     ###        ##         #######     ##   ## " << endl;
    cout << " #####       #######           #########    #####      #####     #####         ####      ####  ###" << endl << endl;

    cout << "Hello, dear User!" << endl << endl;
    cout << "Rules and commands: " << endl;
    cout << "Enter all files' names with .txt" << endl;
    cout << "There are 2 types of DBs: educational unit(EU) or scientific unit(SU)" << endl;
    cout << "To show a list of DBs enter |list of DBs|" << endl;
    cout << "To create new DB enter |create DB <DB name> <DB type>|" << endl;
    cout << "To show DB enter |show data DB <DB name>|" << endl;
    cout << "To delete a DB enter |delete DB <DB name>|" << endl;
    cout << "To rename a DB enter |rename DB <DB name>|" << endl;
    cout << "To edit a DB enter |edit data DB <DB name>|" << endl;
    cout << "To delete data in DB enter |delete data DB <DB name>|" << endl;
    cout << "To add data in DB enter |add data DB <DB name>|" << endl;
    cout << "To sort a DB enter |sort data DB <DB name>|" << endl;
    cout << "To find a DB with something rule |find data DB <DB name>|" << endl;
    cout << "To find organization in BD via FIO enter |find FIO DB <DB name>|" << endl;
    cout << "To find number of students in BD enter |find students DB <DB name>|" << endl;
    cout << "Enter |exit| if you want to stop your programm" << endl << endl;

    string command;
    string input;
    while (input != "exit")
    {
        cout << ">";
        getline(cin, input);
        command = input.substr(0, 10);
        if (command == "list of DB")
        {
            sf::path p("/Users/HP37RTC/source/repos/DZ1/DZ1/Databases");
            for (sf::directory_iterator i(p), end; i != end; i++)
            {
                if (!filesystem::is_directory(i->path()))
                {
                    cout << i->path().filename() << endl;
                }
            }
        }
        if (command == "create DB ")
        {
            filewrite(input);
        }
        if (command == "show data ")
        {
            string dbname = input.substr(13, input.size() - 13);
            vector<pair<Organization*, string>> alltypes = fileshow(dbname);
            cout << "Data read succesfully" << endl << endl;
            for (auto it = alltypes.begin(); it != alltypes.end(); it++)
            {
                ((pair<Organization*, string>)(*it)).first->Print();
                cout << endl;
            }
        }
        if (command == "delete DB ")
        {
            string filename = input.substr(10, input.size() - 10);
            deleter(filename);
        }
        int finder5 = command.find("rename");
        if (command == "rename DB ")
        {
            string oldname = input.substr(10, input.size() - 10);
            renamer(oldname);
        }
        if (command == "edit data ")
        {
            string dbname = input.substr(13, input.size() - 13);
            editor(dbname);
        }
        if (command == "delete dat")
        {
            string dbname = input.substr(15, input.size() - 15);
            deleterdata(dbname);
        }
        if (command == "add data D")
        {
            string dbname = input.substr(12, input.size() - 12);
            adderdata(dbname);
        }
        if (command == "sort data ")
        {
            string dbname = input.substr(13, input.size() - 13);
            sortdb(dbname);
        }
        if (command == "find data ")
        {
            string dbname = input.substr(13, input.size() - 13);
            finddata(dbname);
        }
        if (command == "find FIO D")
        {
            string dbname = input.substr(12, input.size() - 12);
            findFIO(dbname);
        }
        if (command == "find stude")
        {
            string dbname = input.substr(17, input.size() - 17);
            findnumstudents(dbname);
        }
    }
    return 0;
}