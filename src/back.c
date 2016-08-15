#include "../header/back.h"
#include <ncurses.h>
#include <string.h>
#define DELAY2 50000


//---------------------------------
//             Monsters
//---------------------------------

void moveMonster(Monster *mon)
{
    mon[0].y_position = mon[0].y_position-1;
    mon[0].x_position = mon[0].x_position;
}

void monsterRespawn(Monster *mon, int numMonsters)
{
    for(int i = 0; i < numMonsters; i++)
    {
        if (mon[i].alive == 0)
        {
            mon[i].x_position = mon[i].start_positionX;
            mon[i].y_position = mon[i].start_positionY;
            mon[i].sprite = 'M';
            mon[i].alive = 1;
        }
    }
}


//---------------------------------
//             fruit
//----------------------------------
//fruit characters
char fruit[] = {'.', '-', 'o', 'O' } ;

//for customizing fruit types
void setFruit(char input, int index)
{
    fruit[index] = input;
}

void initFruit(Fruit arr[][26])
{
    int ii, jj;

    for ( ii = 0; ii <20; ii++ )
    {
        for (jj = 0; jj<26; jj++)
        {
            arr[ii][jj] = 0;
      }
    }
}

//assign pt value to fruit being eaten and add to score
void eatFruit(PacMan *p1, Fruit f1[][26])
{
    if(f1[p1->y_position][p1->x_position] > 0)
    {
        if(f1[p1->y_position][p1->x_position] == fruit[0])
        {
            p1->score += 1;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit[1])
        {
            p1->score += 10;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit[2])
        {
            p1->score += 100;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit[3])
        {
            p1->score += 100;
            f1[p1->y_position][p1->x_position] = 0;
        }

    }
}

//----------------------------
//          Pacman
//----------------------------

//--------------Globals-------------------
const int MAX_Y = 17;
const int MAX_X = 26;
const int MIN_Y = 0;
const int MIN_X = 0;


//player 1 controls
int player1_up = 'w';
int player1_down = 's';
int player1_left = 'a';
int player1_right = 'd';

//player 2 controls
char player2_up = 'o';
char player2_down = 'l';
char player2_left = 'k';
char player2_right = ';';


void pacmanInitialize(PacMan *a)
{
    a->lives = 1;
    a->x_position = 0;
    a->y_position = 0;
    a->x_direction = 1;
    a->y_direction = 0;
    a->y_start = 0;
    a->x_start = 0;
    a->sprite = '<';
    a->score = 0;
    a->quit = 1;
}

void movePacman(PacMan *player, char wall)
{
  int next_x, next_y;

  next_x = player->x_position + player->x_direction;
  next_y = player->y_position + player->y_direction;

  if (next_x > MAX_X)
  player->x_position = MIN_X;
  else if (next_x < MIN_X)
  player->x_position = MAX_X;
  else if (next_x == wall)
  player->x_direction = 0;

  player->x_position += player->x_direction;


  if (next_y > MAX_Y)
  player->y_position = MIN_Y;
  else if (next_y < MIN_Y)
  player->y_position = MAX_Y;
  else if (next_y == wall)
  player->y_position = 0;

  player->y_position += player->y_direction;
}

void getPacmanDirection1(int *x_dir, int *y_dir, int input, char *sprite)
{
  if (input == player1_left)
  {
    *x_dir = -1;
    *y_dir = 0;
    *sprite = '>';
  }

  else if (input == player1_right)
  {
    *x_dir = 1;
    *y_dir = 0;
    *sprite = '<';
  }

  else if (input == player1_down)
  {
    *x_dir = 0;
    *y_dir = 1;
    *sprite = '^';
  }

  else if (input == player1_up)
  {
    *x_dir = 0;
    *y_dir = -1;
    *sprite = 'V';
  }

}

void getPacmanDirection2(int *x_dir, int *y_dir, int keyInput, char *sprite)
{
  if (keyInput == player2_left)
  {
    *x_dir = -1;
    *y_dir = 0;
    *sprite = '>';
  }

  else if (keyInput == player2_right)
  {
    *x_dir = 1;
    *y_dir = 0;
    *sprite = '<';
  }

  else if (keyInput == player2_down)
  {
    *x_dir = 0;
    *y_dir = 1;
    *sprite = '^';
  }

  else if (keyInput == player2_up)
  {
    *x_dir = 0;
    *y_dir = -1;
    *sprite = 'V';
  }

}

//----------------------------
//       GameBoard
//----------------------------


void gameBoardInitialize(GameBoard *a)
{
    //used to zero out a game board instance
     a->wall = '3';
     a->fruit[0] = '-';
     a->fruit[1] = '*';
     a->fruit[2] = '&';
     a->fruit[3] = '$';
     a->numFruit1 = 0; //number of first fruit on level
     a->numFruit2 = 0; //number of second
     a->numFruit3 = 0; //number of thrid
     a->numFruit4 = 0; //number of fourth
     a->numPacman = 0;    //number of pacman
     a->numMonster = 0;    //number of monsters
     a->pause_state = 0;
     a->run_state = 1;

}

