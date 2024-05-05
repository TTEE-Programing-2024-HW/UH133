//寫出主選單，將變數i，j寫到最前面並宣告
//寫出三角形的排列



#include <stdio.h>
#include <stdlib.h>
int i;
int j;
// 顯示個人風格的畫面畫出上邊界
void display_screen() {
for ( i = 0; i < 20; i++) {
printf("*");
}
printf("\n歡迎來到個人風格的畫面!\n");
for ( i = 0; i < 20; i++) {
printf("*");
}
printf("\n");
for ( i = 0; i < 17; i++) {
printf("*");
for ( j = 0; j < 18; j++) {
printf(" ");
}
printf("*\n");
}
for ( i = 0; i < 20; i++) {
printf("*");
}
printf("\n");
}
// 檢查密碼是否正確
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
// 畫出直角三角形
void draw_triangle(char c) {
int size = c - 'a' + 1;
for ( i = 0; i < size; i++) {
for ( j = 0; j <= i; j++) {
printf("%c ", c);
}
printf("\n");
}
}
void draw_square(char c) {
int size = c - 'a' + 1;
for ( i = 0; i < size; i++) {
for ( j = 0; j < size; j++) {
printf("%c ", c);
}
printf("\n");
}
}
// 顯示乘法表
void print_multiplication_table(int n) {
for ( i = 1; i <= n; i++) {
for ( j = 1; j <= n; j++) {
printf("%d * %d = %d\t", i, j, i * j);
}
printf("\n");
}
}
// 主函數
int main() {
display_screen();
if (!check_password()) {
return 0;
}
// 進入主選單
while (1) {
printf("--------------------------\n");
printf("|  a. 畫出直角三角形\n");
printf("|  b. 顯示乘法表\n");
printf("|  c. 結束\n");
printf("--------------------------\n");
char option;
printf("請選擇一個選項: ");
scanf(" %c", &option);
