cmake_minimum_required(VERSION 3.22)

set (MY_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

set(SOURCE
        main.cpp
        station.cpp
        train.cpp
        )
set(INCLUDE
        ${MY_DIRECTORY}/station.h
        ${MY_DIRECTORY}/train.h
        )


add_executable(elf_village ${SOURCE} ${INCLUDE})
target_include_directories (elf_village PUBLIC ${MY_DIRECTORY})

