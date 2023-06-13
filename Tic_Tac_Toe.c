#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

//declaring global variables
char board[3][3];
const char PLAYER = 'X';
const char CCOMPUTER = 'O';

void resetboard();//makes the 2d char array
void printboard();//prints 2d char array
int checkfreespace();//if 0 game over
void playermove();
void computermove();
char checkwinner();
void printwinner(char);
void game();
void playagain();

void main(){
    char winner = ' ';
    char response;
    
    game();
    
    
    
}
void resetboard(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j]= ' ';
        }
    }
    

}
void printboard(){
    printf(" %c | %c | %c  ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c  ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c  ", board[2][0], board[2][1], board[2][2]);
    printf("\n");

}
int checkfreespace(){
    int freespaces = 9;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(board[i][j] != ' '){
                freespaces--;
            }
        }
    }
    return freespaces;

}
void playermove(){
    int x;
    int y;
    do
    {
        printf("Enter row (1-3): ");
        scanf("%d", &x);
        printf("Enter column (1-3): ");
        scanf("%d", &y);
        y--;x--;
        if (board[x][y] == 0){
            printf("Invalid move!\n");
        }
        else{
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
    

}
void computermove(){
    // creates a seed based on current time
    srand(time(0));
    int x;
    int y;

    if(checkfreespace() > 0){
        do
        {
            x = rand() %3;
            y = rand()% 3;
        } while (board[x][y] != ' ');
        board[x][y] = CCOMPUTER;
        
    }
    else{
        printwinner(' ');
    }
    

}
char checkwinner(){
    //check rows
    for(int i=0; i<3; i++){
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2]){
            return board[i][0];
        }
    }
    //check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j]==board[1][j] && board[0][j]==board[2][j])
        {
            return board[0][j];
        }
        
    }
    //check diagonals
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2]){
        return board[0][0];
    }
    else if (board[0][2]==board[1][1] && board[0][2]==board[2][0])
    {
        return board[0][2];
    }
    
    return ' ';
    

}
void printwinner(char winner){
    if (winner == PLAYER){
        printf("YOU WIN! ! !");
    }
    else if (winner == CCOMPUTER)
    {
        printf("YOU LOSE! ! !");
    }
    else{
        printf("ITS A DRAW! ! !");
    }
        

}


void game(){

    char winner = ' ';
        resetboard();

        while( winner == ' ' && checkfreespace() != 0){
            printboard();

            playermove();
            winner = checkwinner();
            if (winner != ' ' && checkfreespace() == 0){
                break;
            }

            computermove();
            winner = checkwinner();
            if (winner != ' ' && checkfreespace() == 0){
                break;
            }
        }
        printboard();
        printwinner(winner);
        playagain();


}

void playagain(){
    char response;
    printf("\nWould you like to play again? (Y/N): ");
        scanf("%c");
        scanf("%c", &response);
        if(response=='Y'||response =='y'){
            game();

}
else{
    printf("Thank you for playing!\n");
}
}