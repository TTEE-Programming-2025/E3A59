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
// 將建議座位標記為 '*'
void confirmSuggestedSeats() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] == '@')
                seats[i][j] = '*';
}

// 清除所有 '@' 建議座位
void clearSuggestions() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] == '@')
                seats[i][j] = '-';
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
            case 'b': {
                int num;
                printf("請輸入需要的座位數量 (1~4)：");
                scanf("%d", &num);

                if (num < 1 || num > 4) {
                    printf("輸入錯誤，請輸入 1 到 4！\n");
                    break;
                }

                int found = 0;

                // 同列找連續座位（1~3 or 4 人）
                for (int i = 0; i < ROWS && !found; i++) {
                    for (int j = 0; j <= COLS - num; j++) {
                        int ok = 1;
                        for (int k = 0; k < num; k++) {
                            if (seats[i][j + k] != '-') {
                                ok = 0;
                                break;
                            }
                        }
                        if (ok) {
                            for (int k = 0; k < num; k++) {
                                seats[i][j + k] = '@';
                            }
                            found = 1;
                            break;
                        }
                    }
                }

                // 特例：4人時找兩列兩個相同欄位（前後列）
                if (num == 4 && !found) {
                    for (int i = 0; i < ROWS - 1 && !found; i++) {
                        for (int j = 0; j < COLS - 1; j++) {
                            if (seats[i][j] == '-' && seats[i][j + 1] == '-' &&
                                seats[i + 1][j] == '-' && seats[i + 1][j + 1] == '-') {
                                seats[i][j] = seats[i][j + 1] = seats[i + 1][j] = seats[i + 1][j + 1] = '@';
                                found = 1;
                                break;
                            }
                        }
                    }
                }

                if (!found) {
                    printf("找不到可安排的座位，請嘗試其他數量或選項。\n");
                    break;
                }

                // 顯示安排結果
                displaySeats();
                char confirm;
                printf("是否滿意這樣的安排？(y/n)：");
                scanf(" %c", &confirm);

                if (tolower(confirm) == 'y') {
                    confirmSuggestedSeats();
                    printf("已為您完成預約，按 Enter 回主選單...\n");
                    while (getchar() != '\n');
                    getchar();
                } else {
                    clearSuggestions();
                    printf("已取消本次安排，按 Enter 回主選單...\n");
                    while (getchar() != '\n');
                    getchar();
                }
                break;
            }
            case 'c': {
                char input[10];
                int row, col;

                printf("請依序輸入您想預訂的座位（格式: 列-行，例如 1-2），輸入 done 結束：\n");

                while (1) {
                    printf("輸入座位：");
                    scanf("%s", input);

                    if (strcmp(input, "done") == 0) {
                        break;
                    }

                    // 格式檢查：需為 X-Y 形式
                    if (strlen(input) != 3 || input[1] != '-' || !isdigit(input[0]) || !isdigit(input[2])) {
                        printf("格式錯誤，請重新輸入（格式為 列-行）：\n");
                        continue;
                    }

                    row = input[0] - '0';
                    col = input[2] - '0';

                    if (row < 1 || row > 9 || col < 1 || col > 9) {
                        printf("超出範圍，請輸入 1~9 的列與行。\n");
                        continue;
                    }

                    // 座標轉換成陣列索引
                    int i = 9 - row;
                    int j = col - 1;

                    if (seats[i][j] == '*') {
                        printf("該座位已被預訂，請重新選擇。\n");
                    } else if (seats[i][j] == '@') {
                        printf("該座位已在您的選擇中，請選擇其他位置。\n");
                    } else {
                        seats[i][j] = '@';
                        printf("成功選擇 [%d-%d]\n", row, col);
                    }
                }

                // 顯示選擇結果
                printf("\n您選擇的座位如下：\n");
                displaySeats();

                printf("若無誤，按 Enter 確認選擇，將完成預約...\n");
                while (getchar() != '\n'); // 清除緩衝區
                getchar();

                confirmSuggestedSeats(); // 儲存使用者選擇
                break;
            }


            case 'd':
                printf("感謝使用本系統，掰掰喵～\n");
                return 0;
            default:
                printf("功能尚未實作或輸入錯誤，請重新輸入。\n");
        }
    }

    return 0;
}

