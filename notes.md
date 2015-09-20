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

misc notes (old)
================

##Possibles améliorations

###prioritaires

- nouvelle classe ou attribut des clusters pour les massless particles ?
- implementer solution pour collision (donc destructeurs et moyen d'éditer la m_adresses...) afin de mieux génerer les aléas des scripts à particules aléatoires

###à terme

* integrateur RK4 ou frogleap prolongé (ordre 4)
* réduire le nombre de constructeurs au profit de valeurs par défaut
