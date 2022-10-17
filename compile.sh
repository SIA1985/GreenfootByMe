#!/bin/bash

g++ -pthread -g -Wall -I/cplusplus/SFML-2.5.1/include main.cpp UILib/UIObjects.cpp UILib/UI.cpp UILib/WindowWithUI.cpp UILib/ComplicatedUIs.cpp UILib/ComplicatedWindowsWithUI.cpp UILib/ComplicatedUIObjects.cpp -o GreenfootByMe -L/cplusplus/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system

./GreenfootByMe
