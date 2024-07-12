#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    // change the name of the result file
    std::string outputFileName = "merged_files.txt";
    // creating an output file
    std::ofstream outputFile(outputFileName);

    // failed to create
    if (!outputFile.is_open()) {
        std::cerr << "Failed to create the output file." << std::endl;
        return 1;
    }

    // this file's name
    std::string currentSourceFile = "textFromFiles.cpp";

    // parsing the files from the current directory
    for (const auto& entry : fs::directory_iterator(fs::current_path())) {\
        // is a normal file
        if (entry.is_regular_file()) {
            std::string filePath = entry.path().string();
            std::string fileName = entry.path().filename().string();
            std::string extension = entry.path().extension().string();
            // change the extensions for what you need
            if (fileName != currentSourceFile && (extension == ".cpp" || extension == ".h")) {
                std::ifstream inputFile(filePath);

                // can't open the file in order to get the content
                if (!inputFile.is_open()) {
                    std::cerr << "Failed to open file: " << filePath << std::endl;
                    continue;
                }

                // printing the content of a file into the final file
                std::string fileName = entry.path().filename().string();
                outputFile << "File: " << fileName << "\n";
                outputFile << std::string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
                outputFile << "\n\n";

                inputFile.close();
            }
        }
    }

    outputFile.close();
    // success
    std::cout << "All files have been merged into " << outputFileName << std::endl;

    return 0;
}
