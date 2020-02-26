#include "gtest/gtest.h"

#include "../head/CMD.h"
#include "../head/Token.h"
#include "../src/Token.cpp"
#include "../head/Connector.h"
#include "../head/And.h"
#include "../src/And.cpp"
#include "../head/Or.h"
#include "../src/Or.cpp"
#include "../head/Semicolon.h"
#include "../src/Semicolon.cpp"
#include "../head/Exit.h"
#include "../head/Test.h"
#include "../src/Test.cpp"

#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

