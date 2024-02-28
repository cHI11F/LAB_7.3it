#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int Part1_Count(int** a, const int rowCount, const int colCount);
void Part2_SortByPositivePairsSum(int** a, const int rowCount, const int colCount);
unsigned int SumPositiveEvenElements(int* row, const int colCount);
void SwapRows(int** a, int row1, int row2, const int colCount);

int main() {
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    
    if (rowCount <= 0 || colCount <= 0) {
        cout << "Incorrect matrix dimensions!" << endl;
        return 1; 
    }

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    
    Create(a, rowCount, colCount, Low, High);

    Print(a, rowCount, colCount);
    int count = Part1_Count(a, rowCount, colCount);
    cout << "Number of columns without zero elements: " << count << endl;
    cout << endl;
    Part2_SortByPositivePairsSum(a, rowCount, colCount);
    cout << "Matrix after sorting by sum of positive even elements in rows:" << endl;
    Print(a, rowCount, colCount);
    cout << endl;
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount) {
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int Part1_Count(int** a, const int rowCount, const int colCount) {
    int count = 0;
    for (int j = 0; j < colCount; j++) {
        bool hasZero = false;
        for (int i = 0; i < rowCount; i++) {
            if (a[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero) {
            count++;
        }
    }
    return count;
}

unsigned int SumPositiveEvenElements(int* row, const int colCount) {
    unsigned int sum = 0;
    for (int j = 0; j < colCount; ++j)
        if (row[j] > 0 && row[j] % 2 == 0)
            sum += row[j];
    return sum;
}

void SwapRows(int** a, int row1, int row2, const int colCount) {
    for (int j = 0; j < colCount; ++j)
        swap(a[row1][j], a[row2][j]);
}

void Part2_SortByPositivePairsSum(int** a, const int rowCount, const int colCount) {
    unsigned int* sums = new unsigned int[rowCount]; 
    for (int i = 0; i < rowCount; ++i)
        sums[i] = SumPositiveEvenElements(a[i], colCount); 
    for (int i = 0; i < rowCount - 1; ++i)
        for (int j = 0; j < rowCount - i - 1; ++j)
            if (sums[j] > sums[j + 1]) 
                SwapRows(a, j, j + 1, colCount);
    delete[] sums; 
}
