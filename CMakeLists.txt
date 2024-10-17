cmake_minimum_required(VERSION 3.29)
project(Progetto_Programmazione)

set(CMAKE_CXX_STANDARD 20)

add_executable(Progetto_Programmazione main.cpp)
include_directories(headers /usr/include c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED  graphics window system )
if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(TEsting_2 ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

#solo per windows , copia dlls per costruire la directory
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
ENDIF()