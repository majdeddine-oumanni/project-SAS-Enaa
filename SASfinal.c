#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

struct persone {
    char name[100];
    int age;
};
void create(struct persone p[],int iter){

    for(int i=0; i<iter; i++){
        printf("\npersonne: %d\n", i+1);
        printf("name: ");
        fgets(p[i].name, sizeof(p[i].name), stdin);
        printf("age: ");
        scanf("%d", &p[i].age);
        getchar();
    }

}

void read(struct persone p[],int iter){
     for(int i =0; i<iter; i++){
        printf("\n person: %d\n", i+1);
        printf("name: %s\n", p[i].name);
        printf("age: %d\n", p[i].age);
     }
}
//function for update
void update(struct persone p[],int iter){
    int choice;
    printf("\nEntrez le numero de la personne a mettre a jour (1 a %d): ", iter);
    scanf("%d", &choice);
    getchar();
    //checking if user gets his above 0 and under or equal the number of tasks
    if (choice > 0 && choice <= iter){
        choice -= 1; //number of tasks starts with 1 but inside the array starts with 0
        printf("\nMise a jour de la Personne %d:\n", choice + 1);
        printf("entre nouvou nom: ");
        fgets(p[choice].name, sizeof(p[choice].name), stdin);
        printf("entre nouvou age: ");
        scanf("%d", &p[choice].age);
    }else{
        printf("Choix invalide\n");
    }
}
//function for deleting a task from the array
void Delete(struct persone p[], int *iter){
    int choice;
    printf("\nEntrez le numero de la personne a supprimer (1 à %d): ", *iter);
    scanf("%d", &choice);
    getchar();
    if(choice > 0 && choice <= *iter){
        choice -= 1; //number of tasks starts with 1 but inside the array starts with 0
        for(int i=choice; i<*iter-1; i++){
            p[i] = p[i+1];
        }
        (*iter)-=1;
        printf("tache %d supprimee avec succes.\n", choice+1);
    }else{
        printf("Choix invalide\n");
    }

}
int main()
{
    struct persone persons[MAX];
    int iter;
    int choice;
    while(1){
        printf("   \nMenu:\n");
        printf("   1. pour creer une tach.\n");
        printf("   2. Afficher les donnees d'une personne\n");
        printf("   3. Mettre a jour les donnees d'une personne\n");
        printf("   4. Supprimer une personne\n");
        printf("   0. Quitter\n");
        printf("   Entrez votre choix: ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                printf("\n Enter iteration: ");
                scanf("%d", &iter);
                //checking if number of task user wants to input isn't bigger than MAX of tasks
                if(iter<MAX){
                    getchar();
                    create(persons, iter);
                }else{
                    printf("\nError: Invalid number of persons. Please enter a value between 1 and %d.\n", MAX);
                }
                break;
            case 2:
                //checking if user already made an input
                if(iter){
                    read(persons, iter);
                }else{
                    printf("you didn't assign anything yet\n");
                }
                break;
            case 3:
                update(persons, iter);
                break;
            case 4:
                Delete(persons, &iter);
                break;
            case 0:
                printf("\n goodbye \n");
                return 0;
            default:
                printf("\n Error \n");
        }
    }


    return 0;
}
