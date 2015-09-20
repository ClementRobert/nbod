<meta charset="UTF-8">

Notes/TODOS
============

##Problèmes actuels

###Integrateurs
- rk4 needs :
 * constructeur par recopie de Cluster
 * operateur affectation Cluster = Cluster
 * modification de la méthode "euler" (et componestep) pour prendre en argument le step (donc le demi step quand nécessaire)
- leap frog : besoin de lire la [doc](https://en.wikipedia.org/wiki/Leapfrog_integration) dessus

###Affichage
- le centrage est mal fait
- le dessin actuel utilise la position réelle d'une particule comme un _coin_ (ul) de la figure (cercle), ce qui est extrêmement voyant quand on dessine un soleil et son cortège de planètes
- le soleil devrait avoir sa propre classe Star pour utiliser un affichage différent, et une densité différente, sinon le rayon utilisé cache toutes les planètes
- il faut une méthode de classe draw() pour Cluster (dont héritera SolarSystem) avec arguement refpos par défaut centré sur le soleil

