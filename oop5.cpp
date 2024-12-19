#include <iostream>
using namespace std;
template <typename T>
void Sort(T* const array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            std::swap(array[i], array[minIndex]);
        }
    }
}

template <typename T>
void printArray(T* const array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Input and sort an integer array
    int intSize;
    std::cout << "Enter the number of integers: ";
    std::cin >> intSize;
    int* intArray = new int[intSize];
    
    std::cout << "Enter the integers: ";
    for (int i = 0; i < intSize; ++i) {
        std::cin >> intArray[i];
    }

    Sort(intArray, intSize);
    std::cout << "Sorted integers: ";
    printArray(intArray, intSize);
    
    delete[] intArray; // Free allocated memory

    // Input and sort a float array
    int floatSize;
    std::cout << "Enter the number of floats: ";
    std::cin >> floatSize;
    float* floatArray = new float[floatSize];
    
    std::cout << "Enter the floats: ";
    for (int i = 0; i < floatSize; ++i) {
        std::cin >> floatArray[i];
    }

    Sort(floatArray, floatSize);
    std::cout << "Sorted floats: ";
    printArray(floatArray, floatSize);
    
    delete[] floatArray; // Free allocated memory

    return 0;
}
