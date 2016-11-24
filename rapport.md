Choix d'implémentation
-----------------------

Protocoles de communication avec le serveur
============================================

Ce protocole doit permettre de faire passer la couleur de la forme
ainsi que les informations permettant de la tracer.

Il faut aussi savoir si l'on doit ouvrir une nouvelle fenêtre (nouvelle forme)
ou bien si on doit garder la même fenêtre (rotation, homothétie etc).

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

`nomForme,red,green,blue,coord1,coord2,coord3,coord4,coord5,coord6`

ce qui donnerait par exemple : `triangle,23,43,54,30,40,23,98,78,56`
pour dessiner un triangle dans une nouvelle fenêtre.

Vector2D
=========

Les Vector2D représentent des points ou des vecteurs. Ils sont la base de toutes 
les formes mais aussi de tous les vecteurs de transformations (translation, 
homothétie et rotation) qui sont réalisées.

Cette classe est composée de 2 nombres réèls pour chaques coordonnée x et y. Les
opérations de bases (+, -, *) y sont implémentées grâce à la surcharge des
opérateurs déja présents. Les opérations de transformations sont elles aussi
présentent pour pouvoir les effectuer directement.

Couleur
========

Les couleurs sont gérées par une classe couleur constituée des valeurs
rouge, vert, bleu pour créer la couleur.

Mais également d'une map contenant quelques couleurs de base déjà créées,
accessible grâce à une chaine de caractère caractérisant la couleur 
("red", "blue" ...).

La méthode qui permet d'accéder à la map de couleur est statique, il est ainsi
possible d'y accéder sans que la classe soit instanciée.

Angle
======

Les angles, aussi ont une classe pour eux. Elle est très simple puisqu'elle
se comporte comme une encapsulation d'un unique nombre réèl, la valeur en radian
de l'angle. Son constructeur et ses méthodes de modifications (surtout des 
surcharges d'opérateurs) vérifient juste que l'angle est bien compris entre 0 et 2*pi,
et l'ajuste (modulo 2*pi) si besoin.

Les nombreuses surcharges d'opérateur permettent d'utiliser les angles très simplement 
(+, -, *, cos, sin ...).

Transformations de formes
==========================

Chaque forme étant composée de Vector2D, lorsque l'on applique une
transformation sur une forme on effectue simplement cette transformation
sur chacun de ses points, c'est à dire chaque Vector2D qui la compose.
La transformation s'effectue alors simplement sur toute la forme. Un seul
cas particulier est à gérer lors d'une homothétie avec un cercle ; il n'est
pas possible d'appliquer une homothétie sur tous les points du cercle mais 
il suffit simplement de l'appliquer sur le centre et de multiplier le
diamètre par le ratio de l'homothétie.

Dans le cas de la forme composée, les transformations sont appliquées 
successivement pour chacunes des formes élémentaires qui la composent.

Création du socket
===================

Nous avons décidé de n'utiliser qu'un seul socket par client. Se socket
ne doit donc être créé qu'une seule fois, c'est pourquoi il est
implémenté grâce à un singleton.

Ce singleton mets à disposition plusieurs méthodes statiques que l'on
peut donc appeler pour transmettre les messages au serveur.

Le fait que ces méthodes soient statiques permet de les utiliser sans
passer l'instance en paramètes partout.

Le socket possède 3 méthodes essentielles. La première permet de connecter
le socket au serveur, en y renseignant l'adresse IP et le port de ce dernier.
Les deux suivantes permettent d'envoyer et de recevoir, c'est à dire de 
communiquer avec le serveur. Les deux fonctionnent avec des chaine de caractères.

Une dernière fonction permet de fermer la connexion avec le serveur en fin de 
session.

Dessin des formes
=================

Pour permettre l'utilisation de nouveaux modes de dessins nous
utilisons le design pattern visitor.

On met donc une classe abstraite permettant d'implémenter une méthode
de dessins pour chaque type de formes.

Il suffit ensuite de créer une classe descendant de cette interface
pour implémenter différents modes de dessins, avec une classe par
mode de dessin.

Nous avons implémenté le dessin utilisant un serveur Java. Pour ce cas
l'implémentation de chaque dessin est identique.

C'est pourquoi l'interface DrawingVisitor fourni une fonction draw pour chaque type de forme mais également une générale pour un Shape*

Ainsi si une méthode de dessin fait la même chose quelque soit la forme, on implémente la méthode draw prenant en paramètre un Shape*, et puis toutes les autres méthodes draw appeleront celle qui prend le Shape*.

Si une méthode a un traitement différent pour chaque forme, on implémentera chaque méthode draw puis on laissera un corps vide pour draw(Shape*).

Sauvegarde de forme
====================

La sauvegarde de forme utilise également le design pattern visitor et est implémenté de la même manière.
