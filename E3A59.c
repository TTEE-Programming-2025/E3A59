#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    int password;
    char ch;
    
    printf("*********************************\n");
    printf("* 歡迎光臨  貓咪神教   貓咪會征服世界 *\n");
    printf("*********************************\n\n");
    
    // 顯示貓
    printf(" _________\n");
    printf("  /\\_/\\   |         E3A59蔡易霖\n");
    printf(" ( o.o )  |\n");
    printf("  > ^ <   |\n");
    printf(" _________|\n");
 
    // 顯示聖誕樹
    printf("\n");
    printf("          o\n");
    printf("         /_\\\n");
    printf("        /_ _\\\n");
    printf("       /_ _ _\\\n");
    printf("      /_ _ _ _\\\n");
    printf("     /_ _ _ _ _\\\n");
    printf("          ||\n");
    printf("          ||\n");
    printf("    ~~~~~~~~~~~~~~~\n");

    printf("按enter繼續...");
    getchar();
    system("clear");
   
    printf("請輸入四位數密碼: ");
    scanf("%d", &password);
    
    while (password != 2024) {
        printf("密碼錯誤 請重新輸入：");
        scanf("%d", &password);
    }
   
    printf("密碼正確!\n");
    printf("按enter鍵繼續...");
    getchar();
    system("clear");
    
    printf("\n-------------------------\n");
    printf("|  ˋAˊ～～～ ˋZˊ: 大寫字母 |\n");
    printf("|  ˋaˊ～～～ ˋzˊ: 小寫字母 |\n");
    printf("|  ˋ0ˊ～～～ ˋ9ˊ: 數字    |\n");
    printf("|  --輸入其他-- :班級座號  |\n");
    printf("-------------------------\n");
    printf("請輸入一個字元：");
    scanf(" %c", &ch);

        // 判斷輸入類型
        if (ch >= 'A' && ch <= 'Z') {
            printf("\n你輸入的是 大寫字母！\n");
        }
        else if (ch >= 'a' && ch <= 'z') {
            printf("\n你輸入的是 小寫字母 ！\n");
        }
        else if (ch >= '0' && ch <= '9') {
            printf("\n你輸入的是 數字 ！\n");
        }
        else {
            printf("\n你輸入的是 特殊符號！這是你的個人資訊：\n");
            printf("班級座號：E3A59\n");
            printf("姓名：蔡易霖\n");
        }

        printf("\n 按任意鍵結束程式...");
    return 0;

}
