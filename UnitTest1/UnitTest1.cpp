#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_7.3it/LAB_7.3it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(Test_Part1_Count)
        {
            int rowCount = 3;
            int colCount = 3;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; ++i)
                matrix[i] = new int[colCount];
            matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 0;
            matrix[1][0] = 1; matrix[1][1] = 5; matrix[1][2] = 6; 
            matrix[2][0] = 7; matrix[2][1] = 0; matrix[2][2] = 9;
            Assert::AreEqual(1, Part1_Count(matrix, rowCount, colCount));
            for (int i = 0; i < rowCount; ++i)
                delete[] matrix[i];
            delete[] matrix;
        }

        TEST_METHOD(Test_Part2_SortByPositivePairsSum)
        {
            int rowCount = 3;
            int colCount = 3;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; ++i)
                matrix[i] = new int[colCount];
            matrix[0][0] = 7; matrix[0][1] = 1; matrix[0][2] = 9;
            matrix[1][0] = 0; matrix[1][1] = 5; matrix[1][2] = 6;
            matrix[2][0] = 2; matrix[2][1] = 4; matrix[2][2] = -1; 
            Part2_SortByPositivePairsSum(matrix, rowCount, colCount);
            Assert::AreEqual(7, matrix[0][0]);
            Assert::AreEqual(1, matrix[0][1]);
            Assert::AreEqual(9, matrix[0][2]);
            Assert::AreEqual(0, matrix[1][0]);
            Assert::AreEqual(5, matrix[1][1]);
            Assert::AreEqual(6, matrix[1][2]);
            Assert::AreEqual(2, matrix[2][0]);
            Assert::AreEqual(4, matrix[2][1]);
            Assert::AreEqual(-1, matrix[2][2]);
            for (int i = 0; i < rowCount; ++i)
                delete[] matrix[i];
            delete[] matrix;
        }
    };
}
