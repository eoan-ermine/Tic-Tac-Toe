#include <iostream>
#include <vector>
#include <cstdlib>

enum class fieldState: uint8_t { NONE, CROSS, ZERO};

class TicTacToe {
private:
    std::vector<fieldState> gameField;
    int countOfRows, countOfColumns, movesCounter;
    bool over;
public:
    TicTacToe();
    bool isWinAfter(int, int) const noexcept;
    void setState(fieldState, int, int);
    void drawField() const noexcept;
    bool isOver() const noexcept;
    int getStep() const noexcept;
};