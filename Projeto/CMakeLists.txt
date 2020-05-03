cmake_minimum_required(VERSION 3.10.2)

# set(CMAKE_CXX_FLAGS "-std c7.5.0")

project (Rastos VERSION 1.1.1)


add_library (
Bibliotecas SHARED
dados.h
dados.c
logica.h
logica.c
interface.h
interface.c
lista.h
lista.c
)

add_executable(
Jogo
main.c
)

target_link_libraries (Jogo PRIVATE Bibliotecas)
