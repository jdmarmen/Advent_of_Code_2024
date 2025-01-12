#include "graph.hpp"
#include <iostream>

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new AdjList[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjLists[i].head = nullptr;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjLists[i].head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjLists;
}

Graph::Node* Graph::createNode(int vertex) {
    Node* newNode = new Node;
    newNode->vertex = vertex;
    newNode->next = nullptr;
    return newNode;
}

void Graph::addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjLists[src].head;
    adjLists[src].head = newNode;
}

void Graph::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjLists[i].head;
        std::cout << i << ": ";
        while (current) {
            std::cout << current->vertex << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

bool Graph::isOrdered(int src, int dest) const {
    Node* current = adjLists[src].head;
    while (current) {
        if (current->vertex == dest) {
            return true;
        }
        current = current->next;
    }
    return false;
}