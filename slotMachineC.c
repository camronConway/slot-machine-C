/*
* Program Name: COP2220 Project 3
*
* Author: Camron Conway
*
* Description: This program simulates a slot machine by having the player
* enter in a starting amount, and a bet amount. When entered the slot machine
* will generate three random numbers between 1 and 8, and then display the players winnings
* The program will calculate the players new total based on the winnings and ask to play
* again
*
* Algorithm
* 1. print project name, and greetings
* 2. seed random#gen
* 3. prompt user for starting amount
* 4. check amount for error or 0
* 5. if error repeat step 3, if 0 then quit
* 6. prompt user for bid amount
* 7. check amount for error or 0
* 8. if error repeat step 5, if 0 quit
* 9. subtract bid amount from sum
* 10. generate random number for 3 slots, #1-8
* 11. check if win based on conditions
* 12. if win reward money to sum total
* 13. print all information as a slot machine, including win or lose message
* 14. ask to play again
* 15. if yes repeat steps 6 - 14
* 16. if no print exit message
*
* Input: The player first enters a starting sum or 0 to exit, then
* the player enters a bet amount, or 0 to exit the game.
*
* Output: The program outputs a printed slot machine, as well as a message telling
* the type of win, the win amount, and the new total. The program will also output a message
* if the player quits at the start, when the player decides to cash out, if the player runs out of money
* and when the player tries to bid more money than they have.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void slot(int* ax, int* bx, int* cx);
void slotPrint(int sum, int bet, int s1, int s2, int s3, int winPrint);
int bidMaker(int* sumT);
int slotWinning(int s1, int s2, int s3, int betA, int* winSum);
int sumStart(void);

int main (void)
{
    //initial variables
    int playerBet, betWinning, winType, sumTotal;
    int slot1, slot2, slot3;

    //seed
    srand(time(NULL));

    //Title and author of program
    printf("COP 2220 Project 3 - Camron Conway");
    printf("\n\nLet's Play Crazy Eights!\n");
    sumTotal = sumStart();

    //looping slot machine
    while(sumTotal > 0)
    {
    playerBet = bidMaker(&sumTotal);
    slot(&slot1, &slot2, &slot3);
    betWinning = slotWinning(slot1, slot2, slot3, playerBet, &winType);
    sumTotal = sumTotal+betWinning;
    slotPrint(sumTotal, betWinning, slot1, slot2, slot3, winType);
    }
    if (sumTotal == 0)
        printf("\nToo bad, you ran out of money. Better luck next time.\n");
    else

    return 0;
}

/*
* Function Name: sumStart
*
* Input parameters:void
*
* Description: This function uses a loop to have the user
*              input a value that represents their starting sum.
*              The purpose of the loop is so that the program will
*              stop and check if the input value was valid, and repeat
*              the question if not.
*
* Return Values: Int value representing sum
 */
int sumStart(void)
{
    //variable declaration
    int sum;
    int checkSum = 0;

    //Check loop
    while(checkSum == 0)
    {
        printf("\nHow many dollars do you want to start with (0 to quit)? ");
        scanf("%d", &sum);

        if(sum < 0)
            printf("ERROR: Enter at least one dollar or zero if you don't want to play.");
        else if (sum == 0)
            {
            printf("The slot machine stares at you, silently judging as you walk away.");
            exit(222);
            }
        else
            checkSum++;
    }

    return sum;
}

/*
* Function Name: bidMaker
*
* Input Parameters: integer pointer sumT
*
* Description: This function uses a loop to have the user enter
*              an integer input value that represents their bid amount.
*              The purpose of the loop is to check for errors or exit.
*              If there is an error the program will display invalid input
*              then repeat the question until the user inputs a valid input.
*              The errors it checks for is for negative numbers or if the bid
*              amount is higher than the current sum
*
* Return Values: integer for bid amount
*/
int bidMaker(int* sumT)
{
    //variable declaration
    int checkBid = 0;
    int betAmount;

    //check loop
    while (checkBid == 0)
        {
        printf("How much would you like to bet (enter 0 to cash out)? ", *sumT);
        scanf("%d", &betAmount);

        if (betAmount < 0)
            printf("\nThat is an incorrect bid");
        else if (betAmount > *sumT)
            {
            printf("\nYour bid is higher than what you have.\n");
            }
        else if (betAmount == 0)
            {
            printf("Cash out: $%d.", *sumT);
            printf(" Hope you enjoy monopoly money.");
            printf("\nExiting");
            exit(434);
            }
        //else if
        else
            {
            *sumT = *sumT - betAmount;
            checkBid++;
            }
    }
    return betAmount;
}

