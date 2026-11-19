#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void readFile(const std::string &filename);

int main(void) {
    try {
        readFile("datos.txt");
    } catch (const std::ios_base::failure &e) {
        std::cerr << "Error al acceder al archivo: " << e.what() << '\n';
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    std::cout << "El programa termino correctamente.\n";

    return 0;
}

void readFile(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo '" + filename +
                                 "'");
    }

    std::string line;

    std::cout << "Contenido del archivo:\n";

    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }

    if (file.bad()) {
        throw std::ios_base::failure(
            "Ocurrio un error mientras se leia el archivo");
    }

    file.close();
}
