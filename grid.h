#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
private:
    std::vector<std::vector<int>> board;
    int size;
    bool moved;
    int score;

public:
    Grid(int n);
    void display();
    void addRandomTile();
    void moveLeft();
    void moveUp();
    void moveDown();
    void moveRight();
    bool hasMoved() const;
    bool checkWin() const;
    void addToScore(int value);
    int getScore() const;
};

#endif /* GRID_H */
