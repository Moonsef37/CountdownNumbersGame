// squelette de toutes les fonctions utilisées
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "recapFonctions.h"

struct jeu {
  int nbTirage;
  int * Jeu;
  int Cible;
};

typedef struct jeu JEU;

int main(int argc, char * argv[]) {
  JEU Jeu;
  char **operations;
  int n;
  // 1er cas : jeu a partir de fichier donné,
  // on verifie le nombre d'argument à l'exécution
  if (argc==2) {
  printf("vous avez choisi de passer par un fichier jeu \n");
  FILE* f1=NULL;
  f1=fopen(argv[1],"r");
  if (f1==NULL) {
    printf("erreur, impossible d'ouvrir le fichier");
  }
  fscanf(f1,"%d",&(Jeu.nbTirage));

  n = Jeu.nbTirage;
  printf("nombre de tirage = %d",n);
  puts("");
  operations=malloc(n*sizeof(*operations));
  *operations=malloc(n*256*sizeof(**operations));
  int i;
  if (operations == NULL || *operations == NULL) {
    printf("alloc tab operation failed");
    exit(1);
  }
  for(i=1; i<n;i++) {
    operations[i]=operations[i-1]+256;
  }

  Jeu.Jeu=calloc(n, sizeof(int));
  gestionErreur(Jeu.Jeu);
  for (i=0; i<n; i++) {
    fscanf(f1,"%d", &(Jeu.Jeu[i]));
  }
  fscanf(f1,"%d", &(Jeu.Cible));
  printf("le tirage du fichier est le suivant :\n");
  for(i=0; i<n;i++) {
    printf("%d\t", Jeu.Jeu[i]);
  }
  puts("");
  printf("... et la cible est : %d\n", Jeu.Cible);
  fclose(f1);
  }

  else {
    printf("Vous n'avez pas fourni de fichier de jeu. Est-ce normal ? 1=oui/0=non\t");
    int reponse=0;
    scanf("%d", &reponse);
    if (reponse==0) {
      printf("relancez le prog avec un chemin de fichier en second argument\n");
      exit(1);
    }
    else {
      printf("Voulez-vous imposer le tirage ou laisser faire le hasard ? 1=choix/0=hasard\t");
      scanf("%d", &reponse);
      printf("taille du jeu à tirer ?\t");
      scanf("%d", &(Jeu.nbTirage));
      n = Jeu.nbTirage;
      Jeu.Jeu=malloc(n*sizeof(*(Jeu.Jeu)));
      gestionErreur(Jeu.Jeu);
      if (reponse == 1) {
        Jeu.Cible=tirageChoisi(Jeu.Jeu, n);
      }
      else {
        srandom(time(NULL));

        int * plaque = malloc(24* sizeof(*plaque));
        gestionErreur(plaque);
        initialisationPlaque(plaque);

        int compteur=0;
        tirageAleatoire(Jeu.Jeu, n, compteur, plaque);
        printf("le tirage aleatoire est le suivant :\n");
        int i;
        for(i=0; i<n;i++) {
          printf("%d\t", Jeu.Jeu[i]);
        }
        puts("");
        printf("quelle cible voulez-vous atteindre ? : ");
        scanf("%d", &(Jeu.Cible));
      }
      operations=malloc(n*sizeof(*operations));
      *operations=malloc(n*256*sizeof(**operations));
      int i;
      if (operations == NULL || *operations == NULL) {
        printf("alloc tab operation failed");
        exit(1);
      }
      for(i=1; i<n;i++) {
        operations[i]=operations[i-1]+256;
      }
    }
  }
  puts("");
  puts("");
  puts("");
  printf("roulements de tambours...");
  puts("");
  puts("");
  puts("");
  
  if (jeuCorrect(Jeu.Jeu, n, Jeu.Cible) && verifJeuDejaResolu(Jeu.Jeu, n, Jeu.Cible)==0) {
    // int * distancemin=calloc(1, sizeof(int));
    // *distancemin=Jeu.Jeu[0]-Jeu.Cible;
    int distancemin=abs(Jeu.Cible-Jeu.Jeu[0]);
    int resultat=resolutionplusproche(Jeu.Jeu, n, operations, Jeu.Cible, distancemin);
    if (resultat==0) {
      printf("bingo !");
      puts("");
      printf("voici les opérations effectuées :");
      puts("");
      int i;
      for(i=(n-1); i>=1;i--) {
        printf("%s", operations[i]);
        puts("");
      }
    }
    else {
      printf("aucune solution exacte trouvée, la plus proche étant : %d ", Jeu.Cible-resultat);
      puts("");
      printf("voici les opérations effectuées :");
      puts("");
      int i;
      for(i=(n-1); i>=1;i--) {
        printf("%s", operations[i]);
        puts("");
      }
    }
  }
  else{
    printf("jeu deja resolu !!");
    puts("");
  }
  free(*operations);
  free(operations);
  free(Jeu.Jeu);
}
