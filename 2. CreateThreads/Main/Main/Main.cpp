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
int half = 0;

CRITICAL_SECTION cs;

DWORD WINAPI min_max(LPVOID) {
	for (int i = 0; i < n; i++) {
		Max = max(Max, arr[i]);
		Sleep(7);
		Min = min(Min, arr[i]);
		Sleep(7);
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
		Sleep(12);
	}
	half = sumEl / n;
	EnterCriticalSection(&cs);
	std::cout << "Average:" << half << "\n";
	LeaveCriticalSection(&cs);

	return 0;
}
void cinArr() {
	std::cout << "N=: ";
	std::cin >> n;

	arr = new int[n];
	std::cout << "Elements of array: " << '\n';
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}
void swapExtremum() {
	for (int i = 0; i < n; i++) {
		if (arr[i] == Max || arr[i] == Min) {
			arr[i] = half;
		}
	}
}

void coutArr() {
	std::cout << "Result: ";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
}
int main() {
	HANDLE min_max_hThread;
	DWORD min_max_IDThread;

	HANDLE average_hThread;
	DWORD average_IDThread;

	InitializeCriticalSection(&cs);
	
	cinArr();

	min_max_hThread = CreateThread(NULL, 0, min_max, NULL, 0, &min_max_IDThread);
	average_hThread = CreateThread(NULL, 0, average, NULL, 0, &average_IDThread);

	WaitForSingleObject(min_max_hThread, INFINITE);
	WaitForSingleObject(average_hThread, INFINITE);

	swapExtremum();
	coutArr();

	DeleteCriticalSection(&cs);
	CloseHandle(min_max_hThread);
	CloseHandle(average_hThread);
	delete[] arr;
	return 0;
}

