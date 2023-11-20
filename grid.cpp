#include "grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Grid::Grid(int n) : size(n), moved(false), score(0) {
    board.assign(size, std::vector<int>(size, 0));
    srand(time(nullptr));
    addRandomTile();
    addRandomTile();
}
void Grid::addToScore(int value) {
    score += value;
}

int Grid::getScore() const {
    return score;
}


void Grid::display() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "Score: " << getScore() << std::endl;
}

void Grid::addRandomTile() {
    int countEmpty = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == 0) {
                countEmpty++;
            }
        }
    }

    if (countEmpty >= 2) {
        int indexes[2][2];
        int index = 0;
        while (index < 2) {
            int i = rand() % size;
            int j = rand() % size;
            if (board[i][j] == 0) {
                board[i][j] = 2;
                indexes[index][0] = i;
                indexes[index][1] = j;
                index++;
            }
        }
    }
}


void Grid::moveLeft() {
    moved = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size; ++j) {
            if (board[i][j] != 0) {
                int k = j - 1;
                while (k >= 0 && board[i][k] == 0) {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                    k--;
                    moved = true;
                }
                if (k >= 0 && board[i][k] == board[i][k + 1]) {
                    board[i][k] *= 2;
                    addToScore(board[i][k]); // Ajout de la valeur fusionnée au score
                    board[i][k + 1] = 0;
                    moved = true;
                    j = k + 1; // Met à jour la position de j après la fusion
                }
            }
        }
    }
}

void Grid::moveRight() {
    moved = false;
    for (int i = 0; i < size; ++i) {
        for (int j = size - 2; j >= 0; --j) {
            if (board[i][j] != 0) {
                int k = j + 1;
                while (k < size && board[i][k] == 0) {
                    board[i][k] = board[i][k - 1];
                    board[i][k - 1] = 0;
                    k++;
                    moved = true;
                }
                if (k < size && board[i][k] == board[i][k - 1]) {
                    board[i][k] *= 2;
                    addToScore(board[i][k]); // Ajout de la valeur fusionnée au score
                    board[i][k - 1] = 0;
                    moved = true;
                    j = k - 1; // Met à jour la position de j après la fusion
                }
            }
        }
    }
}

void Grid::moveUp() {
    moved = false;
    for (int j = 0; j < size; ++j) {
        for (int i = 1; i < size; ++i) {
            if (board[i][j] != 0) {
                int k = i - 1;
                while (k >= 0 && board[k][j] == 0) {
                    board[k][j] = board[k + 1][j];
                    board[k + 1][j] = 0;
                    k--;
                    moved = true;
                }
                if (k >= 0 && board[k][j] == board[k + 1][j]) {
                    board[k][j] *= 2;
                    addToScore(board[k][j]); // Ajout de la valeur fusionnée au score
                    board[k + 1][j] = 0;
                    moved = true;
                    i = k + 1; // Met à jour la position de i après la fusion
                }
            }
        }
    }
}

void Grid::moveDown() {
    moved = false;
    for (int j = 0; j < size; ++j) {
        for (int i = size - 2; i >= 0; --i) {
            if (board[i][j] != 0) {
                int k = i + 1;
                while (k < size && board[k][j] == 0) {
                    board[k][j] = board[k - 1][j];
                    board[k - 1][j] = 0;
                    k++;
                    moved = true;
                }
                if (k < size && board[k][j] == board[k - 1][j]) {
                    board[k][j] *= 2;
                    addToScore(board[k][j]); // Ajout de la valeur fusionnée au score
                    board[k - 1][j] = 0;
                    moved = true;
                    i = k - 1; // Met à jour la position de i après la fusion
                }
            }
        }
    }
}


bool Grid::hasMoved() const {
    return moved;
}

bool Grid::checkWin() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == 2048) {
                return true;
            }
        }
    }
    return false;
}

