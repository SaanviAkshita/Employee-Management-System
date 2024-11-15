#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define Employee struct emp

void add(FILE *fp);
FILE* del(FILE *fp);
void modify(FILE *fp);
void displayList(FILE *fp);
void searchRecord(FILE *fp);
void printChar(char ch, int n);
void printHead();

struct emp {
    int id;
    char name[100];
    char desgn[10];
    float sal;
    char gender[10];
    char branch[50];
    char psaddr[200];
    char prtaddr[200];
    char phone[15];
    char mail[20];
};

int main() {
    FILE *fp;
    Employee e;
    int option;
    
    if ((fp = fopen("employeeInfo.txt", "rb+")) == NULL) {
        if ((fp = fopen("employeeInfo.txt", "wb+")) == NULL) {
            printf("Cannot open file\n");
            return 0;
        }
    }
    
    char username[10], password[10];
    printHead();
    printf("\n\t\t\t\t  Login Screen");
    printf("\n\t\t\t      Enter Your Credential");
    printf("\n\n\t\tUsername: ");
    scanf("%s", username);
    
    printf("\n\t\tPassword: ");
    int i = 0;
    while (1) {
        password[i] = getch();
        if (password[i] == '\r') break;
        if (password[i] == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else {
            printf("*");
            i++;
        }
    }
    password[i] = '\0';

    if (strcasecmp(username, "admin") == 0 && strcasecmp(password, "pass") == 0) {
        while (1) {
            printHead();
            printf("\n\t\t\t\tMain Menu\n\n");
            printf("\n\t\t1. Add Employee");
            printf("\n\t\t2. Delete Employee");
            printf("\n\t\t3. Modify Employee");
            printf("\n\t\t4. Display Employee List");
            printf("\n\t\t5. Search Record");
            printf("\n\t\t0. EXIT");
            printf("\n\n\t\tEnter Your Option :--> ");
            scanf("%d", &option);
            
            switch (option) {
                case 0: fclose(fp); return 0;
                case 1: add(fp); break;
                case 2: fp = del(fp); break;
                case 3: modify(fp); break;
                case 4: displayList(fp); break;
                case 5: searchRecord(fp); break;
                default: printf("\n\tInvalid Option! Program terminated.\n");
                         fclose(fp);
                         exit(0);
            }
        }
    } else {
        printf("\n\t\tLogin Failed\n");
    }
    
    fclose(fp);
    return 0;
}

void printChar(char ch, int n) {
    while (n--) putchar(ch);
}

void printHead() {
    system("cls");
    printf("\t");
    printChar('=', 65);
    printf("\n\t");
    printChar('=', 16);
    printf("[EMPLOYEE] [MANAGEMENT] [SYSTEM]");
    printChar('=', 16);
    printf("\n\t");
    printChar('=', 65);
    printf("\n");
}

void add(FILE *fp) {
    printHead();
    printf("\n\t\tAdd Employee\n");
    
    Employee e;
    char another = 'y';
    fseek(fp, 0, SEEK_END);
    
    while (another == 'y' || another == 'Y') {
        printf("\n\tEnter ID number: ");
        scanf("%d", &e.id);
        printf("\tEnter Full Name of Employee: ");
        fflush(stdin);
        fgets(e.name, 100, stdin);
        e.name[strcspn(e.name, "\n")] = '\0';
        
        printf("\tEnter Designation: ");
        fgets(e.desgn, 10, stdin);
        e.desgn[strcspn(e.desgn, "\n")] = '\0';
        
        printf("\tEnter Gender: ");
        fgets(e.gender, 10, stdin);
        e.gender[strcspn(e.gender, "\n")] = '\0';
        
        printf("\tEnter Branch: ");
        fgets(e.branch, 50, stdin);
        e.branch[strcspn(e.branch, "\n")] = '\0';
        
        printf("\tEnter Salary: ");
        scanf("%f", &e.sal);
        
        printf("\tEnter Present Address: ");
        fflush(stdin);
        fgets(e.psaddr, 200, stdin);
        e.psaddr[strcspn(e.psaddr, "\n")] = '\0';
        
        printf("\tEnter Permanent Address: ");
        fgets(e.prtaddr, 200, stdin);
        e.prtaddr[strcspn(e.prtaddr, "\n")] = '\0';
        
        printf("\tEnter Phone: ");
        fgets(e.phone, 15, stdin);
        e.phone[strcspn(e.phone, "\n")] = '\0';
        
        printf("\tEnter E-mail: ");
        fgets(e.mail, 20, stdin);
        e.mail[strcspn(e.mail, "\n")] = '\0';
        
        fwrite(&e, sizeof(e), 1, fp);
        
        printf("\n\tWant to enter another employee info (Y/N): ");
        fflush(stdin);
        another = getchar();
    }
}

FILE* del(FILE *fp) {
    printHead();
    printf("\n\t\tDelete Employee\n");
    
    Employee e;
    int flag = 0, tempid;
    FILE *ft = fopen("temp.txt", "wb+");
    
    if (ft == NULL) {
        printf("\n\t!!! ERROR: Unable to open temporary file !!!\n");
        return fp;
    }
    
    printf("\n\tEnter ID number of Employee to delete: ");
    scanf("%d", &tempid);
    rewind(fp);
    
    while (fread(&e, sizeof(e), 1, fp) == 1) {
        if (e.id == tempid) {
            flag = 1;
            printf("\n\tRecord Deleted for Employee ID: %d\n", e.id);
            continue;
        }
        fwrite(&e, sizeof(e), 1, ft);
    }
    
    fclose(fp);
    fclose(ft);
    remove("employeeInfo.txt");
    rename("temp.txt", "employeeInfo.txt");
    
    fp = fopen("employeeInfo.txt", "rb+");
    if (fp == NULL) {
        printf("ERROR: Unable to open employee file\n");
    }
    
    if (flag == 0) printf("\n\tERROR: Record Not Found\n");
    printChar('-', 65);
    printf("\n");
    system("pause");
    return fp;
}

void modify(FILE *fp) {
    Employee e;
    int id, found = 0;
    long int size = sizeof(e);

    printf("\n\tEnter Employee ID to Modify: ");
    scanf("%d", &id);

    rewind(fp);
    while (fread(&e, size, 1, fp) == 1) {
        if (e.id == id) {
            found = 1;
            printf("\n\tEmployee ID: %d", e.id);
            printf("\n\tEnter New Full Name: ");
            fflush(stdin);
            fgets(e.name, 100, stdin);
            e.name[strcspn(e.name, "\n")] = '\0';

            printf("\tEnter New Designation: ");
            fgets(e.desgn, 10, stdin);
            e.desgn[strcspn(e.desgn, "\n")] = '\0';

            printf("\tEnter New Salary: ");
            scanf("%f", &e.sal);

            fseek(fp, -size, SEEK_CUR);
            fwrite(&e, size, 1, fp);
            printf("\n\tRecord updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("\n\tEmployee with ID %d not found.\n", id);
    }
}

void displayList(FILE *fp) {
    Employee e;
    rewind(fp);

    printf("\n\t\tEmployee List\n");
    printf("\n\t%-5s %-20s %-10s %-10s %-10s\n", "ID", "Name", "Designation", "Gender", "Salary");
    printf("\t------------------------------------------------------------\n");

    while (fread(&e, sizeof(e), 1, fp) == 1) {
        printf("\t%-5d %-20s %-10s %-10s %.2f\n", e.id, e.name, e.desgn, e.gender, e.sal);
    }
}

void searchRecord(FILE *fp) {
    Employee e;
    int id, found = 0;

    printf("\n\tEnter Employee ID to Search: ");
    scanf("%d", &id);

    rewind(fp);
    while (fread(&e, sizeof(e), 1, fp) == 1) {
        if (e.id == id) {
            found = 1;
            printf("\n\tEmployee ID: %d", e.id);
            printf("\n\tName: %s", e.name);
            printf("\n\tDesignation: %s", e.desgn);
            printf("\n\tGender: %s", e.gender);
            printf("\n\tBranch: %s", e.branch);
            printf("\n\tSalary: %.2f", e.sal);
            printf("\n\tPresent Address: %s", e.psaddr);
            printf("\n\tPermanent Address: %s", e.prtaddr);
            printf("\n\tPhone: %s", e.phone);
            printf("\n\tE-mail: %s\n", e.mail);
            break;
        }
    }
    if (!found) {
        printf("\n\tEmployee with ID %d not found.\n", id);
    }
}

