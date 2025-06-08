
project(SigmaCore LANGUAGES C CXX)

file(GLOB_RECURSE SIGMA_SOURCES
    "src/*.h"
    "src/*.hpp"
    "src/*.c"
    "src/*.cpp"
)

file(GLOB_RECURSE VENDOR_SOURCES
    "vendor/stb_image/src/*.cpp"
    "vendor/GLAD/src/*.c"
)

add_subdirectory(vendor/GLFW)

add_library(Sigma SHARED ${SIGMA_SOURCES} ${VENDOR_SOURCES})

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)

    set_target_properties(Sigma PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS TRUE
        ARCHIVE_OUTPUT_NAME Sigma
        RUNTIME_OUTPUT_NAME Sigma
    )

    target_compile_definitions(Sigma PRIVATE SIGMA_BUILD_DLL)
endif()

target_include_directories(Sigma PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLAD/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb_image/include
)

target_link_libraries(Sigma PRIVATE glfw)

# if(WIN32)
#     target_compile_definitions(Sigma PRIVATE SIGMA_BUILD_DLL)
#     set_target_properties(Sigma PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
# endif()