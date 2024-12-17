cmake_minimum_required(VERSION 3.5)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/headers)


add_subdirectory(lib/googletest-main)

set(gtest_SOURCE_DIR lib/googletest-main/)

include_directories(${gtest_SOURCE_DIR}/googletest/include)

# Aggiungi la directory di inclusione SFML
include_directories(${SFML_INCLUDE_DIR})



set(SOURCE_TEST_FILES
        Test1.cpp
        RoomTest.cpp

        # Aggiungi qui anche i file delle implementazioni
        ../headers/Room.h
        ../headers/Room_Manager.h
        ../headers/RoomFactory.h
        ../src/Rooms_Structure/Room.cpp
        ../src/Rooms_Structure/Room_Manager.cpp
        ../src/Rooms_Structure/RoomFactory.cpp
)




add_executable(runAllTests ${SOURCE_TEST_FILES})
add_executable(tests Test1.cpp)

#ROOM TEST
add_executable(roomTests RoomTest.cpp)

message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

add_custom_command(TARGET roomTests PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/test/assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/test/assets
        COMMENT "Copying assets to the test directory"
)
  

# Aggiungi il codice per la copia della cartella assets nella directory di esecuzione
add_custom_command(TARGET roomTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:roomTests>/assets"
        COMMENT "Copying assets directory to output folder"
)


# Copia i file .dll di SFML nella directory di esecuzione di roomTests
add_custom_command(TARGET roomTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "C:/SFML/bin"
        $<TARGET_FILE_DIR:roomTests>
)

# Assicurati che roomTests e runAllTests abbiano SFML
target_link_libraries(runAllTests PRIVATE gtest gtest_main rooms sfml-system sfml-window sfml-graphics sfml-audio)
target_link_libraries(roomTests PRIVATE gtest gtest_main rooms sfml-system sfml-window sfml-graphics sfml-audio)




