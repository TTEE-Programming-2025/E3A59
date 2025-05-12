#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define ROWS 9
#define COLS 9
#define MAX_RESERVED 10

char seats[ROWS][COLS]; // 儲存座位狀態

// 初始化座位陣列為 '-'，並隨機選出 10 個座位設為 '*'
void initializeSeats() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-';

    srand((unsigned int)time(NULL));
    int reserved = 0;
    while (reserved < MAX_RESERVED) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            reserved++;
        }
    }
}

// 顯示座位表
void displaySeats() {
    printf("   ");
    for (int i = 1; i <= COLS; i++) {
        printf("%d", i);
    }
    printf("\n");

    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int password = 2025;
    int input;
    int attempts = 0;

    // 歡迎畫面
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

    // 密碼驗證
    while (attempts < 3) {
        printf("請輸入4位數密碼：");
        scanf("%d", &input);

        if (input == password) {
            printf("密碼正確！成功進入下一步！\n");
            break;
        } else {
            attempts++;
            if (attempts < 3) {
                printf("密碼錯誤，請再試一次！目前錯誤次數：%d\n", attempts);
            } else {
                printf("警告：密碼錯誤三次，系統結束！\n");
                return 0;
            }
        }
    }

    initializeSeats(); // 初始化座位

    char choice;
    while (1) {
        printf("\n----------[Booking System]----------\n");
        printf("|   a. Available seats             |\n");
        printf("|   b. Arrange for you             |\n");
        printf("|   c. Choose by yourself          |\n");
        printf("|   d. Exit                        |\n");
        printf("------------------------------------\n");
        printf("請選擇操作：");
        scanf(" %c", &choice);

        switch (tolower(choice)) {
            case 'a':
                displaySeats();
                printf("按下 Enter 鍵回主選單...\n");
                while (getchar() != '\n'); // 清掉前面緩衝
                getchar(); // 等待使用者按下 enter
                break;
            case 'd':
                printf("感謝使用本系統，掰掰喵～\n");
                return 0;
            default:
                printf("功能尚未實作或輸入錯誤，請重新輸入。\n");
        }
    }

    return 0;
}

