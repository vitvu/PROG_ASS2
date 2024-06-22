#include <stdio.h>
#include <cstring>
#include <cstdlib>


int print_menu_get_selection(int choice){
    while (1) {
        printf("Student Management Program\n");
        printf("================================\n");
        printf("1. Enter Student Data\n2. Print All Student Data\n3. Find Max Grade\n4. Find Min Grade\n5. Exit\n");
        printf("================================\n");
        printf("----> Enter your selection: ");
        while(scanf("%d",&choice) != 1) { // Check if choice is assigned properly or not
            printf("Please enter an integer!!!\n");
            exit(0);
        }
        if (choice >= 1 and choice <= 5) {
            break;
        } else {
            printf("[Error] Invalid choice. Try again\n================================\n");
        }
    }
    return choice;
}

int enter_student_data(long student_ids[], float student_grades[], int students_size) {
    // int count, a, b;
    float student_grade;
    int i;
    system("cls");
    // printf("Enter student data from 'a-b': \n");
    // scanf("%d-%d", &a, &b);
    for (i = 0; i < students_size; i++) {
        long student_id;
        printf("\nType '-1' to back to homepage\n");
        printf("Enter ID Student %d: ", i+1);
        scanf("%ld", &student_id);
        if (student_id != -1) {
            printf("Enter Grade Student %d: ", i+1);
            scanf("%f", &student_grade);
            // gets(student_grade);
            student_ids[i] = student_id; // Assign student ID to the array
            student_grades[i] = student_grade; // Assign student grade to the array
            printf("\n---> Student %d: ID %ld - Grade %.2f", i+1, student_ids[i], student_grades[i]);
            printf("\n================================\n");
        } else {
            for (int j = i; j < students_size; j++) {
                student_ids[j] = 0;
                student_grades[j] = 0;
            }
            return 0;
        }

    }
    printf("\n================================\n");
    return 0;
}
int print_student_data(long student_ids[], float student_grades[], int students_size) {
    system("cls");
    if (student_grades[0] == 0 and student_grades[1] == 0) {
        printf("Error: No data ---> Please enter student data\n\n");
        return 0;
    }
    printf("All Student Data:\n");
    printf("No\t\tID\t\t\t\tGrade\n");
    for (int i = 0; i < students_size; i++) {
        printf("%d\t\t%ld\t\t\t\t%.2f\n", i+1, student_ids[i], student_grades[i]);
    }
    printf("\n================================\n");
    return 0;
}
int find_max_grade(long student_ids[], float student_grades[], int students_size) {
    if (student_grades[0] == 0 and student_grades[1] == 0) {
        printf("Error: No data yet ---> Please enter student data\n\n");
        return 0;
    }
    float max_grade = student_grades[0];
    long student_id_highest;
    for (int i = 0; i < students_size; i++) {
        if (student_grades[i] > max_grade) {
            max_grade = student_grades[i];
            student_id_highest = student_ids[i];
        }
    }
    printf("\nHighest grade: ID %ld - Grade %.2f", student_id_highest, max_grade);
    printf("\n================================\n");
    return 0;
}
int find_min_grade(long student_ids[], float student_grades[], int students_size) {
    if (student_grades[0] == 0 and student_grades[1] == 0) {
        printf("Error: No data ---> Please enter student data\n\n");
        return 0;
    }
    float min_grade = student_grades[0];
    long student_id_lowest;
    for (int i = 0; i < students_size; i++) {
        if (student_grades[i] < min_grade and student_grades[i] != 0 and student_ids[i] != 0) {
            min_grade = student_grades[i];
            student_id_lowest = student_ids[i];
        }
    }
    printf("\nLowest grade: ID %ld - Grade %.2f", student_id_lowest, min_grade);
    printf("\n================================\n");
    return 0;
}

int main() {
    system("cls");
    printf("Student Management Program\n");
    printf("================================\n");
    printf("Enter the number of students: ");
    int student_count;
    scanf("%d", &student_count);
    long student_ids[student_count];
    float student_grades[student_count];
    system("cls");
    while (1) {

        int choice;
        choice = print_menu_get_selection(choice);
        switch (choice) {
        case 1:
            enter_student_data(student_ids, student_grades, student_count);
            break;

        case 2:
            print_student_data(student_ids, student_grades, student_count);
            break;

        case 3:
            find_max_grade(student_ids, student_grades, student_count);
            break;

        case 4:
            find_min_grade(student_ids, student_grades, student_count);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);
            break;
        
        default:
            break;
        }
    }
    return 0;
}