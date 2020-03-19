#ifndef SINGLE_LINE_UNIT_TEST_H_
#define SINGLE_LINE_UNIT_TEST_H_
#include "gtest/gtest.h"

#include "../header/CMD.h"
#include "../header/Token.h"
#include "../header/Connector.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Semicolon.h"
#include "../header/Exit.h"
#include "../header/Test.h"
#include "../header/InRed.h"
#include "../header/OutRed.h"
#include "../header/Pipe.h"

#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <unistd.h>
using namespace std;

TEST(Token, TokenRun){
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
    strcpy(arr, "ec");
    f = new Token(arr);
    EXPECT_EQ(f->run(), false);
}

TEST(OrTest, OrRun){
    char* arr1 = new char[32];
    strcpy(arr1, "echo one");
    
    char* arr = new char[32];
    arr[0] = 'e';
    arr[1] = 'c';
    arr[2] = 'h';
    arr[3] = 'o';
    arr[4] = ' ';
    arr[5] = 't';
    arr[6] = 'w';
    arr[7] = 'o';
    arr[8]  = '\0';
    CMD* o = new Or();
    CMD* l = new Token(arr1);
    CMD* r = new Token(arr);
    o->SetL(l);
    o->SetR(r);   
    EXPECT_EQ(o->run(), true);
    strcpy(arr1, "ec");
    l = new Token(arr1);
    o->SetL(l);
    EXPECT_EQ(o->run(), true);
    strcpy(arr, "ec");
    r = new Token(arr);
    o->SetL(r);
    EXPECT_EQ(o->run(), false);
}

TEST(AndTest, AmdRun){
    char* arr1 = new char[32];
    strcpy(arr1, "echo one");

    char* arr = new char[32];
    arr[0] = 'e';
    arr[1] = 'c';
    arr[2] = 'h';
    arr[3] = 'o';
    arr[4] = ' ';
    arr[5] = 't';
    arr[6] = 'w';
    arr[7] = 'o';
    arr[8]  = '\0';
    CMD* o = new And();
    CMD* l = new Token(arr1);
    CMD* r = new Token(arr);
    o->SetL(l);
    o->SetR(r);
    EXPECT_EQ(o->run(), true);
    strcpy(arr1, "ec");
    l = new Token(arr1);
    o->SetL(l);
    EXPECT_EQ(o->run(), false);
    o->SetL(r);
    strcpy(arr, "ec");
    r = new Token(arr);
    o->SetR(r);
    EXPECT_EQ(o->run(), false);
}

TEST(SemicolonTest, SemiRun){
    char* arr1 = new char[32];
    strcpy(arr1, "echo one");

    char* arr = new char[32];
    arr[0] = 'e';
    arr[1] = 'c';
    arr[2] = 'h';
    arr[3] = 'o';
    arr[4] = ' ';
    arr[5] = 't';
    arr[6] = 'w';
    arr[7] = 'o';
    arr[8]  = '\0';
    CMD* o = new Semicolon();
    CMD* l = new Token(arr1);
    CMD* r = new Token(arr);
    o->SetL(l);
    o->SetR(r);
    EXPECT_EQ(o->run(), true);
    strcpy(arr1, "ec");
    l = new Token(arr1);
    o->SetL(l);
    EXPECT_EQ(o->run(), true);
    strcpy(arr, "ec");
    l = new Token(arr);
    o->SetR(l);
    strcpy(arr1, "echo one");
    r = new Token(arr1);
    o->SetL(r);
    EXPECT_EQ(o->run(), true);
    strcpy(arr1, "ec");
    l = new Token(arr1);
    o->SetL(l);
    EXPECT_EQ(o->run(), true);
}



TEST(InRedTest, InRedRun){

    char* arr1 = new char[32];
    strcpy(arr1, "echo one");

    char* arr = new char[32];
    arr[0] = 'c';
    arr[1] = 'a';
    arr[2] = 't';
    arr[3] = ' ';
    arr[4] = 'f';
    arr[5] = 't';
    arr[6] = 'w';
    arr[7] = 'o';
    arr[8]  = '\0';
    CMD* l = new Token(arr);
    CMD* r = new Token(arr1);
    CMD* o = new InRed();
    o->SetR(r);
    o->SetL(l);
    EXPECT_EQ(o->run(), true);
}


TEST(OutRedTest, OutRedRun){

    char* arr1 = new char[32];
    strcpy(arr1, "echo one");

    char* arr = new char[32];
    arr[0] = 'c';
    arr[1] = 'a';
    arr[2] = 't';
    arr[3] = ' ';
    arr[4] = 'f';
    arr[5] = 't';
    arr[6] = 'w';
    arr[7] = 'o';
    arr[8]  = '\0';
    CMD* l = new Token(arr);
    CMD* r = new Token(arr1);
    CMD* o = new OutRed();
    o->SetR(r);
    o->SetL(l);
    EXPECT_EQ(o->run(), true);
}


TEST(PipeTest, PipeRun){

    char* arr1 = new char[32];
    strcpy(arr1, "echo one");

    char* arr = new char[32];
    arr[0] = 'c';
    arr[1] = 'a';
    arr[2] = 't';
    arr[3] = ' ';
    arr[4] = 'f';
    arr[5] = 't';
    arr[6] = 'w';
    arr[7] = 'o';
    arr[8]  = '\0';
    CMD* l = new Token(arr);
    CMD* r = new Token(arr1);
    CMD* o = new Pipe();
    o->SetR(r);
    o->SetL(l);
    EXPECT_EQ(o->run(), true);
}




#endif
