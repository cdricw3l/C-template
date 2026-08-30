# C project template

# description 

Ce project est le template qui servira pour mes future project en C. Le but est de faciliter l'implementation de test unitaire, de test d'integration et de test end to end.

Tous les module de test partage une base de regles et de variables commune implementées dans le fichier config.mk tout en laissant la possibilité d'implementer des structure de fichier personalisé dans le makefile du module

## Test folder

```bash

test
├── 0_include
│   ├── color-codes.h
│   └── test.h
├── config.mk                   --> shared rules and variable
├── draft
│   ├── draft.c
│   └── Makefile                --> draft Makefile
├── end-to-end
│   ├── e2e.c
│   └── Makefile                --> end to end Makefile    
├── integration
│   ├── integration.c
│   └── Makefile                --> integration Makefile
├── Makefile                    --> Global test Makefile
└── unit
    ├── Makefile                --> unitaire test Makefile
    └── unit.c

```
## Root 

```bash
#### TEST VARIABLE ###
TEST_FOLDER= test
TYPE ?= unit
######################

test:
	make -C $(TEST_FOLDER) TYPE=$(TYPE) MEMORY_CHECK=$(MEMORY_CHECK) test

```

La variable TEST_FOLDER defini le dossier de test. \
La variable MEMORY_CHECK defini si le programme de verification de memoire adequate doit etre lancé. (valgrind pour les platforme linux, leaks pour macOS).

```bash

ifeq ($(shell uname),Darwin)
	MEMORY_CHECK_ARG= leaks -atExit --
else
	MEMORY_CHECK_ARG= valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file=$(MEMORY_LOG)
endif

```

# Commande

Lancer le module de test draft + verification de memoire:
```bash
make test TYPE=draft MEMORY_CHECK=1
```
Lancer le module de test unitaire + verification de memoire:

```bash
make test TYPE=unit MEMORY_CHECK=1
```
Lancer le module de test integration + verification de memoire:
```bash
make test TYPE=integration MEMORY_CHECK=1
```
Lancer le module de test end to end + verification de memoire:
```bash
make test TYPE=e2e MEMORY_CHECK=1
```
Supprimer tout les fichiers object
```bash
make clean
```
Supprimer tout les executables object
```bash
make fclean
```
