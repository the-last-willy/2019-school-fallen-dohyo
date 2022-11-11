# Fallen Dohyo

Fallen Dohyo est un jeu de combat en multijoueur local.
Le but est de pousser l'adversaire en dehors de l'arêne.

## Arborescence

- bin: exécutables (.exe, .out), librairies dynamiques (.dll)
- build: fichiers objets (.o), makefiles de dépendance (.d)
- doxygen: Doxyfile, documentation html
- ext: sources des dépendances (.zip)
- inc: headers des dépendances (.hpp)
- lib: librairies statiques (.a, .lib)
- media: textures (.png)
- src: code source du projet (.cpp, .hpp)

## Dépendances

- Catch 2
- EnTT 2.0.0
- SFML 2.4.2

Catch 2 et EnTT sont des bibliothèques 'headers only',
il n'est pas nécessaire de les compiler.

## Contrôles

Aller à gauche: Q, Flèche gauche
Aller à droite: D, Flèche droite
Sauter: Z, Flèche haute
Foncer: Espace, Numpad0

## Compilation

A la racine du dossier, exécuter la cible makefile:
- sous Windows, bin/debug.exe
- sous Linux, bin/debug.out

## Documentation

A la racine du dossier, executer la cible makefile 'doc'.
La documentation sera générée dans le dossier ./doc/html.
