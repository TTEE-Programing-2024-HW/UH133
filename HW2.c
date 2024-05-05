//修改個人風格畫面



#include <stdio.h>
#include <stdlib.h>
int i;
int j;
// 顯示個人風格的畫面畫出上邊界
void display_screen() {
printf("888888888888888888888888888888888888888888888888888888888888888888888888888\n");
printf("888888888888888888888888888888888888   888888888888888888888888888888888888\n");
printf("88888888888    888888888888888888888   888888888888888888888888888888888888\n");
printf("88888888888    888888888888888888888    88888888888888888888888888888888888\n");
printf("88888888888    888888888888                     8888888   888            88\n");
printf("88888888888    888888888888                     8888888   88888888888    88\n");
printf("88888888888    888888888888   888888888888888   888888    8888888888    888\n");
printf("88888888888    888888888888   888888888888888   888           88888    8888\n");
printf("88                      888                     888888   88   888     88888\n");
printf("88                      88888888888    888888888888888   8    8888   888888\n");
printf("88888888888    8888888888888888888    88888   8888888    8   88888   888888\n");
printf("88888888888    88888888888888888      88888    888888   88   88888   888888\n");
printf("8888888888     88888888888888          88      888888   88                8\n");
printf("8888888888      8888888888       88         88888888    8                 8\n");
printf("888888888        8888888888    88           88888888        888888   888888\n");
printf("888888888    8   88888888888888     8       8888888888      888888   888888\n");
printf("88888888    88    88888888888     88         8888888888    8888888   888888\n");
printf("8888888    8888    8888888       8       8    888888888     888888   888888\n");
printf("888888    888888    8888888    88    8   88    8888888       88888   888888\n");
printf("88888     8888888    8888888888    888   88     88888    8    8888   888888\n");
printf("888     8888888888     88888      8888   888     888    888    888   888888\n");
printf("8      888888888888     88      88       88888  888    88888888      888888\n");
printf("88   888888888888888   8888   88888     888888888888  888888888     8888888\n");
printf("88888888888888888888888888888888888  88888888888888888888888888888888888888\n");
printf("888888888888888888888888888888888888888888888888888888888888888888888888888\n");
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
if (option == 'a' || option == 'A') {
char c;
printf("請輸入一個‘a’到‘n’的字元: ");
scanf(" %c", &c);
if (c < 'a' || c > 'n') {
printf("輸入字元不在‘a’至‘n’區間，請重新輸入。\n");
continue;
}
draw_triangle(c);
} else if (option == 'b' || option == 'B') {
int n;
printf("請輸入一個1至9的整數: ");
scanf("%d", &n);
if (n < 1 || n > 9) {
printf("輸入的數字不在1至9區間，請重新輸入。\n");
continue;
}
print_multiplication_table(n);
} else if (option == 'c' || option == 'C') {
char c;
printf("_______\n");
printf("|  c  |\n");
printf("|     |\n");
printf("| bc  |\n");
printf("|     |\n");
printf("|abc  |\n");
printf("_______\n");
printf("Continue? (y/n): ");
scanf(" %c", &c);
  // 根據選項進行操作
if (c == 'y' || c == 'Y') {
continue;
} else if (c == 'n' || c == 'N') {
break;
} else {
printf("輸入的字元不是‘y’或‘n’，請重新輸入。\n");
continue;
}
} else {
printf("輸入的選項無效，請重新輸入。\n");
}
}
return 0;
}
