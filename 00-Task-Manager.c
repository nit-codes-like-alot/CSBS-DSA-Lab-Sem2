// ============================================================
//   TASK MANAGER - DSA Project
//   Concepts used:
//     - Struct array (array-based storage)
//     - Linear Search (Lab 9a)
//     - Bubble Sort   (Lab 9c)
//     - Array shift on delete (Lab 7)
//     - Switch-case menu loop (Lab 10)
// ============================================================

#include <stdio.h>
#include <string.h>

#define MAX 100

// --------- Task struct -------------

struct Task {
    int id;
    char title[50];
    char description[100];
    int priority;     // 1 = High, 2 = Medium, 3 = Low
    int completed;    // 0 = Pending, 1 = Done
};

// making a global array to store tasks
struct Task tasks[MAX];
int taskCount = 0;
int nextID = 1;

// getting label to the task as per priority int

void getPriorityLabel(int priority, char *label) {
    if (priority == 1)
        strcpy(label, "High");
    else if (priority == 2)
        strcpy(label, "Medium");
    else
        strcpy(label, "Low");
}

// getting label to the task as per completed int

void getStatusLabel(int completed, char *label) {
    if (completed == 1)
        strcpy(label, "Done");
    else
        strcpy(label, "Pending");
}

// printing a single task row (used in multiple places)

void printTaskRow(struct Task t) {
    char priorityLabel[10];
    char statusLabel[10];
    getPriorityLabel(t.priority, priorityLabel);
    getStatusLabel(t.completed, statusLabel);

    printf("%-5d %-25s %-20s %-10s %-10s\n",
           t.id, t.title, t.description, priorityLabel, statusLabel); // the % ones are for formatting the output,
           // the "-" ones are for left alignment, the numbers are the width of the column, without the "-" they are right aligned
}

// printing table header

void printTableHeader() {
    printf("\n%-5s %-25s %-20s %-10s %-10s\n",
           "ID", "Title", "Description", "Priority", "Status"); // again, printing the formatted output
    printf("----------------------------------------------------------------------------\n");
}

// adding a task

void addTask() {
    if (taskCount == MAX) {
        printf("Cannot add more tasks! List is full.\n");
        return;
    }

    struct Task t;
    t.id = nextID;
    t.completed = 0;

    printf("Enter task title: ");
    scanf(" %[^\n]", t.title); // the %[^\n] is for reading the input until a newline is encountered

    printf("Enter short description: ");
    scanf(" %[^\n]", t.description);

    printf("Enter priority:\n");
    printf("  1 = High\n");
    printf("  2 = Medium\n");
    printf("  3 = Low\n");
    printf("Your choice: ");
    scanf("%d", &t.priority);

    // Validate priority input
    if (t.priority < 1 || t.priority > 3) {
        printf("Invalid priority entered. Setting to 3 (Low) by default.\n");
        t.priority = 3;
    }

    // Store task in array
    tasks[taskCount] = t;
    taskCount++;
    nextID++;

    printf("----------------------------------\n");
    printf("Task added successfully! (ID: %d)\n", t.id);
    printf("----------------------------------\n");
}

// viewing all tasks

void viewAllTasks() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    printf("\n======= ALL TASKS (%d total) =======\n", taskCount);
    printTableHeader();

    for (int i = 0; i < taskCount; i++) {
        printTaskRow(tasks[i]);
    }

    printf("\n");
}

// searching a task by title (Linear Search - Lab 9a)

void searchTask() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    char keyword[50];
    printf("Enter title keyword to search: ");
    scanf(" %[^\n]", keyword);

    int found = 0;

    printf("\n======= Search Results for '%s' =======\n", keyword);
    printTableHeader();

    // Linear search through array - same concept as Lab 9a
    for (int i = 0; i < taskCount; i++) {
        // strstr checks if keyword exists anywhere inside the title
        if (strstr(tasks[i].title, keyword) != NULL) {
            printTaskRow(tasks[i]);
            found++;
        }
    }

    if (found == 0) {
        printf("No tasks found with title containing '%s'.\n", keyword);
    } else {
        printf("\n%d task(s) found.\n", found);
    }
}

