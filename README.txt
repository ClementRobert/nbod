Version : 07/17/2014
Author : Clément Robert
first implementation 05/26/2014

current compilation script : comprun.sh
current main file : scenario.cpp
parameters (G, c, timestep) and #includes in parameters.cpp (shouldn't this be a .h file ?)

*-*-*-*-*-*-*-*-*-*-*-*-*-
Possibles améliorations :
*-*-*-*-*-*-*-*-*-*-*-*-*-

===============
 prioritaire :
===============

* nouvelle classe ou attribut des clusters pour les massless particles ?
* implementer solution pour collision (donc destructeurs et moyen d'éditer la m_adresses...) afin de mieux génerer les aléas des scripts à particules aléatoires

===============
   à terme :
===============

* integrateur RK4 ou frogleap prolongé (ordre 4)
* réduire le nombre de constructeurs au profit de valeurs par défaut
* remplacer le script bash par un makefile ? (plus pour apprendre à les faires qu'autre chose)
