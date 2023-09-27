#include "..//Creator/Employee.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>


void fileReader(std::ifstream &file, std::vector<Employee> &employees) {
	Employee emp;
	if (file.is_open()) {
		while (!file.eof()) {
			file.read((char*)&emp, sizeof(Employee));
			employees.push_back(emp);
		}
		employees.pop_back();
	}
	else {
		std::cout << "File not open";
	}
}
void fileWriter(std::ofstream &file, int salary_for_hour,  std::vector<Employee> &employees) {
	if (file.is_open()) {

		for (int i = 0; i < employees.size(); i++)
		{
			file << "Number: " << employees[i].num << " Name: " << employees[i].name << " Hours: " << employees[i].hours << " Salary: " << salary_for_hour * employees[i].hours << "\n";
		}
	} 
	else {
		std::cout << "File not open";
	}
}
int main(int argc, char* argv[]) {
	Employee emp;
	std::string input_name = argv[1];
	std::string output_name = argv[2];
	int salary_for_hour = std::stoi(argv[3]);
	std::ifstream file_input;
	std::ofstream file_output;
	std::vector<Employee> employees;

	file_input.open(input_name, std::ios::binary);
	fileReader(file_input, employees);
	file_input.close();

	file_output.open(output_name);
	fileWriter(file_output, salary_for_hour, employees);
	file_output.close();
	Sleep(100);
	return 0;
}