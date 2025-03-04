cmake_minimum_required(VERSION 3.5)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})



add_subdirectory(lib/googletest)
set(gtest_SOURCE_DIR  ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include)



set(TEST_SOURCE_FILES test_main.cpp
        test_room_factory.cpp
        test_enemy_factory.cpp
        test_state_playing.cpp
        test_basic.cpp
        test_sound.cpp
        test_negativeDamage.cpp
        test_messagebox.cpp
        test_fighting.cpp
)
add_executable(RunALLTests ${TEST_SOURCE_FILES})
target_link_libraries(RunALLTests gtest gtest_main core sfml-system sfml-window sfml-graphics sfml-audio)

#implemento le DDL di SFML nella directory di TEST per assicurarmi che siano visibili
add_custom_command(TARGET RunALLTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "C:/SFML/bin"
        $<TARGET_FILE_DIR:RunALLTests>
)
