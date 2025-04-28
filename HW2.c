//
//  main.c
//  HW2
//
//  Created by 蔡易霖 on 2025/4/25.
//

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int password = 2025;
    int input;
    int a = 0;

    printf("========================================\n");
    printf("=                  E3A59               =\n");
    printf("=--------------------------------------=\n");
    printf("=                  蔡易霖               =\n");
    printf("=--------------------------------------=\n");
    printf("=--------------------------------------=\n");
    printf("=        Press Enter to Start          =\n");
    printf("========================================\n");
    printf("\n\n");


    while (a < 3) {
        printf("請輸入4位數密碼：");
        scanf("%d", &input);

        if (input == password) {
            printf("密碼正確！成功進入下一步！\n");
            break;
        } else {
            a++;
            if (a < 3) {
                printf("密碼錯誤，請再試一次！目前錯誤次數：%d\n", a);
            }
        }
    }

    if (a == 3) {
        printf("警告：密碼錯誤三次，系統結束！\n");
    }
    char choice;

        do {
            // 顯示主選單
            printf("----------------------------------\n");
            printf("|          主選單                |\n");
            printf("|--------------------------------|\n");
            printf("| a. 畫出直角三角形              |\n");
            printf("| b. 顯示乘法表                  |\n");
            printf("| c. 結束                       |\n");
            printf("----------------------------------\n");
            printf("請選擇一個選項 (a/b/c)：");
            scanf(" %c", &choice);
            choice = tolower(choice);

            if (choice == 'a'){
                while (1) {
                    printf("\n直角三角形：\n");
                    printf("|\\\n");
                    printf("| \\\n");
                    printf("|  \\\n");
                    printf("|   \\\n");
                    printf("|    \\\n");
                    printf(" -----\n");
                    printf("\n");
                    break;
                }
            }
            else if (choice == 'b'){
                printf("\n乘法表：\n");
                for (int i = 1; i <= 9; i++) {
                    for (int j = 1; j <= 9; j++) {
                        printf("%d×%d=%2d  ", i, j, i*j);
                    }
                    printf("\n");
                }
                    
                
            }
                        else if (choice == 'c') {
                                    char again;
                                    while (1) {
                                        printf("Continue? (y/n): ");
                                        scanf(" %c", &again);
                                        again = tolower(again);
                                        
                                        if (again == 'y') {
                                            break; // 回到主選單
                                        } else if (again == 'n') {
                                            printf("感謝使用，程式結束！\n");
                                            return 0;
                                        } else {
                                            printf("輸入錯誤，請輸入 y 或 n！\n");
                                        }
                                    }
                                }
                                else {
                                    printf("輸入錯誤，請輸入 a、b 或 c！\n");
                                }
                            } while (1);
                        }
