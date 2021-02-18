#include <iostream>
using namespace std;

int const n = 8;

void default_cb(char A[n][n])
{
    A[0][0] = 'r';
    A[0][1] = 'n';
    A[0][2] = 'b';
    A[0][3] = 'q';
    A[0][4] = 'k';
    A[0][5] = 'b';
    A[0][6] = 'n';
    A[0][7] = 'r';
    for (int i = 1; i == 1; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 'p';
        }
    }
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = ' ';
        }
    }
    for (int i = 6; i == 6; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 'P';
        }
    }
    A[7][0] = 'R';
    A[7][1] = 'N';
    A[7][2] = 'B';
    A[7][3] = 'Q';
    A[7][4] = 'K';
    A[7][5] = 'B';
    A[7][6] = 'N';
    A[7][7] = 'R';
}

void print_cb(char A[n][n])
{
    int k = 8;
    for (int i = 0; i < n; i++) {
        cout << " " << k << " ";
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        k--;
        cout << endl;
    }
    cout << "   ";
    cout << "a"
         << " ";
    cout << "b"
         << " ";
    cout << "c"
         << " ";
    cout << "d"
         << " ";
    cout << "e"
         << " ";
    cout << "f"
         << " ";
    cout << "g"
         << " ";
    cout << "h"
         << " ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char chessboard[n][n];
    default_cb(chessboard);
    print_cb(chessboard);

    return 0;
}
