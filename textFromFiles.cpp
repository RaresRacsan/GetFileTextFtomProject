#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    // change the name of the result file
    std::string outputFileName = "merged_files.txt";
    std::ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        std::cerr << "Failed to create the output file." << std::endl;
        return 1;
    }

    for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        if (entry.is_regular_file()) {
            std::string filePath = entry.path().string();
            std::string extension = entry.path().extension().string();
            // change the extensions for what you need
            if (extension == ".cpp" || extension == ".h") {
                std::ifstream inputFile(filePath);

                if (!inputFile.is_open()) {
                    std::cerr << "Failed to open file: " << filePath << std::endl;
                    continue;
                }

                std::string fileName = entry.path().filename().string();
                outputFile << "File: " << fileName << "\n";
                outputFile << std::string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
                outputFile << "\n\n";

                inputFile.close();
            }
        }
    }

    outputFile.close();
    std::cout << "All files have been merged into " << outputFileName << std::endl;

    return 0;
}
