#pragma once
#include <iostream>

class Graph {
private:
    struct Node {
        int vertex;
        Node* next;
    };

    struct AdjList {
        Node* head;
    };

    int numVertices;
    AdjList* adjLists;

    Node* createNode(int vertex);

public:
    Graph(int vertices);
    ~Graph();

    void addEdge(int src, int dest);
    void printGraph() const;
    bool isOrdered(int src, int dest) const;
};