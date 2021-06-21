#include <algorithm> // std::sort
#include <cstddef> // std::size_t
#include <iostream>
#include <string>
#include <vector>

struct Student
{
  int grade{};
  std::string name{};
};

int getNumberOfStudents()
{
    int NumberOfStudents{};

    do
    {
        std::cout << "How many students do you want to enter? ";
        std::cin >> NumberOfStudents;

    } while (NumberOfStudents <= 0);

    return NumberOfStudents;
}

std::vector<Student> getStudents()
{
    using vector_type = std::vector<Student>;

    int numberOfStudents{ getNumberOfStudents() };

    //size_type is a (static) member type of the type vector<int>
     // Create a vector with numberOfStudents elements.
    vector_type students(static_cast<vector_type::size_type>(numberOfStudents));

    int studentNumber{ 1 };

    for(auto& i : students)
    {
        std::cout << "Enter name #" << studentNumber << ": ";
        std::cin >> i.name;
        std::cout << "Enter grade #" << studentNumber << ": ";
        std::cin >> i.grade;
 
        ++studentNumber;
    }
    return students;
}

// Pass by reference to avoid slow copies.
bool compareStudents(const Student& a, const Student& b)
{
  return (a.grade > b.grade);
}

int main()
{
    auto students{ getStudents() };

    std::sort(students.begin(), students.end(), compareStudents);

    // Print out all the names
    for(const auto& i : students)
    {
        std::cout << i.name << " got a grade of " << i.grade << '\n';
    }
    return 0;
}