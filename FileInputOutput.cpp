/*
#include <iostream>
#include <string>
#include <fstream>

struct Student
{
	int id;
	std::string name;
	std::string gpa;
};

int main()
{
	// Create an instance of the student struct
	Student s1 = { 123, "Jonathan Brown", "4.0" };

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
*/

#include <iostream>
#include <fstream>
#include <string>

struct Student
{
	int id;
	std::string name;
	double gpa;
};

int main()
{
	Student s1 = { 123, "Jonathan Brown", 3.5 };

	// Write the struct data to a file
	std::ofstream outfile("student.txt", std::ios::binary);
	if (outfile.is_open())
	{
		outfile.write(reinterpret_cast<char*>(&s1), sizeof(Student));
		outfile.close();
		std::cout << "Data written to file successfully." << std::endl;
	}
	else
	{
		std::cerr << "Unable to open file for writing." << std::endl;
	}

	// Read the struct data from a file
	std::ifstream infile("student.txt", std::ios::binary);
	if (infile.is_open())
	{
		Student s2;
		infile.read(reinterpret_cast<char*>(&s2), sizeof(Student));
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