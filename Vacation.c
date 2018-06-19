#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

//cc freshman.c -o freshman -lcurses
void fileOpen(char filename[])
{
  FILE *fp = fopen(filename, "r");
  char str;
  if(fp == NULL)
  {
    endwin();
    printf("file not exist!");
  }

  while(!feof(fp))
  {
    str  = fscanf(fp, "c");
  }
  clear();
  move(0,0);
  addstr(str);
  refresh();
}

int Vacation(int season)
{
  int choice = -1;
  char str = "texts.txt";
    if(season == 0)//여름 계절학기
    {
      fileOpen(str);
      choice = getch();
      if(choice == 0)//인도
      {
        fileOpen(str);
      }
      else if(choice == 1)//미국
      {
        fileOpen(str);
      }
      else if(choice == 2)//계절
      {
        fileOpen(str);
      }
      else if(choice == 3)//이불
      {
        fileOpen(str);
      }
      else
      {
        return -1;
      }
    }
    else{
      fileOpen(str);
      choice = getch();
      if(choice == 0)//글리
      {
        fileOpen(str);
      }
      else if(choice == 1)//계절
      {
        //hp -= 20;
        fileOpen(str);
      }
      else if(choice == 2)//이불
      {
        //hp+=10;
        fileOpen(str);
      }
      else
      {
        return -1;
      }
    }
}
