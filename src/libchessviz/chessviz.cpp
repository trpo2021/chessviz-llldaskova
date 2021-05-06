#include "chessviz.h"
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int start_letters = 97;
const int end_letters = 104;
const int start_numbers = 49;
const int end_numbers = 56;
const int alf = 32;

//поле с фигурами
void default_cb(int n, char** chessboard)
{
    int k = 6;
    chessboard[0][0] = 'r';
    chessboard[0][1] = 'n';
    chessboard[0][2] = 'b';
    chessboard[0][3] = 'q';
    chessboard[0][4] = 'k';
    chessboard[0][5] = 'b';
    chessboard[0][6] = 'n';
    chessboard[0][7] = 'r';
    for (int i = 1; i == 1; i++) {
        for (int j = 0; j < n; j++) {
            chessboard[i][j] = 'p';
        }
    }
    for (int i = 2; i < k; i++) {
        for (int j = 0; j < n; j++) {
            chessboard[i][j] = ' ';
        }
    }
    for (int i = 6; i == k; i++) {
        for (int j = 0; j < n; j++) {
            chessboard[i][j] = 'P';
        }
    }
    chessboard[7][0] = 'R';
    chessboard[7][1] = 'N';
    chessboard[7][2] = 'B';
    chessboard[7][3] = 'Q';
    chessboard[7][4] = 'K';
    chessboard[7][5] = 'B';
    chessboard[7][6] = 'N';
    chessboard[7][7] = 'R';
}
//вывод поля
void print_cb(int n, char** chessboard)
{
    int k = 8;
    for (int i = 0; i < n; i++) {
        cout << " " << k << " ";
        for (int j = 0; j < n; j++) {
            cout << chessboard[i][j] << " ";
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
//Открытие файла, построчное считывание
int file(int n, char** chessboard)
{
    setlocale(LC_ALL, "Russian");
    int line_size = 50;
    char line[line_size];
    int pressmark[12];
    int size_er = 12;
    int error_string[size_er];
    int error_d_size = 6;
    int error_d[error_d_size];
    FILE* file = fopen("notation.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл");
        return 0;
    }
    while (1) {
        if (fgets(line, line_size, file) == NULL)
            break;
        printf("\n%s", line);
        checkstring(line, pressmark, size_er, error_string);
        checkstring_print(error_string);
        int test = 0; //отключение вывода для теста
        act(pressmark, chessboard, n, error_d_size, error_d, test);
    }

    fclose(file);
    return 0;
}
void checkstring(char* line, int* chess_string, int size_er, int* error_string)
{
    for (int i = 0; i < size_er; i++) {
        chess_string[i] = 0;
        error_string[i] = 0;
    }
    int space = 0;
    int add = 0;
    checkstring_side(line, error_string, space, add, chess_string);

    add = 6;
    checkstring_side(line, error_string, space, add, chess_string);
    printf("\n");
}
void checkstring_side(
        char* line, int* error_string, int& space, int add, int* chess_string)
{
    while (line[space] == ' ') {
        space++;
    }
    switch (line[0 + space]) {
    case 'K':
        chess_string[0 + add] = 75;
        break;
    case 'Q':
        chess_string[0 + add] = 81;
        break;
    case 'R':
        chess_string[0 + add] = 82;
        break;
    case 'B':
        chess_string[0 + add] = 66;
        break;
    case 'N':
        chess_string[0 + add] = 78;
        break;
    }
    if (chess_string[0 + add] != 0) //не пешка и не пустая
    {
        space++;
    } else if (
            chess_string[0 + add] == 0 && line[0 + space] <= end_letters
            && line[0 + space] >= start_letters) //пешка
    {
        chess_string[0 + add] = 80; // 80-пешка
    } else                          //пустая
    {
        error_string[0 + add] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= end_letters && line[space] >= start_letters) {
        chess_string[1 + add] = line[space];
        space++;
    } else {
        error_string[1 + add] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= end_numbers && line[space] >= start_numbers) {
        chess_string[2 + add] = line[space];
        space++;
    } else {
        error_string[2 + add] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] == 'x' || line[space] == '-') {
        chess_string[3 + add] = line[space];
        space++;
    } else {
        error_string[3 + add] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= end_letters && line[space] >= start_letters) {
        chess_string[4 + add] = line[space];
        space++;
    } else {
        error_string[4 + add] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
    if (line[space] <= end_numbers && line[space] >= start_numbers) {
        chess_string[5 + add] = line[space];
        space++;
    } else {
        error_string[5 + add] = 1;
        space++;
    }
    while (line[space] == ' ') {
        space++;
    }
}
void checkstring_print(int* error_string)
{
    int check = 0;
    for (int i = 0; i < 12; i++) {
        if (i == 0 && error_string[i] == 1) {
            printf("Некорректная белая фигура\n");
            check++;
        } else if (i == 1 && error_string[i] == 1) {
            printf("Некорректная записана буква кординаты нахождения белой "
                   "шахматы в нотации\n");
            check++;
        } else if (i == 2 && error_string[i] == 1) {
            printf("Некорректно записана цифра кординаты нахождения белой "
                   "шахматы в нотации\n");
            check++;
        } else if (i == 3 && error_string[i] == 1) {
            printf("Неккоректно записано действие белых в нотации\n");
            check++;
        } else if (i == 4 && error_string[i] == 1) {
            printf("Некорректная записана буква кординаты хода белой шахматы в "
                   "нотации\n");
            check++;
        } else if (i == 5 && error_string[i] == 1) {
            printf("Некорректная записана цифра кординаты хода белой шахматы в "
                   "нотации\n");
            check++;
        } else if (i == 6 && error_string[i] == 1) {
            printf("Некорректная черная фигура\n");
            check++;
        } else if (i == 7 && error_string[i] == 1) {
            printf("Некорректная записана буква кординаты нахождения черной "
                   "шахматы в нотации\n\n");
            check++;
        } else if (i == 8 && error_string[i] == 1) {
            printf("Некорректно записана цифра кординаты нахождения черной "
                   "шахматы в нотации\n\n");
            check++;
        } else if (i == 9 && error_string[i] == 1) {
            printf("Неккоректно записано действие черных в нотации\n");
            check++;
        } else if (i == 10 && error_string[i] == 1) {
            printf("Некорректная записана буква кординаты хода черной шахматы "
                   "в нотации\n");
            check++;
        } else if (i == 11 && error_string[i] == 1) {
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

void act(
        int* chess_string,
        char** CH,
        int n,
        int error_d_size,
        int* error_d,
        int test)
{
    int i, j, i1, j1, i2, j2, i3, j3;
    for (int i = 0; i < error_d_size; i++) {
        error_d[i] = 0;
    }
    i = abs(chess_string[2] - end_numbers); //цифра
    j = chess_string[1] - start_letters;    //буква
    if (CH[i][j] != chess_string[0]) {
        error_d[0] = 1;
    }
    i1 = abs(chess_string[5] - end_numbers); //цифра
    j1 = chess_string[4] - start_letters;    //буква

    if (chess_string[3] == '-' && CH[i1][j1] == ' ') {
        CH[i1][j1] = CH[i][j];
        CH[i][j] = ' ';
    } else if (chess_string[3] == '-' && CH[i1][j1] != ' ') {
        error_d[1] = 1;
    } else if (chess_string[3] == 'x' && CH[i1][j1] != ' ') {
        CH[i1][j1] = CH[i][j];
        CH[i][j] = ' ';
    } else if (chess_string[3] == 'x' && CH[i1][j1] == ' ') {
        error_d[2] = 1;
    }

    i2 = abs(chess_string[8] - end_numbers); //цифра
    j2 = chess_string[7] - start_letters;    //буква
    if (CH[i2][j2] != chess_string[6] + alf) {
        error_d[3] = 1;
    }
    i3 = abs(chess_string[11] - end_numbers); //цифра
    j3 = chess_string[10] - start_letters;    //буква

    if (chess_string[9] == '-' && CH[i3][j3] == ' ') {
        CH[i3][j3] = CH[i2][j2];
        CH[i2][j2] = ' ';
    } else if (chess_string[9] == '-' && CH[i3][j3] != ' ') {
        error_d[4] = 1;
    } else if (chess_string[9] == 'x' && CH[i3][j3] != ' ') {
        CH[i3][j3] = CH[i2][j2];
        CH[i3][j3] = ' ';
    } else if (chess_string[9] == 'x' && CH[i3][j3] == ' ') {
        error_d[5] = 1;
    }
    if (test == 0) {
        act_print(chess_string, error_d, CH, i, j, i2, j2);

        print_cb(n, CH);
    }
}

void act_print(
        int* chess_string,
        int* error_d,
        char** CH,
        int i,
        int j,
        int i2,
        int j2)
{
    printf("\n");
    int check = 0;

    if (error_d[0] == 1 && CH[i][j] == ' ') {
        printf("Белая фигура отсутствует в клетке\n");
        check++;
    } else if (error_d[0] == 1 && CH[i][j] != chess_string[0]) {
        printf("Вид белой фигуры отличается от записи в нотации\n");
        check++;
    }
    if (error_d[1] == 1) {
        printf("Такой ход для белых шахмат недоступен, клетка занята\n");
        check++;
    } else if (error_d[2] == 1) {
        printf("Такой ход для белых шахмат недоступен, клетка свободна\n");
        check++;
    }
    if (error_d[3] == 1 && CH[i2][j2] == ' ') {
        printf("Черная фигура отсутствует в клетке\n");
        check++;
    } else if (error_d[3] == 1 && CH[i2][j2] != chess_string[6] + alf) {
        printf("Вид черной фигуры отличается от записи в нотации\n");
        check++;
    }
    if (error_d[4] == 1) {
        printf("Такой ход для черных шахмат недоступен, клетка занята\n");
        check++;
    } else if (error_d[5] == 1) {
        printf("Такой ход для черных шахмат недоступен, клетка свободна\n");
        check++;
    }

    if (check > 0) {
        printf("Количество ошибок:%d\n", check);
        exit(1);
    }
}
