#include "ctest.h"
#include "libchessviz/chessviz.h"

CTEST(checkline, test_zero_error)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "b2-b4 d7-e3";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(0, real[0]);
    ASSERT_EQUAL(0, real[1]);
    ASSERT_EQUAL(0, real[2]);
    ASSERT_EQUAL(0, real[3]);
    ASSERT_EQUAL(0, real[4]);
    ASSERT_EQUAL(0, real[5]);
    ASSERT_EQUAL(0, real[6]);
    ASSERT_EQUAL(0, real[7]);
    ASSERT_EQUAL(0, real[8]);
    ASSERT_EQUAL(0, real[9]);
    ASSERT_EQUAL(0, real[10]);
    ASSERT_EQUAL(0, real[11]);
}
CTEST(checkline, test_everyerror)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Y9yvm-   Fttmpp";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(1, real[0]);
    ASSERT_EQUAL(1, real[1]);
    ASSERT_EQUAL(1, real[2]);
    ASSERT_EQUAL(1, real[3]);
    ASSERT_EQUAL(1, real[4]);
    ASSERT_EQUAL(1, real[5]);
    ASSERT_EQUAL(1, real[6]);
    ASSERT_EQUAL(1, real[7]);
    ASSERT_EQUAL(1, real[8]);
    ASSERT_EQUAL(1, real[9]);
    ASSERT_EQUAL(1, real[10]);
    ASSERT_EQUAL(1, real[11]);
}
CTEST(checkline, test_error6)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Ra1x  a2 Mc  8-d6";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(0, real[0]);
    ASSERT_EQUAL(0, real[1]);
    ASSERT_EQUAL(0, real[2]);
    ASSERT_EQUAL(0, real[3]);
    ASSERT_EQUAL(0, real[4]);
    ASSERT_EQUAL(0, real[5]);
    ASSERT_EQUAL(1, real[6]);
    ASSERT_EQUAL(0, real[7]);
    ASSERT_EQUAL(0, real[8]);
    ASSERT_EQUAL(0, real[9]);
    ASSERT_EQUAL(0, real[10]);
    ASSERT_EQUAL(0, real[11]);
}
CTEST(checkline, test_error0)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "M a 1 x  a2 c  8-d6";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(1, real[0]);
    ASSERT_EQUAL(0, real[1]);
    ASSERT_EQUAL(0, real[2]);
    ASSERT_EQUAL(0, real[3]);
    ASSERT_EQUAL(0, real[4]);
    ASSERT_EQUAL(0, real[5]);
    ASSERT_EQUAL(0, real[6]);
    ASSERT_EQUAL(0, real[7]);
    ASSERT_EQUAL(0, real[8]);
    ASSERT_EQUAL(0, real[9]);
    ASSERT_EQUAL(0, real[10]);
    ASSERT_EQUAL(0, real[11]);
}
CTEST(checkline, test_error1)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Kk1xa2 c8-d6";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(0, real[0]);
    ASSERT_EQUAL(1, real[1]);
    ASSERT_EQUAL(0, real[2]);
    ASSERT_EQUAL(0, real[3]);
    ASSERT_EQUAL(0, real[4]);
    ASSERT_EQUAL(0, real[5]);
    ASSERT_EQUAL(0, real[6]);
    ASSERT_EQUAL(0, real[7]);
    ASSERT_EQUAL(0, real[8]);
    ASSERT_EQUAL(0, real[9]);
    ASSERT_EQUAL(0, real[10]);
    ASSERT_EQUAL(0, real[11]);
}
CTEST(checkline, test_error2)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Kaaxa2 c8-d6";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(0, real[0]);
    ASSERT_EQUAL(0, real[1]);
    ASSERT_EQUAL(1, real[2]);
    ASSERT_EQUAL(0, real[3]);
    ASSERT_EQUAL(0, real[4]);
    ASSERT_EQUAL(0, real[5]);
    ASSERT_EQUAL(0, real[6]);
    ASSERT_EQUAL(0, real[7]);
    ASSERT_EQUAL(0, real[8]);
    ASSERT_EQUAL(0, real[9]);
    ASSERT_EQUAL(0, real[10]);
    ASSERT_EQUAL(0, real[11]);
}
CTEST(checkline, test_error4_5)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Ka1-2a c8-d6";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(0, real[0]);
    ASSERT_EQUAL(0, real[1]);
    ASSERT_EQUAL(0, real[2]);
    ASSERT_EQUAL(0, real[3]);
    ASSERT_EQUAL(1, real[4]);
    ASSERT_EQUAL(1, real[5]);
    ASSERT_EQUAL(0, real[6]);
    ASSERT_EQUAL(0, real[7]);
    ASSERT_EQUAL(0, real[8]);
    ASSERT_EQUAL(0, real[9]);
    ASSERT_EQUAL(0, real[10]);
    ASSERT_EQUAL(0, real[11]);
}
CTEST(checkline, test_error7_8)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "b2-b4 K7d-e3";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(0, real[0]);
    ASSERT_EQUAL(0, real[1]);
    ASSERT_EQUAL(0, real[2]);
    ASSERT_EQUAL(0, real[3]);
    ASSERT_EQUAL(0, real[4]);
    ASSERT_EQUAL(0, real[5]);
    ASSERT_EQUAL(0, real[6]);
    ASSERT_EQUAL(1, real[7]);
    ASSERT_EQUAL(1, real[8]);
    ASSERT_EQUAL(0, real[9]);
    ASSERT_EQUAL(0, real[10]);
    ASSERT_EQUAL(0, real[11]);
}
CTEST(checkline, test_error3)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "b2vb4 Kd7-e3";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(0, real[0]);
    ASSERT_EQUAL(0, real[1]);
    ASSERT_EQUAL(0, real[2]);
    ASSERT_EQUAL(1, real[3]);
    ASSERT_EQUAL(0, real[4]);
    ASSERT_EQUAL(0, real[5]);
    ASSERT_EQUAL(0, real[6]);
    ASSERT_EQUAL(0, real[7]);
    ASSERT_EQUAL(0, real[8]);
    ASSERT_EQUAL(0, real[9]);
    ASSERT_EQUAL(0, real[10]);
    ASSERT_EQUAL(0, real[11]);
}
CTEST(checkline, test_error9_10_11)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "b2-b4 Kd7m9-";
    int real[size];
    checkstring(line, chess_string, size, real);
    ASSERT_EQUAL(0, real[0]);
    ASSERT_EQUAL(0, real[1]);
    ASSERT_EQUAL(0, real[2]);
    ASSERT_EQUAL(0, real[3]);
    ASSERT_EQUAL(0, real[4]);
    ASSERT_EQUAL(0, real[5]);
    ASSERT_EQUAL(0, real[6]);
    ASSERT_EQUAL(0, real[7]);
    ASSERT_EQUAL(0, real[8]);
    ASSERT_EQUAL(1, real[9]);
    ASSERT_EQUAL(1, real[10]);
    ASSERT_EQUAL(1, real[11]);
}
CTEST(check_act, test_zero_error)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "a2-a3 b7-b6";
    int real[size];
    checkstring(line, chess_string, size, real);
    int n = 8;
    int error_d_size = 6;
    int error_d[error_d_size];
    char** chessboard = new char*[n];
    for (int i = 0; i < n; i++) {
        chessboard[i] = new char[n];
    }
    default_cb(n, chessboard);
    act(chess_string, chessboard, n, error_d_size, error_d, 1);
    for (int i = 0; i < n; i++)
        delete chessboard[i];
    delete[] chessboard;
    chessboard = NULL;
    ASSERT_EQUAL(0, error_d[0]);
    ASSERT_EQUAL(0, error_d[1]);
    ASSERT_EQUAL(0, error_d[2]);
    ASSERT_EQUAL(0, error_d[3]);
    ASSERT_EQUAL(0, error_d[4]);
    ASSERT_EQUAL(0, error_d[5]);
}
CTEST(check_act, test_error0)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "a3-a4 b7-b6";
    int real[size];
    checkstring(line, chess_string, size, real);
    int n = 8;
    int error_d_size = 6;
    int error_d[error_d_size];
    char** chessboard = new char*[n];
    for (int i = 0; i < n; i++) {
        chessboard[i] = new char[n];
    }
    default_cb(n, chessboard);
    act(chess_string, chessboard, n, error_d_size, error_d, 1);
    for (int i = 0; i < n; i++)
        delete chessboard[i];
    delete[] chessboard;
    chessboard = NULL;
    ASSERT_EQUAL(1, error_d[0]);
    ASSERT_EQUAL(0, error_d[1]);
    ASSERT_EQUAL(0, error_d[2]);
    ASSERT_EQUAL(0, error_d[3]);
    ASSERT_EQUAL(0, error_d[4]);
    ASSERT_EQUAL(0, error_d[5]);
}
CTEST(check_act, test_error1)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Nb1-a2 b7-b6";
    int real[size];
    checkstring(line, chess_string, size, real);
    int n = 8;
    int error_d_size = 6;
    int error_d[error_d_size];
    char** chessboard = new char*[n];
    for (int i = 0; i < n; i++) {
        chessboard[i] = new char[n];
    }
    default_cb(n, chessboard);
    act(chess_string, chessboard, n, error_d_size, error_d, 1);
    for (int i = 0; i < n; i++)
        delete chessboard[i];
    delete[] chessboard;
    chessboard = NULL;
    ASSERT_EQUAL(0, error_d[0]);
    ASSERT_EQUAL(1, error_d[1]);
    ASSERT_EQUAL(0, error_d[2]);
    ASSERT_EQUAL(0, error_d[3]);
    ASSERT_EQUAL(0, error_d[4]);
    ASSERT_EQUAL(0, error_d[5]);
}
CTEST(check_act, test_error2)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Nb1xa3 b7-b6";
    int real[size];
    checkstring(line, chess_string, size, real);
    int n = 8;
    int error_d_size = 6;
    int error_d[error_d_size];
    char** chessboard = new char*[n];
    for (int i = 0; i < n; i++) {
        chessboard[i] = new char[n];
    }
    default_cb(n, chessboard);
    act(chess_string, chessboard, n, error_d_size, error_d, 1);
    for (int i = 0; i < n; i++)
        delete chessboard[i];
    delete[] chessboard;
    chessboard = NULL;
    ASSERT_EQUAL(0, error_d[0]);
    ASSERT_EQUAL(0, error_d[1]);
    ASSERT_EQUAL(1, error_d[2]);
    ASSERT_EQUAL(0, error_d[3]);
    ASSERT_EQUAL(0, error_d[4]);
    ASSERT_EQUAL(0, error_d[5]);
}
CTEST(check_act, test_error3)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Nb1xa2 Nb7-b6";
    int real[size];
    checkstring(line, chess_string, size, real);
    int n = 8;
    int error_d_size = 6;
    int error_d[error_d_size];
    char** chessboard = new char*[n];
    for (int i = 0; i < n; i++) {
        chessboard[i] = new char[n];
    }
    default_cb(n, chessboard);
    act(chess_string, chessboard, n, error_d_size, error_d, 1);
    for (int i = 0; i < n; i++)
        delete chessboard[i];
    delete[] chessboard;
    chessboard = NULL;
    ASSERT_EQUAL(0, error_d[0]);
    ASSERT_EQUAL(0, error_d[1]);
    ASSERT_EQUAL(0, error_d[2]);
    ASSERT_EQUAL(1, error_d[3]);
    ASSERT_EQUAL(0, error_d[4]);
    ASSERT_EQUAL(0, error_d[5]);
}
CTEST(check_act, test_error4)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Nb1xa2 b7-b8";
    int real[size];
    checkstring(line, chess_string, size, real);
    int n = 8;
    int error_d_size = 6;
    int error_d[error_d_size];
    char** chessboard = new char*[n];
    for (int i = 0; i < n; i++) {
        chessboard[i] = new char[n];
    }
    default_cb(n, chessboard);
    act(chess_string, chessboard, n, error_d_size, error_d, 1);
    for (int i = 0; i < n; i++)
        delete chessboard[i];
    delete[] chessboard;
    chessboard = NULL;
    ASSERT_EQUAL(0, error_d[0]);
    ASSERT_EQUAL(0, error_d[1]);
    ASSERT_EQUAL(0, error_d[2]);
    ASSERT_EQUAL(0, error_d[3]);
    ASSERT_EQUAL(1, error_d[4]);
    ASSERT_EQUAL(0, error_d[5]);
}
CTEST(check_act, test_error5)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "Nb1xa2 b7xb6";
    int real[size];
    checkstring(line, chess_string, size, real);
    int n = 8;
    int error_d_size = 6;
    int error_d[error_d_size];
    char** chessboard = new char*[n];
    for (int i = 0; i < n; i++) {
        chessboard[i] = new char[n];
    }
    default_cb(n, chessboard);
    act(chess_string, chessboard, n, error_d_size, error_d, 1);
    for (int i = 0; i < n; i++)
        delete chessboard[i];
    delete[] chessboard;
    chessboard = NULL;
    ASSERT_EQUAL(0, error_d[0]);
    ASSERT_EQUAL(0, error_d[1]);
    ASSERT_EQUAL(0, error_d[2]);
    ASSERT_EQUAL(0, error_d[3]);
    ASSERT_EQUAL(0, error_d[4]);
    ASSERT_EQUAL(1, error_d[5]);
}
CTEST(check_act, test_error0_5)
{
    int size = 12;
    int chess_string[size];
    char line[50] = "b1xa2 b7xb6";
    int real[size];
    checkstring(line, chess_string, size, real);
    int n = 8;
    int error_d_size = 6;
    int error_d[error_d_size];
    char** chessboard = new char*[n];
    for (int i = 0; i < n; i++) {
        chessboard[i] = new char[n];
    }
    default_cb(n, chessboard);
    act(chess_string, chessboard, n, error_d_size, error_d, 1);
    for (int i = 0; i < n; i++)
        delete chessboard[i];
    delete[] chessboard;
    chessboard = NULL;
    ASSERT_EQUAL(1, error_d[0]);
    ASSERT_EQUAL(0, error_d[1]);
    ASSERT_EQUAL(0, error_d[2]);
    ASSERT_EQUAL(0, error_d[3]);
    ASSERT_EQUAL(0, error_d[4]);
    ASSERT_EQUAL(1, error_d[5]);
}
