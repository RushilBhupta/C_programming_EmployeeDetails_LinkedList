#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char fName[10];
    char lName[10];
    int age;
    int D, M, Y;
};

struct Address {
    char city[20];
    char state[20];
    int pin;
    long pNumber;
};

struct Employee {
    struct Person person;
    struct Address address;
    struct Employee* next;
};

struct Employee* insert(struct Employee* head);
struct Employee* update(struct Employee* head);
struct Employee* removeEmployee(struct Employee* head);
void displayList(struct Employee* head);
void display(struct Employee* head);
struct Employee* delete(struct Employee* head);
void freeList(struct Employee* head);
int sort_Even_Odd(struct Employee *head, struct Employee** headEven, struct Employee** headOdd);
void displayByMonth(struct Employee* evenMonthsHead, struct Employee* oddMonthsHead);
void split(struct Employee *head, struct Employee** headEven, struct Employee** headOdd);

int main() {
    struct Employee* head = NULL;
    struct Employee* headOdd = NULL;
    struct Employee* headEven = NULL;
    int choice;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Sort List\n");
        printf("5. Display List\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter the Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insert(head);
                break;
            case 2:
                head = update(head);
                break;
            case 3:
                head = removeEmployee(head);
                break;
            case 4:
            	sort_Even_Odd(head, &headEven, &headOdd);
            	break;
            case 5:
            	split(head,&headEven,&headOdd);
                break;
            case 6:
                display(head);
                break;
            case 7:
                freeList(head);
                freeList(headEven);
                freeList(headOdd);
                exit(0);
            default:
                printf("Invalid Input.\n");
                break;
        }
    }

    return 0;
}

void split(struct Employee* head, struct Employee** headEven, struct Employee** headOdd) {
    int x;
    while (1) {
        printf("\n1. Main List\n");
        printf("2. Even List\n");
        printf("3. Odd List\n");
        printf("4. Exit\n");
        printf("Enter the List Number that you are looking for: ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                displayList(head);
                break;
            case 2:
                if (headEven != NULL) {
                    displayList(*headEven);
                } else {
                    printf("Even List is empty.\n");
                }
                break;
            case 3:
                if (headOdd != NULL) {
                    displayList(*headOdd);
                } else {
                    printf("Odd List is empty.\n");
                }
                break;
            case 4:
                return;
            default:
                printf("Invalid Input.\n");
                break;
        }
    }
}

