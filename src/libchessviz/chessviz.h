#pragma once
void default_cb(int n, char** chessboard);
void print_cb(int n, char** chessboard);
int file(int n, char** chessboard);
void checkstring(char* line, int* chess_string, int size_er, int* error_string);
void checkstring_side(
        char* line, int* error_string, int& space, int add, int* A);
void checkstring_print(int* error_string);
void act(
        int* chess_string,
        char** CH,
        int n,
        int error_d_size,
        int* error_d,
        int test);
void act_print(
        int* chess_string,
        int* error_d,
        char** CH,
        int i,
        int j,
        int i2,
        int j2);
