#include <iostream>
#include <sqlite3.h>

int main(void) {
    sqlite3 *database;

    if (sqlite3_open("tareas.db", &database) != SQLITE_OK) {
        std::cerr << "Could not open database\n";
        return 1;
    }

    const char *create_table = "CREATE TABLE IF NOT EXISTS tareas ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                               "nombre TEXT NOT NULL"
                               ");";

    char *error_message = nullptr;

    if (sqlite3_exec(database,
                     create_table,
                     nullptr,
                     nullptr,
                     &error_message) != SQLITE_OK) {
        std::cerr << "Error creating table: " << error_message << '\n';

        sqlite3_free(error_message);
        sqlite3_close(database);
        return 1;
    }

    const char *insert = "INSERT INTO tareas (nombre) "
                         "VALUES ('Estudiar C++');";

    if (sqlite3_exec(database, insert, nullptr, nullptr, &error_message) !=
        SQLITE_OK) {
        std::cerr << "Error inserting task: " << error_message << '\n';

        sqlite3_free(error_message);
        sqlite3_close(database);
        return 1;
    }

    std::cout << "Task inserted successfully\n";

    const char *query = "SELECT id, nombre FROM tareas;";

    sqlite3_stmt *statement;

    if (sqlite3_prepare_v2(database, query, -1, &statement, nullptr) !=
        SQLITE_OK) {
        std::cerr << "Error preparing query\n";
        sqlite3_close(database);
        return 1;
    }

    std::cout << "\nTasks:\n";

    while (sqlite3_step(statement) == SQLITE_ROW) {
        int id = sqlite3_column_int(statement, 0);
        const char *name =
            reinterpret_cast<const char *>(sqlite3_column_text(statement, 1));

        std::cout << id << ". " << name << '\n';
    }

    sqlite3_finalize(statement);
    sqlite3_close(database);

    return 0;
}
