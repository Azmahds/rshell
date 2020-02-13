CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    src/test.cpp
    src/Token.cpp
    src/Or.cpp
    src/And.cpp
    src/Semicolon.cpp
    src/CMD.h
    src/Connector.h
)

ADD_EXECUTABLE(rshell
    main.cpp
    src/Token.cpp
    src/Or.cpp
    src/And.cpp
    src/Semicolon.cpp
    src/CMD.h
    src/Connector.h
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

