#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

//cc freshman.c -o freshman -lcurses


//scene

int dogliver();//개강
int timetable();//시간표 짜기

int endSemester();//종강

int festival();//축제

int midexam();//중간고사
int finalexam();//기말고사

int choicemajor();//융전 복전 학석사 선택

int lovehome();//이불밖은 위험해
int india();//인도
int sanjose();//미국

int die(char reason[], char die[]);//사망

int main(void)
{
  int i;
  initscr();

  for(i=0;i<5;i++){
    clear();
    move(LINES/2, 5*i+20);
    sleep(1);
    addstr("~ freshman ~");
    refresh();
  }
  clear();
  refresh();
  getch();



  endwin();
}

int dogliver()//개강
{

}
int timetable()//시간표 짜기
{

}

int endSemester()//종강
{

}

int festival()//축제
{

}

int midexam()//중간고사
{

}
int finalexam()//기말고사
{

}

int choicemajor()//융전 복전 학석사 선택
{

}

int lovehome()//이불밖은 위험해
{

}
int india()//인도
{

}
int sanjose()//미국
{

}

int die(char reason[], char die[])//사망
{
  
}
