#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>

struct names_and_grades
{
    int grade{};
    std::string name{};
};

bool greater( const names_and_grades& a, const names_and_grades& b)
{
    // Order @a before @b if @a is greater than @b.
    return(a.grade > b.grade);
}

std::size_t how_many_students()
{
    std::cout << "How many students would you like to add? :";
    std::size_t how_many{};
    std::cin >> how_many;

    return how_many;
}

names_and_grades make_info(const std::string& s1, const int& s2)
{
    names_and_grades info;
    info.name = s1;
    info.grade = s2;
    
    return info;
}

int main()
{
    names_and_grades student_name{};
    names_and_grades student_grade{};

    std::size_t how_many_student{ how_many_students() };

    std::vector<names_and_grades> innpuu;

    for(std::size_t count{ 0 }; count < how_many_student; ++count)
    {
        std::cin >> student_name.name;
        std::cin >> student_grade.grade;

        if(student_grade.grade > 100)
        {
            student_grade.grade = 100;
        }

        innpuu.push_back(make_info(student_name.name, student_grade.grade));
    }

    std::cout << std::endl;

    
    std::sort( innpuu.begin(), innpuu.end(), greater );

    for(auto& i : innpuu)
    {
        std::cout << i.name << " got a grade of " << i.grade << '\n';
    }

    return 0;
}






/*
Question #2

Write the following program: Create a struct that holds a student’s first name and grade 
(on a scale of 0-100). Ask the user how many students they want to enter. Create a std::vector 
to hold all of the students. Then prompt the user for each name and grade. Once the user has entered 
all the names and grade pairs, sort the list by grade (highest first). Then print all the names and 
grades in sorted order.

For the following input:

Joe
82
Terry
73
Ralph
4
Alex
94
Mark
88

The output should look like this:

Alex got a grade of 94
Mark got a grade of 88
Joe got a grade of 82
Terry got a grade of 73
Ralph got a grade of 4

You can assume that names don’t contain spaces and that that input extraction doesn’t fail.
*/






