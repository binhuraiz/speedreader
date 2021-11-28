#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

FILE *file;
char filename[100], c;
int sleepdur,wpm,charsps;

int findspeed(int wpm){
    charsps=(4 * wpm)/60;
    sleepdur = 1000000/charsps;
    return 0;
}

void printfile(){
    initscr();
    scrollok(stdscr, TRUE);
    int i =1;
    c = fgetc(file);
    while (c != EOF){
        if (c == '<' && i == 1) i--;

        if (i == 1){
            wprintw (stdscr,"%c", c); 
            usleep(sleepdur);
        }

        if (c == '>' && i == 0) i++;

        refresh();
    if(c == EOF) refresh();
        c = fgetc(file);
    }
}

void openfile(){
    file = fopen(filename, "r");
    file == NULL ? printf("Cannot open file \n") : printfile();
}

int main(){
    printf("Enter the filename to open:\n");
    scanf("%s", filename);

    printf("enter the desirable reading speed\n");
    scanf("%d",&wpm);
    findspeed(wpm);

    openfile();
    fclose(file);
    printf("\n");

    getch(); 
    endwin();
    return 0;
} 