#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_tache 100

struct date{
    int day;
    int month;
    int year;
};

struct task {
    char priority[10];
    char titre[100];
    char description[300];
    struct date task_date;
    char status[20];
};

void create(struct task tasks[],int count){

    for(int i=0; i<count; i++){
        printf("\ntache : %d\n", i+1);
        printf("Entrez le titre de la tache : ");
        scanf("%[^\n]", tasks[i].titre);
        getchar();

        printf("Entre la description de tache : ");
        scanf("%[^\n]", tasks[i].description);
        getchar();

        while(1){
            printf("Entrez le jour : ");
            scanf("%d", &tasks[i].task_date.day);
            getchar();
            if(tasks[i].task_date.day<=0 || tasks[i].task_date.day > 31){
                printf("invalid day number \n");
            }
            printf("entrez le moi : ");
            scanf("%d", &tasks[i].task_date.month);
            getchar();
            if(tasks[i].task_date.month<=0 || tasks[i].task_date.month > 12){
                printf("invalid month number \n");
            }
            printf("entrez l'annee : ");
            scanf("%d", &tasks[i].task_date.year);
            getchar();
            if(tasks[i].task_date.year<1000 || tasks[i].task_date.day > 2100){
                printf("invalid year number \n");
            }else{
                break;
            }

        }

        printf("Entrez la priorite (high/low) : ");
        scanf("%s", tasks[i].priority);
        getchar();

        printf("entre status complet/incomplet : ");
        scanf("%s", tasks[i].status);
        getchar();
    }

}
//function read() shows the data of the task
void read(struct task tasks[],int count){
     for(int i =0; i<count; i++){
        printf("\n---Tache %d---\n", i+1);
        printf("Titre       : %s\n", tasks[i].titre);
        printf("Description : %s\n", tasks[i].description);
        printf("la date     : %d/%d/%d\n", tasks[i].task_date.day, tasks[i].task_date.month, tasks[i].task_date.year);
        printf("Priorite    : %s\n", tasks[i].priority);
        printf("status     : %s\n", tasks[i].status);
        printf("---------------------------\n");
     }
}

//function for update
void update(struct task tasks[], int count) {
    int task_num;

    printf("Entrez le numero de la tache a modifier (1-%d) : ", count);
    scanf("%d", &task_num);
    getchar(); // Consume the remaining newline character

    if (task_num < 1 || task_num > count) {
        printf("Numéro de tâche invalide.\n");
        return;
    }

    task_num--; // Adjusting the index of the task (starts at 0)

    printf("Modifier le titre de la tache : ");
    scanf("%[^\n]" ,tasks[task_num].titre);
    getchar();

    printf("Modifier la description de la tache : ");
    scanf("%[^\n]", tasks[task_num].description);
    getchar();

    printf("Modifier le jour : ");
    scanf("%d", &tasks[task_num].task_date.day);
    getchar();

    printf("Modifier le moi : ");
    scanf("%d", &tasks[task_num].task_date.month);
    getchar();

    printf("Modifier l'anne : ");
    scanf("%d", &tasks[task_num].task_date.year);
    getchar();


    printf("Modifier la priorite (high/low) : ");
    scanf("%s", tasks[task_num].priority);
    getchar();

    printf("modifier le status (complet/incomplet)");
    scanf("%s", tasks[task_num].status);

    printf("Tache modifiee avec succes.\n");
}

//function for deleting a task from the array
void Delete(struct task tasks[], int *count){
    int choice;
    printf("\nEntrez le numero de la tache a supprime (1 a %d): ", *count);
    scanf("%d", &choice);
    getchar();
    if(choice > 0 && choice <= *count){
        choice -= 1; // Ajusting the index of the task (starts at 0)
        for(int i=choice; i<*count-1; i++){
            tasks[i] = tasks[i+1];
        }
        (*count)-=1;
        printf("tache %d supprimee avec succes.\n", choice+1);
    }else{
        printf("Choix invalide\n");
    }
}

