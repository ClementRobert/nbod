# -*- coding:Utf-8 -*-
import os

def rechfiles(rep = '') :
    #retourne une liste de fichiers dans le repertoire d'entrée "IN", donné en chemin relatif
    fichiers = []
    cwd = os.getcwd()
    if rep != '' :
        IN = '/' + rep
        OUT = rep + '/'
    else :
        IN = ''
        OUT = ''
    for fic in os.listdir(cwd+IN) :
        if not fic.startswith('._') and not fic.endswith('~') :
            fichiers.append(OUT+fic)
    return fichiers


def compterlignes(rep = '') :
    #affiche le nombre total de lignes des fichiers fits dans le répértoire IN
    liste = rechfiles(rep)
    N = 0
    for fic in liste :
        n = 0
        try :
            f = open(fic)
        except :
            1
        else : 
            for line in f :
                n+=1
            print fic, ": ", n
        N += n
    print "nombre de lignes de code : {}".format(N)
