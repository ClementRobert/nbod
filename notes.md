<meta charset="UTF-8">

Notes/TODOS
===========

##Problèmes actuels

###Affichage
- il faut une méthode de classe draw() pour Cluster (dont héritera SolarSystem) avec arguement refpos par défaut centré sur le soleil

###Integrateurs
- rk4 needs :
 * constructeur par recopie de Cluster
 * operateur affectation Cluster = Cluster
 * modification de la méthode "euler" (et componestep) pour prendre en argument le step (donc le demi step quand nécessaire)
- leap frog : besoin de lire la [doc](https://en.wikipedia.org/wiki/Leapfrog_integration) dessus

##A faire 

- ameliorer/afiner la méthode de construction random des position/velocités/masses
- ajouter affichage de l'étoile, du centre de masse
- ajouter tracé des orbites instatanées
- vérifier l'existence des 4 fonctions minimales pour chaque classe 


##Bugs
- Le soleil (et peut-être les autres particules aussi) n'est pas affiché avec son propre rayon.