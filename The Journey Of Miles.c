//The Journey Of Miles

/*
Prepared By:
1.Md. Rafin Jawad Hafiz (200041223)
2.Sahab Al Chowdhury (200041255)
3.Rezwan Islam Salvi (200041235)

Section: CSE(2A), IUT
*/


#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>


#define row 20
#define coloumn 60


//variable and array initialization for tictactoe:
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int player=1, v=0, pos[100], num=0;
char sq[10] = {'o','1','2','3','4','5','6','7','8','9'};
char show[100];


//variable and array initialization for snake:
int n=14,p=9,i=3,j,a,b,r=8,t=13,x=17, Field_of_play[row][coloumn],
    snake_x,snake_y, Gy,Head,Tail,Game=0,Food=0,var,direction='d',score=0;


//function prototypes for tictactoe:
int tictactoe();
void board();
void replayboard();
int checkwin();
void input(char c);
void advantage();
void timer();


//function prototypes for story sequence:
void story();
void next_story();
void last_story();
void snake_guideline();
void tic_tac_toe_guideline();


//function prototypes for snake:
void snakegame();
void print();
void snake_body_initialize();
void obstacles();
void Reset_Screen_Position();
void Random_Food_Generation();
void movement_of_snake();
void Tail_removing();
void obstacles2();



//main function of the entire project:
int main()
{
    int skip=0,guideline;
    int pl;
    Sleep(2000);
    printf("~~THE JOURNEY OF MILES~~\n\n");
    Sleep(2000);
    printf("Do you want to skip the initial story?\n");
    printf("1 = YES  2 = NO\n");
    scanf("%d",&skip);
    if(skip==2)
    {
         story();
         //Sleep(2000);
    }
    if(skip==1)
    {
        printf("\nDo you want to read the guideline of tic-tac-toe?\n");
        printf("1 = YES   2 = NO\n");
        scanf("%d",&guideline);
        if(guideline==1)
        {
            tic_tac_toe_guideline();
            system("cls");
            pl=tictactoe();
            if (pl==1)
            {
                Sleep(1000);
                printf("\nMiles gets the money from Joe.\n");
                Sleep(3000);
            }
            else if(pl==2)
            {
                Sleep(1000);
                printf("\nGameover!! Miles cannot go to the adventure trip.\n");
                Sleep(3000);
                return 0;
            }
        }
        else
        {
             pl=tictactoe();
             if (pl==1)
             {
                Sleep(1000);
                printf("\nMiles gets the money from Joe.\n");
                Sleep(3000);
             }
              else if(pl==2)
             {
                Sleep(1000);
                printf("\nGameover!! Miles can not go to the adventure trip.\n");
                Sleep(3000);
                return 0;
             }
        }

    }

    system("cls");

    printf("\nDo you want to skip the next story?\n");
    printf("1 = YES   2 = NO\n");
    scanf("%d",&skip);
    guideline=0;

    if(skip==2)
    {
        next_story();
    }
    if(skip==1)
    {
        printf("Do you want to read the guideline of snake game?\n");
        printf("1 = YES    2 = NO\n");
        scanf("%d",&guideline);
        if(guideline==1)
        {
            snake_guideline();
            snakegame();
        }
        else
        {
            snakegame();
        }
    }

    return 0;

}




//GAME-1(TIC-TAC-TOE)


//initial story
void story()
{
    int i=1;
    int guide=0;

    char ch;
    scanf("%c",&ch);

    while(ch=='\n' && i!=5)
    {
        if(i==1)
        {
            printf("\nThe journey begins with Miles willing to go an adventure with her friends.\n");
        }
        if(i==2)
        {
            printf("She asks her friend, Joe, for some money as she does not have enough herself.\n");
        }
        if(i==3)
        {
            printf("Joe asks her to beat him in a game in order to get the money.\n");
        }
        if(i==4)
        {

            system("cls");
            printf("HERE COMES THE GAME, ~~~TIC TAC TOE~~~\n");
            Sleep(2000);


        }
        Sleep(1000);
        i++;
        printf("[Press Enter to continue]\n");
        scanf("%c",&ch);
    }
     Sleep(2000);
     printf("Do you want to read the tic-tac-toe guideline?\n");
     printf("1=YES   2=NO\n");
     scanf("%d",&guide);
     if(guide==1)
     {
        tic_tac_toe_guideline();
        tictactoe();
     }
     else
     {
         tictactoe();
     }


}


