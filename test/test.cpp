#include "ctest.h"
#include "libchessviz/chessviz.h"

CTEST(checkline, test1)
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