// marking a task as complete

void markComplete() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    int id;
    printf("Enter task ID to mark as complete: ");
    scanf("%d", &id);

    // Linear search by ID
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            if (tasks[i].completed == 1) {
                printf("Task ID %d is already marked as Done.\n", id);
            } else {
                tasks[i].completed = 1;
                printf("Task ID %d marked as complete!\n", id);
            }
            return;
        }
    }

    printf("Task with ID %d not found.\n", id);
}

// marking a task as pending (undoing the complete)
// this is literally the opposite of the markComplete function

void markPending() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    int id;
    printf("Enter task ID to mark as pending: ");
    scanf("%d", &id);

    // Linear search by ID
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            if (tasks[i].completed == 0) {
                printf("Task ID %d is already Pending.\n", id);
            } else {
                tasks[i].completed = 0;
                printf("Task ID %d marked as pending!\n", id);
            }
            return;
        }
    }

    printf("Task with ID %d not found.\n", id);
}

// editing a task

void editTask() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    int id;
    printf("Enter task ID to edit: ");
    scanf("%d", &id);

    // Linear search by ID
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            int editChoice;
            printf("\n--- Editing Task ID %d ---\n", id);
            printf("What do you want to edit?\n");
            printf("  1 = Title    (current: %s)\n", tasks[i].title);
            printf("  2 = Description (current: %s)\n", tasks[i].description);
            printf("  3 = Priority (current: %d)\n", tasks[i].priority);
            printf("Your choice: ");
            scanf("%d", &editChoice);

            if (editChoice == 1) {
                printf("Enter new title: ");
                scanf(" %[^\n]", tasks[i].title);
                printf("Title updated!\n");
            } else if (editChoice == 2) {
                printf("Enter new description: ");
                scanf(" %[^\n]", tasks[i].description);
                printf("Description updated!\n");
            } else if (editChoice == 3) {
                printf("Enter new priority (1 = High, 2 = Medium, 3 = Low): ");
                int newPriority;
                scanf("%d", &newPriority);
                if (newPriority >= 1 && newPriority <= 3) {
                    tasks[i].priority = newPriority;
                    printf("Priority updated!\n");
                } else {
                    printf("Invalid priority. No changes made.\n");
                }
            } else {
                printf("Invalid choice. No changes made.\n");
            }

            return;
        }
    }

    printf("Task with ID %d not found.\n", id); // if ID is not found during iteration, this line executes.
}

// deleting a task (Array shift - same as Lab 7)

void deleteTask() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    int id;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            // Shift all elements left - same logic as deleting from array (Lab 7)
            for (int j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            printf("Task ID %d deleted successfully!\n", id);
            return;
        }
    }

    printf("Task with ID %d not found.\n", id);
}

// filtering by status

void filterByStatus() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    printf("Filter by:\n");
    printf("  1 = Pending only\n");
    printf("  2 = Done only\n");
    printf("Your choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice.\n");
        return;
    }

    int filterVal = (choice == 2) ? 1 : 0;
    char filterLabel[10];
    getStatusLabel(filterVal, filterLabel);

    printf("\n======= Tasks with status: %s =======\n", filterLabel);
    printTableHeader();

    int found = 0;

    // Linear search - check each task's completed field
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed == filterVal) {
            printTaskRow(tasks[i]);
            found++;
        }
    }

    if (found == 0) {
        printf("No tasks with status '%s'.\n", filterLabel);
    } else {
        printf("\n%d task(s) found.\n", found);
    }
}

// filtering by priority

void filterByPriority() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    printf("Filter by priority:\n");
    printf("  1 = High\n");
    printf("  2 = Medium\n");
    printf("  3 = Low\n");
    printf("Your choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid priority.\n");
        return;
    }

    char priorityLabel[10];
    getPriorityLabel(choice, priorityLabel);

    printf("\n======= Tasks with priority: %s =======\n", priorityLabel);
    printTableHeader();

    int found = 0;

    // Linear search - check each task's priority field
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].priority == choice) {
            printTaskRow(tasks[i]);
            found++;
        }
    }

    if (found == 0) {
        printf("No tasks with priority '%s'.\n", priorityLabel);
    } else {
        printf("\n%d task(s) found.\n", found);
    }
}

