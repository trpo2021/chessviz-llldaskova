#include "chessviz.h"
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
//поле с фигурами
void default_cb(int n, char** A)
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
//вывод поля
void print_cb(int n, char** A)
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
    char M[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    cout << "   ";
    for (int i = 0; i < 8; i++) {
        cout << M[i] << " ";
    }
}

void act(int* P, char** CH, int n)
{
    int er[6];
    int i, j, i1, j1, i2, j2, i3, j3;
    for (int i = 0; i < 6; i++) {
        er[i] = 0;
    }
    i = abs(P[2] - 56); //цифра
    j = P[1] - 97;      //буква
    if (CH[i][j] != P[0]) {
        er[0] = 1;
    }
    i1 = abs(P[5] - 56); //цифра
    j1 = P[4] - 97;      //буква

    if (P[3] == '-' && CH[i1][j1] == ' ') {
        CH[i1][j1] = CH[i][j];
        CH[i][j] = ' ';
    } else if (P[3] == '-' && CH[i1][j1] != ' ') {
        er[1] = 1;
    } else if (P[3] == 'x' && CH[i1][j1] != ' ') {
        CH[i1][j1] = CH[i][j];
        CH[i][j] = ' ';
    } else if (P[3] == 'x' && CH[i1][j1] == ' ') {
        er[2] = 1;
    }

    i2 = abs(P[8] - 56); //цифра
    j2 = P[7] - 97;      //буква
    if (CH[i2][j2] != P[6] + 32) {
        er[3] = 1;
    }
    i3 = abs(P[11] - 56); //цифра
    j3 = P[10] - 97;      //буква

    if (P[9] == '-' && CH[i3][j3] == ' ') {
        CH[i3][j3] = CH[i2][j2];
        CH[i2][j2] = ' ';
    } else if (P[9] == '-' && CH[i3][j3] != ' ') {
        er[4] = 1;
    } else if (P[9] == 'x' && CH[i3][j3] != ' ') {
        CH[i3][j3] = CH[i2][j2];
        CH[i3][j3] = ' ';
    } else if (P[9] == 'x' && CH[i3][j3] == ' ') {
        er[5] = 1;
    }

    printf("\n");
    int check = 0;

    if (er[0] == 1 && CH[i][j] == ' ') {
        printf("Белая фигура отсутствует в клетке\n");
        check++;
    } else if (er[0] == 1 && CH[i][j] != P[0]) {
        printf("Вид белой фигуры отличается от записи в нотации\n");
        check++;
    }
    if (er[1] == 1) {
        printf("Такой ход для белых шахмат недоступен, клетка занята\n");
        check++;
    } else if (er[2] == 1) {
        printf("Такой ход для белых шахмат недоступен, клетка свободна\n");
        check++;
    }
    if (er[3] == 1 && CH[i2][j2] == ' ') {
        printf("Черная фигура отсутствует в клетке\n");
        check++;
    } else if (er[3] == 1 && CH[i2][j2] != P[6] + 32) {
        printf("Вид черной фигуры отличается от записи в нотации\n");
        check++;
    }
    if (er[4] == 1) {
        printf("Такой ход для черных шахмат недоступен, клетка занята\n");
        check++;
    } else if (er[5] == 1) {
        printf("Такой ход для черных шахмат недоступен, клетка свободна\n");
        check++;
    }

    if (check > 0) {
        printf("Количество ошибок:%d\n", check);
        exit(1);
    }
    print_cb(n, CH);
}
void check(char* line, int* A)
{
    int p = 12; //размер массива А
    int er[p];
    for (int i = 0; i < p; i++) {
        A[i] = 0;
        er[i] = 0;
    }
    int space = 0;

    while (line[space] == ' ') {
        space++;
    }
    switch (line[0 + space]) {
    case 'K':
        A[0] = 75;
        break;
    case 'Q':
        A[0] = 81;
        break;
    case 'R':
        A[0] = 82;
        break;
    case 'B':
        A[0] = 66;
        break;
    case 'N':
        A[0] = 78;
        break;
    }
    if (A[0 + space] != 0) //не пешка и не пустая
    {
        space++;
    } else if (
            A[0] == 0 && line[0 + space] <= 104
            && line[0 + space] >= 97) //пешка
    {
        A[0] = 80; // 80-пешка
    } else         //пустая
    {
        er[0] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= 104 && line[space] >= 97) {
        A[1] = line[space];
        space++;
    } else {
        er[1] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= 56 && line[space] >= 49) {
        A[2] = line[space];
        space++;
    } else {
        er[2] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] == 'x' || line[space] == '-') {
        A[3] = line[space];
        space++;
    } else {
        er[3] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= 104 && line[space] >= 97) {
        A[4] = line[space];
        space++;
    } else {
        er[4] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= 56 && line[space] >= 49) {
        A[5] = line[space];
        space++;
    } else {
        er[5] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }

    switch (line[space]) {
    case 'K':
        A[6] = 75;
        break;
    case 'Q':
        A[6] = 81;
        break;
    case 'R':
        A[6] = 82;
        break;
    case 'B':
        A[6] = 66;
        break;
    case 'N':
        A[6] = 78;
        break;
    }
    if (A[6] != 0) //не пешка
    {
        space++;
    } else if (A[space] == 0 && line[space] <= 104 && line[space] >= 97) //пешка
    {
        A[6] = 80; // 80-пешка
    } else         //пустая
    {
        er[6] = 1;
        space++;
    }

    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= 104 && line[space] >= 97) {
        A[7] = line[space];
        space++;
    } else {
        er[7] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= 56 && line[space] >= 49) {
        A[8] = line[space];
        space++;
    } else {
        er[8] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] == 'x' || line[space] == '-') {
        A[9] = line[space];
        space++;
    } else {
        er[9] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= 104 && line[space] >= 97) {
        A[10] = line[space];
        space++;
    } else {
        er[10] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= 56 && line[space] >= 49) {
        A[11] = line[space];
        space++;
    } else {
        er[11] = 1;
        space++;
    }
    printf("\n");
    int check = 0;
    for (int i = 0; i < 12; i++) {
        if (i == 0 && er[i] == 1) {
            printf("Некорректная белая фигура\n");
            check++;
        } else if (i == 1 && er[i] == 1) {
            printf("Некорректная записана буква кординаты нахождения белой "
                   "шахматы в нотации\n");
            check++;
        } else if (i == 2 && er[i] == 1) {
            printf("Некорректно записана цифра кординаты нахождения белой "
                   "шахматы в нотации\n");
            check++;
        } else if (i == 3 && er[i] == 1) {
            printf("Неккоректно записано действие белых в нотации\n");
            check++;
        } else if (i == 4 && er[i] == 1) {
            printf("Некорректная записана буква кординаты хода белой шахматы в "
                   "нотации\n");
            check++;
        } else if (i == 5 && er[i] == 1) {
            printf("Некорректная записана цифра кординаты хода белой шахматы в "
                   "нотации\n");
            check++;
        } else if (i == 6 && er[i] == 1) {
            printf("Некорректная черная фигура\n");
            check++;
        } else if (i == 7 && er[i] == 1) {
            printf("Некорректная записана буква кординаты нахождения черной "
                   "шахматы в нотации\n\n");
            check++;
        } else if (i == 8 && er[i] == 1) {
            printf("Некорректно записана цифра кординаты нахождения черной "
                   "шахматы в нотации\n\n");
            check++;
        } else if (i == 9 && er[i] == 1) {
            printf("Неккоректно записано действие черных в нотации\n");
            check++;
        } else if (i == 10 && er[i] == 1) {
            printf("Некорректная записана буква кординаты хода черной шахматы "
                   "в нотации\n");
            check++;
        } else if (i == 11 && er[i] == 1) {
            printf("Некорректная записана цифра кординаты хода черной шахматы "
                   "в нотации\n");
            check++;
        }
    }
    if (check > 0) {
        printf("Количество ошибой:%d\n", check);
        exit(1);
    }
}
//Открытие файла, построчное считывание
int file(int n, char** chessboard)
{
    setlocale(LC_ALL, "Russian");
    int d = 50;
    char line[d];
    int pressmark[12];
    FILE* file = fopen("notation.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл");
        return 0;
    }
    while (1) {
        if (fgets(line, d, file) == NULL)
            break;
        printf("\n%s", line);
        check(line, pressmark);
        act(pressmark, chessboard, n);
    }

    fclose(file);
    return 0;
}
