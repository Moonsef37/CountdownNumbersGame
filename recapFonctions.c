// squelette de toutes les fonctions utilisées
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "recapFonctions.h"

//fonciton de gestion d'erreur qui stop le prog en cas d'echec d'allocation de memoire
void gestionErreur(void * tab) {
  if (tab==NULL) {
    printf("alloc echouee");
    exit(1);
  }
}

//fonciton realisant l'operation plus
void plus(int * jeu, int n, int i, int j, char ** operations) {
  jeu[i]=jeu[i]+jeu[j];
}

//fonciton réalisant l'operation moins en faisant attention a :
//- le resultat ne peut pas etre negatif
//n'affiche et ne retourne rien
void moins(int * jeu, int n, int i, int j, char ** operations) {
  if (jeu[i]>jeu[j]) {
    jeu[i]=jeu[i]-jeu[j];
  }
}

///fonciton réalisant l'operation division en faisant attention a :
//- la divison d'un nombre par un autre plus grand ne pourra jamais donner un entier
//- le nombre divisé est bien divisible par celui par lequel on le divise
//- la division par 0 est impossible
//- la division par 1 n'a pas d'interet
//n'affiche et ne retourne rien
void division(int * jeu, int n, int i, int j, char ** operations) {
  if (jeu[i]>jeu[j] && jeu[i]%jeu[j]==0 && (jeu[j]!=0 && jeu[j]!=1)) {
    jeu[i]=jeu[i]/jeu[j];
  }
}

//fonciton realisant l'operation multiplier en faisant attention a :
//- la multiplication par 1 n'a pas d'interet
//n'affiche et ne retourne rien
void fois(int * jeu, int n, int i, int j, char ** operations) {
  if (jeu[i]!=1 && jeu[j]!=1) {
    jeu[i]=jeu[i]*jeu[j];
  }
}

//verifie si le jeu n'est pas deja resolu
//retourne 1 si tel est le cas, 0 sinon
int verifJeuDejaResolu(int * jeu, int n, int cible) {
  int i;
  for (i=0; i<n; i++) {
    if (jeu[i]==cible) {
      return 1;
    }
  }
  return 0;
}

//fonction permettant de parcourir les 4 operations par l'intermediaire d'un indice entier k
//n'affiche et ne retourne rien
void parcoursOpe(int * jeu, int n, int i, int j, char ** operations, int k) {
  if (k==0) {plus(jeu, n, i, j, operations);}
  else if (k==1) {moins(jeu, n, i, j, operations);}
  else if (k==2) {fois(jeu, n, i, j, operations);}
  else if (k==3) {division(jeu, n, i, j, operations);}
}

//fonction permettant de stocker une trace des operations réalisées en les ecrivant dans tableau de chr operations
//n'affiche et ne retourne rien
void afficheOpe(int * jeu, int n, int i, int j , int k, char** operations) {
  if (k==0) {
    sprintf(operations[n-1],"%d %c %d = %d",jeu[i],'+',jeu[j],jeu[i]+jeu[j]);
  }
  else if (k==1) {
    sprintf(operations[n-1],"%d %c %d = %d",jeu[i],'-',jeu[j],jeu[i]-jeu[j]);
  }
  else if (k==2) {
    sprintf(operations[n-1],"%d %c %d = %d",jeu[i],'*',jeu[j],jeu[i]*jeu[j]);
  }
  else if (k==3) {
    sprintf(operations[n-1],"%d %c %d = %d",jeu[i],'/',jeu[j],jeu[i]/jeu[j]);
  }
}

//fonction permettant de stocker une trace des operations réalisées en les ecrivant dans tableau de chr operations
//n'affiche et ne retourne rien
void afficheOpeAuPlusProche(int n, int x, int y, int k, char** operations) {
  if (k==0) {
    sprintf(operations[n-1],"%d %c %d = %d",x,'+',y,x+y);
  }
  else if (k==1) {
    sprintf(operations[n-1],"%d %c %d = %d",x,'-',y,x-y);
  }
  else if (k==2) {
    sprintf(operations[n-1],"%d %c %d = %d",x,'*',y,x*y);
  }
  else if (k==3) {
    sprintf(operations[n-1],"%d %c %d = %d",x,'/',y,x/y);
  }
}

//cherche si une solution au jeu existe : retourne 1 si oui, 0 sinon
int existenceSol(int *jeu, int n, char ** operations, int cible) {
  // declaration et allocation du tableau stockant une copie du jeu
  int *sauvJeu=NULL;
  sauvJeu=calloc(n, sizeof(int));
  gestionErreur(sauvJeu);

  int i, j, k;
  //parcourt des jeu[i]
  for (i=0; i<n;i++) {
    //jeu resolu ? si oui on retourne 0
    if (jeu[i]==cible) {
      return 0;
    }
    //si non, on continue
    //parcourt des jeu[j]
    for (j=0; j<n; j++) {
      if (i!=j) {
        //parcourt des 4 operations possibles
        for(k=0; k<4; k++) {
          memcpy(sauvJeu, jeu, n*sizeof(int)); /*on sauvegarde le jeu dans le tableau prévu a cet effet sauvJeu*/
          parcoursOpe(jeu, n, i, j, operations, k); /*réalise l'operation d'indice k entre jeu[i] et jeu[j]*/
          jeu[j]=jeu[n-1];
          //jeu resolvable ?
          if (existenceSol(jeu, n-1, operations, cible)==0) {
            //la cible est atteinte, on remonte les operations effectuées en les montrant a l'utilisateur
            memcpy(jeu, sauvJeu, n*sizeof(int));
            afficheOpe(jeu, n, i, j , k, operations);
            return 0;
          }
          //la cible n'est pas atteinte, on reprend le jeu d'avant operation qui a été stocké dans le tableau de sauvegarde
          memcpy(jeu, sauvJeu, n*sizeof(int));
        }
      }
    }
  }
  //on libere l'espace memoire du tableau sauvJeu
  free(sauvJeu);
  return 1;
}

