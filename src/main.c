#include <stdio.h>

void initTaskBacklog() {
    int choice = 0;
    int n;

    printf("\n========================================\n");
    printf("   SYSTEM INITIALIZATION: TASK BACKLOG\n");
    printf("========================================\n");
    
    while (choice != 2) {
        printf("\n1. Enqueue a new task\n");
        printf("2. Finish adding tasks and proceed\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n>> Enqueuing new task...\n");
            scanf("%d", &n); //might change
            enqueueTask(n);  //might change
        } else if (choice != 2) {
            printf("\n[!] Invalid choice. Please press 1 or 2.\n");
        }
    }
}


int main(){

    return 0;
}