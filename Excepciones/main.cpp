#include <iostream>
#include <limits>
#include <regex>
#include <stdexcept>
#include <string>

void askAge(int &age);
void askMail(std::string &mail);

int main(void) {
    int age;
    std::string mail;

    try {
        askAge(age);
        std::cout << "Age is valid: " << age << '\n';
    } catch (const std::exception &e) {
        std::cout << "Invalid age: " << e.what() << '\n';
    }

    try {
        askMail(mail);
        std::cout << "Email is valid: " << mail << '\n';
    } catch (const std::exception &e) {
        std::cout << "Invalid email: " << e.what() << '\n';
    }

    return 0;
}

void askAge(int &age) {
    std::string answer;

    std::cout << "Please enter a valid age: ";
    std::cin >> answer;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        std::size_t position;
        int number = std::stoi(answer, &position);

        // Verifica que todo el string haya sido convertido.
        if (position != answer.length()) {
            throw std::invalid_argument("Age must be a number");
        }

        if (number < 0 || number > 150) {
            throw std::out_of_range("Age must be between 0 and 150");
        }

        age = number;
    } catch (const std::invalid_argument &) {
        throw std::invalid_argument("Age must be a number");
    } catch (const std::out_of_range &) {
        throw std::out_of_range("Age is out of range");
    }
}

void askMail(std::string &mail) {
    const std::regex pattern(
        "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

    std::string answer;

    std::cout << "Please enter a valid mail: ";
    std::cin >> answer;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (!std::regex_match(answer, pattern)) {
        throw std::runtime_error("Invalid email format");
    }

    mail = answer;
}
