//
//  main.c
//  HW2
//
//  Created by 蔡易霖 on 2025/4/25.
//

//
//  main.c
//  HW2 密碼登入+主選單操作
//
//  Created by 蔡易霖 on 2025/4/25.
//
//  說明：
//  本程式先要求使用者輸入4位數密碼（最多三次機會），密碼正確才能進入主選單。
//  主選單有三個功能：畫直角三角形、顯示乘法表、詢問是否繼續。
//  程式中有完整的輸入錯誤檢查，以及清楚的畫面提示。
//
//  心得：
//  這次作業讓我練習了條件判斷（if/else）、迴圈（while/do-while/for）
//  以及使用函式庫（如ctype.h來處理大小寫問題）。
//  在排版輸出時，發現細節很重要，例如乘法表對齊、以及提示使用者正確操作。
//  寫這份作業也讓我學到如何讓程式更有「互動性」，讓使用者使用起來更友善。

#include <stdio.h>
#include <ctype.h> // for tolower()

int main(void) {
    int password = 2025;  // 預設密碼
    int input;            // 使用者輸入
    int attempts = 0;     // 密碼錯誤次數紀錄

    // 顯示歡迎畫面
    printf("========================================\n");
    printf("=                  E3A59               =\n");
    printf("=--------------------------------------=\n");
    printf("=                  蔡易霖               =\n");
    printf("=--------------------------------------=\n");
    printf("=        Press Enter to Start          =\n");
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
    }

    char choice; // 主選單選項變數

    // 進入主選單
    do {
        printf("--------------------------------\n");
        printf("|          主選單                |\n");
        printf("|-------------------------------|\n");
        printf("| a. 畫出直角三角形               |\n");
        printf("| b. 顯示乘法表                  |\n");
        printf("| c. 結束                       |\n");
        printf("-------------------------------\n");
        printf("請選擇一個選項 (a/b/c)：");
        scanf(" %c", &choice);
        choice = tolower(choice); // 不分大小寫

        if (choice == 'a') {
            // 畫直角三角形
            while (1) {
                printf("\n直角三角形：\n");
                printf("|\\\n");
                printf("| \\\n");
                printf("|  \\\n");
                printf("|   \\\n");
                printf("|    \\\n");
                printf(" -----\n");
                printf("\n");
                break; // 畫完後跳出
            }
        }
        else if (choice == 'b') {
            // 顯示9x9乘法表
            printf("\n乘法表：\n");
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    printf("%d×%d=%2d  ", i, j, i*j);
                }
                printf("\n");
            }
        }
        else if (choice == 'c') {
            // 選擇結束，詢問是否繼續
            char again;
            while (1) {
                printf("Continue? (y/n): ");
                scanf(" %c", &again);
                again = tolower(again);

                if (again == 'y') {
                    break; // y則回到主選單
                } else if (again == 'n') {
                    printf("感謝使用，程式結束！\n");
                    return 0; // n則結束程式
                } else {
                    printf("輸入錯誤，請輸入 y 或 n！\n");
                }
            }
        }
        else {
            // 選項錯誤處理
            printf("輸入錯誤，請輸入 a、b 或 c！\n");
        }
    } while (1); // 無限迴圈，直到使用者選擇結束
}