int gameBoardLoad(GameBoard *gameboard, PacMan *pacman, Fruit fruitArr[][26], char fileName[])
{   FILE* fp = NULL;
    char charInput;
    char str[27];
    int i,j;
    int numRead;
    int currentPos;

    fp = fopen(fileName, "r");
    if (!fp)
        return -1;

    //get wall
    fgets(str, 27, fp);

    if(fp)
    {
        gameboard->wall = str[0];
    }

    //get fruit
    fgets(str, 27, fp);
    if(fp)
    {
        numRead = numBytesRead(fp);
        for(i = 0; i < numRead; i++)
        {
            if (str[i] > 32 && str[i] < 127 )
            {
                gameboard->fruit[i] = str[i];
                setFruit(str[i], i);
            }
        }
    }

    for ( i = 0; i < 18; i++ )
    {
        fgets(str, 100, fp);
        for (j = 0; j<26; j++)
	       {
               charInput = str[j];

               if(charInput == gameboard->wall || charInput == ' ')
               gameboard->map[i][j] = charInput;

               else if(charInput == gameboard->fruit[0] ||
                   charInput == gameboard->fruit[1] ||
                   charInput == gameboard->fruit[2] ||
                   charInput == gameboard->fruit[3])
               {
                   fruitArr[i][j] = charInput;

                   gameboard->map[i][j] = ' ';

                   if(charInput == gameboard->fruit[0])
                   gameboard->numFruit1++;

                   else if(charInput == gameboard->fruit[1])
                   gameboard->numFruit2++;

                   else if(charInput == gameboard->fruit[2])
                   gameboard->numFruit3++;

                   else
                   gameboard->numFruit4++;

               }

               else if(charInput == 'M')
               {
                   gameboard->numMonster++;
                   gameboard->map[i][j] = charInput;
               }

               else if(charInput == '<')
               {
                   pacman->x_start=i;
                   pacman->y_start=j;
                   pacman->x_position = j;
                   pacman->y_position = i;
                   gameboard->numPacman++;
                   gameboard->map[i][j] = ' ';
               }
           }
       }
    fclose(fp);

    if (gameboard->numPacman == 1)
    return 1;
    else
    return -1;
}

int numBytesRead(FILE *ptr)
{
    static int lastPos = 0;
    int currentPos = ftell(ptr);
    int diffrence = currentPos - lastPos;
    lastPos = currentPos;

    return diffrence;
}

void monsterInitialize(int numMons, Monster *mon, GameBoard *board)
{
    int i, j, k;
    //for(i = 0; i < board.numMonster; i++)
    //{
        mon->start_positionX = -1;
        mon->x_direction = 0;
        mon->y_direction = 0;
        mon->state = 0;
        mon->alive = 0;
        mon->sprite = 'M';

        //find monster's X Y
        for(j = 0; j < 18; j++)
        {
            for(k = 0; k < 26; k++)
            {
                if (board->map[j][k] == 'M')
                {
                    mon->start_positionX = k;
                    mon->start_positionY = j;
                    board->map[j][k] = ' ';
                    mon->x_position = k;
                    mon->y_position = j;
                    break;
                }
            }
            if(mon->start_positionX != -1)
            break;
        }
    //}

}

//----------------------------
//        SinglePlayer
//----------------------------

int max_y = 20;
int max_x = 26;
const int test = 0;

int quit(char input)
{
    if (input == 'q')
    return 0;
    else
    return 1;
}

void fileNameCreater(char *file, int level)
{
    char alevel[20];
    const char partialPath[] = "../single_player_maps/Level_";

    sprintf(alevel, "%d", level);
    strcpy(file, partialPath);
    strcat(file, alevel);
    strcat(file, ".txt");
}

int singlePlayerGameController()
{

    int exitCondition;
    PacMan player1;
    char fullPath[100];
    int level = 1;

    pacmanInitialize(&player1); //set pacman initial state;

    do {
        fileNameCreater(fullPath, level);

        if (test == 1)
        {
            clear();
            mvprintw(0, 0, "%s", fullPath);
            refresh();
            getch();
        }


        player1 = singlePlayerGameEngine(player1, fullPath);
    } while(player1.quit);


    return 0;
}

char startGame(int x, int y, char sprite)
{
    char k;
    clear();
    mvprintw(y, x, "%c", sprite);
    refresh();
    k = getch();
    return k;
}

PacMan singlePlayerGameEngine(PacMan p1, char *fileName)
{
    char keypress;              //userinput from keyboard
    GameBoard gb;
    gameBoardInitialize(&gb);

    //ensure filename gets to function
    if (test == 2)
    {
        clear();
        mvprintw(0, 0, "%s", fileName);
        refresh();
        getch();
    }

    keypress = startGame(p1.x_position, p1.y_position, p1.sprite); //function to gameboard and wait for input
    nodelay(stdscr, TRUE);        //once input recived turn off delay from keyboard

    do{
        movePacman(&p1, gb.wall);
        getPacmanDirection1(&p1.x_direction, &p1.y_direction, keypress, &p1.sprite);
        clear();
        mvprintw(p1.y_position, p1.x_position, "%c", p1.sprite); //print p
        refresh();

        usleep(DELAY2);

        keypress = getch();

        p1.quit = quit(keypress);

    }while(0 != p1.quit);

    nodelay(stdscr, FALSE);
    return p1;
}
