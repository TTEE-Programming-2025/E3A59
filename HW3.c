//
//  main.c
//  HW3
//
//  Created by 蔡易霖 on 2025/5/12.
//
#include <stdio.h>
#include <ctype.h> // for tolower()

int main(void) {
    int password = 2025;  // 預設密碼
    int input;            // 使用者輸入
    int attempts = 0;     // 密碼錯誤次數紀錄

    // 顯示歡迎畫面
    printf("========================================\n");
    printf("=                  E3A59               =\n");
    printf("=                                      =\n");
    printf("=                  蔡易霖               =\n");
    printf("=                                      =\n");
    printf("=                                      =\n");
    printf("=              /\\  /\\                =\n");
    printf("=             ( 。  。 )    /\\         =\n");
    printf("=              ||   || \\ // \\        =\n");
    printf("=              ||   || //              =\n");
    printf("=             ()----()/                =\n");
    printf("=   雖然很難理解但他確實是貓               =\n");
    printf("========================================\n");
    printf("\n\n");

    // 密碼輸入檢查（最多三次）
    while (attempts < 3) {
        printf("請輸入4位數密碼：");
        scanf("%d", &input);

        if (input == password) {
            printf("密碼正確！成功進入下一步！\n");
            break; // 正確則跳出
        } else {
            attempts++;
            if (attempts < 3) {
                printf("密碼錯誤，請再試一次！目前錯誤次數：%d\n", attempts);
            }
        }
    }

    if (attempts == 3) {
        printf("警告：密碼錯誤三次，系統結束！\n");
        return 0; // 密碼錯三次，直接結束

        printf("----------[Booking System]----------\n");
        printf("|   a. Available seats             |\n");
        printf("|   b. Arrange for you             |\n");
        printf("|   c. Choose by yourself          |\n");
        printf("|   d. Exit                        |\n");
        printf("------------------------------------\n");
