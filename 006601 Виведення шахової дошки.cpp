#include <iostream>

class ChessBoard;

class Display {
private:
    bool v_boardForWhite;

public:
    Display(bool boardForWhite = true) : v_boardForWhite(boardForWhite) {}

    void displayBoard(ChessBoard& board);
};

class ChessBoard {
private:
    char board[8][8];

public:
    ChessBoard() {
        initializeBoard();
    }

    void initializeBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = ' ';
            }
        }

        board[0][0] = 'R';
        board[0][1] = 'N';
        board[0][2] = 'B';
        board[0][3] = 'Q';
        board[0][4] = 'K';
        board[0][5] = 'B';
        board[0][6] = 'N';
        board[0][7] = 'R';

        board[7][0] = 'R';
        board[7][1] = 'N';
        board[7][2] = 'B';
        board[7][3] = 'Q';
        board[7][4] = 'K';
        board[7][5] = 'B';
        board[7][6] = 'N';
        board[7][7] = 'R';

        board[1][0] = 'P';
        board[1][1] = 'P';
        board[1][2] = 'P';
        board[1][3] = 'P';
        board[1][4] = 'P';
        board[1][5] = 'P';
        board[1][6] = 'P';
        board[1][7] = 'P';

        board[6][0] = 'P';
        board[6][1] = 'P';
        board[6][2] = 'P';
        board[6][3] = 'P';
        board[6][4] = 'P';
        board[6][5] = 'P';
        board[6][6] = 'P';
        board[6][7] = 'P';
    }

    void displayBoard(Display& display) {
        display.displayBoard(*this);
    }

    friend class Display;
};

void Display::displayBoard(ChessBoard& board) {
    std::cout << "Chessboard for the ";
    if (v_boardForWhite) {
        std::cout << "white player:\n";
    }
    else {
        std::cout << "black player:\n";
    }

    std::cout << "  ";
    if (v_boardForWhite) {
        for (char c = 'a'; c <= 'h'; ++c) {
            std::cout << c << " ";
        }
    }
    else {
        for (char c = 'h'; c >= 'a'; --c) {
            std::cout << c << " ";
        }
    }
    std::cout << '\n';

    if (v_boardForWhite) {
        for (int i = 0; i < 8; ++i) {
            std::cout << 8 - i << " ";
            for (int j = 0; j < 8; ++j) {
                std::cout << board.board[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
    else {
        for (int i = 0; i < 8; ++i) {
            std::cout << i + 1 << " ";
            for (int j = 7; j >= 0; --j) {
                std::cout << board.board[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
}

int main() {
    ChessBoard chessBoard;
    Display displayForWhite(true);
    Display displayForBlack(false);

    chessBoard.displayBoard(displayForWhite);

    std::cout << std::endl;

    chessBoard.displayBoard(displayForBlack);

    return 0;
}
