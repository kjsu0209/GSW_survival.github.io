#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

//cc freshman.c -o freshman -lcurses

//scene

int hp = 100, iq = 0;

void fileOpen(char fname[]) {
    char statement[10000];
    int i=0;
    FILE *fp = fopen(fname, "r");
    
    while(!feof(fp)) {
        fscanf(fp, "%c", &statement[i++]);
    }
    
    addstr(statement);
}

void timeTable() {
    char major, gyoyang;
    
    fileOpen("timetable.txt");
    
    major = getch();
    gyoyang = getch();
    
    if(atoi(&major) > atoi(&gyoyang)) { // 전공이 더 많을 때
        hp -= 30;
        iq += 30;
    }
    
    else if(atoi(&major) < atoi(&gyoyang)) { // 교양이 더 많을 때
        hp -= 20;
    }
    
    else { // 교양과목 == 전공과목
        hp -= 10;
        iq += 50;
    }
}

void dogriver() { // 개강
    fileOpen("dogriver.txt");
    hp -= 5;
}

void endSemester() { // 종강
    fileOpen("endSemester.txt");
    hp += 50;
    
    if(hp > 100) {
        hp = 100;
    }
}


void midterm() { // 중간고사
    fileOpen("midterm.txt");
    hp -= 15;
}

void finterm() { // 기말고사
    fileOpen("finterm.txt");
    hp -= 15;
    
    sleep(2);
    
    if(iq >= 50) { // 아이큐 50 이상 -> A
        fileOpen("gradeA.txt");
    }
    
    else { // 아이큐 50 미만 -> F
        fileOpen("gradeF.txt");
    }
}

void dead() {
    fileOpen("dead.txt");
    
    hp = 0;
    
    endwin();
}

void home() {
    fileOpen("home.txt");
    
    hp += 10;
    
    if(hp > 100) {
        hp = 100;
    }
}

void Vacation(season){
    
}

void student2() {
    
    timeTable();
    
    if(hp <= 0) {
        dead();
    }
    
    dogriver();
    
    if(hp <= 0) {
        dead();
    }
    
    midterm();
    
    if(hp <= 0) {
        dead();
    }
    
    finterm();
    
    if(hp <= 0) {
        dead();
    }
    
    endSemester();
    
    int season;
    season = getch();
    
    Vacation(season);
    
    if(hp <= 0) {
        dead();
    }

}
