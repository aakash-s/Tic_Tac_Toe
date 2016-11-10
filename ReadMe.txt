The following project is designated for windows platform . It uses SDL2 as dependencies.
The following project is organised as follows

deps
--include
    contains sdl2 files used as dependencies.
--lib
    contains sdl2 library files used as dependencies.
  (in order to use them , you need to tell your compiler where to 
   look for these files, settings are different for different        compilers)

Tic_Tac_Toe
--assets
    contain graphics files for the project.In order to use them,     store them in the same directory as you executable.
--include
    header files for the project
--src
    contain cpp source files
--main.cpp
    
dlls
This contains all the dlls required to be placed in the same folder as your executive.

About the Project
This project is based on the MINIMAX algorithm that allows us to choose the best possible option in a game of Tic Tac Toe for every available choice , so that the computer always plays to win.

For creating user interface , it uses the functions of the SDL(Simple DirectMedia Layer) 2.0 library of C++. The code is organized in a object oriented way that makes it easier to understand.

    
