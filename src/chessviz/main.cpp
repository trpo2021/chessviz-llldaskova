#include "libchessviz/chessviz.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 8;
    char** chessboard = new char*[n];
    for (int i = 0; i < n; i++) {
        chessboard[i] = new char[n];
    }

    default_cb(n, chessboard);
    print_cb(n, chessboard);
    printf("\n");
    file(n, chessboard);
    for (int i = 0; i < n; i++)
        delete chessboard[i];

    delete[] chessboard;
    chessboard = NULL;
    return 0;
}