//fonction qui permet d'initialiser le tableau plaque pour le tirage aléatoire
//n'affiche et ne retourne rien
void initialisationPlaque(int * plaque) {
  int i, compteur=1;
  for (i=0; i<=19; i++) {
    plaque[i]=compteur;
    if (i%2) {
      compteur+=1;
    }
  }
  plaque[23]=100;
  plaque[22]=75;
  plaque[21]=50;
  plaque[20]=25;
}

//fonction qui effectue le tirage aleatoire par methode recursive
//n'affiche et ne retourne rien
void tirageAleatoire(int * jeu, int nbTirage, int compteur, int * plaque) {
  if (nbTirage>compteur) {
    int k=rand()%(24-compteur);
    jeu[compteur]=plaque[k];
    plaque[k]=plaque[23-compteur];
    tirageAleatoire(jeu, nbTirage, compteur+1, plaque);
  }
}

//fonction qui permet à l'utilisateur de realiser le tirage de son choix et de choisir la cible
//la fonction retourne la cible choisie
int tirageChoisi(int *jeu, int n) {
  int i, cible;
  for(i=0; i<n; i++) {
    printf("%d eme tirage :", i+1);
    scanf("%d", &jeu[i]);
  }
  printf("le tirage choisi est le suivant :\n");
  for(i=0; i<n;i++) {
    printf("%d\t", jeu[i]);
  }
  puts(""),
  printf("quelle est votre cible ?");
  scanf("%d", &cible);
  return cible;
}

// transforme le tableau jeu en un tableau de nombre allant de 1 à 14 :
//  utile pour verifier si le jeu est exacte et suit les regles
// retourne l'adresse du nouveau tableau utile
int * transforme(int * jeu, int n) {
  int i;
  int * t;
  t=calloc(n, sizeof(int));
  gestionErreur(t);
  for (i=0; i<n;i++) {
    if (jeu[i]<=10) {
      t[i]=jeu[i];
    }
    else if (jeu[i]==25) { t[i]=11;}
    else if (jeu[i]==50) { t[i]=12;}
    else if (jeu[i]==75) { t[i]=13;}
    else if (jeu[i]==100) { t[i]=14;}
    else {
      printf("le nombre %d n'est pas valide\n", jeu[i]);
      return NULL;
    }
  }
  return t;
}

//fonction qui verifie si le jeu respecte les regles : retourne 1 si oui, 0 sinon
// nombres tirés sticts positifs, de 1 a 10 jusqu'a 2 ex et 25, 50, 75, 100 en 1 ex
int jeuCorrect(int * jeu, int n, int cible) {
  int i;
  if (cible>0 && cible<=100000) {
  int * jeuTr = calloc(n, sizeof(int));
  gestionErreur(jeuTr);
  jeuTr=transforme(jeu, n);
  if(jeuTr==NULL) {
    printf("ici");
    return 0;
  }
  int *tabCompteur;
  tabCompteur = calloc(14, sizeof(int));
  gestionErreur(tabCompteur);
  for(i=0; i<n; i++) {
    if (jeuTr[i]<=0){
      printf("le nombre %d n'est pas valide\n", jeuTr[i]);
      return 0;
    }
    else {
      tabCompteur[jeuTr[i]-1]+=1;
    }
  }
  for (i=0; i<14;i++) {
    if ((i<=9 && tabCompteur[i]>2) ||(i>9 && tabCompteur[i]>1) ) {
      printf("le nombre %d n'est pas valide\n", jeu[i]);
      return 0;
    }
  }
  free(tabCompteur);
  free(jeuTr);
  return 1;
  }
  else {
    printf("la cible doit être strictement positive et inferieure a 100000 \n");
    exit(1);
  }
}

//cherche si une solution au jeu existe : retourne 0 si oui, le resultat le plus proche trouvé sinon
int resolutionplusproche(int *jeu, int n, char ** operations, int cible, int distancemin) {
  int *sauvJeu=NULL;
  sauvJeu=calloc(n, sizeof(int));
  gestionErreur(sauvJeu);
  int i, j, k, val;
  for (i=0; i<n;i++) {
    if (jeu[i]==cible) {
      return 0;
    }
    for (j=0; j<n; j++) {
      if (i!=j) {
        for(k=0; k<4; k++) {
            memcpy(sauvJeu, jeu, n*sizeof(int));
            parcoursOpe(jeu, n, i, j, operations, k);
            jeu[j]=jeu[n-1];
            if (abs(jeu[i]-cible)<abs(distancemin)) {
              distancemin=cible-jeu[i];
              afficheOpeAuPlusProche(n, sauvJeu[i], sauvJeu[j], k, operations);
            }
            val=resolutionplusproche(jeu, n-1, operations, cible, distancemin);
            if (val==0 || jeu[i]==cible) {
                memcpy(jeu, sauvJeu, n*sizeof(int));
                afficheOpe(jeu, n, i, j , k, operations);
                return 0;
            }
            if (abs(val)<abs(distancemin)) {
              distancemin=val;
              afficheOpeAuPlusProche(n, sauvJeu[i], sauvJeu[j], k, operations);
            }
            memcpy(jeu, sauvJeu, n*sizeof(int));
          }
        }
      }
    }
  free(sauvJeu);
  return distancemin;
}
