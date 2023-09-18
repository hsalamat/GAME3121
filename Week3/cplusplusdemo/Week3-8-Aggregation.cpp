/** @file Week3-8-Aggregation.cpp
 *  @brief Aggregation Dem o
 *
 *  Because aggregations are similar to compositions in that they are both part - whole relationships,
 *  they are implemented almost identically, and the difference between them is mostly semantic.
 *  In a composition, we typically add our parts to the composition using normal member variables
 *  (or pointers where the allocation and deallocation process is handled by the composition class).
 *  In an aggregation, we also add parts as member variables.
 *  However, these member variables are typically either references or pointers
 *  that are used to point at objects that have been created outside the scope of the class.
 *  Consequently, an aggregation usually either takes the objects it is going to point to as constructor parameters,
 *  or it begins empty and the subobjects are added later via access functions or operators.
*   
 *  @attention Technically speaking, the “has - a” relationship is called composition  while the “uses - a” relationship is called aggregation
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <functional> // std::reference_wrapper
#include <iostream>
#include <vector>
#include <string>

class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(const std::string& name)
        : m_name{ name }
    {
    }

    std::string& getName() { return m_name; }
};

class Department
{
private:
    std::string m_name{};

public:
    Department(const std::string& name)
        : m_name{ name }
    {
    }

    std::string& getName() { return m_name; }
    std::vector<Teacher> departmentTeachers;
};

int main()
{
    Teacher tom{ "Tom" };
    Teacher berta{ "Berta" };

    {
        Department computerDep("Computer");

        computerDep.departmentTeachers.push_back(tom);
        computerDep.departmentTeachers.push_back(berta);

        Teacher jim{ "Jim" };

        computerDep.departmentTeachers.push_back(jim);

        for (auto name : computerDep.departmentTeachers)
        {
            std::cout << name.getName() << '\n'; // Jim Beam
        }       
    } // department goes out of scope here and is destroyed

    // tom still exists here, but the department doesn't

    std::cout << tom.getName() << " still exists!\n";

    return 0;
}