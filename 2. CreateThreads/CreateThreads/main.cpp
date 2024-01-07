#include <Windows.h>
#include <algorithm>
#include "functions.h"

CRITICAL_SECTION cs;

DWORD WINAPI min_max(LPVOID) {
    for (int i = 0; i < n; i++) {
        Max = (Max < arr[i] ? arr[i] : Max);
        Sleep(7);
        Min = (Min > arr[i] ? arr[i] : Min);
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
