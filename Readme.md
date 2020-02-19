# FT_Select

_A 42 termcaps project_

## Installation

```bash
$> make
```

## Usage

```bash
$> ./ft_select
usage: ft_select choix1 etc.
$> ls `./ft_select src/*.c`
```

## Sujet

* Ecrire un programme `ft_select` qui prend en paramètre une série d’arguments.\
La liste d’arguments s’affiche.

* L’utilisateur peut alors se déplacer dans la liste des arguments à l’aide des flèches (<kbd>↑ up</kbd> et <kbd>↓ down</kbd>) (la liste est circulaire).

* Un ou plusieurs choix peuvent être sélectionnés ou désélectionnés à l’aide de la touche <kbd>espace</kbd>. A chaque sélection effectuée, le curseur doit automatiquement se positionner sur l’élément suivant.

* Dès que l’utilisateur valide la sélection à l’aide de la touche <kbd>return</kbd>, la liste des choix doit être __renvoyée au shell__. Les choix renvoyés devront être separés par le caractère espace. Ceci permettra alors d’utiliser votre programme `ft_select` à l’intérieur d’un script shell (pour faire un "set", par exemple).

* On doit pouvoir écrire les commandes suivantes :
```bash
$> set reponse = `ft_select choix1 choix2 choix3 choix4`
$> more `ft_select *.c`
$> rm `ft_select ~/*`
```
> __NB:__ N'utilisez la dernière commande `rm` __QUE__ si vous êtes __SÛR__ que votre `ft_select` fonctionne. Nous dégageons toute responsabilité en cas de bug de votre `ft_select`...

* Vous devrez également gérer le redimensionnement de la fenêtre par l’utilisateur.\
La liste doit s’afficher sur plusieurs colonnes si la taille de la fenêtre ne comporte pas assez de lignes pour tout afficher en une seule colonne. Si l’utilisateur redimensionne la fenêtre en cours d’utilisation, l’ensemble des choix doit se repositionner automatiquement et les choix selectionnés doivent le rester. Le curseur de selection doit être positionné de manière raisonnable après un redimensionnement.

* Si la fenêtre est trop petite pour tout afficher (pas assez de lignes et/ou de colonnes,
alors le programme doit réagir raisonnablement tant que la dimension de la fenêtre
n’est pas suffisante. En aucun cas il ne doit quitter. Lorsque la fenêtre est de
nouveau assez grande, le programme doit fonctionner de nouveau normalement.

* Si l’utilisateur appuie sur la touche <kbd>echap</kbd>, le programme ne doit rien renvoyer au shell et terminer normalement.

* Si l’utilisateur appuie sur la touche <kbd>⌫ delete</kbd> ou <kbd>⌦ backspace</kbd>, l’élément sur lequel
pointe le curseur doit être effacé de la liste. S’il n’y a plus d’élément dans la liste,
le comportement est le même que si l’utilisateur avait appuyé sur la touche <kbd>echap</kbd>.

* choix non selectionné : texte normal.

* choix selectionné : texte video inversé.

* position curseur : texte souligné.

* choix selectionné + position curseur : texte video inversé souligné.

* Quelque soit le moyen par lequel votre programme se termine, la configuration
par defaut de votre terminal __DOIT__ être restaurée. Oui, même après avoir reçu
un signal (sauf signaux qu’on ne peut pas intercepter, mais ca veut dire que votre programme ne fonctionne pas de toute façon).

* On doit pouvoir interrompre votre programme avec un <kbd>ctrl</kbd> + <kbd>z</kbd> et le restaurer avec `fg` sans que cela influe sur son comportement.

* Si le programme est lancé avec un environnement vide, vous devez adopter un
comportement raisonnable.

## Fonctions autorisées

* `isatty`, `ttyname`, `ttyslot`
* `ioctl`
* `getenv`
* `tcsetattr`, `tcgetattr`
* `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`
* `open`, `close`, `write`
* `malloc`, `free`
* `read`, `exit`
* `signal`

----

[Sujet complet](subject/fr.subject.pdf).