// sorting by priority (Bubble Sort - Lab 9c)

void sortByPriority() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    // Bubble sort - exactly same logic as Lab 9c, just applied to structs instead of arrays
    for (int i = 0; i < taskCount; i++) {
        for (int j = 0; j < taskCount - 1; j++) {
            if (tasks[j].priority > tasks[j + 1].priority) {
                // Swap entire struct (same kinda swapping we did for arrays in Lab 9c)
                // ascending order, so we've got like all 1s then all 2s then all 3s so technically, all highs, then meds and then lows
                struct Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    printf("Tasks sorted by priority (High -> Medium -> Low).\n");
    viewAllTasks();
}

// sorting by status (Bubble Sort - pending first)

void sortByStatus() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    // Bubble sort - pending (0) before done (1)
    for (int i = 0; i < taskCount; i++) {
        for (int j = 0; j < taskCount - 1; j++) {
            if (tasks[j].completed > tasks[j + 1].completed) { // now thiw cuz 0 means pending and 1 means done
                struct Task temp = tasks[j];    // so we're gonna print pending tasks first and then done tasks
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    printf("Tasks sorted by status (Pending first, Done last).\n");
    viewAllTasks();
}

// task summary / stats
// this is just a simple function to show the stats of the tasks (simplest function in the program imo)
void showStats() {
    if (taskCount == 0) {
        printf("No tasks found. Add a task first.\n");
        return;
    }

    int doneTasks = 0;
    int pendingTasks = 0;
    int highPriority = 0;
    int mediumPriority = 0;
    int lowPriority = 0;

    // Count everything in one loop
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed == 1)
            doneTasks++;
        else
            pendingTasks++;

        if (tasks[i].priority == 1)
            highPriority++;
        else if (tasks[i].priority == 2)
            mediumPriority++;
        else
            lowPriority++;
    }

    printf("\n========= TASK SUMMARY =========\n");
    printf("Total Tasks    : %d\n", taskCount);
    printf("Done           : %d\n", doneTasks);
    printf("Pending        : %d\n", pendingTasks);
    printf("---------------------------------\n");
    printf("High Priority  : %d\n", highPriority);
    printf("Medium Priority: %d\n", mediumPriority);
    printf("Low Priority   : %d\n", lowPriority);
    printf("=================================\n");
}

// -------------- functions over, main function below --------------

int main() {
    int choice;

    printf("============================================\n");
    printf("         TASK MANAGER - DSA Project         \n");
    printf("============================================\n");

    while (1) {
        printf("\n============ MAIN MENU ============\n");
        printf(" 1.  Add Task\n");
        printf(" 2.  View All Tasks\n");
        printf(" 3.  Search Task by Title\n");
        printf(" 4.  Mark Task as Complete\n");
        printf(" 5.  Mark Task as Pending\n");
        printf(" 6.  Edit Task\n");
        printf(" 7.  Delete Task\n");
        printf(" 8.  Filter by Status\n");
        printf(" 9.  Filter by Priority\n");
        printf(" 10. Sort by Priority\n");
        printf(" 11. Sort by Status\n");
        printf(" 12. Show Summary / Stats\n");
        printf("  0. Exit\n");
        printf("===================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) { // obviously, using a simple switch case statement to call the functions
            case 1:
                addTask();
                break;
            case 2:
                viewAllTasks();
                break;
            case 3:
                searchTask();
                break;
            case 4:
                markComplete();
                break;
            case 5:
                markPending();
                break;
            case 6:
                editTask();
                break;
            case 7:
                deleteTask();
                break;
            case 8:
                filterByStatus();
                break;
            case 9:
                filterByPriority();
                break;
            case 10:
                sortByPriority();
                break;
            case 11:
                sortByStatus();
                break;
            case 12:
                showStats();
                break;
            case 0:
                printf("\nExiting Task Manager. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number from the menu.\n");
        }
    }
}
