<meta charset="UTF-8">

Notes/TODOS
============

##Problèmes actuels

###Affichage
- le soleil devrait avoir sa propre classe Star pour utiliser un affichage différent, et une densité différente, sinon le rayon utilisé cache toutes les planètes
- il faut une méthode de classe draw() pour Cluster (dont héritera SolarSystem) avec arguement refpos par défaut centré sur le soleil

###Integrateurs
- rk4 needs :
 * constructeur par recopie de Cluster
 * operateur affectation Cluster = Cluster
 * modification de la méthode "euler" (et componestep) pour prendre en argument le step (donc le demi step quand nécessaire)
- leap frog : besoin de lire la [doc](https://en.wikipedia.org/wiki/Leapfrog_integration) dessus

##A faire 

- ameliorer/afiner la méthode de construction random des position/velocités/masses

