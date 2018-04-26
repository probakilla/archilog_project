#### REVERSI@CODE@C++ ####

Options de CMAKE :
    Par défaut, toutes les options sont désactivées.
    Liste des options :
    -DTESTS : Inclut le fichier des tests lors du build des exécutables. Pour
        lancer les tests, il faut effectuer la commande 'make test' après avoir
        compilé le programme (make).
    -DDEBUG : Ajoute l'option -g à g++.
Exemple d'utilisation :
    Depuis le fichier code/build
        cmake -DTESTS=ON

Cibles du Makefile supplémentaires:
    - doc    : Génère la documentation du code avec doxygen et l'ouvre dans le
      navigateur par défaut.
    - format : Lance la commande clang-format sur tout les fichiers du projet.
Exemple d'utilisation :
    Depuis le fichier code/build
        make format