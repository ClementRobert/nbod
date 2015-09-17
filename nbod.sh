#!/bin/bash

echo ""
echo "compilation"
main="main_cluster.cpp"

g++ $main sources/*.cpp -I headers -std=c++11 -Wextra -ansi -pedantic -O2 -s -o nbod_main

if [ -e executable ]; then
    echo "execution"
    ./nbod_main

    echo "lecture"
    ipython lecteur.py

    echo "nettoyage"
    if [ -e *~ ]; then 
        rm -vr *~ #vire les fichiers temporaires
    fi
    if [ -e *.pyc ]; then 
        rm -vr *.pyc
    fi
    rm -v nbod_main

fi
echo "fin du script"
echo ""
