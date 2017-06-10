/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// track the blank spot
int blankIndex[2];



// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();
    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int largest = d * d - 1;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (largest <= 0) {
                board[i][j] = 0;
            } else {
                board[i][j] = largest--;    
            }
        }
    }
    
    if (d % 2 == 0) {
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 3] = 1;
    }
    
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            // eprintf("board[%i][%i] = %i\n", i, j, board[i][j]);
        }
    }
    
    // init the blank index;
    blankIndex[0] = d - 1;
    blankIndex[1] = d - 1;

    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{

    int times = d * 5;
    for (int i = 0; i < d; i++) {
        for (int k = 0; k < times + 1; k++) {
            printf("-");
        }
        printf("\n");
        for (int j = 0; j < d; j++) {
            if (board[i][j] == 0) {
                printf("%s%3s%s", "|", "_", " ");
            } else {
                printf("%s%3i%s", "|", board[i][j], " ");
                
            }
        }
        printf("|");
        printf("\n");
    }
    for (int l = 0; l < times + 1; l++) {
        printf("-");
    }
    printf("\n");

}


/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // find the index;
    int tileIndex[2];
    int i; 
    int j;
    for (i = 0; i < d; i++) {
        for (j = 0 ; j < d; j++) {
            if (board[i][j] == tile) {
                tileIndex[0] = i;
                tileIndex[1] = j;
                break;
            }
        }
        if (board[i][j] == tile) {
            break;
        }
    } 
    // printf("tileIndex[0] = %i --- tileIndex[1] = %i", tileIndex[0], tileIndex[1]);
    
    // printf("\n");
    // printf("blankIndex[0] = %i --- blankIndex[1] = %i", blankIndex[0], blankIndex[1]);
    // printf("\n");
    // int tileNum = board[tileIndex[0]][tileIndex[1]];
    // int blankNum = board[blankIndex[0]][blankIndex[1]];
    // printf("The tile number is: %i\n", tileNum);
    // printf("The blank number is: %i\n", blankNum);

    if (
        (tileIndex[0] == blankIndex[0] && tileIndex[1] - 1 == blankIndex[1]) ||
        (tileIndex[0] == blankIndex[0] && tileIndex[1] + 1 == blankIndex[1]) ||
        (tileIndex[1] == blankIndex[1] && tileIndex[0] - 1 == blankIndex[0]) ||
        (tileIndex[1] == blankIndex[1] && tileIndex[0] + 1 == blankIndex[0])
       ) {

           // swap the number in board
           int tempNum = board[tileIndex[0]][tileIndex[1]];
           //   eprintf("The temp number is: %i\n", tempNum);
           board[tileIndex[0]][tileIndex[1]] = board[blankIndex[0]][blankIndex[1]];
           board[blankIndex[0]][blankIndex[1]] = tempNum;
           //   Set the blank position
           blankIndex[0] = tileIndex[0];
           blankIndex[1] = tileIndex[1];
           return true;
       }
       
    return false;
}


/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int start = 1;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (i == d - 1 && j == d - 1 && board[i][j] == 0) {
                return true;
            }
            if (board[i][j] != start++) {
                return false;
            }
        }
    }
    return true;
}
