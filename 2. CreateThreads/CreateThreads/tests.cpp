#include <gtest/gtest.h>
#include "functions.h"

// Тесты для функции cinArr()

TEST(ArrayFunctionsTest, CinArr_InputValidValues) {
    std::istringstream input("3\n1 2 3\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    cinArr();

    ASSERT_EQ(arr[0], 1);
    ASSERT_EQ(arr[1], 2);
    ASSERT_EQ(arr[2], 3);

    std::cin.rdbuf(oldCin);
}

TEST(ArrayFunctionsTest, CinArr_InputZeroElements) {
    std::istringstream input("0\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    cinArr();

    ASSERT_EQ(n, 0);

    std::cin.rdbuf(oldCin);
}

TEST(ArrayFunctionsTest, CinArr_InputNegativeElements) {
    std::istringstream input("4\n-1 -2 -3 -4\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    cinArr();

    ASSERT_EQ(arr[0], -1);
    ASSERT_EQ(arr[1], -2);
    ASSERT_EQ(arr[2], -3);
    ASSERT_EQ(arr[3], -4);

    std::cin.rdbuf(oldCin);
}

// Тесты для функции swapExtremum()

TEST(ArrayFunctionsTest, SwapExtremum_SwapMaxValue) {
    n = 5;
    arr = new int[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 5;
    Max = 5;
    Min = 1;
    half = 10;

    swapExtremum();

    ASSERT_EQ(arr[0], 10);
    ASSERT_EQ(arr[1], 2);
    ASSERT_EQ(arr[2], 3);
    ASSERT_EQ(arr[3], 10);
    ASSERT_EQ(arr[4], 10);

    delete[] arr;
}

TEST(ArrayFunctionsTest, SwapExtremum_SwapMinValue) {
    n = 4;
    arr = new int[4];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 2;
    Max = 3;
    Min = 0;
    half = 2;

    swapExtremum();

    ASSERT_EQ(arr[0], 2);
    ASSERT_EQ(arr[1], 1);
    ASSERT_EQ(arr[2], 2);
    ASSERT_EQ(arr[3], 2);

    delete[] arr;
}

TEST(ArrayFunctionsTest, SwapExtremum_NoExtremumValues) {
    n = 3;
    arr = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    Max = 10;
    Min = 0;
    half = -1;

    swapExtremum();

    ASSERT_EQ(arr[0], 1);
    ASSERT_EQ(arr[1], 2);
    ASSERT_EQ(arr[2], 3);

    delete[] arr;
}

// Тесты для функции coutArr()

TEST(ArrayFunctionsTest, CoutArr_OutputValidResult) {
    n = 4;
    arr = new int[4];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    coutArr();

    std::string result = output.str();

    ASSERT_EQ(result, "Result: 1 2 3 4 ");

    std::cout.rdbuf(oldCout);

    delete[] arr;
}

TEST(ArrayFunctionsTest, CoutArr_OutputEmptyResult) {
    n = 0;
    arr = nullptr;

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    coutArr();

    std::string result = output.str();

    ASSERT_EQ(result, "Result: ");

    std::cout.rdbuf(oldCout);
}

TEST(ArrayFunctionsTest, CoutArr_OutputNegativeResult) {
    n = 5;
    arr = new int[5];
    arr[0] = -1;
    arr[1] = -2;
    arr[2] = -3;
    arr[3] = -4;
    arr[4] = -5;

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    coutArr();

    std::string result = output.str();

    ASSERT_EQ(result, "Result: -1 -2 -3 -4 -5 ");

    std::cout.rdbuf(oldCout);

    delete[] arr;
}