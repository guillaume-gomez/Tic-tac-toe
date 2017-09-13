#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void AfficheTableau (char tableau[]);


int main()
{

    char tableau[9] = {'1','2','3','4','5','6','7','8','9',};
    int gagne = 0;
    int rejouer = 0;
    srand(time(NULL));
    int MIN = 1, MAX= 2, joueurCommence = (rand() % (MAX - MIN + 1)) + MIN;
    int choixCase;
    int i = 0;
    int varjouer[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char prenomJ1[30];
    char prenomJ2[30];
    int continuer = 0;

    do
    {
        printf("\t\tMORPION\t\t\n");
        printf("Veuillez entrer votre nom j1:");
        scanf("%s", prenomJ1);
        printf("\n");
        printf("\nVeuillez entre votre nom j2:");
        scanf("%s", prenomJ2);
        printf("\n");


        AfficheTableau(tableau);
        while(gagne != 1)
        {
            do
            {
                rejouer = 0;
                if(joueurCommence == 1)
                {
                    printf("A toi de jouer %s\n", prenomJ1);
                    scanf("%i", &choixCase);

                }
                else
                {
                    printf("A toi de jouer %s\n", prenomJ2);
                    scanf("%i",&choixCase);
                }

                if (varjouer[choixCase-1] == 1)
                {
                    printf("Deja joue !\n\n");
                    rejouer = 1;
                }
                else
                {
                    if(joueurCommence == 1)
                    {
                        tableau[choixCase-1] = 'x';
                        varjouer[choixCase-1] = 1;
                    }
                    else if(joueurCommence == 2)
                    {
                       tableau[choixCase-1] = 'o';
                       varjouer[choixCase-1] = 1;
                    }
                }
            } while(rejouer == 1);
            AfficheTableau(tableau);
            i++;
            if(
             (tableau[0] == 'o' && tableau[1] == 'o' && tableau[2] == 'o') || (tableau[0] == 'o' && tableau[3] == 'o' && tableau[6] =='o') || (tableau[1] =='o' && tableau[4] =='o' && tableau[7] == 'o') ||
             (tableau[2] == 'o' && tableau[5] == 'o' && tableau[8] == 'o') || (tableau[3] == 'o' && tableau[4] == 'o' && tableau[5] =='o') || (tableau[6] =='o' && tableau[7] =='o' && tableau[8] == 'o') ||
             (tableau[0] == 'o' && tableau[4] == 'o' && tableau[8] == 'o') || (tableau[2] == 'o' && tableau[4] == 'o' && tableau[6] =='o') ||
             (tableau[0] == 'x' && tableau[1] == 'x' && tableau[2] == 'x') || (tableau[0] == 'x' && tableau[3] == 'x' && tableau[6] =='x') || (tableau[1] =='x' && tableau[4] =='x' && tableau[7] == 'x') ||
             (tableau[2] == 'x' && tableau[5] == 'x' && tableau[8] == 'x') || (tableau[3] == 'x' && tableau[4] == 'x' && tableau[5] =='x') || (tableau[6] =='x' && tableau[7] =='x' && tableau[8] == 'x') ||
             (tableau[0] == 'x' && tableau[4] == 'x' && tableau[8] == 'x') || (tableau[2] == 'x' && tableau[4] == 'x' && tableau[6] =='x'))
            {
                gagne = 1;
                if(joueurCommence == 1)
                {
                printf("Bravo vous avez gagné %s\n", prenomJ1);
                }
                else{
                   printf("Bravo vous avez gagné %s\n", prenomJ2);
                }
            }
            else if (i == 9)
            {
                printf("Match nul\n");
                gagne = 1;
            }

            if(joueurCommence == 1)
            {
                joueurCommence = 2;
            }
            else
            {
               joueurCommence = 1;
            }
        }

        printf("\nVoulez vous rejouer 1:oui 2:non\n");
        scanf("%i", &continuer);
    } while (continuer == 1);
    return 0;
}

void AfficheTableau(char tableau[])
{
    printf("\n ____ ____ ____\n");
    printf("|    |    |    |\n");
    printf("| %c  | %c  | %c  |\n", tableau[6], tableau[7], tableau[8]);
    printf("|____|____|____|\n");
    printf("|    |    |    |\n");
    printf("| %c  | %c  | %c  |\n", tableau[3], tableau[4], tableau[5]);
    printf("|____|____|____|\n");
    printf("|    |    |    |\n");
    printf("| %c  | %c  | %c  |\n", tableau[0], tableau[1], tableau[2]);
    printf("|____|____|____|\n");
}
