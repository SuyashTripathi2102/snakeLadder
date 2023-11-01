#include <stdio.h>
#include <stdlib.h>
int random()
{
	int result;
    do {
        result = rand() % 7;
    } while (result == 0);
    return result;
}
void displayBoard(int currentPlayerPosition, char playerName[4])
{
    int row, column, temp, count, shift = 0, diceResult, position1, position2;

    if (currentPlayerPosition == 100)
    {
        printf("*****Congratulations*****\n\n\nPlayer %s wins\n", playerName);
        scanf("%*s");
        exit(0);
    }

    for (row = 10; row > 0; row--)
    {
        temp = row - 1;
        if ((shift % 2) == 0)
        {
            count = 0;
            for (column = 10; column >= 1; column--)
            {
                diceResult = (row * column) + (temp * count++);

                if (currentPlayerPosition == diceResult)
                    printf("%s\t", playerName);
                else
                    printf("%d\t", diceResult);
            }
            shift++;
        }
        else
        {
            count = 9;
            for (column = 1; column <= 10; column++)
            {
                diceResult = (row * column) + (temp * count--);

                if (currentPlayerPosition == diceResult)
                    printf("%s\t", playerName);
                else
                    printf("%d\t", diceResult);
            }

            shift++;
        }
        printf("\n\n");
    }

    printf("--------------------------------------------------------------------------\n");
}

void main()
{
	int i, dice, cursorPosition1 = 0, cursorPosition2 = 0;
	char choice;
	while (1)
	{
		printf("		** SNAKE AND LADDER GAME** \n          ");
		printf("        Snakes:- 15 to 5,\t 46 to 32,\t 98 to  3.\n");
		printf("        Ladder:- 17 to 42,\t 63 to 73,\t 73 to 96.\n\n\n");
		printf("Choose your option\n");
		printf("1. Player 1's chance\n");
		printf("2. Player 2's chance\n");
		printf("3. Exit\n");
		scanf("%s", &choice);

		switch (choice)
		{

		case '1':
			dice = random();
			system("cls");
			printf("\t\t\t\tDice = %d\n\n", dice);
			if (dice == 6)
				printf("Dice rolled 6 so you can play one more time.\n");
			cursorPosition1 += dice;
			if (cursorPosition1 < 101)
			{
				if (cursorPosition1 == 98)
				{
					displayBoard(3, "*P1*"); 
				}
				if (cursorPosition1 == 46)
				{
					displayBoard(32, "*P1*"); 
				}
				if (cursorPosition1 == 15)
				{
					displayBoard(5, "*P1*"); 
				}
				if (cursorPosition1 == 73)
				{
					displayBoard(96, "*P1*"); 
				}
				if (cursorPosition1 == 63)
				{
					displayBoard(73, "*P1*"); 
				}
				if (cursorPosition1 == 17)
				{
					displayBoard(42, "*P1*"); 
				}
				else
				{
					displayBoard(cursorPosition1, "*P1*");
				}
			}
			else
			{
				cursorPosition1 -= dice;
				printf("Range exceeded for Player 1.\n");
				displayBoard(cursorPosition1, "*P1*");
			}
			printf("Player 2's position is %d\n", cursorPosition2);

			break;
		case '2':
			dice = random();
			system("cls");
			printf("\t\t\t\tDice = %d\n\n", dice);
			cursorPosition2 += dice;
			if (cursorPosition2 < 101)
			{
				if (cursorPosition2 == 98) 
				{
					displayBoard(3, "*P2*");
				}
				if (cursorPosition2 == 46) 
				{
					displayBoard(32, "*P2*");
				}
				if (cursorPosition2 == 15) 
				{
					displayBoard(5, "*P2*");
				}
				if (cursorPosition2 == 73) 
				{
					displayBoard(96, "*P2*");
				}
				if (cursorPosition2 == 63) 
				{
					displayBoard(73, "*P2*");
				}
				if (cursorPosition2 == 17) 
				{
					displayBoard(42, "*P2*");
				}
				else
				{
					displayBoard(cursorPosition2, "*P2*");
				}
			}

			else
			{
				cursorPosition2 -= dice;
				printf("Range exceeded for Player 2.\n");
				displayBoard(cursorPosition2, "*P2*");
			}
			printf("Player 1's position is %d\n", cursorPosition1);
			break;
		case '3':
			exit(0);
			break;

		default:
			printf("Wrong choice.Try Again\n");
		}
	}
}
