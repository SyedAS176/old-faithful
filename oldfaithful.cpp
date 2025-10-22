#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::string filepath = "C:/Users/smabd/OneDrive/Desktop/CSC122 Assignments/In Class/old_faithful.csv";

    std::ifstream file(filepath); // Creating an ifstream object named "file"
                                  // and opening the file located at "filepath"

    if (!file.is_open()) { // This line checks if the file opened correctly
        std::cerr << "Failed to open file: " << filepath << "\n"; // Using "cerr" since I looked at C++ documentation
        return -1;
    }

    std::string line;
    double totalEruption = 0.0;
    double totalWait = 0.0;
    int count = 0;

    // Read header line (eruptions & waiting) this just skips the very top row
    std::getline(file, line);

    while (std::getline(file, line)) { // Loop over each line
        std::stringstream ss(line);          // Creating a stream from line for parsing information
        std::string eruptionStr, waitStr;

        if (!std::getline(ss, eruptionStr, ',') || !std::getline(ss, waitStr, ',')) {
            continue; // Skips the current iteration since we do not need commas
        }

        double eruption = std::stod(eruptionStr);
        double wait = std::stod(waitStr);

        totalEruption += eruption;
        totalWait += wait;
        count++;
    }

    file.close();

    double avgEruption = totalEruption / count;
    double avgWait = totalWait / count;

    std::cout << "The average eruption length is " << avgEruption << " minutes.\n";
    std::cout << "The average eruption wait time is " << avgWait << " minutes.\n";

    return 0;
}