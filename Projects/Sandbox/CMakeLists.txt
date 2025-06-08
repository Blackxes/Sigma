
project(SandboxLANGUAGES C CXX)

file(GLOB_RECURSE SANDBOX_SOURCES
    "src/*.h"
    "src/*.hpp"
    "src/*.c"
    "src/*.cpp"
)

add_executable(Sandbox ${SANDBOX_SOURCES})

target_link_libraries(Sandbox PRIVATE Sigma)

target_link_directories(Sandbox PRIVATE
    ${CMAKE_BINARY_DIR}/lib
)

target_include_directories(Sandbox PRIVATE
    ${CMAKE_SOURCE_DIR}/Sigma/src
)