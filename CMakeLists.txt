CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    unit_tests/all_unit_tests.cpp
    src/Token.cpp
    src/Or.cpp
    src/And.cpp
    src/Semicolon.cpp
    header/Exit.h
    header/CMD.h
    header/Connector.h
    src/postfix.hpp
    src/Test.cpp
)


ADD_EXECUTABLE(rshell
    src/main.cpp
    src/Token.cpp
    src/Or.cpp
    src/And.cpp
    src/Semicolon.cpp
    header/Exit.h
    header/CMD.h
    header/Connector.h
    src/postfix.hpp
    src/Test.cpp
    src/Pipe.cpp
    src/InRed.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
