# Diagramme des classes

## Le client

### Les classes utilitaires et géométriques

#### La classe Vector2D

Ils représentent des points ou des vecteurs. Ils sont la base de toutes les formes mais aussi de tous les vecteurs de transformations (translation, homothétie et rotation) qui seront réalisées. 

Cette classe est composée de 2 nombres réèls pour chaques coordonnée x et y. Les opérations de bases (+, -, *) y sont implémentées grâce à la surcharge des opérateurs déja présents. Les opérations de transformations sont elles aussi présentent pour pouvoir les effectuer directement sur chaque point.

#### Les Couleurs

Les couleurs sont gérées par une classe couleur constituée de 3 unsigned char : rouge, vert et bleu. Ce sont simplement les valeurs RGB qui vont nous permettrent de créer la couleur.

Elle dispose également d'une map contenant quelques couleurs de base déjà créées. La méthode qui permet d'accéder à la map de couleur est statique, il est ainsi possible d'y accéder sans que la classe soit instanciée. Les couleurs pré-enregistrée sont accessible grâce à une chaine de caractère caractérisant la couleur ("red", "blue" ...).

#### Les Angles

Les angles, aussi ont une classe pour eux. Elle est très simple puisqu'elle se comporte comme une encapsulation d'un unique nombre réèl, la valeur en radian de l'angle. Son constructeur et ses méthodes de modifications (surtout des surcharges d'opérateurs) vérifient juste que l'angle est bien compris entre 0 et 2*pi, et l'ajuste (modulo 2*pi) si besoin.

Les nombreuses surcharges d'opérateur permettent d'utiliser les angles très simplement (+, -, *, cos, sin ...).

### Les formes

#### La classe Shape

La classe shape est la classe mère de toute les formes. Autrement dit, toutes les formes héritent de cette dernière. Le seul membre commun à toutes les formes est la couleur, qui est ainsi déclaré ici. Sans ce membre la classe pourrait se résumer à une interface. Et les méthodes sont nombreuses
1. Les méthodes de transformation géométrique et de calcul d'aire
2. Celles de dessin et de sauvergarde
3. Et les opérateurs << et (string) 

Mis à part l'opérateur << et les getters/setters, toutes les méthodes sont des virtuelles pures. Nous reviendrons sur l'implémentation de ces dernières.

Chaque forme étant composée d'au moins un Vector2D, lorsque l'on applique une transformation sur une forme on effectue simplement cette transformation sur chacun de ses points, c'est à dire chaque Vector2D qui la compose. En effet l'opération est la même pour toutes les formes : pour appliquer un rotation à une forme, il faut appliquer une rotation à tous les points de la formes. Un seul cas particulier est à gérer, lors d'une homothétie avec un cercle ; il n'est pas possible d'appliquer une homothétie sur tous les points du cercle mais il suffit de l'appliquer sur le centre et de multiplier le diamètre par le ratio de l'homothétie.

Dans le cas de la forme composée, les transformations sont appliquées successivement pour chacunes des formes élémentaires qui la composent.

#### Les classe des formes

Comme dit précedemment, les formes héritent toutes de la classe Shape. Elles sont chacunes composées de caractériques précises. La seule forme de sous-héritage est entre Triangle et Polygon puisque Triangle est aussi un Polygon.

Toutes disposent d'un opérateur de cast en string, qui vas nous être très utile puisque c'est celui la même qui va nous permettre de communiquer les caractéritiques de nos formes.

#### La classe de forme composée

Les différentes formes la composent sont stockés dans un tableau de forme. Du coup chacune des opérations qui doivent être executées le sont pour chacunes des formes l'une après l'autre. 

### Le socket

Nous avons décidé de n'utiliser qu'un seul socket par client. Se socket ne doit donc être créé qu'une seule fois, c'est pourquoi il est implémenté grâce à un singleton.

Ce singleton mets à disposition plusieurs méthodes statiques que l'on peut donc appeler pour transmettre les messages au serveur. Le fait que ces méthodes soient statiques permet de les utiliser sans devoir tout le temps passer l'instance en paramètes.

Le socket possède 3 méthodes essentielles. La première permet de connecter le socket au serveur, en y renseignant l'adresse IP et le port de ce dernier. Les deux suivantes permettent d'envoyer et de recevoir, c'est à dire de communiquer avec le serveur. Les deux fonctionnent avec des chaine de caractères.  

Une dernière fonction permet de fermer la connexion avec le serveur en fin de 
session.

#### Protocoles de communication avec le serveur

Ce protocole doit permettre de faire passer la couleur de la forme ainsi que les informations permettant de la tracer. 

Les différentes formes simples à tracer sont :

* Segment
* Cercle
* Triangle
* Polygone quelconque fermé (sans auto-intersection)

Le nombre de valeurs à faire passer dans les message varient en fonction des formes puisqu'elle n'ont pas le même nombres de membre. Et dans le cas du polygone il peut y avoir un nombre non défini de segments à tracer, selon la taille du polygone. La chaine de caractère qui va être envoyée au serveur commence donc par la nom de la forme ce qui lui permettra de savoir rapidement ce qu'il devra dessiner.
S'en suivent ensuite la couleur sous sa forme rgb, puis en fonction de la forme, ses différentes caractéristiques.

Le protocole se comporte de la façon suivante :

`nomForme,red,green,blue,coord1,coord2,coord3,coord4,coord5,coord6`

Ce qui donnerait avec un exemple : `triangle,0,0,255,30,40,50,60,70,80`
pour un triangle bleu avec (30;40), (50;60) et (70;80) en coordonées.

Dans le cas de la forme composée, la nom commencera par le mot `composedshape` puis les différentes formes y seront listées entre des '|'. Ce qui nous donne avec un exemple :

`composedshape|triangle,r,g,b,1,2,3,4,5,6|segment,r,g,b,1,2,3,4

Chacunes des formes sera ainsi traitée une après l'autre.

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

Chargement de forme
======================

Pour pouvoir charger des formes nous avons décider de créer deux 
chain of responsibility.

Une qui se chargera de reconnaître le format de sauvegarde utilisé.

Et l'autre qui se chargera de reconnaître la forme stockée et 
l'instanciera.

Ainsi la première chaîne reconnait le format de sauvegarde, traduit 
ce format dans le même format que l'on utilise pour transmettre les 
données au serveurs. On passe ensuite cette string à la chaine qui 
va retourner une instance de la forme qui était sauvegardée.

Dessin avec Qt
================

Nous avons choisi comme fonctionnalité supplémentaire d'implémenter 
un mode de dessin utilisant la librairie Qt.

Cela a demandé plusieurs modifications dans notre code. En effet 
lorsque l'on dessine avec Qt, nous utilisons une classe QtDrawer 
qui hérite de DrawingVisitor.

Cependant pour dessiner avec Qt nous devons créer une QGraphicsScene 
ainsi qu'une QGraphicsView qui vont changer lors des dessins.

Donc l'instance de QtDrawer ne peut être const. Comme ServerDrawer 
lui ne changeait rien nous avions passé le DrawingVisitor en const 
dans les méthodes draw des formes ce que nous avons donc du changer.
