#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

struct task {
    char titre[100];
    char description[300];
    char date[11];
    char priority[10];
};
void create(struct task tasks[],int count){

    for(int i=0; i<count; i++){
        printf("\ntache : %d\n", i+1);
        printf("Entrez le titre de la tache : ");        
        fgets(tasks[i].titre, sizeof(tasks[i].titre), stdin);

        printf("Entrez la date d'echeance (JJ/MM/AAAA) : ");
        fgets(tasks[i].date, sizeof(tasks[i].date), stdin);

        printf("entre la priorite (high/low) : ");
        fgets(tasks[i].priority, sizeof(tasks[i].priority), stdin);
    }

}

void read(struct task tasks[],int count){
    if(count == 0){
        printf("Aucune tâche à afficher.\n");
        return;
    }
     for(int i =0; i<count; i++){
        printf("\nTache %d:\n", i+1);
        printf("Titre       : %s\n", tasks[i].titre);
        printf("Description : %s\n", tasks[i].description);
        printf("Echeance    : %s\n", tasks[i].date);
        printf("Priorite    : %s\n", tasks[i].priority);
     }
}
//function for update
void update(struct task tasks[],int count){
    int choice;
    printf("\nEntrez le numero de la personne a mettre a jour (1 a %d): ", count);
    scanf("%d", &choice);
    getchar();
    //checking if user gets his above 0 and under or equal the number of tasks
    if (choice > 0 && choice <= count){
        choice -= 1; //number of tasks starts with 1 but inside the array starts with 0
        printf("\nMise a jour de la Personne %d:\n", choice + 1);
        printf("entre nouvou nom: ");
        fgets(tasks[choice].titre, sizeof(tasks[choice].titre), stdin);
        printf("entre nouvou date: ");
        scanf("%d", &tasks[choice].date);
    }else{
        printf("Choix invalide\n");
    }
}
//function for deleting a task from the array
void Delete(struct task tasks[], int *count){
    int choice;
    printf("\nEntrez le numero de la personne a supprimer (1 à %d): ", *count);
    scanf("%d", &choice);
    getchar();
    if(choice > 0 && choice <= *count){
        choice -= 1; //number of tasks starts with 1 but inside the array starts with 0
        for(int i=choice; i<*count-1; i++){
            tasks[i] = tasks[i+1];
        }
        (*count)-=1;
        printf("tache %d supprimee avec succes.\n", choice+1);
    }else{
        printf("Choix invalide\n");
    }

}
void filtre(struct task tasks[], int count){
    char choice[5];
    printf("Entrez la priorité (high/low) : ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';
    if(count>0){
            if (strcmp(choice, "high")==0 || strcmp(choice, "low")==0){
                for(int i=0; i<count; i++){
                    if(strcmp(tasks[i].priority, choice) == 0){
                        printf("\n person: %d\n", i+1);
                        printf("titre: %s\n", tasks[i].titre);
                        printf("date: %d\n", tasks[i].date);
                        printf("piorite: %s\n", tasks[i].priority);
                    }
                }
            }else{
                printf("Choix invalide\n");
            }
    }else{
        printf("\n il n'y a pas de taches \n");
    }
}
int main()
{
    struct task tasks[MAX];
    int count;
    int choice;
    while(1){
        printf("\n--- Application de Gestion de Taches ---\n");
        printf("   1. pour creer une tach.\n");
        printf("   2. Afficher les donnees d'une tache\n");
        printf("   3. Mettre a jour les donnees d'une tache\n");
        printf("   4. Supprimer une tache\n");
        printf("   5. filtrer\n");
        printf("   0. Quitter\n");
        printf("   Entrez votre choix: ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                printf("\n Enter countation: ");
                scanf("%d", &count);
                //checking if number of task user wants to input isn't bigger than MAX of tasks
                if(count<MAX){
                    getchar();
                    create(tasks, count);
                }else{
                    printf("\nError: Invalid number of tasks. Please enter a value between 1 and %d.\n", MAX);
                }
                break;
            case 2:
                //checking if user already made an input
                if(count){
                    read(tasks, count);
                }else{
                    printf("you didn't assign anything yet\n");
                }
                break;
            case 3:
                update(tasks, count);
                break;
            case 4:
                Delete(tasks, &count);
                break;
            case 5:
                filtre(tasks, count);
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
