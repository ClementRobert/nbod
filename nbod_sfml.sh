#!/bin/bash

echo ""
echo "compilation"
main="main_sfml.cpp"
out="main_sfml.o"

if [ -e $out ]; then
    rm $out
fi

g++ $main sources/*.cpp -I headers -std=c++11 -Wextra -ansi -pedantic -O2 -s -o $out -lsfml-graphics -lsfml-window -lsfml-system

if [ -e $out ]; then
    echo "execution"
    ./$out

    # echo "nettoyage"
    # if [ -e *~ ]; then 
    #     rm -vr *~ #vire les fichiers temporaires
    # fi
    # if [ -e *.pyc ]; then 
    #     rm -vr *.pyc
    # fi
    # rm -v nbod_main
fi


echo "fin du script"
echo ""
