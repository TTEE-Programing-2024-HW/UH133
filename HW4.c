//寫主程式以及輸入密碼


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
