cmake_minimum_required(VERSION 3.10.2)

# set(CMAKE_CXX_FLAGS "-std c7.5.0")

project (banderitas VERSION 1.0.0)

# add the executable
#add_library ()
#say-ola
#dados.h
#logica.h
#interface.h
#lista.h


add_executable(
Bot4
bot.c
dados.c
logica.c
interface.c
lista.c
)

#target_link_libraries (Banderitas PRIVATE say-ola)
