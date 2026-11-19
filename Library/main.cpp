#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(void) {
    json task;

    task["id"] = 1;
    task["name"] = "Study C++";
    task["completed"] = false;

    std::cout << "Task:\n";
    std::cout << "ID: " << task["id"] << '\n';
    std::cout << "Name: " << task["name"] << '\n';
    std::cout << "Completed: " << std::boolalpha << task["completed"] << '\n';

    std::cout << "\nJSON:\n";
    std::cout << task.dump(4) << '\n';

    return 0;
}
