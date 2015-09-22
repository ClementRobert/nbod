<meta charset="UTF-8">

Notes/TODOS
===========

##Problèmes actuels

##A faire 

- créer classes 2D et 3D vectors puis classes filles pos, vel, acc, forces, en vue d'implémenter des lois d'additon propres et éviter les erreurs du type (acc+vel) dans le code.
- ameliorer/afiner la méthode de construction random des position/velocités/masses selon une loi uniforme
- permettre l'utilisation d'une loi gaussienne avec la dispersion en argument à la fois pour les masses, les positions et les velocités
- ajouter affichage du centre de masse
- ajouter tracé des orbites instatanées
- vérifier l'existence des 4 fonctions minimales pour chaque classe 


###Affichage
- il faut une méthode de classe draw() pour Cluster (dont héritera SolarSystem) avec arguement refpos par défaut centré sur le soleil

###Integrateurs
- rk4 needs :
 * constructeur par recopie de Cluster
 * operateur affectation Cluster = Cluster
 * modification de la méthode "euler" (et componestep) pour prendre en argument le step (donc le demi step quand nécessaire)
- leap frog : besoin de lire la [doc](https://en.wikipedia.org/wiki/Leapfrog_integration) dessus


##Bugs
- Le soleil (et peut-être les autres particules aussi) n'est pas affiché avec son propre rayon.
- le bouton fermetture de la fenêtre ne répond pas (le if correspondant doit être mal positioné dans le code)

misc notes (old)
================

##Possibles améliorations

###prioritaires

- nouvelle classe ou attribut des clusters pour les massless particles ?
- implementer solution pour collision (donc destructeurs et moyen d'éditer la m_adresses...) afin de mieux génerer les aléas des scripts à particules aléatoires

###à terme

* integrateur RK4 ou frogleap prolongé (ordre 4)
* réduire le nombre de constructeurs au profit de valeurs par défaut
