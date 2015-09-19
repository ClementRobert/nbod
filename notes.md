<meta charset="UTF-8">

Notes
=====

##Problèmes actuels

###Integrateurs
- rk4 needs :
 * constructeur par recopie de Cluster
 * operateur affectation Cluster = Cluster
 * modification de la méthode "euler" (et componestep) pour prendre en argument le step (donc le demi step quand nécessaire)
- leap frog : besoin de lire la [doc](https://en.wikipedia.org/wiki/Leapfrog_integration) dessus

###Affichage
- erreur de segmentation quand on appelle la fonction membre "draw" de la classe cluster
- le soleil dans le scénario (main) nbod_sfml.cpp n'a pas l'air de bouger du tout (tentative de le tracker ne semble rien amener comme info)

##Perspectives

- réparer/refondre Cluster::draw()
- implémenter LeapFrog (long term)