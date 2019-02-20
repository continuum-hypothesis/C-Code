#include <stdio.h>
#include <stdlib.h>

/*This program is a typical file viewer application that is used in Unix/Linux terminals
  Gives a readout of the text of the document as well as a character and word count.
  When you compile the program give the path to the text file you want to view as the argument.
  For example ./file.out text_file
*/
int main(int argc, char *argv[])  // argc is 1 by defalt and is the program name stored in argv
{
    long int ch;
    FILE *file_pointer;
    long count = 0;

    if(argc != 2)
    {
        printf("Program requiers exactly one argument\n);
        exit(1);
    }
    if ((file_pointer = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open %s\n", argv[1]);
        exit(1);
    }

    int previous = 32;
    long int words = 0;
    while((ch = getc(file_pointer)) != EOF) // as long as we're not at the EOF character keep going
    {
        if(ch == 32 && previous != 32)  // at end of loop previous is assigned the value of ch before
            words++;                    // ch recieves new value.if they are both 32 that means there
                                        // are two or more spaces in a row so don't count that as another word
        putc(ch, stdout);               // output current ch to the screen
        count++;
        previous = ch;
    }
    if(words > 0)                   // hacky but if there is no white space after the last word it
        words++;                    // won't be counted
    fclose(file_pointer);
    printf("\n%s has %ld characters and %ld words\n", argv[1], count, words);

    return 0;
}
