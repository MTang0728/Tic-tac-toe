
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int playturn = 1;       //number of turns
    int turn = 2;           //divider, use to decide player
    int player = 1;         //1 for player A:X, 0 for player B:O
    int choice = 0;         //player choice
    bool win = false;
    
    int row = 0;
    int col = 0;
    
    
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };
    
    while (playturn < 10 && win == false)
    {
        //print the board
        printf("\n");
        printf("%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf("---+----+---\n");
        printf("%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf("---+----+---\n");
        printf("%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);  
        //check if there is a winner
        if ((board[0][0]==board[1][1] && board[0][0]==board[2][2]) || (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
        {
            win = true;
            printf("winner is %c", player = 1? 'A':'B');
            break;
        }
        else
        {
            for(int line = 0; line <=2 ; ++line)
            {
                if ((board[line][0] == board[line][1] && board[line][0] == board[line][2]) || (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                {
                    win = true;
                    printf("winner is %c", player = 1? 'A':'B');
                    break;
                }
            }
        }
        //determine player, 1 for player A, 0 for player B
        player = playturn%turn;
        //get user input
        printf("\nplayer %c, please enter your choice: ", player == 1? 'A':'B');
        scanf("%d", &choice);
        //determine row and column;
        row = (choice - 1)/3;
        col = (choice - 1)%3;
        //change the board
        board[row][col] = (player == 1)? 'X':'O';

        
        //increment the game
        playturn++;
    };
    return 0;
}
