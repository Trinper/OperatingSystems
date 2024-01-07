#pragma once

#include <iostream>

int n = 0;
int* arr = nullptr;
int Max = INT_MIN;
int Min = INT_MAX;
int sumEl = 0;
int half = 0;

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
