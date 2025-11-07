#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 50

typedef struct {
    int id;
    char name[50];
    char department[30];
    float salary;
    int age;
} Employee;

// Global Variables
Employee database[MAX_EMPLOYEES];
int TotalEmployees = 0;
bool exit_flag = false;

// Function Declarations
void showMenu();
void showID(int target_idx);
int searchID(int check_id);
void addEmployee();
void removeEmployee();
void modifyEmployee();
void viewAllEmployees();

// Show employee details
void showID(int target_idx) {
    printf("\n*----------*------------*---------*\n");
    printf("ID: %d\n", database[target_idx].id);
    printf("Name: %s\n", database[target_idx].name);
    printf("Department: %s\n", database[target_idx].department);
    printf("Salary: %.2f\n", database[target_idx].salary);
    printf("Age: %d\n", database[target_idx].age);
    printf("*----------*------------*---------*\n");
}

// Show menu
void showMenu() {
    printf("\n**************** MENU ******************\n");
    printf("1. Add Employee\n");
    printf("2. Remove Employee\n");
    printf("3. Search Employee\n");
    printf("4. Modify Employee Details\n");
    printf("5. View All Employees\n");
    printf("6. Exit\n");
    printf("***************************************\n");
}

// Search by ID
int searchID(int check_id) {
    int found = -1;

    for(int i = 0; i < TotalEmployees; i++) {
        if(check_id == database[i].id) {
            printf("\n Employee Details Found!\n");
            showID(i);
            found = i;
            break;
        }
    }

    if(found == -1) {
        printf("\n Employee ID Not Found!!!\n");
    }

    return found;
}

// Add employee
void addEmployee() {
    // Check if database is full
    if(TotalEmployees >= MAX_EMPLOYEES) {
        printf("\n Database Full! Cannot add more employees.\n");
        return;
    }

    Employee *emp = &database[TotalEmployees];

    printf("\n--- ADDING NEW EMPLOYEE ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &emp->id);

    // Check for duplicate IDs
    for(int i = 0; i < TotalEmployees; i++) {
        if(database[i].id == emp->id) {
            printf(" Employee ID already exists! Enter different ID.\n");
            return;
        }
    }

    printf("Name: ");
    getchar(); // Clear buffer
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strcspn(emp->name, "\n")] = '\0';

    printf("Department: ");
    fgets(emp->department, sizeof(emp->department), stdin);
    emp->department[strcspn(emp->department, "\n")] = '\0';

    printf("Salary: ");
    scanf("%f", &emp->salary);

    printf("Age: ");
    scanf("%d", &emp->age);

    TotalEmployees++;
    printf("\n Employee added successfully!\n");
    printf(" Total employees: %d\n", TotalEmployees);
}

// Remove employee
void removeEmployee() {
    if(TotalEmployees == 0) {
        printf("\n No employees in database!\n");
        return;
    }

    printf("\n--- REMOVE EMPLOYEE ---\n");
    int id_to_remove;
    printf("Enter ID for Removal: ");
    scanf("%d", &id_to_remove);

    int found = -1;
    for(int i = 0; i < TotalEmployees; i++) {
        if(database[i].id == id_to_remove) {
            found = i;
            break;
        }
    }

    if(found == -1) {
        printf(" Employee with ID %d not found!\n", id_to_remove);
        return;
    }

    // Show employee to be removed
    printf("\n Employee to be removed:\n");
    showID(found);

    // Confirm removal
    char confirm;
    printf("Confirm removal? (y/n): ");
    getchar(); // Clear buffer
    scanf("%c", &confirm);

    if(confirm != 'y' && confirm != 'Y') {
        printf(" Removal cancelled.\n");
        return;
    }

    // Shift elements
    for(int i = found; i < TotalEmployees - 1; i++) {
        database[i] = database[i + 1];
    }

    TotalEmployees--;
    printf("\n Employee removed successfully!\n");
    printf(" Total employees: %d\n", TotalEmployees);
}

// Modify employee
void modifyEmployee() {
    if(TotalEmployees == 0) {
        printf("\n No employees in database!\n");
        return;
    }

    printf("\n--- MODIFY EMPLOYEE ---\n");
    int id_to_modify;
    printf("Enter Employee ID to modify: ");
    scanf("%d", &id_to_modify);

    int found = searchID(id_to_modify);

    if(found == -1) {
        return;
    }

    Employee *emp = &database[found];

    printf("\nWhat would you like to modify?\n");
    printf("1. Name\n2. Department\n3. Salary\n4. Age\n5. All Details\n");
    int choice;
    printf("Choice: ");
    scanf("%d", &choice);

    getchar(); // Clear buffer

    switch(choice) {
        case 1:
            printf("New Name: ");
            fgets(emp->name, sizeof(emp->name), stdin);
            emp->name[strcspn(emp->name, "\n")] = '\0';
            break;
        case 2:
            printf("New Department: ");
            fgets(emp->department, sizeof(emp->department), stdin);
            emp->department[strcspn(emp->department, "\n")] = '\0';
            break;
        case 3:
            printf("New Salary: ");
            scanf("%f", &emp->salary);
            break;
        case 4:
            printf("New Age: ");
            scanf("%d", &emp->age);
            break;
        case 5:
            printf("New Name: ");
            fgets(emp->name, sizeof(emp->name), stdin);
            emp->name[strcspn(emp->name, "\n")] = '\0';

            printf("New Department: ");
            fgets(emp->department, sizeof(emp->department), stdin);
            emp->department[strcspn(emp->department, "\n")] = '\0';

            printf("New Salary: ");
            scanf("%f", &emp->salary);

            printf("New Age: ");
            scanf("%d", &emp->age);
            break;
        default:
            printf(" Invalid choice!\n");
            return;
    }

    printf("\n Employee details updated successfully!\n");
    showID(found);
}

// View all employees
void viewAllEmployees() {
    if(TotalEmployees == 0) {
        printf("\n No employees in database!\n");
        return;
    }

    printf("\n--- ALL EMPLOYEES (Total: %d) ---\n", TotalEmployees);
    printf("%-5s %-20s %-15s %-10s %-5s\n",
           "ID", "Name", "Department", "Salary", "Age");
    printf("----------------------------------------------------------------\n");

    for(int i = 0; i < TotalEmployees; i++) {
        printf("%-5d %-20s %-15s $%-9.2f %-5d\n",
               database[i].id,
               database[i].name,
               database[i].department,
               database[i].salary,
               database[i].age);
    }
    printf("----------------------------------------------------------------\n");
}

// Main function
int main() {
    int choice;

    printf(" EMPLOYEE MANAGEMENT SYSTEM \n");
    printf("================================\n");

    while(!exit_flag) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                removeEmployee();
                break;
            case 3: {
                int search_id;
                printf("Enter Employee ID to search: ");
                scanf("%d", &search_id);
                searchID(search_id);
                break;
            }
            case 4:
                modifyEmployee();
                break;
            case 5:
                viewAllEmployees();
                break;
            case 6:
                printf("\n Goodbye! Thank you for using the system.\n");
                exit_flag = true;
                break;
            default:
                printf(" Invalid choice! Please select 1-6.\n");
        }

        if(!exit_flag) {
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
        }
    }

    return 0;
}
