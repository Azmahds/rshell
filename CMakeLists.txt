CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    unit_tests/unit_test.cpp
)

ADD_EXECUTABLE(rshell
    src/test.cpp
    src/Token.cpp
    src/Or.cpp
    src/And.cpp
    src/Semicolon.cpp
    src/CMD.h
    src/Connector.h
    #src/postfix.hpp
)

ADD_EXECUTABLE(main
    src/main.cpp
    src/Token.cpp
    src/Or.cpp
    src/And.cpp
    src/Semicolon.cpp
    src/Exit.h
    src/CMD.h
    src/Connector.h
    src/postfix.hpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

