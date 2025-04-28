//
//  main.c
//  HW2
//
//  Created by 蔡易霖 on 2025/4/25.
//

#include <stdio.h>

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

    return 0;
}
