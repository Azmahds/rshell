#include "gtest/gtest.h"


#include "../src/CMD.h"
#include "../src/Token.h"
#include "../src/Token.cpp"
#include "../src/Connector.h"
#include "../src/Connector.h"
#include "../src/And.h"
#include "../src/And.cpp"
#include "../src/Or.h"
#include "../src/Or.cpp"
#include "../src/Semicolon.h"
#include "../src/Semicolon.cpp"
//#include "src/postfix.hpp"

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


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

