#include "main.h"

void showMenu() {
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. View All Tasks\n");
    printf("4. Complete Task\n");
    printf("5. Exit \n");
}

int main() {
    ToDoList todoList;

    int choice = -1;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char descAdd[100];
                fflush(stdin);
                fgets(descAdd, sizeof(descAdd), stdin);
                descAdd[strcspn(descAdd, "\n")] = '\0';

                todoList.addTask(std::string(descAdd));

                break;
            }

            case 2: {
                char descRemove[100];
                fflush(stdin);
                fgets(descRemove, sizeof(descRemove), stdin);

                descRemove[strcspn(descRemove, "\n")] = '\0';
                todoList.removeTask(std::string(descRemove));
                break;
            }
            case 3: {
                todoList.viewTasks();
                break;
            }

            case 4: {
                char desccomplete[100];
                fflush(stdin);
                fgets(desccomplete, sizeof(desccomplete), stdin);
                desccomplete[strcspn(desccomplete, "\n")] = '\0';
                todoList.completeTask(std::string(desccomplete));

                break;
            }
            default:

                break;
        }
    } while (choice != 5);
}