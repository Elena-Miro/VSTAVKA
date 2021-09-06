#include <iostream>
using namespace std;
void printArray(const int array[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		cout << array[i] << " ";
}
void insertArray(int** array, size_t size, size_t index, int value)
{
	int* copy = new int[size + 1];
	for (size_t i = 0; i < index; i++)
		copy[i] = (*array)[i];
	copy[index] = value;
	for (size_t i = index + 1; i <= size; i++)
		copy[i] = (*array)[i - 1];
	delete[] * array;
	*array = copy;
}
void printMatrix(int** matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    size_t rows;
    cout << "Enter amount of rows in matrix: ";
    cin >> rows;
    size_t columns;
    cout << "Enter amount of columns in matrix: ";
    cin >> columns;
    int** matrix = new int* [rows];
    for (size_t i = 0; i < rows; i++)
        matrix[i] = new int[columns];
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
        {
            cout << "Enter " << j << " element of " << i << " row: ";
            cin >> matrix[i][j];
        }
    printMatrix(matrix, rows, columns);
    for (size_t i = 0; i < rows; i++)
        delete matrix[i];
    delete[] matrix;
    return 0;
}