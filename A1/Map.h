#pragma once
#include <iostream>

class Map {
private:
    bool** adjMatrix;
    int numVertices;
    
public:
    
    Map(int);
    ~Map();

    void addEdge(int, int);

    void removeEdge(int, int);

    void toString();

    void traverse(int, bool*);

    bool Validate();
};


