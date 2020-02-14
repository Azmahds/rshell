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
    arr[4] = '\0';
    Token* f = new Token(arr );
    EXPECT_EQ(f->run(), true);
}







int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

