cmake_minimum_required(VERSION 3.29)
project(TABELA_HASH)

set(CMAKE_CXX_STANDARD 17)

add_executable(TABELA_HASH main.cpp
        Aluno.cpp
        Aluno.h
        Hash.cpp
        Hash.h)