//main function for tictactoe
//This function also contains the codes for replay feature from line-270.
int tictactoe()
{

	int i,v=0, choice, opt;
	char mark;
	Sleep(2000);

	do
	{
		board();
		Sleep(1000);
		player=(player%2)?1:2;
		printf("Player %d: ", player);
        timer();
		i=checkwin();
		player++;
	} while(i==-1);

    board();
	if(i==1)
		{
            Beep(600,500);
            Beep(700,500);
            Beep(800,500);
            Sleep(2000);
            printf("\aPlayer %d wins!!!",--player);
            if (player==2)
            {
                printf("\nAlas!! Gameover!!");
                exit(0);
            }
            Sleep(3000);
        }
	else
		{
            Beep(750,500);
            Beep(850,500);
            Beep(950,500);
            Sleep(2000);
            printf("\aGame is a draw!");
            printf("\n\nThe game is restarting....");
            Sleep(3000);
            tictactoe();
        }

    system("cls");
    system("color 0E");

    printf("Do you want to watch the replay of the game?");
    printf("\n1 = YES    2 = NO\n");
    scanf("%d", &opt);
    if (opt==1)
    {
        printf("\n\nReplay of the game: \n");
        Sleep(3000);
        replayboard();
        Sleep(3000);
        {
            for (int j=0; j<=num; j++)
            {
                sq[pos[j]]=show[j]; //replay - 3 arrays are used.
                replayboard();
                if (j==num)
                {
                    break;
                }
                Sleep(2000);
            }

            if(i==1)
            {
                printf("\aPlayer %d wins!!!",player);
                Sleep(2000);
                return player;
            }
            else
            {
                printf("\aGame is a draw!");
                Sleep(2000);
            }
        }
    }
    else if (opt!=1)
    {
        return 1;
    }


}


