Groupe : Ghorreshi Omid, Garcia Maxime
Filière : MMIS

Phase 2 :

Question 2 :

la différence entre les opérateurs "Dvetor operator+ (Dvector a, Dvector b)" et "Dvetor operator+ (const Dvector &a, const Dvector &b)" est que ce dernier n'effectue pas de recopie des arguments a et b qui lui sont passés en paramètre car ce sont des reférences vers des Dvector. Pour indiquer que a et b ne seront pas modifiés dans le deuxième opérateur + on les munis du labal const pour indiquer qu'ils ne sont pas modifiable dans la fonction. Pour le premier opérateur cette action est inutile parce que ce ne sont pas les paramètres qui sont susceptibles d'être modifiés mais c'est leur recopie. Il y aura donc 3 objets créés dans le premier opérateur et seulement dans le deuxième.

Question 3 :

afin de factoriser du code nous avons utilisé : 

     - l'opérateur +=(const double r) pour implémenter +(const Dvector &d, const double r);
     - l'opérateur -=(const double r) pour implémenter -(const Dvector &d, const double r);
     - l'opérateur *=(const double r) pour implémenter *(const Dvector &d, const double r);
     - l'opérateur /=(const double r) pour implémenter /(const Dvector &d, const double r);
     - l'opérateur +(const Dvector& d, const double r) pour implémenter +(const double r, const Dvector& d);
     - l'opérateur *(const Dvector& d, const double r) pour implémenter *(const double r, const Dvector& d);
     - l'opérateur +=(const Dvector& d) pour implémenter +(const Dvector& d1, const Dvector& d2);
     - l'opérateur -=(const Dvector& d) pour implémenter -(const Dvector& d1, const Dvector& d2);
     - l'opérateur ==(const Dvector& d) const pour implémenter !=(const Dvector& d) const;

pour ces cas ci nous avons prévilégié la maintenabilité du code plutôt que la performance puisque les seules recopies faites par les opérateurs sont des recopies de double, on peut donc estimer que les performances des opérateurs ne seront pas déteriorées.
