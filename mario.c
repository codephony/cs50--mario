// These bring outside code into our by telling the compiler to pull these files in from the outside
#include <cs50.h>
#include <stdio.h>

// Function protoype that declare our functions for use later, askHeight, printBlok, and printRow, these three functions solve the main problems we discussed earlier
int askHeight(void);
void printBlok(int rowLength, int rowNumber) ;
void printRow(int height);

// Main function that delegates all the work
int main(void)
{   
    // Here we call printRow and feed it our height, this lets it know how tall to make the pyramid
    printRow(askHeight());
}

// Asks the user for the height, repeats until the user gives what we want, a positive integer between and including 1-8
int askHeight(void)
{
    // Declare the a bool to change once we have the right input
    bool incorrect_input = true;
    // Declare a height variable to store our height
    int height;
    
    // Use a while loop to keep asking the user for their input until we get the correct input
    while (incorrect_input)
    {
        // Use cs50's get_int to ask the user for their Height and stores it in height
        height = get_int("Height: \n");   
        
        // If height is greater than 0 and less than 9 we'll change the incorrect_input boolean to false, which breaks us out of the while loop
        if (height > 0 && height < 9)
        {
            // Sets the incorrect_input boolean to false
            incorrect_input = false;
        }
    }
    // Here we return the height to the program to use however we'd like, calling this function, askHeight, will put this height integer wherever it's called
    return height;
}

// This function prints the blocks along the row, there are probably more ways to do this but this is how I did it, it takes a the rowLength to determine how many blocks to print(empty blocks & regular blocks) and it takes the rowNumber to determine how many regular blocks are needed on the particular row we're focusing on
void printBlok(int rowLength, int rowNumber)
{
    // First I set a count to count the  block number I'm currently on
    int blokCount = 0;
    
    // The way I imagined this was to print empty spaces where there is a lack of blocks, so essentially I'm printing two big rectangles and half of the rectangles are missing, so the empty blocks variable counts the unmber of empty blocks
    int emptyBloks = (rowLength - rowNumber) - 1;
    
    // In this case fullBloks would be the inverse of empty Blocks
    int fullBloks = (rowLength - emptyBloks) - 1;
    
    // Variable that stores a number for the full row length AKA the length of both sides of the pyramid combined, I could have doubled the rowLength, but this way I don't have to print the empty blocks on the right side of the pyramid
    int fullRowLength = (rowLength + fullBloks) + 1;
    
    // While my blokCount(the block we are currently focusing on) is  less than the fullRowLength we will print something
    while (blokCount < fullRowLength)
    {
        // If the blockCount is equal to the rowLength, meaning, it's at the end of the row of the pyramid we were working on.  We'll print the last block of that row and add the space to introduce the gap between pyramids
        if (blokCount == (rowLength - 1))
        {
            // This will do the printing
            printf("#  ");
            // Very important, this shifts the block we're focusing on to the next block in the row
            blokCount++;
        }
        // Here we print a block and then move to a new line because we have reach the fullRowLength.  We subtract 1 because the blokCount starts at 0.
        else if (blokCount == (fullRowLength - 1))
        {
            // Same as above, but prints a block and moves us to a new line
            printf("#\n");
            // Increases the block count which focuses on the next block (in this case it will break the loop because block count will equal fullRowLength)
            blokCount++;
        }
        // Here we check if the blokCount has surpassed the emptyBlok value, until emptyBloks is GREATER THAN OR EQUAL TO the blokCount we will only print emptyBloks ALSO KNOWN AS SPACES
        else if (blokCount < emptyBloks)
        {
            // Prints a space
            printf(" ");
            // Shifts focus to next blok
            blokCount++;
        }
        // If all the above conditions are not met, meaning, the slot we're focusing on is NOT at the far right side of EITHER pyramid and the blokCount is GREATER THAN OR EQUAL TO the emptyBlok value we will just print a solitary #
        else
        {
            // Same as above
            printf("#");
            blokCount++;
        }
    }
}

// Here we print a row, we take in arguement height to tell printRow how many total rows to print
void printRow(int height)
{
    // rowCount keeps track of which row we're on
    int rowCount = 0;
    
    // This loop calls printBlok to print the rows until we reach the height value
    while (rowCount < height)
    {
        // Here we actually call printBlock and feed it the height and rowCount variables to work with
        printBlok(height, rowCount);
        // Shifts our focus to the next row
        rowCount++;
    }
}
