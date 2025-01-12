#include "InputFiles/InputFiles.hpp"
#include "Graph/graph.hpp"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

void readEdges(std::ifstream& file, Graph& graph) {
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        if (line.find('|') != std::string::npos) {
            int src = 0, dest = 0;
            sscanf(line.c_str(), "%d|%d", &src, &dest);
            graph.addEdge(src, dest);
        }
    }
}

std::vector<std::vector<int>> readCommaSeparatedLines(std::ifstream& file) {
    std::vector<std::vector<int>> commaLines;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        if (line.find(',') != std::string::npos) {
            std::vector<int> numbers;
            std::stringstream ss(line);
            std::string number;
            while (std::getline(ss, number, ',')) {
                numbers.push_back(std::stoi(number));
            }
            commaLines.push_back(numbers);
        }
    }
    return commaLines;
}

int calculateSumOfMiddles(const std::vector<std::vector<int>>& commaLines, const Graph& graph) {
    int sumOfMiddles = 0;

    for (const auto& line : commaLines) {
        bool isLineOrdered = true;
        for (size_t i = 0; i < line.size() - 1; ++i) {
            if (!graph.isOrdered(line[i], line[i + 1])) {
                isLineOrdered = false;
                break;
            }
        }
        if (isLineOrdered) {
            int middleIndex = line.size() / 2;
            int middleValue = line[middleIndex];
            sumOfMiddles += middleValue;
            std::cout << "La línea ";
            for (const auto& num : line) {
                std::cout << num << " ";
            }
            std::cout << "está ordenada correctamente." << std::endl;
        } else {
            std::cout << "La línea ";
            for (const auto& num : line) {
                std::cout << num << " ";
            }
            std::cout << "no está ordenada correctamente." << std::endl;
        }
    }

    return sumOfMiddles;
}

int main() {
    std::ifstream file;
    std::string path = "../Day_5/day_5_puzzle.txt";
    if (InputFiles::open_file(&path, &file) != 0) {
        return 1;
    }

    // Suponiendo que conocemos el número de vértices de antemano
    int numVertices = 100; // Ajusta este valor según sea necesario
    Graph graph(numVertices);

    // Leer y agregar aristas al grafo
    readEdges(file, graph);

    // Volver al inicio del archivo para leer las líneas separadas por comas
    file.clear();
    file.seekg(0, std::ios::beg);

    // Leer las líneas separadas por comas
    std::vector<std::vector<int>> commaLines = readCommaSeparatedLines(file);

    InputFiles::close_file(&file);

    graph.printGraph();

    // Calcular la suma de los valores del medio de las líneas ordenadas correctamente
    int sumOfMiddles = calculateSumOfMiddles(commaLines, graph);

    std::cout << "La suma de los valores del medio de las líneas ordenadas correctamente es: " << sumOfMiddles << std::endl;

    return 0;
}