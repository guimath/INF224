# INF224 - Guilhem Mathieux

## Avancement :

Je suis allé jusqu'à l'étape 11 en C++ et à la dernière étape en Java Swing.

## Partie C++ : réponses aux questions

### Étape 4 :

Comment appelle-t-on ce type de méthode et comment faut-il les déclarer ?

- Une méthode qui ne peut pas être appelée est une méthode dite virtuelle. On la définit en utilisant le mot-clé `Virtual`.

Il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?

- La classe de base est devenue une classe abstraite puisque l'une de ses fonctions est virtuelle. On ne peut donc plus instancier d'objet de cette classe.

### Étape 5 :

Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?

- C'est le polymorphisme qui permet d'appeler la méthode propre a chaque classe sans connaître la classe.


Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?

- Il faut déclarer le tableau en tant que tableau de pointeur d'éléments multimedia, ainsi la définition la plus haute de la fonction est appelée.


Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.

- Le tableau contient des pointeurs vers les objets, car c'est comme cela que l'on utilise nos objets de classe en C++. En Java, on aurais utilisé les objets directement.

### Étape 6

Que faut-il faire pour que l'objet `Film` ait plein contrôle sur ses données et que son tableau de durées des chapitres ne puisse pas être modifié (ou pire, détruit) à son insu ?

- Il faut le déclarer en `private` et ne jamais copier les pointeurs directement, mais bien les pointés.


Le contenu du tableau n'est pas recopié et l'appelant peut le modifier à sa guise. Quelle est la solution très simple que propose C/C++ pour éviter ce problème ?

- On peut soit créer un autre pointeur dans lequel on recopie les valeurs des durées des chapitres puis que l'on return, soit return le pointeur avec le mot clé `const` (on interdit ainsi la modification en dehors de la classe).

### Étape 7

Parmi les classes précédemment écrites, quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ?

- Il faut modifier toutes les classes avec des tableaux de données ce qui, dans notre cas, ce réduit à la classe Film.


De même, la copie d'objets peut poser problème dans certains cas. Pourquoi et que faudrait-il faire ?

- La copie d'objet pourrait entraîner deux objets avec des pointeurs en commun.

### Étape 8

La liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.

- La liste est bien une liste de pointeurs, car c'est comme cela que l'on accède à un objet d'une classe en C++. En Java, on aura directement l'objet.

### Étape 10

Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?

- Pour interdire la création d'objets en dehors de notre nouvelle classe, il faudrait déclarer le constructeur en private et rajouter la classe qui gère l'ensemble des fichiers (`FileProcSys` dans mon cas) en `friend`

## Partie Java : réponse aux questions

### Étape 1

Lancez votre programme, cliquez plusieurs fois sur les deux premiers boutons, retaillez la fenêtre. Que constate-t-on ?

- On constate qu'une partie de la `JTextArea` n'est plus visible. Pour palier ce problème, on rajoute un `JScrollPane` dans lequel on met notre `JTextArea` et qui nous permet de faire défiler le texte.

## Étape 2

- Notes : pour améliorer l'affichage, il faudrait changer le layout de manière à ne pas avoir un espacement vertical égale pour la `JToolBar` et la `JTextArea`.

### Étape 3

Notes :

- Pour améliorer l'affichage, il faudrait rajouter un menu déroulant à la place du textField des actions (comme on a choix limité d'action). On peut aussi imaginer faire de même pour la selection du fichier en rajoutant un méthode listant tout les fichier du coté `FileProcSys`.

- On pourrait aussi ajouter une boite de dialogue dans le cas où le fichier n'a pas été trouvé.

- De manière à améliorer la lisibilité de la réponse, il faudrait améliorer l'affichage (en rajoutant par exemple les line break au endroit auportain)