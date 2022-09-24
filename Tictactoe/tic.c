#include <stdio.h>
#include <cs50.h>

char a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void printxo();
int markborder(int choice, char mark);
int checkwinner();
int main(void)
{
    int play = 1;
    while(play == 1)
    {
    int choice = 0, player = 1, checker, marker;
    char mark;
    do
    {
        printxo();
        if(player % 2 == 1)
        {
            player = 1;
            mark = 'X';
        }
        else
        {
            player = 2;
            mark = 'O';
        }

        printf("Enter your choice player%i : ", player);
        scanf("%d", &choice);

        marker = markborder(choice, mark);
        if(marker == 0)
        {
            player ++;

        }
        checker = checkwinner();
        if(checker == -1)
        {
            player ++;
        }
    }
    while(checker == -1);

    printxo();
    
    if(checker == 1)
    {
        printf("player %i is won\n", player);
    }

    if(checker == 0)
    {
        printf("----<Game Draw>------\n");
    }
    
    printf("Do you want to play another game?\n");
    printf("Enter 0 to exit, 1 to continue\n");
    scanf("%d", &play);
    
    if (play == 1)
    {
        a[1] = '1';
        a[2] = '2';
        a[3] = '3';
        a[4] = '4';
        a[5] = '5';
        a[6] = '6';
        a[7] = '7';
        a[8] = '8';
        a[9] = '9';
    }
    else
    {
        return 0;
    }

    }
    
}

void printxo()
{
    printf("\n");
    printf("-----player1 (X)    -----player2 (O) \n\n");
    printf(" -------------------\n");
    printf("|      |      |     |\n");
    printf("|   %c  |   %c  |   %c |\n", a[1], a[2], a[3]);
    printf("|      |      |     |\n");
    printf(" -------------------\n");
    printf("|      |      |     |\n");
    printf("|   %c  |   %c  |   %c |\n", a[4], a[5], a[6]);
    printf("|      |      |     |\n");
    printf(" -------------------\n");
    printf("|      |      |     |\n");
    printf("|   %c  |   %c  |   %c |\n", a[7], a[8], a[9]);
    printf("|      |      |     |\n");
    printf(" -------------------\n");
}

int markborder(int choice, char mark)
{
    if(choice == 1 && a[1] == '1')
        a[1] = mark;
    else if(choice == 2 && a[2] == '2')
        a[2] = mark;
    else if(choice == 3 && a[3] == '3')
        a[3] = mark;
    else if(choice == 4 && a[4] == '4')
        a[4] = mark;
    else if(choice == 5 && a[5] == '5')
        a[5] = mark;
    else if(choice == 6 && a[6] == '6')
        a[6] = mark;
    else if(choice == 7 && a[7] == '7')
        a[7] = mark;
    else if(choice == 8 && a[8] == '8')
        a[8] = mark;
    else if(choice == 9 && a[9] == '9')
        a[9] = mark;
    else
    {
        printf("Please enter a valid choice.\n");
        return 0;
    }

    return 1;
}

int checkwinner()
{
    if (a[1] == a[2] && a[2] == a[3])
        return 1;
    else if (a[4] == a[5] && a[5] == a[6])
        return 1;
    else if (a[7] == a[8] && a[8] == a[9])
        return 1;
    else if (a[1] == a[4] && a[4] == a[7])
        return 1;
    else if (a[2] == a[5] && a[5] == a[8])
        return 1;
    else if (a[3] == a[6] && a[6] == a[9])
        return 1;
    else if (a[1] == a[5] && a[5] == a[9])
        return 1;
    else if (a[3] == a[5] && a[5] == a[7])
        return 1;
    else if (a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' && a[5] != '5' && a[6] != '6' && a[7] != '7' && a[8] != '8' && a[9] != '9')
        return 0;

    return -1;
}