//board to be displayed during game play of tictactoe
void board()
{
    system("cls");
    printf("\n\n\t\tTic Tac Toe\n\n");

    printf("Player 1 - Miles (X)  -  Player 2 - Joe (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}


//board to be displayed during replay of tictactoe
void replayboard()
{
    system("cls");
    printf("\n\n\t\tTic Tac Toe\n\n");

    printf("Player 1 - Miles (X)  -  Player 2 - Joe (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", sq[1], sq[2], sq[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", sq[4], sq[5], sq[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", sq[7], sq[8], sq[9]);

    printf("     |     |     \n\n");
}


//function to check result of tictactoe
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}


//function to take normal input(not advantage move)
void input(char c)
{
        char choice=c, mark;
        mark=(player == 1) ? 'X' : 'O';
        pos[num]=choice-'0';
        show[num]=mark;
        num++;

		if (choice == '1' && square[1] == '1')
			square[1] = mark;
		else if (choice == '2' && square[2] == '2')
			square[2] = mark;
		else if (choice == '3' && square[3] == '3')
			square[3] = mark;
		else if (choice == '4' && square[4] == '4')
			square[4] = mark;
		else if (choice == '5' && square[5] == '5')
			square[5] = mark;
		else if (choice == '6' && square[6] == '6')
			square[6] = mark;
		else if (choice == '7' && square[7] == '7')
			square[7] = mark;
		else if (choice == '8' && square[8] == '8')
			square[8] = mark;
		else if (choice == '9' && square[9] == '9')
			square[9] = mark;
}


//function to take input of advantage move
void advantage()
{
    char cho, mark;
    mark=(player == 1) ? 'O' : 'X';
    int y;

    if (player==1)
    {
        y=2;
    }
    else if (player==2)
    {
        y=1;
    }

    system("color 0B");
    printf("\n\nAdvantage move (with no timer) for player %d: ", y);

    scanf(" %c", &cho);
    pos[num]=cho-'0';
    show[num]=mark;
    num++;
    Beep(500,500);

        if (cho == '1' && square[1] != mark)
			square[1] = mark;
		else if (cho == '2' && square[2] != mark )
			square[2] = mark;
		else if (cho == '3' && square[3] != mark)
			square[3] = mark;
		else if (cho == '4' && square[4] != mark)
			square[4] = mark;
		else if (cho == '5' && square[5] != mark)
			square[5] = mark;
		else if (cho == '6' && square[6] != mark)
			square[6] = mark;
		else if (cho == '7' && square[7] != mark)
			square[7] = mark;
		else if (cho == '8' && square[8] != mark)
			square[8] = mark;
		else if (cho == '9' && square[9] != mark)
			square[9] = mark;
        else
            printf("Player %d could not utilize the advantage move, such a fool!!! ", y);
            Sleep(3000);
}


//timer of 5 seconds in tictactoe (not included in advantage move)
void timer()
{
    printf("\n\nCountdown begins, enter your move within 5 seconds!!!\n");

    int s=5,x; char ch;

    while(1)
    {
        Sleep(1000);

            if(s>2) //green color
            {
                system("color 0A");
                printf("Time Remaining: %ds\n",s);

                if ( kbhit() )
                {
                    ch = getch();
                    x=ch-'0';
                    Beep(s*500,500);
                        if (ch!='1' && ch!='2' && ch!='3' && ch!='4' && ch!='5'
                            && ch!='6' && ch!='7' && ch!='8'&& ch!='9')
                        {
                            printf("Invalid move. ");
                            Sleep(1000);
                            advantage();
                            player--;
                            return;
                        }
                        else if ((square[x]=='X')||(square[x]=='O'))
                        {
                            printf("Invalid move. ");
                            Sleep(1000);
                            advantage();
                            player--;
                            return;
                        }
                        else
                        {
                            input(ch);
                            return;
                        }
                }
            }


            if(s==2 || s==1)  //red color to indicate time is getting over
            {
                system("color 0C");
                printf("Time Remaining: %ds\n",s);

                if ( kbhit() )
                {
                    ch = getch();
                    x=ch-'0';
                    Beep(500,500);
                        if (ch!='1' && ch!='2' && ch!='3' && ch!='4' && ch!='5'
                            && ch!='6' && ch!='7' && ch!='8'&& ch!='9')
                        {
                            printf("Invalid move. ");
                            Sleep(1000);
                            advantage();
                            player--;
                            return;
                        }
                        else if ((square[x]=='X')||(square[x]=='O'))
                        {
                            printf("Invalid move. ");
                            Sleep(1000);
                            advantage();
                            player--;
                            return;
                        }
                        else
                        {
                            input(ch);
                            return;
                        }

                }
            }


            if(s==0)
            {
                system("color 0C");
                printf("Alas, your time is up!!!");
                Beep(1000,1000);
                Sleep(1000);
                advantage();
                player--;
                return;
                //break;
            }

            s--;
            if (s<0)
                break;

        }
}



//GAME-2(SNAKE)


//story to be followed after end of tictactoe game
void next_story()
{
    int i=1;
    int guide=0;

    char ch;
    scanf("%c",&ch);

    while(ch=='\n' && i!=5)
    {
        if(i==1)
        {
            printf("\nShe went to the trip and was having a really good time.\n");
        }
        if(i==2)
        {
            printf("\nBut soon, a monster named Putin from another galaxy caught Miles\n");
        }
        if(i==3)
        {
            printf("\nPutin tells her that he will let her go only if she can win in a snake game.\n");
        }
        if(i==4)
        {
            system("cls");
            printf("HERE COMES THE SNAKE GAME.\n");
            printf("Do you want to read the guideline?\n");
            printf("1 = YES      2 = NO\n");
            scanf("%d",&guide);
            if(guide==1)
            {
                snake_guideline();
                snakegame();
            }
            else
            {
                snakegame();
            }
            break;

        }
        Sleep(1000);
        i++;
        printf("\n[Press Enter to continue]\n");
        scanf("%c",&ch);
    }

}


//main function for snakegame
void snakegame()
{
    system("cls");
    Sleep(2000);
    printf("~~~~SNAKE GAME~~~~");
    Sleep(2000);
    system("cls");
    snake_body_initialize();
    printf("~~~LEVEL-1~~~");
    Sleep(2000);
    system("cls");

  while(Game==0)
  {
     system("color 0A");
     print();
     Reset_Screen_Position();
     Random_Food_Generation();
     movement_of_snake();
     Tail_removing();
     Sleep(99);
     if(score==50)
    {
        Game++;
        score=0;
        break;
    }

  }

  system("cls");
  printf("~~~LEVEL-2~~~");
  Sleep(2000);
  system("cls");
  while(Game==1)
  {
     system("color 0A");
     obstacles();
     print();
     Reset_Screen_Position();
     Random_Food_Generation();
     movement_of_snake();
     Tail_removing();
     Sleep(99);
     if(score==50)
    {
        Game++;
        score=0;
        break;
    }
  }

  system("cls");
  printf("~~~LEVEL-3~~~");
  Sleep(2000);
  system("cls");
  while(Game==2)
  {
     system("color 0A");
     obstacles2();
     print();
     Reset_Screen_Position();
     Random_Food_Generation();
     movement_of_snake();
     Tail_removing();
     Sleep(99);
     if(score==100)
    {
        system("cls");
        system("cls");
        Sleep(100);
        last_story();
        break;
    }
  }

}


//function to fix first position of snake(in centre) at the very beginning of game
void snake_body_initialize()
{
    for(i=0;i<row;i++)
    {
        for(j=0;j<coloumn;j++)
        {
            Field_of_play[i][j]=0;
        }
    }
    snake_x=row/2;
    snake_y=coloumn/2;
    Gy=snake_y;
    Head=5;
    Tail=1;
    for(i=0;i<Head;i++)
    {
        Gy++;
        Field_of_play[snake_x][Gy-Head]=i+1;
    }

}


//function to print grid of snake game
void print()
{
    for(i=0;i<=coloumn+1;i++)
    {
        if(i==0)
        {
            printf("%c",201);
        }
        else if(i==coloumn+1)
        {
            printf("%c",187);
        }
        else
        {
            printf("%c",205);
        }
    }
    printf("Score: %d",score);
    printf("\n");
    for(i=0;i<row;i++)
    {
        printf("%c",186);
        for(j=0;j<coloumn;j++)
        {
            if(Field_of_play[i][j]==0)
            {
                printf(" ");
            }
            if(Field_of_play[i][j]>0 && Field_of_play[i][j]!=Head)
            {
                printf("%c",176);
            }
            if(Field_of_play[i][j]==Head)
            {
                printf("%c",153);
            }
            if(Field_of_play[i][j]==-1)
            {
                printf("X");
            }
            if(Field_of_play[i][j]==-4000 )
            {
                printf("%c",220);
            }
            if(j==coloumn-1)
            {
                printf("%c",186);
                printf("\n");
            }
        }
    }
    for(i=0;i<=coloumn+1;i++)
    {
        if(i==0)
        {
            printf("%c",200);
        }
        else if(i==coloumn+1)
        {
            printf("%c",188);
        }
        else
        {
            printf("%c",205);
        }
    }
}


//function to reset screen position constantly in snake game
void Reset_Screen_Position()
{
    HANDLE hOut;
    COORD Position;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X=0;
    Position.Y=0;
    SetConsoleCursorPosition(hOut,Position);
}


//function to generate the food randomly(rows are fixed to avoid overlapping with obstacles)
void Random_Food_Generation()
{
    srand(time(0));
    while (1)
    {
        a=rand()%19;
        if (a==1 || a==3 || a==5 || a==8 || a==10 || a==13 || a==15 || a==17)
        {
            continue;
        }
        else
        {
            break;
        }

    }

    b=rand()%59;
    if(Food==0 && Field_of_play[a][b]==0 && Field_of_play[a][b]!=-4000)
    {
        Field_of_play[a][b]=-1;
        Food=1;
    }
}


//function to take input from user during snake game
int get_character()
{
    if(_kbhit())
    {
        return _getch();
    }
    else
        return -1;
}


//function to check whether game is over in snake
void gameover()
{

    Sleep(1000);
    system("cls");
    printf("\nAlas! Game over.\n");
}


//function for snake movement using W,A,S,D
void movement_of_snake()
{
    var=get_character();
    var=tolower(var);
    if((var=='d' || var=='s' || var=='a' || var=='w') && (abs(direction-var)>5))
    {
        direction=var;
    }
    if(direction=='d')
    {
        snake_y++;
        if(snake_y==coloumn)
        {
            gameover();
            exit(0);
        }
        if (Field_of_play[snake_x][snake_y]==-1)
        {
            Food=0;
            score=score+10;
            Tail=Tail-2; //to make the tail longer after consuming food
        }
         if(Field_of_play[snake_x][snake_y]!=0 && Field_of_play[snake_x][snake_y]!=-1)
        {
            gameover();
            exit(0);

        }
        Head++;
        Field_of_play[snake_x][snake_y]=Head;
    }
    if(direction=='a')
    {
        snake_y--;
         if (Field_of_play[snake_x][snake_y]==-1)
        {
            Food=0;
            score=score+10;
            Tail=Tail-2; //to make the tail longer after consuming food
        }
        if(Field_of_play[snake_x][snake_y]!=0 && Field_of_play[snake_x][snake_y]!=-1)
        {
            gameover();
            exit(0);
        }
        if(snake_y<0)
        {
            gameover();
            exit(0);
        }
        Head++;
        Field_of_play[snake_x][snake_y]=Head;
    }
     if(direction=='w')
    {
        snake_x--;
         if (Field_of_play[snake_x][snake_y]==-1)
        {
            Food=0;
            score=score+10;
            Tail=Tail-2;  //to make the tail longer after consuming food
        }
        if(Field_of_play[snake_x][snake_y]!=0 && Field_of_play[snake_x][snake_y]!=-1)
        {
            gameover();
            exit(0);
        }
        if(snake_x==-1)
        {
            gameover();
            exit(0);
        }
        Head++;
        Field_of_play[snake_x][snake_y]=Head;
    }
     if(direction=='s')
    {
        snake_x++;
        if (Field_of_play[snake_x][snake_y]==-1)
        {
            Food=0;
            score=score+10;
            Tail=Tail-2;  //to make the tail longer after consuming food
        }
        if(Field_of_play[snake_x][snake_y]!=0 && Field_of_play[snake_x][snake_y]!=-1)
        {
            gameover();
            exit(0);
        }
        if(snake_x==row)
        {
            gameover();
            exit(0);
        }
        Head++;
        Field_of_play[snake_x][snake_y]=Head;
    }

}


//function to shorten tail after movement from one column/row to next as head is moving one place ahead
void Tail_removing()
{
    for(i=0;i<row;i++)
    {
        for(j=0;j<coloumn;j++)
        {
            if(Field_of_play[i][j]==Tail)
            {
                Field_of_play[i][j]=0;
            }
        }
    }
    //the loop is for normal movement (when the snake is not gobbling up the food)
    Tail++;
}


//function to generate obstacles in level-2 of snake(rows are fixed to avoid overlapping with food)
void obstacles()
{
    i=3,r=8,t=13,x=17;
    p++;
    n++;

    for(j=p;j<n;j++)
    {
        if (Field_of_play[i][j]!=-1) Field_of_play[i][j]=-4000;
        if (Field_of_play[r][j]!=-1) Field_of_play[r][j]=-4000;
        if (Field_of_play[t][j]!=-1) Field_of_play[t][j]=-4000;
        if (Field_of_play[x][j]!=-1) Field_of_play[x][j]=-4000;

        Field_of_play[i][p]=0;
        Field_of_play[r][p]=0;
        Field_of_play[t][p]=0;
        Field_of_play[x][p]=0;

        if(n==61)
      {

          for(j=0;j<60;j++)
          {
              Field_of_play[i][j]=0;
              Field_of_play[r][j]=0;
              Field_of_play[t][j]=0;
              Field_of_play[x][j]=0;
          }

        n=4;p=-1;
        }

    }

}


//function to generate the obstacles randomly in level-3 of snake(rows are fixed to avoid overlapping with food)
void obstacles2()
{
    srand(time(0));
    while(1)
    {
      i=rand()%19;
      if (i==1 || i==3 || i==5 || i==8 || i==10 || i==13 || i==15 ||i==17)
      {
          break;
      }
      else
      {
          continue;
      }
    }

    p++;
    n++;
    for(j=p;j<n;j++)
    {
        Field_of_play[i][j]=-4000;
        Field_of_play[i][p]=0;
        if(n==61){

          for(j=0;j<60;j++)
          {
              Field_of_play[i][j]=0;
          }

        n=4;p=-1;
        }

    }
}


//function for the last part of story after user wins snake game.
void last_story()
{
    printf("Congratulations Miles!!! You won!!! You have done it!!!\n");
    Sleep(1000);
    printf("\nPutin then rewards her by taking her to an adventure in his galaxy");
    Sleep(1000);
    printf(" \nwhich becomes the most adventurous journey of her life.\n");
    Sleep(1000);
    printf("\nThat is all about the journey of Miles.");
}


//guideline on how to play the tictactoe game
void tic_tac_toe_guideline()
{
    printf("\n1.There is a grid from 1 to 9. The user can put in any of the positions from 1 to 9 by pressing that digit on the keyboard.\n");
    Sleep(2000);
    printf("\n2.There will be a timer of 5 seconds for each player.\n");
    Sleep(2000);
    printf("\n3.If a user fails to give a move within 5 seconds, opponent will get an advantage move\n");
    Sleep(2000);
    printf("\n4.Advantage Move:\n");
    Sleep(1000);
    printf("\n5.There is no timer in the advantage move. And the opponent will get the advantage of replacing any of the previous moves of the other player except for his own previous moves\n");
    Sleep(5000);
    printf("\n6.If along any row or coloumn, or diagonally, the same symbol appears(X or O), then the user holding that particular symbol will win.\n");
    Sleep(3000);
    system("cls");
}


//guideline on how to play the snake game
void snake_guideline()
{
    printf("\n1.A snake will start to move and there will be food in different positions which needs to be eaten by the snake to score 10 points.\n");
    Sleep(3000);
    printf("\n2.Snake will be moved by the keys W,A,S,D.\n");
    Sleep(2000);
    printf("\n3.W-UP, A-LEFT, S-DOWN, D-RIGHT\n");
    Sleep(2000);
    printf("\n4.But hang on!!!\n");
    Sleep(1000);
    printf("\n5.The game is not that easy. There will be three levels of difficulty.\n");
    Sleep(2000);
    printf("\n6.The border line will be the only obstacle in the first level.\n");
    Sleep(2000);
    printf("\n7.If the score becomes 50,then user will level up to second level.\n");
    Sleep(2000);
    printf("\n8.In level 2,there will be 4 obstacles along with the border. And the obstacles will move from LEFT TO RIGHT.\n");
    Sleep(3000);
    printf("\n9.If the score reaches 50,then user will level up to level three.\n");
    Sleep(2000);
    printf("\n10.In level 3,obstacles will be randomly generated. And obstacles will move from LEFT to RIGHT.\n");
    Sleep(3000);
    printf("\n11.If the score becomes 100 in level 3, the user will win the game.\n");
    Sleep(2000);
}
