CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    test.cpp
    CMD.h
    Token.h
    Token.cpp
    Or.h
    Or.cpp
    And.h
    And.cpp
    Semicolon.h
    Semicolon.cpp
    Connector.h
    Exit.h
)

ADD_EXECUTABLE(rshell
    main.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

