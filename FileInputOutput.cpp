#include <iostream>
#include <string>
#include <fstream>

struct Student
{
	int id;
	std::string name;
	double gpa;
};

int main()
{
	// Create an instance of the student struct
	Student s1 = { 123, "Jonathan Brown", 4.0 };

	// Write struct data to a file
	std::ofstream outfile("student.txt");
	if (outfile.is_open())
	{
		outfile << s1.id << " " << s1.name << " " << s1.gpa << std::endl;
		outfile.close();
		std::cout << "Data written to file successfully." << std::endl;
	}
	else
	{
		std::cerr << "Unable to open file for writing." << std::endl;
	}

	// Read struct data from a file
	std::ifstream infile("student.txt");
	if (infile.is_open())
	{
		Student s2;
		infile >> s2.id >> s2.name >> s2.gpa;
		std::cout << "Read data from file: " << std::endl;
		std::cout << "Student ID: " << s2.id << std::endl;
		std::cout << "Student Name: " << s2.name << std::endl;
		std::cout << "Student GPA: " << s2.gpa << std::endl;
		infile.close();
	}
	else
	{
		std::cerr << "Unable to open file for reading." << std::endl;
	}

	return 0;
}