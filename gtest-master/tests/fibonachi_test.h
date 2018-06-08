/* #ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>

extern "C" {
#include "myfunc.h"
}

TEST(fibonachiTest, num0) {
    ASSERT_EQ(fibonachi(0), 0);
    ASSERT_EQ(fibonachi(1), 1);
    ASSERT_EQ(fibonachi(2), 2);
}

TEST(fibonachiTest, greather2) {
    ASSERT_EQ(fibonachi(5), 5);
    ASSERT_EQ(fibonachi(10), 55);
}

TEST(fibonachiTest, negative) {
    ASSERT_EQ(fibonachi(-1), 0);
}

#endif // FIBONACHI_H
*/

#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


extern "C" {
#include "myfunc.h"
#include "common.h"
#include "text/text.h"
#include "text/_text.h"
}

#define OUTPUT 1
#define STDOUT 1



TEST (group_01, test1)
{
    text txt = create_text();
    ASSERT_EQ(pos_return(txt), 0);

}

TEST (group_01, test2)
{
    text txt = create_text();
    ASSERT_NE(pos_return(txt), -1);

}

TEST(group_02, test1){

    int fptr;
    int oldstdout;
    fptr = open("file.test",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
    oldstdout = dup(STDOUT);
    dup2(fptr,STDOUT);
    close(fptr);

    text txt = create_text();
    load(txt,(char *)"file.test");
    dup2(oldstdout,STDOUT);
    SUCCEED();
}

#endif // FIBONACHI_H
