# S5 Project - Countdown Numbers Game

This was one of the first C projects I coded in 2022.

The rules are as follows: only strictly positive numbers are drawn, from 1 to 10 up to two times each, and 25, 50, 75, 100 appear only once each. The target must also be strictly positive and below 100,000.

Note: The programs work well for games up to 8 draws using the predefined game files. Beyond this, the calculation times become significantly longer, even though nearly all proposed optimizations were implemented (except for commutativity in addition). Similar issues occur for randomly drawn games and games chosen by the user. It remains to be seen if this is due to limited computing power or inadequate algorithm optimization.

About Algorithm 1:
The file recapFonctions.c contains all functions essential to its operation.
The library recapFonctions.h includes the function declarations and is imported at the beginning of algorithme1.c.

How it works:
The file is compiled using the command: make algorithme1.

Once compiled, the executable file can be run in 3 different ways: user-selected game, random game, or game file.

Without additional arguments (by command ./algorithme1): the program asks if this choice is desired.

          If yes, the program asks if the user wants to search for a solution from a random game or a chosen game.

          If random game: only the target will be requested, and the program will verify that the target follows the rules.

          If chosen game: the user selects numbers and target, which are then checked for compliance with the rules.

          If the game and target do not meet the rules, a new draw is initiated or the program stops, depending on user choice.

With an additional argument (for example, with the command ./algorithme1 ./jeux/jeu7-2.txt): the program reads data (number of draws, drawn numbers, target) from the specified game file.

The program checks if the game is already solved:

          If so, it notifies the user with the message “game already solved.”

          If a solution is found: the program notifies the user with the message "Bingo" and displays the operations and numbers used to reach the target.

          If no combination works: the program displays the message “Oops.”

About Algorithm 2:
The file recapFonctions.c contains all functions essential to its operation.
The library recapFonctions.h includes function declarations and is imported at the beginning of algorithme2.c.

How it works:
The file is compiled using the command: make algorithme2.

Once compiled, the executable file can be run in 3 different ways: user-selected game, random game, or game file.

Without additional arguments (by command ./algorithme2): the program asks if this choice is desired.

          If yes, the program asks if the user wants to search for a solution from a random game or a chosen game.

          If random game: only the target will be requested, and the program will verify that the target follows the rules.

          If chosen game: the user selects numbers and target, which are then checked for compliance with the rules.

          If the game and target do not meet the rules, a new draw is initiated or the program stops, depending on user choice.

With an additional argument (for example, with the command ./algorithme2 ./jeux/jeu7-2.txt): the program reads data (number of draws, drawn numbers, target) from the specified game file.

The program checks if the game is already solved:

          If so, it notifies the user with the message “game already solved.”

          If a solution is found: the program notifies the user with the message "Bingo" and displays the operations and numbers used to reach the target.

          If no combination works: the program notifies the user with the message "No exact solution found, the closest result is: closest_result" and displays the operations and numbers used to achieve this closest result.

# Projet S5 Compte est bon

On rappelle les règles : nombres tirés sticts positifs, de 1 a 10 jusqu'à 2 exemplaires et 25, 50, 75, 100 en 1 exemplaire
Et : la cible doit être strictement positive et inférieure à 100000

A noter : les programmes fonctionnent bien pour des jeux allant jusqu'à 8 tirages pour les fichiers jeux imposés, au-delà les temps de calculs
          sont infiniment plus grands même si presque toutes les optimisations proposées ont été implantées (hormis la commutativité pour l'addition).
          Un problème similaire est notable pour des jeux tirés au hasard et ceux choisi par l'utilisateur.
          Reste à voir si cela provient de la faible puissance des ordinateurs que nous possédons ou si cela est dû à une mauvaise optimisation de l'algorithme.

Concernant l'algorithme 1 :

 - le fichier recapFonctions.c contient toutes les fonctions utiles à son fonctionnement

 - la libraire recapFonctions.h contient leur squelette et est implantée en début du fichier algorithme1.c

 - comment ça fonctionne ?

    -> le fichier se compile par l'intermédiaire de la commande : make algorithme1

    -> une fois compilé, le fichier exécutable s'exécute de 3 manières différentes : jeu tiré par l'utilisateur, jeu aléatoire, fichier jeu

        * sans argument supplémentaire (par la commande ./algorithme1): le programme demande si cette décision est voulue,

         si oui, le programme demande si l'utilisateur souhaite réaliser la recherche de solution a partir d'un jeu aléatoire ou un jeu choisi

         si jeu aléatoire : seule la cible souhaitée sera demandée, on vérifiera que la cible respecte les règles

         si jeu choisi : on laisse l'utilisateur choisir ces nombres et sa cible, on vérifie si le jeu et la cible vérifient les règles

              si ce n'est pas le cas, on recommence le tirage ou on arrête le programme selon le choix de l'utilisateur

        * avec argument supplémentaire (par exemple avec la commande ./algorithme1 ./jeux/jeu7-2.txt):

          le programme lit les données (nombre de tirage, les tirages, la cible) dans le fichier jeu imposé

    -> le programme vérifie si le jeu n'est pas déjà résolu :

        si oui, il le montre à l'utilisateur par l'intermédiaire du message "jeu déjà résolu"

    -> en cas de solution trouvée : le programme le montre à l'utilisateur par l'intermédiaire du message "Bingo"

        il affiche ensuite les opérations et les nombres manipulés pour en arriver à la cible

    -> si aucune combinaison ne fonctionne : le programme le montre à l'utilisateur par l'intermédiaire du message "Oups"

Concernant l'algorithme 2 :

     - le fichier recapFonctions.c contient toutes les fonctions utiles à son fonctionnement

     - la libraire recapFonctions.h contient leur squelette et est implantée en début du fichier algorithme2.c

     - comment ça fonctionne ?

        -> le fichier se compile par l'intermédiaire de la commande : make algorithme2

        -> une fois compilé, le fichier exécutable s'exécute de 3 manières différentes : jeu tiré par l'utilisateur, jeu aléatoire, fichier jeu

            * sans argument supplémentaire (par la commande ./algorithme2): le programme demande si cette décision est voulue,

             si oui, le programme demande si l'utilisateur souhaite réaliser la recherche de solution a partir d'un jeu aléatoire ou un jeu choisi

             si jeu aléatoire : seule la cible souhaitée sera demandée, on vérifiera que la cible respecte les règles

             si jeu choisi : on laisse l'utilisateur choisir ces nombres et sa cible, on vérifie si le jeu et la cible vérifient les règles

                  si ce n'est pas le cas, on recommence le tirage ou on arrête le programme selon le choix de l'utilisateur

            * avec argument supplémentaire (par exemple avec la commande ./algorithme2 ./jeux/jeu7-2.txt):

              le programme lit les données (nombre de tirage, les tirages, la cible) dans le fichier jeu imposé

        -> le programme vérifie si le jeu n'est pas déjà résolu :

            si oui, il le montre à l'utilisateur par l'intermédiaire du message "jeu déjà résolu"

        -> en cas de solution trouvée : le programme le montre à l'utilisateur par l'intermédiaire du message "Bingo"

            il affiche ensuite les opérations et les nombres manipulés pour en arriver à la cible

        -> si aucune combinaison ne fonctionne :

          le programme le montre à l'utilisateur par l'intermédiaire du message "aucune solution exacte trouvée, la plus proche étant :        "aucune solution exacte trouvée, la plus proche étant : le_resultat_trouvé"

          il affiche ensuite les opérations et les nombres manipulés pour en arriver à ce résultat