//function filters using the priority of the task
void priorityFilter(struct task tasks[], int count) {
    char choice[10];
    printf("\nEntrez la priorite (high/low) pour filtrer : ");
    scanf("%s", choice);

    if (count == 0) {
        printf("Aucune tache disponible.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(choice, tasks[i].priority) ==0){
            printf("\n---Tache %d---\n", i + 1);
            printf("Titre      : %s\n", tasks[i].titre);
            printf("Description: %s\n", tasks[i].description);
            printf("la date    : %d/%d/%d\n", tasks[i].task_date.day, tasks[i].task_date.month, tasks[i].task_date.year);
            printf("Priorite   : %s\n", tasks[i].priority);
            printf("status     : %s\n", tasks[i].status);
            printf("---------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Aucune tache ne correspond a cette priorite.\n");
    }
}

//function filters using the status of the task
void statusFilter(struct task tasks[], int count){
    char choice[20];
    printf("\nEntrez le status (complet/incomplet) pour filtrer : ");
    scanf("%s", choice);

    if (count == 0) {
        printf("Aucune tache disponible.\n");
        return;
    }
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(tasks[i].status, choice) == 0)
        {
            printf("\n---Tache %d---\n", i + 1);
            printf("Titre      : %s\n", tasks[i].titre);
            printf("Description: %s\n", tasks[i].description);
            printf("la date    : %d/%d/%d\n", tasks[i].task_date.day, tasks[i].task_date.month, tasks[i].task_date.year);
            printf("Priorite   : %s\n", tasks[i].priority);
            printf("status     : %s\n", tasks[i].status);
            printf("---------------------------\n");
            found = 1;
        }

    }
    if (!found)
    {
        printf("Aucune tache ne correspond a cette priorite.\n");
    }


}

int main()
{
    //opening a file called data.txt
    FILE *ptask = fopen("data.txt", "w+");

    struct task tasks[MAX_tache];
    int count;
    int choice;
    while(1){
        printf("\n--- Application de Gestion de Taches ---\n");
        printf("   1. pour creer une tach.\n");
        printf("   2. Afficher les donnees d'une tache\n");
        printf("   3. Mettre a jour les donnees d'une tache\n");
        printf("   4. Supprimer une tache\n");
        printf("   5. filtrer par priorite (high/low)\n");
        printf("   6. filtrer par statut (complet/incomplet)\n");
        printf("   0. Quitter\n");
        printf("   Entrez votre choix: ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                printf("\n Enter countation: ");
                scanf("%d", &count);
                getchar();
                //checking if number of task user wants to input isn't bigger than MAX_tache of tasks
                if(count<=MAX_tache){
                    create(tasks, count);
                }else{
                    printf("\nError: Invalid number of tasks. Please enter a value between 1 and %d.\n", MAX_tache);
                }
                break;
            case 2:
                //checking if user already made an input
                if(count){
                    read(tasks, count);
                }else{
                    printf("You didn't assign anything yet\n");
                }
                break;
            case 3:
                update(tasks, count);
                break;
            case 4:
                Delete(tasks, &count);
                break;
            case 5:
                priorityFilter(tasks, count);
                break;
            case 6:
                statusFilter(tasks, count);
                break;
            case 0:
                printf("\n Au revoir !\n");
                return 0;
            default:
                printf("\n Error \n");
        }
    }


    if (ptask == NULL) {
        printf("Error opening a file.\n");
        return 1;
    }
    // Writing data to the file
    for (int i = 0; i < count; i++) {
        fprintf(ptask, "\n---Tache %d---\n", i + 1);
        fprintf(ptask, "Titre      : %s\n", tasks[i].titre);
        fprintf(ptask, "Description: %s\n", tasks[i].description);
        fprintf(ptask, "la date    : %d/%d/%d\n", tasks[i].task_date.day, tasks[i].task_date.month, tasks[i].task_date.year);
        fprintf(ptask, "Priorite   : %s\n", tasks[i].priority);
        fprintf(ptask, "status     : %s\n", tasks[i].status);
        fprintf(ptask, "---------------------------\n");
    }

    //closing the file
    fclose(ptask);
    return 0;
}