struct Employee* insert(struct Employee* head) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));

    if (newEmployee == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    printf("Enter the details of the Employee: \n");
    printf("Enter the First Name of the Employee: ");
    scanf("%s", newEmployee->person.fName);
    printf("Enter the Last Name of the Employee: ");
    scanf("%s", newEmployee->person.lName);
    printf("Enter the Age of the Employee: ");
    scanf("%d", &newEmployee->person.age);
    printf("Enter the DOB of the Employee in the format (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &newEmployee->person.D, &newEmployee->person.M, &newEmployee->person.Y);
    printf("Enter the City of the Employee: ");
    scanf("%s", newEmployee->address.city);
    printf("Enter the State of the Employee: ");
    scanf("%s", newEmployee->address.state);
    printf("Enter the PIN CODE of the city of Employee: ");
    scanf("%d", &newEmployee->address.pin);
    printf("Enter the Phone Number of the Employee: ");
    scanf("%ld", &newEmployee->address.pNumber);
    newEmployee->next = head;
    return newEmployee;
}

struct Employee* update(struct Employee* head) {
    int i;
    printf("Enter the Employee Number whose data need to be updated: ");
    scanf("%d", &i);

    struct Employee* current = head;
    while (current != NULL) {
        if (i == 0) {
            printf("Enter The choice that you need to update:\n");
            printf("1. fName\n");
            printf("2. lName\n");
            printf("3. Age\n");
            printf("4. DOB\n");
            printf("5. City\n");
            printf("6. State\n");
            printf("7. PINCODE\n");
            printf("8. PHN NUMBER\n");
            int x;
            printf("Enter the Number to the Choice: ");
            scanf("%d", &x);

            switch (x) {
                case 1:
                    printf("Enter the First Name to be updated: ");
                    scanf("%s", current->person.fName);
                    printf("First Name updated Successfully!!\n");
                    break;
                case 2:
                    printf("Enter the Last Name to be updated: ");
                    scanf("%s", current->person.lName);
                    printf("Last Name updated Successfully!!\n");
                    break;
                case 3:
                    printf("Enter the Age to be updated: ");
                    scanf("%d", &current->person.age);
                    printf("Age updated Successfully!!\n");
                    break;
                case 4:
                    printf("Enter the DOB to be updated: ");
                    scanf("%d/%d/%d", &current->person.D, &current->person.M, &current->person.Y);
                    printf("DOB updated Successfully!!\n");
                    break;
                case 5:
                    printf("Enter the City to be updated: ");
                    scanf("%s", current->address.city);
                    printf("City updated Successfully!!\n");
                    break;
                case 6:
                    printf("Enter the state to be updated: ");
                    scanf("%s", current->address.state);
                    printf("State updated Successfully!!\n");
                    break;
                case 7:
                    printf("Enter the PIN CODE to be updated: ");
                    scanf("%d", &current->address.pin);
                    printf("PIN CODE updated Successfully!!\n");
                    break;
                case 8:
                    printf("Enter the Phone Number to be updated: ");
                    scanf("%ld", &current->address.pNumber);
                    printf("Phone Number updated Successfully!!\n");
                    break;
                default:
                    printf("Invalid Input.\n");
                    break;
            }
            break;
        }
        current = current->next;
        i--;
    }

    if (i != 0) {
        printf("Invalid Employee Number or Data does not exist.\n");
    }

    return head;
}

int sort_Even_Odd(struct Employee *head, struct Employee** headEven, struct Employee** headOdd) {
    
    *headEven = NULL;
    *headOdd = NULL;

    struct Employee *temp = head;
    struct Employee *newEmployee;
    struct Employee *temp_odd = NULL;
    struct Employee *temp_even = NULL;

    do {
        newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
        memcpy(newEmployee, temp, sizeof(struct Employee));
        if ((newEmployee->person.M) % 2 == 0) {
            if (*headEven == NULL) {
                *headEven = newEmployee;
                (*headEven)->next = NULL;
                temp_even = *headEven;
            } else {
                temp_even->next = newEmployee;
                temp_even = temp_even->next;
            }
            temp_even->next = NULL;
        } else {
            if (*headOdd == NULL) {
                *headOdd = newEmployee;
                (*headOdd)->next = NULL;
                temp_odd = *headOdd;
            } else {
                temp_odd->next = newEmployee;
                temp_odd = temp_odd->next;
            }
            temp_odd->next = NULL;
        }
        temp = temp->next;
    } while (temp != NULL);

    printf("Sorting is Done!!.\n");

    return 0;
}

struct Employee* removeEmployee(struct Employee* head){
    int i;
    printf("Enter the Employee Number whose data need to be removed: ");
    scanf("%d", &i);

    if (i == 0) {
        struct Employee* temp = head;
        head = head->next;
        free(temp);
        printf("Employee removed successfully!\n");
    } else {
        struct Employee* current = head;
        while (current != NULL) {
            if (i == 1) {
                struct Employee* temp = current->next;
                if (temp != NULL) {
                    current->next = temp->next;
                    free(temp);
                    printf("Employee removed successfully!\n");
                } else {
                    printf("Invalid Employee Number or Data does not exist.\n");
                }
                break;
            }
            current = current->next;
            i--;
        }
    }

    return head;
}


void displayList(struct Employee* head) {
    struct Employee* current = head;

    while (current != NULL) {
        printf("=======================================\n");
        printf("The First Name of the Employee is %s.\n", current->person.fName);
        printf("The Last Name of the Employee is %s.\n", current->person.lName);
        printf("The Age of the Employee is %d.\n", current->person.age);
        printf("The DOB Name of the Employee is (%d/%d/%d).\n", current->person.D, current->person.M, current->person.Y);
        printf("The City of the Employee is %s.\n", current->address.city);
        printf("The State of the Employee is %s.\n", current->address.state);
        printf("The PINCODE of the Employee is %d.\n", current->address.pin);
        printf("The PHONE NUMBER of the Employee is %ld.\n", current->address.pNumber);
        printf("=========================================\n");

        current = current->next;
    }
}

void display(struct Employee* head) {
    int i;
    printf("Enter the Employee Number whose data you want to display: ");
    scanf("%d", &i);

    struct Employee* current = head;
    while (current != NULL) {
        if (i == 0) {
            printf("=======================================\n");
            printf("The First Name of the Employee is %s.\n", current->person.fName);
            printf("The Last Name of the Employee is %s.\n", current->person.lName);
            printf("The Age of the Employee is %d.\n", current->person.age);
            printf("The DOB Name of the Employee is (%d/%d/%d).\n", current->person.D, current->person.M, current->person.Y);
            printf("The City of the Employee is %s.\n", current->address.city);
            printf("The State of the Employee is %s.\n", current->address.state);
            printf("The PINCODE of the Employee is %d.\n", current->address.pin);
            printf("The PHONE NUMBER of the Employee is %ld.\n", current->address.pNumber);
            printf("=========================================\n");
            break;
        }
        current = current->next;
        i--;
    }

    if (i != 0) {
        printf("Invalid Employee Number or Data does not exist.\n");
    }
}

struct Employee* delete(struct Employee* head) {
    int i;
    printf("Enter the Employee Number whose data need to be deleted: ");
    scanf("%d", &i);

    if (i == 0) {
        struct Employee* temp = head;
        head = head->next;
        free(temp);
        printf("Employee deleted successfully!\n");
    } else {
        struct Employee* current = head;
        while (current != NULL) {
            if (i == 1) {
                struct Employee* temp = current->next;
                if (temp != NULL) {
                    current->next = temp->next;
                    free(temp);
                    printf("Employee deleted successfully!\n");
                } else {
                    printf("Invalid Employee Number or Data does not exist.\n");
                }
                break;
            }
            current = current->next;
            i--;
        }
    }

    return head;
}

void freeList(struct Employee* head) {
    while (head != NULL) {
        struct Employee* temp = head;
        head = head->next;
        free(temp);
    }
}
