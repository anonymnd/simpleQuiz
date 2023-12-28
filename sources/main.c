#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "../headers/gotoxy.h"

void displayScore(void);

void startQuiz(void)
{
//git
    system("cls");
    char question[10][250];
    strcpy(question[0], "This is question no 1");
    strcpy(question[1], "This is question no 2");
    strcpy(question[2], "This is question no 3");
    strcpy(question[3], "This is question no 4");
    strcpy(question[4], "This is question no 5");
    strcpy(question[5], "This is question no 6");
    strcpy(question[6], "This is question no 7");
    strcpy(question[7], "This is question no 8");
    strcpy(question[8], "This is question no 9");
    strcpy(question[9], "This is question no 10");
    printf("\nQuiz started\n");

    char option[10][4][50] = {
        {"option1", "option2", "option3", "option4"},
        {"option1", "option2", "option3", "option4"},
        {"option1", "option2", "option3", "option4"},
        {"option1", "option2", "option3", "option4"},
        {"option1", "option2", "option3", "option4"},
        {"option1", "option2", "option3", "option4"},
        {"option1", "option2", "option3", "option4"},
        {"option1", "option2", "option3", "option4"},
        {"option1", "option2", "option3", "option4"},
        {"option1", "option2", "option3", "option4"},
    };
    char answer[10] = {'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b'};
    char letter[4] = {'a', 'b', 'c', 'd'};
    char ans;
    int score = 0;

    for (int i = 0; i < 10; i++)
    {
        system("cls");
        gotoxy(20, 8);
        printf("%s\n", question[i]);
        for (int j = 0; j < 4; j++)
        {
            if (j == 0 || j == 2)
            {
                gotoxy(20, 10 + j);
                printf("%c) %s\n", letter[j], option[i][j]);
            }
            else
            {
                gotoxy(55, 9 + j);
                printf("%c) %s\n", letter[j], option[i][j]);
            }
        }

        do
        {
            gotoxy(22, 15);
            printf("Please Choose Answer using key a or b or c or d: ");
            ans = tolower(getch());
            if (ans == 'a' || ans == 'b' || ans == 'c' || ans == 'd')
                break;
        } while (1);

        if (ans == answer[i])
        {
            gotoxy(22, 15);
            printf("Correct Answer!!     PRESS ANY KEY TO Continue....");
            score++;
            getch();
        }
        else
        {
            gotoxy(22, 15);
            printf("Wrong Answer!!     PRESS ANY KEY TO Continue....");
            getch();
        }
    }

    system("cls");
    gotoxy(22, 8);
    printf("You have score %d Out of 10.     PRESS ANY KEY TO Continue....", score);
    getch();

    mainMenu();
}
void mainMenu(void)
{
    system("cls");
    gotoxy(30, 8);
    printf("WELCOME TO QUIZ TEST PROGRAM");
    gotoxy(30, 10);
    printf("----------------------------");
    gotoxy(30, 12);
    printf("Enter S to start game");
    gotoxy(30, 14);
    printf("Enter Q or ESc to quit");
    gotoxy(30, 16);
    printf("----------------------------");

    int ch;

    do
    {
        // Check if a key has been pressed
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 13)
            {
                printf("\nGame Started\n");
                startQuiz();
            }
            else if (ch == 27)
            {
                printf("\nGame Ended\n");
                return;
            }
        }
    } while (1);
}

int main(void)
{
    mainMenu();
    return EXIT_SUCCESS;
}
