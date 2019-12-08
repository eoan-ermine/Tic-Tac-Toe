#include "../include/TicTacToe.h"

#include <array>
#include <algorithm>

std::ostream& operator<<(std::ostream& stream, const fieldState& lhs) {
    switch(lhs) {
        case fieldState::NONE:
            stream << "N";
            break;
        case fieldState::CROSS:
            stream << "X";
            break;
        case fieldState::ZERO:
            stream << "O";
            break;
    }
    return stream;
}

TicTacToe::TicTacToe() : countOfRows(3), countOfColumns(3), movesCounter(0), over(false) {
    gameField.resize(countOfColumns * countOfColumns, fieldState::NONE);
}

bool TicTacToe::isWinAfter(int row, int column) const noexcept {
    fieldState currentState = gameField[row * countOfColumns + column];
    
    bool columnTest = true, rowTest = true;
    
    for(int currentColumn = 0; currentColumn < countOfColumns; ++currentColumn) {
        if(gameField[row * countOfColumns + currentColumn] != currentState) {
            columnTest = false;
            break;
        }
    }
    
    for(int currentRow = 0; currentRow < countOfRows; ++currentRow) {
        if(gameField[currentRow * countOfColumns + column] != currentState) {
            rowTest = false;
            break;
        }
    }
    
    std::array<fieldState, 3> firstDiagonal = {{gameField[0], gameField[4], gameField[8]}};
    std::array<fieldState, 3> secondDiagonal = {{gameField[2], gameField[4], gameField[6]}};
    
    auto predicate = [currentState](const fieldState& lhs) {
        return lhs == currentState;
    };
    
    bool diagonalTest = std::all_of(firstDiagonal.begin(), firstDiagonal.end(), predicate) || std::all_of(secondDiagonal.begin(), secondDiagonal.end(), predicate);
    
    return columnTest || rowTest || diagonalTest;
}

void TicTacToe::setState(fieldState state, int row, int column) {
    if(row > countOfRows || column > countOfColumns) {
        return;
    }
    
    row -= 1;
    column -= 1;
    movesCounter += 1;
    
    gameField[row * countOfColumns + column] = state;
    if(isWinAfter(row, column)) {
        over = true;
    }
}

void TicTacToe::drawField() const noexcept {
    for(int row = 0; row < countOfRows; ++row) {
        std::cout << "|";
        for(int column = 0, end = countOfColumns - 1; column < countOfColumns; ++column) {
            std::cout << gameField[row * countOfColumns + column];
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool TicTacToe::isOver() const noexcept{
    return over;
}

int TicTacToe::getStep() const noexcept{
    return movesCounter;
}