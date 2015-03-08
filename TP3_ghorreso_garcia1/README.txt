Groupe : Ghorreshi Omid, Garcia Maxime
Filière : MMIS


L'objectif de ce TP est d'implémenter la version finale de la librairie d'algèbre linéaire permettant de réaliser les opérations standards entre matrices et vecteurs en utilisant une hiérarchie de classe (Darray la classe mère et Dmatrix et Dvector les classes filles).. Il y a deux dossiers : un dossier src/ contenant 
le code source des classes Darray, Dmatrix et Dvector et des tests de ces classes; un dossier 
doc/ permettant de générer la documentation de la classe. Voici la liste des 
commandes utiles pour ce TP, à lancer à partir du répertoire TP3_ghorreso_garcia1 :

1) make (ou make all)

Cette commande génère le dossier doc/html qui contient le fichier index.html 
permettant d'accéder à la documentation. La commande génère aussi les 
exécutables "test*" associés aux différents tests de la classe.

2) make check

Cette commande permet de vérifier la conformité du code fourni.

3) make doc

Cette commande génère le dossier doc/html qui contient le fichier 
index.html permettant d'accéder à la documentation.

4) make test

Cette commande génère les exécutables "test*" associés aux 
différents tests de la classe.

5) make exectest

Cette commande exécute tous les tests sur les classes Darray, Dmatrix et Dvector. Elle affiche
"TEST DU ... : OK" pour chaque test réussi.

6) make clean

Cette commande fonctionne que si le dossier doc/html a été généré. Cette 
commande efface le dossier doc/html et les fichiers *.o, *.txt et les 
fichiers exécutables dans le dossier src/.

7) make cleandoc

Cette commande efface le dossier doc/html.

8) make cleansource

Cette commande est utile si on n'a pas généré le dossier doc/html et qu'on
 ne peut donc pas utiliser la commande "make clean". Cette commande efface 
les fichiers *.o, *.txt et les fichiers exécutables dans le dossier src/. 

9) make valgrinds 

cette commande lance valgrind sur tous les tests de la base de test se 
trouvant dans src/
