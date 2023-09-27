#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>
#include "..//Creator/Employee.h"
#include <conio.h>


int main()
{
	std::string binary_name;
	std::string txt_name;
	std::string amount_of_notes;
	std::ifstream input_name;
	std::ifstream output_name;
	std::string pay_for_hour;
	std::vector<Employee> employees;
	Employee emp;

	std::cout << "Enter name of binary file ";
	std::cin >> binary_name;
	std::cout << "Enter amount of notes ";
	std::cin >> amount_of_notes;

	std::string creator_exe = "Creator.exe " + binary_name + " " + amount_of_notes;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	si.cb = sizeof(STARTUPINFO);

	if (!CreateProcess(NULL, const_cast<char*>(creator_exe.c_str()), NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		std::cout << "The Creator process is not running.\n";
		return GetLastError();
	}
	WaitForSingleObject(pi.hProcess, INFINITE);

	input_name.open(binary_name, std::ios::binary);
	if (input_name.is_open()) {
		while (!input_name.eof()) {
			input_name.read((char*)&emp, sizeof(Employee));
			employees.push_back(emp);
		}
		employees.pop_back();
	}

	for (int i = 0; i < employees.size(); i++)
	{
		std::cout << "Number: " << employees[i].num << " |Name: " << employees[i].name << " |Hours: " << employees[i].hours << "\n";
	}

	std::cout << "Enter name of the report file ";
	std::cin >> txt_name;
	std::cout << "Enter pay per our ";
	std::cin >> pay_for_hour;

	std::string reporter_exe = "Reporter.exe " + binary_name + " " + txt_name + " " + pay_for_hour;

	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	si.cb = sizeof(STARTUPINFO);

	if (!CreateProcess(NULL, const_cast<char*>(reporter_exe.c_str()), NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		std::cout << "The Reporter process is not running.\n";
		return GetLastError();
	}
	WaitForSingleObject(pi.hProcess, INFINITE);


	output_name.open(txt_name);
	if (output_name.is_open()) {
		while (!output_name.eof()) {
			std::string temporary;
			std::getline(output_name, temporary);
			std::cout << temporary << "\n";
		}
	}
	output_name.close();

	_getch();
	TerminateProcess(pi.hProcess, 1);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	_getch();
	return 0;
}