//寫主選單和宣告函數還有學生結構定義

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define PASSWORD "2024"

// 學生結構定義
typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
} Student;

// 函式宣告
void enterGrades(Student students[], int *n);
void displayGrades(const Student students[], int n);
void searchGrades(const Student students[], int n);
void gradeRanking(const Student students[], int n);
void clearScreen();
int compareAverage(const void *a, const void *b);

// 主程式
int main() {
    Student students[MAX_STUDENTS]; // 學生資料陣列
    int studentCount = 0; // 學生數量
    char option; // 選單選項
    char inputPassword[5]; // 輸入密碼
    int passwordAttempts = 0; // 密碼嘗試次數
// 個人風格畫面
    printf("Welcome to the Simple Grade System\n");
    // 密碼輸入部分
    do {
        printf("Please enter the 4-digit password: ");
        scanf("%s", inputPassword);
        if (strcmp(inputPassword, PASSWORD) == 0) {
            printf("Access granted. Welcome!\n");
            break;
        } else {
            printf("Incorrect password. Try again.\n");
            passwordAttempts++;
        }
    } while (passwordAttempts < 3);

    if (passwordAttempts == 3) {
        printf("Too many incorrect attempts. Exiting program.\n");
        return 0;
    }
// 主選單
    do {
        clearScreen();
        printf("------------[Grade System]----------\n");
        printf("| a. Enter student grades          |\n");
        printf("| b. Display student grades        |\n");
        printf("| c. Search for student grades     |\n");
        printf("| d. Grade ranking                 |\n");
        printf("| e. Exit system                   |\n");
        printf("------------------------------------\n");
        printf("Select an option: ");
        scanf(" %c", &option); // 注意空格，用於忽略前面的換行符

        switch (option) {
            case 'a':
                enterGrades(students, &studentCount);
                break;
            case 'b':
                displayGrades(students, studentCount);
                break;
            case 'c':
                searchGrades(students, studentCount);
                break;
            case 'd':
                gradeRanking(students, studentCount);
                break;
            case 'e':
                printf("Are you sure you want to exit? (y/n): ");
                scanf(" %c", &option);
                if (option == 'y' || option == 'Y') {
                    printf("Exiting system...\n");
                    return 0;
                }
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 'e');

    return 0;
}
// 清除螢幕函式
void clearScreen() {
    system("clear || cls");
}
