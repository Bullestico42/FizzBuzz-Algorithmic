![Capture d’écran 2024-11-14 210731](https://github.com/user-attachments/assets/bd270ed1-1060-43ea-8b6c-66cc562da68a)
Que fait la fonction ?
----------------------
La fonction ft_printf reproduit le comportement de la fonction printf de la bibliothèque <stdio.h>. Elle permet d'afficher une chaîne de caractères formatée avec différents types de variables.

Pour ce projet, j'ai le droit d'utiliser les bibliothèques suivantes :
-------
    <unistd.h> : elle me permet d'utiliser la fonction write pour écrire des caractères sur la sortie standard.
    <stdarg.h> : elle est utilisée pour gérer les arguments variables (va_arg) dans les appels de fonction, comme ceux spécifiés par %....

Quelle est la logique derrière le code ?
-
Mon approche a été de décomposer la chaîne de caractères fournie en entrée, selon le prototype suivant :

    int ft_printf(const char *str, ...);

Dans ce prototype, la chaîne str contient le texte à afficher ainsi que les directives de formatage, tandis que les trois points ... représentent les arguments supplémentaires, accessibles via va_arg, et qui contiennent les valeurs à afficher selon les directives dans str. Par exemple :

    ft_printf("Hello %s\n", "World!");

Ici, %s indique qu'une chaîne de caractères est attendue comme argument, ici "World!". L'objectif est de remplacer %s par "World!" dans la sortie.

Au début de la fonction, je vérifie si la chaîne str est valide. Si elle est NULL, la fonction se termine immédiatement. Sinon, je parcours str jusqu'à la fin. Pour chaque caractère, si celui-ci est un %, j'appelle la fonction convert, à laquelle je passe la position actuelle dans str et l'adresse des arguments. Si le caractère n'est pas un %, j'appelle ma fonction ft_putc qui affiche le caractère actuel sur la sortie standard.

Dans la fonction convert, je vérifie si le caractère suivant % correspond à l'un des formats suivants :

    %c : imprime un caractère.
    %s : imprime une chaîne de caractères.
    %d : imprime un entier signé.
    %u : imprime un entier non signé.
    %x : imprime une valeur en hexadécimal (minuscules).
    %X : imprime une valeur en hexadécimal (majuscules).
    %p : imprime l'adresse d'un pointeur.

Cas particuliers :
-
    %% : imprime simplement un %.
    %\0 (fin de chaîne) : signifie la fin de la chaîne, la fonction convert se termine ici.

Que font les fonctions appelées dans convert ?
-
    ft_putc et ft_putstr : ces fonctions affichent des caractères sur la sortie standard.
    ft_putc ne peut afficher qu'un seul caractère à la fois, tandis que ft_putstr peut afficher une chaîne de caractères complète.
    ft_puthex : cette fonction convertit et affiche une adresse en base hexadécimale (base 16).
    ft_putnbr : elle affiche un entier en base 10.
    ft_putun : cette fonction affiche un entier non signé en base 10.
    ft_putptr : elle convertit une donnée en adresse de pointeur, commençant toujours par 0x....


