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
int main()
{
	size_t size;
	cout << "Enter size of array: ";
	cin >> size;
	int* array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter" << i << " element of array:";
		cin >> array[i];
	}
	cout << "Your array:";
	printArray(array, size);
	size_t index;
	size_t value;
	cout << "Enter index of insertion to array:";
	cin >> index;
	cout << "Enter value to insert to array:";
	cin >> value;
	insertArray(array, size, index, value);
	cout << "Your inserted array:";
	printArray(array, size + 1);
	
	delete[] array;
	
	return 0;
}