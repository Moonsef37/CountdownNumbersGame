#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "recapFonctions.h"

//Declaration de la structure permettant de stocker les données d'un jeu :
//un entier pour le nombre de tirage, un pointeur sur tableau d'entiers pour le tirage obtenu
//un entier pour la cible à atteindre.
struct jeu {
  int nbTirage;
  int * Jeu;
  int Cible;
};

//On renomme la structure en JEU pour simplifier les notations
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

  f1=fopen(argv[1],"r"); /* on ouvre le fichier texte contenant le jeu */
  if (f1==NULL) {
    printf("erreur, impossible d'ouvrir le fichier");
  }

  fscanf(f1,"%d",&(Jeu.nbTirage)); /* on lit le nombre de tirage réalisé */

  n = Jeu.nbTirage;
  printf("nombre de tirage = %d",n);
  puts("");

  //allocation des différents tableaux utiles
  operations=malloc(n*sizeof(*operations));
  *operations=malloc(n*256*sizeof(**operations));
  int i;
  if (operations == NULL || *operations == NULL) {
    printf("alloc tab operation failed");
    exit(1);
  }

  //operations est une matrice qu'on construit tableaux contigües
  for(i=1; i<n;i++) {
    operations[i]=operations[i-1]+256;
  }

  Jeu.Jeu=calloc(n, sizeof(int));
  gestionErreur(Jeu.Jeu);

  //on lit le tirage imposé par le fichier texte qu'on stocke dans un tableau
  for (i=0; i<n; i++) {
    fscanf(f1,"%d", &(Jeu.Jeu[i]));
  }
  //on lit la cible imposée
  fscanf(f1,"%d", &(Jeu.Cible));

  //on affiche le tirage et la cible imposés
  printf("le tirage du fichier est le suivant :\n");
  for(i=0; i<n;i++) {
    printf("%d\t", Jeu.Jeu[i]);
  }
  puts("");
  printf("... et la cible est : %d\n", Jeu.Cible);
  fclose(f1);
  }

  //...si le fichier est executé sans argument supplémentaire
  else {
    //on vérifie si ce n'est pas une erreur ou un oubli de l'utilisateur
    printf("Vous n'avez pas fourni de fichier de jeu. Est-ce normal ? 1=oui/0=non\t");
    int reponse=0;
    scanf("%d", &reponse);

    //si oui on arrête le programme
    if (reponse==0) {
      printf("relancez le prog avec un chemin de fichier en second argument\n");
      exit(1);
    }

    //dans le cas echeant, on a le choix entre un tirage imposé par l'utilisateur et un tirage aléatoire
    else {
      printf("Voulez-vous imposer le tirage ou laisser faire le hasard ? 1=choix/0=hasard\t");
      scanf("%d", &reponse);
      printf("taille du jeu à tirer ?\t");
      scanf("%d", &(Jeu.nbTirage));
      n = Jeu.nbTirage;
      if (n<=0) {
        while (n<=0) {
        printf("merci de rentrer un entier naturel non nul \n");
        printf("taille du jeu à tirer ?\t");
        scanf("%d", &(Jeu.nbTirage));
        n = Jeu.nbTirage;
        }
      }
      Jeu.Jeu=malloc(n*sizeof(*(Jeu.Jeu)));
      gestionErreur(Jeu.Jeu);

      //dans le cas d'un jeu choisi
      if (reponse == 1) {
        Jeu.Cible=tirageChoisi(Jeu.Jeu, n);
        //on verifie si le tirage choisi est correct
        if (jeuCorrect(Jeu.Jeu, n, Jeu.Cible)==0) {
          //si non, on rappelle les regles et on recommence le tirage si l'utilisateur le souhaite
          int recommencerTirage;
          int correct=0;
          printf("On rappelle les régles : nombres tirés sticts positifs, de 1 a 10 jusqu'a 2 ex et 25, 50, 75, 100 en 1 ex \n");
          printf("Et : la cible doit être inférieure à 100000\n");
          printf("On recommence ? 1=oui/0=non");
          scanf("%d", &recommencerTirage);
          while (correct==0 && recommencerTirage==1) {
            Jeu.Cible=tirageChoisi(Jeu.Jeu, n);
            correct=jeuCorrect(Jeu.Jeu, n, Jeu.Cible);
            printf("On rappelle les régles : nombres tirés sticts positifs, de 1 a 10 jusqu'a 2 ex et 25, 50, 75, 100 en 1 ex \n");
            printf("Et : la cible doit être inférieure à 100000\n");
            printf("On recommence ? 1=oui/0=non ");
            scanf("%d", &recommencerTirage);
          }
          //si l'utilisateur ne veut plus recommencer on arrete le programme
          if(correct==0) {
            exit(1);
          }
        //lecture au clavier du tirage et de la cible
        }
      }

      //dans le cas d'un jeu aléatoire
      else {
        srandom(time(NULL));

        //plaque est un tableau qui contient les différentes possibilités de tirage répétées selon leur multiplicité
        int * plaque = malloc(24* sizeof(*plaque));
        gestionErreur(plaque);
        initialisationPlaque(plaque);

        //on tire un jeu aléatoire et on l'affiche
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

      //allocation de la matrice operations par tableaux contigüs
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

  //on verifie que le jeu n'est pas deja resolu : un des nombres tirés est la cible
  //cela permet d'eviter des calculs inutils
  if (jeuCorrect(Jeu.Jeu, n, Jeu.Cible)==1 && verifJeuDejaResolu(Jeu.Jeu, n, Jeu.Cible)) {
    //on cherche si une solution exacte existe
    if (existenceSol(Jeu.Jeu, n, operations, Jeu.Cible)==0) {
      //si oui on affiche les operations effectuees pour l'atteindre
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
    //si non on montre a l'utilisateur qu'aucune suite d'operation ne mene à la cible
    else {
      printf("oups");
      puts("");
    }
  }

  else {
    printf("jeu deja resolu !!");
    puts("");
  }

  //on libere les espaces memoires alloués dynamiquement
  free(*operations);
  free(operations);
  free(Jeu.Jeu);
}
