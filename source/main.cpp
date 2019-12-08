#include "../include/TicTacToe.h"

int main() {
	int row, column;

	TicTacToe game;

	while(true) {
		game.drawField();
		if(game.isOver()) {
			std::cout << (game.getStep() % 2 == 0 ? "Second player has won!" : "First player has won!");
			break;
		}
		std::cout << "Enter a row and column, please: ";
		std::cin >> row >> column;
		game.getStep() % 2 == 0 ?  game.setState(fieldState::CROSS, row, column) : game.setState(fieldState::ZERO, row, column);
	}
}