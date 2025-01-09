cmake_minimum_required(VERSION 3.5)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})



add_subdirectory(lib/googletest)
set(gtest_SOURCE_DIR  ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include)



set(TEST_SOURCE_FILES test_main.cpp
        test_room_factory.cpp)
add_executable(runGameCharacterTests ${TEST_SOURCE_FILES})
target_link_libraries(runGameCharacterTests gtest gtest_main core sfml-system sfml-window sfml-graphics sfml-audio)

#implemento le DDL di SFML nella directory di TEST per assicurarmi che siano visibili
add_custom_command(TARGET runGameCharacterTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "C:/SFML/bin"
        $<TARGET_FILE_DIR:runGameCharacterTests>
)
