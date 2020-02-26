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

TEST(TestClass, Word_Test){
char arr[10];
strcpy(arr, "test src/");

CMD* temp  = new TestClass(arr);
EXPECT_EQ(temp->run(), true);
}
/*
TEST(TestClass, Bracket_Test){


}
*/
