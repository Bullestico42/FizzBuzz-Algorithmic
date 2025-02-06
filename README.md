FizzBuzz Grid Generator

🎥 Présentation vidéo

[Insérez ici le lien vers la vidéo explicative]

📌 Description du projet

FizzBuzz Grid Generator est un projet visant à explorer la complexité émergente d'un système basé sur une itération avancée du principe du FizzBuzz. Le FizzBuzz classique est souvent utilisé comme test de base en programmation : il consiste à afficher "Fizz" pour les multiples de 3, "Buzz" pour les multiples de 5, et "FizzBuzz" pour les multiples de 3 et 5. Ici, ce concept est étendu à une grille dynamique qui évolue au fil du temps en fonction des règles suivantes :

Chaque cellule de la grille est initialisée à 0.

À chaque itération, une cellule aléatoire contenant 0 est remplacée par 1.

Si l'itération actuelle est un multiple de 3 (Fizz), toutes les cellules contenant 1 deviennent 2.

Si l'itération actuelle est un multiple de 5 (Buzz), toutes les cellules contenant 2 redeviennent 1.

Si l'itération actuelle est un multiple de 3 et 5 (FizzBuzz), toutes les cellules contenant 1 ou 2 sont réinitialisées à 0.

Ce processus crée un motif évolutif qui varie en fonction du nombre d'itérations et de la distribution aléatoire des transformations.

Le but de ce projet est d’illustrer de manière visuelle et interactive comment des règles simples peuvent générer un comportement complexe lorsqu'elles sont appliquées à une structure dynamique. L’évolution de la grille est affichée en temps réel, permettant d’observer des cycles, des motifs émergents et des zones de stabilité ou d’instabilité selon les itérations.

🖥️ Affichage dynamique

L'affichage de la grille est mis à jour en continu afin de refléter les transformations en cours. Chaque itération apporte une modification visible qui permet d’étudier l'impact des règles appliquées sur la répartition des valeurs dans la grille. Ce suivi graphique offre une représentation intuitive du fonctionnement interne de l’algorithme et met en évidence l'évolution des cellules en fonction du temps.

L'idée principale est de donner une vision interactive de l'effet combiné du hasard et des règles déterministes. Il devient alors possible d’observer comment certaines structures persistent au fil des itérations tandis que d'autres disparaissent sous l'effet des transformations successives.

🔊 Intégration audio (SDL2)

En complément de l'affichage visuel, une composante sonore a été intégrée grâce à la bibliothèque SDL2. Chaque transformation de la grille s'accompagne d'un effet sonore chiptune, ajoutant une dimension supplémentaire à l'expérience interactive du programme.

Les sons sont déclenchés selon les règles suivantes :

Une note spécifique est jouée lorsqu'un 1 apparaît sur la grille.

Une tonalité différente est utilisée lorsqu'un 1 devient 2 sous l'effet de Fizz.

Une autre variation sonore est émise lorsqu'un 2 redevient 1 sous l'effet de Buzz.

Lors d’un FizzBuzz, une séquence sonore spéciale est jouée pour marquer la réinitialisation de la grille.
