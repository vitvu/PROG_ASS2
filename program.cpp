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
        scanf("%d",&choice);
        if (choice >= 1 and choice <= 5) {
            break;
        } else {
            printf("[Error] Invalid choice. Try again\n================================\n");
        }
    }
    return choice;
}

int enter_student_data(long student_ids[], float student_grades[], int students_size) {
    float student_grade;
    int i;
    system("cls");
    for (i = 0; i < students_size; i++) {
        long student_id;
        printf("Enter ID Student %d: ", i+1);
        scanf("%ld", &student_id);
        printf("Enter Grade Student %d: ", i+1);
        scanf("%f", &student_grade);
        student_ids[i] = student_id; // Assign student ID to the array
        student_grades[i] = student_grade; // Assign student grade to the array
        printf("\n---> Student %d: ID %ld - Grade %.2f", i+1, student_ids[i], student_grades[i]);
        printf("\n================================\n");

    }
    printf("\n================================\n");
    return 0;
}
int print_student_data(long student_ids[], float student_grades[], int students_size) {
    system("cls");
    printf("All Student Data:\n");
    printf("No\t\tID\t\t\t\tGrade\n");
    for (int i = 0; i < students_size; i++) {
        printf("%d\t\t%ld\t\t\t\t%.2f\n", i+1, student_ids[i], student_grades[i]);
    }
    printf("\n================================\n");
    return 0;
}
int find_max_grade(long student_ids[], float student_grades[], int students_size) {
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
    float min_grade = student_grades[0];
    long student_id_lowest;
    for (int i = 0; i < students_size; i++) {
        if (student_grades[i] < min_grade) {
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