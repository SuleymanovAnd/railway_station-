cmake_minimum_required(VERSION 3.22)

set (MY_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

set(SOURCE
        main.cpp

        )
set(INCLUDE
        ${MY_DIRECTORY}/
        )


add_executable(elf_village ${SOURCE} ${INCLUDE})
target_include_directories (elf_village PUBLIC ${MY_DIRECTORY})

add_executable(railway_station main.cpp)