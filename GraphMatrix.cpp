#include "GraphMatrix.hpp"

GraphMatrix::GraphMatrix(int numV, GType type) : Graph(numV, 0, type) {
    adjMatrix = new bool*[numV];
    for (int i = 0; i < numV; i++) {
        adjMatrix[i] = new bool[numV];
        for (int j = 0; j < numV; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

GraphMatrix::~GraphMatrix() {
    for (int i = 0; i < v; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

bool GraphMatrix::isEdge(int i, int j) const {
    if (i < 0 || i >= v || j < 0 || j >= v) {
        return false;
    }
    return adjMatrix[i][j];
}

ostream& GraphMatrix::print(ostream& os) const {
    os << "    ";
    for (int i = 0; i < v; i++) {
        os << i << ' ';
    }
    os << endl;

    os << "---";
    for (int i = 0; i < v; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < v; i++) {
        os << i << " | ";
        for (int j = 0; j < v; j++) {
            os << adjMatrix[i][j] << ' ';
        }
        os << endl;
    }

    return os;
}

void GraphMatrix::toggleEdge(int i, int j) {
    if (i < 0 || i >= v || j < 0 || j >= v) {
        return;
    }
    adjMatrix[i][j] = !adjMatrix[i][j];
    if (graphType == UNDIRECTED) {
        adjMatrix[j][i] = adjMatrix[i][j];
    }
}