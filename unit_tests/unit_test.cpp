#include "gtest/gtest.h"


//#include "src/CMD.h"
#include "Token.h"
#include "Token.cpp"
//#include "src/Connector.h"
//#include "src/And.h"
//#include "src/Or.h"
//#include "src/Semicolon.h"
//#include "src/postfix.hpp"







TEST(TokenTest, TokenDisplay){
    Token* f = new Token();
    EXPECT_EQ(f->display(), "TOKEN");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

