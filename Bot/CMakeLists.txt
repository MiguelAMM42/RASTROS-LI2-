cmake_minimum_required(VERSION 3.10.2)

# set(CMAKE_CXX_FLAGS "-std c7.5.0")

project (banderitas VERSION 1.0.0)


add_library (
say-ola SHARED
dados.h
dados.c
logica.h
logica.c
interface.h
interface.c
)

add_executable(
BotGoncalo
bot.c
)

target_link_libraries (BotGoncalo PRIVATE say-ola)