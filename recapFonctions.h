#ifndef _RECAP_H_
#define _RECAP_H_

//fonciton de gestion d'erreur qui stop le prog en cas d'echec
//d'allocation de memoire
void gestionErreur(void * tab);

int main(int argc, char * argv[]);
//fonciton realisant l'operation plsu
void plus(int * jeu, int n, int i, int j, char ** operations);

//fonciton realisant l'operation moins
void moins(int * jeu, int n, int i, int j, char ** operations);

//fonciton realisant l'operation divisioniser
void division(int * jeu, int n, int i, int j, char ** operations);

//fonciton realisant l'operation multiplier
void fois(int * jeu, int n, int i, int j, char ** operations);

//verifie si le jeu n'est pas deja resolu
int verifJeuDejaResolu(int * jeu, int n, int cible);

//fonction permettant de parcourir les 4 operations
void parcoursOpe(int * jeu, int n, int i, int j, char ** operations, int k);

void afficheOpe(int * jeu, int n, int i, int j , int k, char** operations);

//cherche si une solution au jeu existe : retourne 0 si oui, 1 sinon
int existenceSol(int *jeu, int n, char ** operations, int cible);

void initialisationPlaque(int * plaque);

void tirageAleatoire(int * jeu, int nbTirage, int compteur, int * plaque);

int tirageChoisi(int *jeu, int n);

//fonction qui verifie si le jeu respecte les regles : retourne 1 si oui, 0 sinon
// nombres tirés sticts positifs, de 1 a 10 jusqu'a 2 ex et 25, 50, 75, 100 en 1 ex
int jeuCorrect(int * jeu, int n, int cible);

// transforme le tableau jeu en un tableau de nombre allant de 1 à 14 :
//  utile pour verifier si le jeu est exacte et suit les regles
// retourne l'adresse du nouveau tableau utile
int * transforme(int * jeu, int n);

//cherche si une solution au jeu existe : retourne 0 si oui, le resultat le plus proche trouvé sinon
int resolutionplusproche(int *jeu, int n, char ** operations, int cible, int distancemin);

#endif
