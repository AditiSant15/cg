#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Step 1: Create an output file and write information to it
    std::ofstream outputFile("example.txt");
    if (!outputFile) {
        std::cerr << "Error creating the file!" << std::endl;
        return 1; // Return with an error code
    }

    // Writing some information to the file
    outputFile << "Hello, World!" << std::endl;
    outputFile << "This is a simple C++ program." << std::endl;
    outputFile << "File handling in C++ is straightforward." << std::endl;

    // Close the output file
    outputFile.close();

    // Step 2: Open the file again as an input file and read the information
    std::ifstream inputFile("example.txt");
    if (!inputFile) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1; // Return with an error code
    }

    // Reading the information from the file
    std::string line;
    std::cout << "Contents of the file:" << std::endl;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl; // Output the line read from the file
    }

    // Close the input file
    inputFile.close();

    return 0; // Successful completion
}
