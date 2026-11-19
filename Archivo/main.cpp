#include <fstream>
#include <iostream>
#include <string>

void writeTasks();
void readTasks();

int main(void) {
    int option;

    std::cout << "1. Write tasks\n";
    std::cout << "2. Read tasks\n";
    std::cout << "Choose an option: ";
    std::cin >> option;

    if (option == 1) {
        writeTasks();
    } else if (option == 2) {
        readTasks();
    } else {
        std::cout << "Invalid option\n";
    }

    return 0;
}

void writeTasks() {
    std::ofstream file("hola.txt");

    if (!file.is_open()) {
        std::cout << "Could not open file\n";
        return;
    }

    std::string tasks[5] = {"Study C++",
                            "Do homework",
                            "Practice programming",
                            "Read a book",
                            "Go for a walk"};

    for (const std::string &task : tasks) {
        file << task << '\n';
    }

    file.close();

    std::cout << "Tasks saved successfully\n";
}

void readTasks() {
    std::ifstream file("hola.txt");

    if (!file.is_open()) {
        std::cout << "Could not open file\n";
        return;
    }

    std::string task;

    std::cout << "\nTasks:\n";

    while (std::getline(file, task)) {
        std::cout << "- " << task << '\n';
    }

    file.close();
}
