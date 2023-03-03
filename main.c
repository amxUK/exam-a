#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HORIZ 0
#define VERT 1

void saisir(int grid[9][9]) {                      //création grille
    printf("\n");
    int i, j, v;                                   //i,j,v=lignes,colonnes,nombres
printf("choisissez le nombre des lignes: \n");
scanf("%d", &i);
printf("choisissez le nombre des Colonnes : \n");
scanf("%d", &j);
printf("choisissez le nombre de numéro : \n");
scanf("%d", &v);
                                                   //on prend le nombre de lignes, colonnes, et valeurs.
if(i < 0 || i > 8 || j < 0 || j > 8 || v < 1 || v > 9) {
printf("Erreur\n");                         //nb de ligne  0-8, nb de colonnes 0-8, nb valeurs 1-9 sinon message erreurs
}
else {
if(grid[i][j] == 0) {
grid[i][j] = v;                                    //i,j=0 - i,j=v
} else {
printf("Erreur\n");
}
}
}
                                                    //ligne colonne valide ?
int verifierLigneColonne(int grid[9][9], int value, int sens) {
    int i;
    int array[9];
    if(sens == 0) {
        for(i = 0; i < 9; i++) {
            array[i] = grid[i][value];
        }
    } else if(sens == 1) {
        for(i = 0; i < 9; i++) {
            array[i] = grid[value][i];
        }
    }

    int sum = 0;
    for(i = 0; i < 9; i++) {
        sum += array[i];
    }

    if(sum == 45) {
        return 0;
    } else {
        return 1;
    }
}

                                            //combien de cases ont déjà été remplies, utile pour vérifier la validité de la grille

void generer(int grid[9][9]) {
    int ligne, colonne;
    int nombrenonnul = 0;

    for (ligne = 0; ligne < 9; ligne++) {
        for (colonne = 0; colonne < 9; colonne++) {
            if (grid[ligne][colonne] != 0) {
                nombrenonnul++;
            }
        }
    }

    for(ligne = 0;ligne < 9; ++ligne) {
        for(colonne = 0; colonne < 9; ++colonne) printf("%d ", grid[ligne][colonne]); printf("\n");  //grille
    }

    printf("non nuls : %d\n", nombrenonnul);
}
//int verifierRegion(int grid[9][9], int k, int l) {
//    int i, j;
//    int array[9];
//    int index = 0;
//
//    for(i = 0; i < 3; i++) {
//        for(j = 0; j < 3; j++) {
//            array[index] = grid[i + k][j + l];
//            index++;
//        }
//    }
int verifierGrille(int grid[9][9]) {
 //   bool region = false;
 //   bool ligne = false;
 //   bool colonne = false;
 //   for (int i = 3; i < 9; i += 3) {
 //       for(int j = 3; j < 9; j += 3) {
 //           if (verifierRegion(grid, i, j) == 0) {
  //              region = true;
 //           }
 //       }
 //   }

int main(){
    // Ne pas toucher le code entre les commentaires
    srand(time(NULL));
    int i, j;
    int solution[9][9];
    printf("SOLUTION");
    printf("\n");
    printf("---------------------------------");
    printf("\n");
    for(j=0;j<9; ++j) {
        for(i=0; i<9; ++i) solution[j][i] = (i + j*3 +j /3) % 9 +1 ;
    }
    int num_to_remove  = 30;
    while (num_to_remove > 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (solution[row][col] != 0) {
            solution[row][col] = 0;
            num_to_remove--;
        }
    }
    generer(solution);
    printf("\n");
    int valid = 1;
    while(valid == 1) {
        saisir(solution);
        generer(solution);
        valid = verifierGrille(solution);
    }

    printf("reussi\n");
    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

//pas fini