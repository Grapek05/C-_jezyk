#include <stdio.h>
#include <stdbool.h>

void showBoard(char board[3][3]);
void clearBoard(char board[3][3]);
bool isFinished(char board[3][3], char *winner);
bool setPoint(char board[3][3], unsigned int x, unsigned int y, char player);
void playerMove(char board[3][3], char player);
void printGameResult(char winner);

int main() {
    char board[3][3];
    char winner = ' ';
    bool gameFinished = false;

    clearBoard(board);

    while (!gameFinished) {
        showBoard(board);
        
        // Ruch gracza X
        playerMove(board, 'X');
        gameFinished = isFinished(board, &winner);
        if (gameFinished) break;

        showBoard(board);
        
        // Ruch gracza O
        playerMove(board, 'O');
        gameFinished = isFinished(board, &winner);
    }

    showBoard(board);
    printGameResult(winner);

    return 0;
}

void showBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

void clearBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

bool isFinished(char board[3][3], char *winner) {
    // Sprawdzanie wierszy
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            *winner = board[i][0];
            return true;
        }
    }

    // Sprawdzanie kolumn
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            *winner = board[0][j];
            return true;
        }
    }

    // Sprawdzanie przekątnych
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        *winner = board[0][0];
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        *winner = board[0][2];
        return true;
    }

    // Sprawdzanie, czy są wolne pola
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // Gra trwa
            }
        }
    }

    *winner = 'R';  // Remis
    return true;
}

bool setPoint(char board[3][3], unsigned int x, unsigned int y, char player) {
    if (board[x][y] == ' ') {
        board[x][y] = player;
        return true;
    }
    return false;
}

void playerMove(char board[3][3], char player) {
    unsigned int x, y;
    printf("Gracz %c, wybierz pole (wpisz x i y): ", player);
    scanf("%u %u", &x, &y);

    // Sprawdzamy, czy wybór jest poprawny
    while (x >= 3 || y >= 3 || !setPoint(board, x, y, player)) {
        printf("Nieprawidłowy ruch, spróbuj ponownie (wpisz x i y): ");
        scanf("%u %u", &x, &y);
    }
}

void printGameResult(char winner) {
    if (winner == 'R') {
        printf("Gra zakończona remisem!\n");
    } else {
        printf("Gratulacje! Zwycięzcą jest gracz %c!\n", winner);
    }
}
