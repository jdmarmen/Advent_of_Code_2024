#include "InputFiles/InputFiles.hpp"
#include "Hash_Table/hash_table.h"
#include <sstream>
#include <iostream>
#include <algorithm>

// Función que verifica si una línea puede ser construida con los patrones disponibles
bool canConstruct(const std::string &line, HashTable &hashTable) {
    int n = line.size();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && hashTable.searchItem(line.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

// Función que elimina espacios y llama a canConstruct
bool canConstructIgnoringSpaces(const std::string &line, HashTable &hashTable) {
    std::string cleanedLine;
    for (char c : line) {
        if (c != ' ') {
            cleanedLine += c;
        }
    }
    return canConstruct(cleanedLine, hashTable);
}

// Función para leer y almacenar los patrones en la tabla hash
void readPatterns(std::ifstream &file, HashTable &hashTable) {
    std::string linea = InputFiles::read_line(&file);
    std::istringstream iss(linea);
    std::string trozo;

    while (std::getline(iss, trozo, ',')) {
        // Eliminar espacios en blanco alrededor de los trozos
        trozo.erase(std::remove(trozo.begin(), trozo.end(), ' '), trozo.end());
        hashTable.insertItem(trozo);
    }
}

// Función para verificar las líneas del archivo
int verifyLines(std::ifstream &file, HashTable &hashTable) {
    int posibles = 0;
    std::vector<std::string> lines = InputFiles::read_lines(&file);

    for (const auto& line : lines) {
        if (line.empty()) {
            continue;
        }
        if (canConstructIgnoringSpaces(line, hashTable)) {
            std::cout << line << " -> Posible" << std::endl;
            posibles++;
        } else {
            std::cout << line << " -> Imposible" << std::endl;
        }
    }

    return posibles;
}

int main() {
    std::ifstream file{};
    std::string path = "../Day_19/day_19_puzzle.txt";
    InputFiles::open_file(&path, &file);

    HashTable hashTable(1000); // Crear una tabla hash con 1000 cubetas

    // Leer la primera línea y almacenar los trozos en la tabla hash
    readPatterns(file, hashTable);

    // Leer el resto del archivo y verificar cada línea
    int posibles = verifyLines(file, hashTable);

    InputFiles::close_file(&file);

    std::cout << "Número de líneas posibles: " << posibles << std::endl;

    return 0;
}