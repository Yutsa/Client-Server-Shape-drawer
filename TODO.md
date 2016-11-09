TODO
-----
Itérations de développement
==============================

1 ère version : simple client/serveur permettant de dessiner une forme.
2 ème version : simple client/serveur permettant de dessiner toutes 
	            les formes demandées.
				
1 - Mettre en place un protocole pour transmettre forme
==============================================================

Ce protocole doit permettre de faire passer la couleur de la forme 
ainsi que les informations permettant de la tracer.

Les différentes formes simples à tracer sont : 

* Segment
* Cercle
* Triangle
* Polygone quelconque fermé (sans auto-intersection)

Le nombre de valeurs à faire passer dans les message varient car 
il peut y avoir un nombre non défini de segment à tracer pour les 
polygones, selon leur taille. Il faut donc un moyen de savoir qu'on 
a lu toutes les informations.

Un premier exemple de protocole simple pourrait être le suivant :

`couleur,nomForme,coord1,coord2,coord3,coord4,coord5,coord6,END`

ce qui donnerait par exemple : `black,triangle,30,40,23,98,78,56,END`

2 - Création du serveur, DP chain of responsability
=========================================================

Un serveur Java multisocket qui écoute puis dessine la forme demandée par 
le client.

Il peut également effectuer les transformations demandées par le client.

Pour distinguer les formes à dessiner on implémentera le design pattern 
chain of responsability.

3 - Application de transformation aux formes
=================================================

On doit pouvoir effectuer les transformations suivantes :

* Translation
* Homothétie
* Rotation

4 - Séparation de l'appel "dessiner forme" et du serveur
===============================================================

On doit implémenter le design pattern Visitor pour dessiner une 
forme en utilisant d'autres librairies et donc sans passer par 
le serveur java utilisant swing.

5 - Utilisation d'un singleton pour l'initialisation des sockets côté client
=====================================================================================

L'initialisation du socket côté client devra être effectué par un 
singleton pour être sûr qu'elle sera effectué une seule fois.

6 - Création de formes complexes
====================================

À partir des formes simples on pourra créer des formes complexes.