/*
* Function Name: slot
*
* Input Parameters: Three integer pointer values
*
* Description: This function generates three random numbers between 1 and 8
*              and assigns them to three pointer values.
*
* Return values: void
*/
void slot(int* ax, int* bx, int* cx)
{
    *ax = rand()%8+1;
    *bx = rand()%8+1;
    *cx = rand()%8+1;
    return ;
}

/*
* Function name: slotPrint
*
* Input Parameters: six int type values
*
* Description: This function takes the values that represent the three
*              slot machine values, the players current sum, the bet winnings,
*              and the type of win. The function prints these values to simulate
*              a slot machine.
* Return values: void
*/
void slotPrint(int sum, int betW, int s1, int s2, int s3, int winPrint)
{
    printf("       _____");
    printf("\n _____/ 888 \\_____");
    printf("\n/  Crazy Eights   \\ ");
    printf("\n|=================|  __");
    printf("\n| 888     80x Bet | (  )");
    printf("\n| Match 3 25x Bet |  ||");
    printf("\n| Match 2  2x Bet |  ||");
    printf("\n| Eight    1x Bet |  ||");
    printf("\n|-----+-----+-----|  ||");
    printf("\n| [%d] | [%d] | [%d] |  ||", s1, s2, s3);
    printf("\n|-----+-----+-----|  ||");
    if(winPrint < 5)
        printf("\n|  WIN! WIN! WIN! |__||");
    else
        printf("\n|      Sorry!     |__||");
    switch(winPrint)
    {
        case 1:
            printf("\n|     Jackpot!!   |---'");
            break;
        case 2:
            printf("\n|   Match Three!  |---'");
            break;
        case 3:
            printf("\n|    Match Two!   |---'");
            break;
        case 4:
            printf("\n|   Crazy Eight!  |---'");
            break;
        case 5:
            printf("\n|    Try Again!   |---'");
            break;
        default:
            //should not happen
            break;
    }//switch 1

    printf("\n|     _______     |");
    printf("\n|____/ o  o  \\____|");
    printf("\n\\     o  oo  o    /");
    printf("\n \\_______________/");
    printf("\n  U             U");

    switch(winPrint)
    {
    case 1:
        printf("\n\nJACKPOT! Make it rain! You win $%d", betW);
        break;
    case 2:
        printf("\n\nMatch Three! You win $%d", betW);
        break;
    case 3:
        printf("\n\nMatch Two! You win $%d", betW);
        break;
    case 4:
        printf("\n\nCrazy 8! You win $%d", betW);
        break;
    case 5:
        printf("\n\nSorry, no winning combination.");
    }//switch 2

    printf("\n\nYour current total is $%d\n", sum);

    return ;
}

/*
* Function Name: slotWinning
*
* Input Parameters: Three int variables representing the slot machine numbers
*                   An int variable representing the bet amount, and a pointer
*                   to a variable representing the type of win.
*
* Description: This program determines if the three random numbers produced a win or
*              a loss, as well as the type of win. Three 8 = Jackpot, Three of a kind = match 3
*              2 of a kind = match 2, and at least one 8 = crazy eight. The function then determines
*              the amount of winnings based on the type of win. Using the use of the pointer value to
*              assign a variable with an int value representing the type of win.
*
* Return value: Int variable that represents the amount of bet winnings
*/
int slotWinning(int s1, int s2, int s3, int betA, int* winSum)
{
    int winAmount;

    if ((s1 == 8) && (s2 == 8) && (s3 == 8))
       {
        *winSum = 1;
        winAmount = betA * 80;
       } //Jackpot
    else if ((s1 == s2) && (s1 == s3))
        {
         *winSum = 2;
         winAmount = betA * 25;
        } //Match 3
    else if ((s1 == s2) || (s1 == s3) || (s2 == s3))
        {
         *winSum = 3;
         winAmount = betA *2;
        } // Match 2
    else if ((s1 == 8) || (s2 == 8) || (s3 == 8))
        {
         *winSum = 4;
         winAmount = betA * 1;
        }//Crazy Eight
    else
        {
         *winSum = 5;
         winAmount = betA * 0;
        }//Bust
    return winAmount;

}
