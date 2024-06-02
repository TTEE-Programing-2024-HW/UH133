//寫心得

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
// 輸入學生成績
void enterGrades(Student students[], int *n) {
    printf("Enter the number of students (5-10): ");
    scanf("%d", n);
    if (*n < 5 || *n > 10) {
        printf("Error: Number of students must be between 5 and 10.\n");
        return;
    }

    for (int i = 0; i < *n; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter ID for student %d (6 digits): ", i + 1);
        scanf("%d", &students[i].id);
        printf("Enter Math grade for student %d (0-100): ", i + 1);
        scanf("%d", &students[i].math);
        printf("Enter Physics grade for student %d (0-100): ", i + 1);
        scanf("%d", &students[i].physics);
        printf("Enter English grade for student %d (0-100): ", i + 1);
        scanf("%d", &students[i].english);
    }
}
// 顯示所有學生的成績
void displayGrades(const Student students[], int n) {
    clearScreen();
    for (int i = 0; i < n; i++) {
        float average = (students[i].math + students[i].physics + students[i].english) / 3.0;
        printf("Name: %s, ID: %06d, Math: %d, Physics: %d, English: %d, Average: %.1f\n",
               students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, average);
    }
    printf("Press any key to continue...\n");
    getchar(); // 捕捉前一個回車鍵
    getchar(); // 等待使用者按鍵
}
// 搜尋學生的成績
void searchGrades(const Student students[], int n) {
    char searchName[50];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            float average = (students[i].math + students[i].physics + students[i].english) / 3.0;
            printf("Name: %s, ID: %06d, Math: %d, Physics: %d, English: %d, Average: %.1f\n",
                   students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, average);
            return;
        }
    }
    printf("Student not found.\n");
}

//成績排名
void gradeRanking(const Student students[], int n) {
    // 複製學生資料以進行排序，以免改變原始數據
    Student sortedStudents[MAX_STUDENTS];
    memcpy(sortedStudents, students, sizeof(Student) * n);

    // 使用 qsort 進行排序
    qsort(sortedStudents, n, sizeof(Student), compareAverage);

    // 顯示排序後的學生資料
    for (int i = 0; i < n; i++) {
        float average = (sortedStudents[i].math + sortedStudents[i].physics + sortedStudents[i].english) / 3.0;
        printf("Name: %s, ID: %06d, Average: %.1f\n",
               sortedStudents[i].name, sortedStudents[i].id, average);
    }
    printf("Press any key to continue...\n");
    getchar(); // 捕捉前一個回車鍵
    getchar(); // 等待使用者按鍵
}
// 比較學生的平均成績
int compareAverage(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    float averageA = (studentA->math + studentA->physics + studentA->english) / 3.0;
    float averageB = (studentB->math + studentB->physics + studentB->english) / 3.0;
    return (averageB - averageA); // 降序排序
}
//撰寫這個成績系統的C語言程式碼，對我來說，就像是在解決一個複雜的拼圖。
//每一個函式和結構都是拼圖的一部分，當它們正確地組合在一起時，就能夠創
//造出一個有序和功能完善的系統。這個過程讓我體會到，程式設計能夠反映出
//思考和努力。在這個過程中，我學到了如何完成題目的要求，如何了解將這些
//需求轉為具體的功能。我也學會了耐心，因為有時候找出一個錯誤或解決一個
//問題可能需要時間和多次嘗試。完成這個程式碼後，其實還蠻累的，因為每次
//寫的時候，都會覺得程式碼好複雜，希望自己能夠繼續撐下去。寫的時候，都會覺得程式碼好複雜，希望自己能夠繼續撐下去。
