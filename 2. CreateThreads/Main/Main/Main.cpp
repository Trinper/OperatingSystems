#define max(a,b)(((a) > (b)) ? (a) : (b))
#define min(a,b)(((a) < (b)) ? (a) : (b))
#include <Windows.h>
#include <iostream>
#include <algorithm>

int n = 0;
int* arr = nullptr;
int Max = INT_MIN;
int Min = INT_MAX;
int sumEl = 0;
double half = 0;

CRITICAL_SECTION cs;

DWORD WINAPI extremum(LPVOID) {
	for (int i = 0; i < n; i++) {
		Max = max(Max, arr[i]);
		Sleep(10);
		Min = min(Min, arr[i]);
		Sleep(10);
	}
	EnterCriticalSection(&cs);
	std::cout << "Min: " << Min << "\n";
	std::cout << "Max: " << Max << "\n";
	LeaveCriticalSection(&cs);

	return 0;
}

DWORD WINAPI average(LPVOID) {
	for (int i = 0; i < n; i++) {
		sumEl += arr[i];
		Sleep(10);
	}
	half = (double)sumEl / n;
	EnterCriticalSection(&cs);
	std::cout << "Average:" << half << "\n";
	LeaveCriticalSection(&cs);

	return 0;
}

int main() {
	HANDLE extremum_hThread;
	DWORD extremum_IDThread;

	HANDLE average_hThread;
	DWORD average_IDThread;
}

