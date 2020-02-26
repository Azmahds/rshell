#ifndef SINGLE_LINE_UNIT_TEST_H_
#define SINGLE_LINE_UNIT_TEST_H_
#include "gtest/gtest.h"

#include "../head/CMD.h"
#include "../head/Token.h"
#include "../head/Connector.h"
#include "../head/And.h"
#include "../head/Or.h"
#include "../head/Semicolon.h"
#include "../head/Exit.h"
#include "../head/Test.h"

#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <unistd.h>
using namespace std;

/*
TEST(AndTest, AndDisplay){
    And* f = new And();
    EXPECT_EQ(f->display(), "AND");
}

TEST(OrTest, OrDisplay){
    Or* f = new Or();
    EXPECT_EQ(f->display(), "OR");
}

TEST(SemiTest, SemiDisplay){
    Semicolon* f = new Semicolon();
    EXPECT_EQ(f->display(), "SEMICOLON");
}


TEST(TokenTest, TokenDisplay){
    Token* f = new Token();
    EXPECT_EQ(f->display(), "TOKEN");
}
*/

TEST(TokenTest, TokenRun){
    char* arr = new char[32];
    arr[0] = 'l';
    arr[1] = 's';
    arr[2] = '\0';
    Token* f = new Token(arr );
    EXPECT_EQ(f->run(), true);
}

TEST(TokenTest, TokenRunEcho){
    char* arr = new char[32];
    arr[0] = 'e';
    arr[1] = 'c';
    arr[2] = 'h';
    arr[3] = 'o';
    arr[4] = ' ';
    arr[5] = '"';
    arr[6] = 'h';
    arr[7] = 'e';
    arr[8] = 'l';
    arr[9] = 'l';
    arr[10] = 'o';
    arr[11] = '"';
    arr[12] = '\0';
    Token* f = new Token(arr );
    EXPECT_EQ(f->run(), true);
}

TEST(OrTest, OrRun){
    char* arr1 = new char[32];
    arr1[0] = 'l';
    arr1[1] = 's';
    arr1[2] = '\0';
    
    char* arr = new char[32];
    arr[0] = 'e';
    arr[1] = 'c';
    arr[2] = 'h';
    arr[3] = 'o';
    arr[4] = ' ';
    arr[5] = 'h';
    arr[6] = 'i';
    arr[7] = '\0';
    Or* o = new Or();
    Token* f = new Token(arr);
    o->SetL(f);
    f = new  Token(arr1);
    o->SetR(f);   
    EXPECT_EQ(o->run(), true);
}


#endif
