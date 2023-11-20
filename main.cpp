#include "grid.h"
#include <iostream>

int main() {
    Grid gameGrid(4);
    gameGrid.display();

    char move;
    while (true) {
        std::cout << "Enter a move (ZQSD): ";
        std::cin >> move;

        if (move == 'Z' || move == 'z') {
            gameGrid.moveUp();
        } else if (move == 'S' || move == 's') {
            gameGrid.moveDown();
        } else if (move == 'Q' || move == 'q') {
            gameGrid.moveLeft();
        } else if (move == 'D' || move == 'd') {
            gameGrid.moveRight();
        } else {
            std::cout << "Invalid move! Please enter Z, Q, S, or D." << std::endl;
            continue;
        }

        if (gameGrid.hasMoved()) {
            gameGrid.addRandomTile();
            gameGrid.display();
            if (gameGrid.checkWin()) {
                std::cout << "Congratulations! You have reached 2048. You win!" << std::endl;
                break;
            }
        } else {
            std::cout << "No valid moves left! Game Over." << std::endl;
            break;
        }

        // Ajouter des conditions de fin de jeu (par exemple, atteindre 2048)

        // Debug pour voir s'il reste bloqué dans la boucle
        std::cout << "Debug: Loop iteration completed." << std::endl;
    }

    return 0;
}