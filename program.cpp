#include <stdio.h>
#include <cstdlib>


int printmenu(int choice){
    printf("================================\n");
    printf("1. Enter Data\n2. Print Data\n3. Find Max Grade\n4. Find Min Grade\n5. Exit\n");
    printf("================================\n");
    printf("Enter your selection: ");
    return choice;
}

int enterdata(int idstudents[], float gradestudents[], int numberstudent) {
    float studentgrade;
    int i;
    
    for (i = 0; i < numberstudent; i++) {
        int studentid;
        printf("Enter ID Student %d: ", i+1);
        scanf("%d", &studentid);
        printf("Enter Grade Student %d: ", i+1);
        scanf("%f", &studentgrade);
        idstudents[i] = studentid;
        gradestudents[i] = studentgrade;
        printf("\nStudent %d: ID %d - Grade %.2f", i+1, idstudents[i], gradestudents[i]);
        printf("\n----------------------------\n");
    }
    return 0;
}
int printdata(int idstudents[], float gradestudents[], int numberstudent) {
    
    printf("Number\t\tID\t\t\tGrade\n");
    for (int i = 0; i < numberstudent; i++) {
        printf("%d\t\t%d\t\t\t%.2f\n", i+1, idstudents[i], gradestudents[i]);
    }
    return 0;
}
int findmaxgrade(int idstudents[], float gradestudents[], int numberstudent) {
    float max = 0;
    int higestid;
    for (int i = 0; i < numberstudent; i++) {
        if (gradestudents[i] > max) {
            max = gradestudents[i];
            higestid = idstudents[i];
        }
    }
    printf("\nHighest grade: ID %d - Grade %.2f", higestid, max);
    return 0;
}
int findmingrade(int idstudents[], float gradestudents[], int numberstudent) {
    float min = 100;
    int lowestid;
    for (int i = 0; i < numberstudent; i++) {
        if (gradestudents[i] < min) {
            min = gradestudents[i];
            lowestid = idstudents[i];
        }
    }
    printf("\nLowest grade: ID %d - Grade %.2f", lowestid, min);
    return 0;
}

int main() {
    printf("Enter the number of students: ");
    int numberstudent;
    scanf("%d", &numberstudent);
    int idstudents[numberstudent];
    float gradestudents[numberstudent];
    
    while (1) {

        int choice;
        while (1) {
            choice = printmenu(choice);
            scanf("%d", &choice);
            if (choice >= 1 and choice <= 5) {
                break;
            } else {
                printf("Invalid choice. Try again\n");
            }
        }
        switch (choice) {
        case 1:
            enterdata(idstudents, gradestudents, numberstudent);
            break;

        case 2:
            printdata(idstudents, gradestudents, numberstudent);
            break;

        case 3:
            findmaxgrade(idstudents, gradestudents, numberstudent);
            break;

        case 4:
            findmingrade(idstudents, gradestudents, numberstudent);
            break;

        case 5:
            exit(0);
            break;
        
        default:
            break;
        }
    }
    return 0;
}