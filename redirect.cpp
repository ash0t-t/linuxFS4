#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <fcntl.h>

void initialize(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input file provided.\n";
        exit(1);
    }

    int fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor < 0) {
        std::cerr << "Error: Unable to open file " << argv[1] << ".\n";
        exit(2);
    }

    if (dup2(fileDescriptor, STDIN_FILENO) < 0) {
        std::cerr << "Error: Failed to redirect.\n";
        close(fileDescriptor);
        exit(3);
    }
    
    close(fileDescriptor);
}

int main(int argc, char** argv) {
    initialize(argc, argv);

    std::string input;
    std::cin >> input;

    std::string reversed(input.rbegin(), input.rend());

    std::cout << reversed << std::endl;

    return 0;
}
