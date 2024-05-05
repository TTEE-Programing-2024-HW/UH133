//修改個人介面,以及修正c99，c11的版本問題，比如在for迴圈前，要先宣告變數
//寫了警告提示字句



#include <stdio.h>
#include <stdlib.h>

void display_screen() {
int i;
int j;
for (i = 0; i < 20; i++) {
printf("*");
}
printf("\n歡迎來到個人風格的畫面!\n");
for (i = 0; i < 20; i++) {
printf("*");
}
printf("\n");
for (i = 0; i < 17; i++) {
printf("*");
for (j = 0; j < 18; j++) {
printf(" ");
}
printf("*\n");
}
for (i = 0; i < 20; i++) {
printf("*");
}
printf("\n");
}
int check_password() {
int correct_password = 2024;
int attempts = 0;
while (attempts < 3) {
int password;
printf("請輸入4個數字的密碼: ");
scanf("%d", &password);
if (password == correct_password) {
printf("密碼正確，進入下一步驟!\n");
return 1;
} else {
attempts++;
printf("密碼錯誤，您已經嘗試了 %d 次。\n", attempts);
}
}
printf("警告：您已經連續錯誤三次，程式將結束。\n");
return 0;
}
