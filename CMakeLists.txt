cmake_minimum_required(VERSION 3.22.1)

project(SaberTest)

set(CPP_VERSION 17)

if(NOT WIN32 AND NOT WIN_NATIVE)
    find_program(CCACHE_PROGRAM ccache)
endif()

if(CCACHE_PROGRAM)
    # Set up wrapper scripts
    set(C_LAUNCHER   "${CCACHE_PROGRAM}")
    set(CXX_LAUNCHER "${CCACHE_PROGRAM}")
    configure_file(launch-c.in   launch-c)
    configure_file(launch-cxx.in launch-cxx)
    execute_process(COMMAND chmod a+rx
                     "${CMAKE_BINARY_DIR}/launch-c"
                     "${CMAKE_BINARY_DIR}/launch-cxx"
    )

    if(CMAKE_GENERATOR STREQUAL "Xcode")
        # Set Xcode project attributes to route compilation and linking
        # through our scripts
        set(CMAKE_XCODE_ATTRIBUTE_CC         "${CMAKE_BINARY_DIR}/launch-c")
        set(CMAKE_XCODE_ATTRIBUTE_CXX        "${CMAKE_BINARY_DIR}/launch-cxx")
        set(CMAKE_XCODE_ATTRIBUTE_LD         "${CMAKE_BINARY_DIR}/launch-c")
        set(CMAKE_XCODE_ATTRIBUTE_LDPLUSPLUS "${CMAKE_BINARY_DIR}/launch-cxx")
    else()
        # Support Unix Makefiles and Ninja
        set(CMAKE_C_COMPILER_LAUNCHER   "${CMAKE_BINARY_DIR}/launch-c")
        set(CMAKE_CXX_COMPILER_LAUNCHER "${CMAKE_BINARY_DIR}/launch-cxx")
    endif()
 endif()

set(SRC_LIST source/task1.cpp source/task2.cpp source/task3.cpp source/main.cpp source/task1.h source/task2.h source/task3.h)

add_executable(${PROJECT_NAME} ${SRC_LIST})