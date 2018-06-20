#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//cc freshman.c -o freshman -lcurses

//scene

int hp = 100, iq = 0;

void fileOpen(char fname[]) {
    
    int fd;
    char ch;
    
    fd = open(fname, O_RDONLY );  // 읽기 전용을 파일을 연다.
    
    while( read( fd, &ch, 1 ) )
        write( 1, &ch, 1 );
    
    close(fd);
    return;
    
}

void timeTable() {
    char major, gyoyang;
    
    fileOpen("/Users/knuprime104/Desktop/OS/timetable.txt");
    sleep(1);
    clear();
    refresh();
    fileOpen("/Users/knuprime104/Desktop/OS/timetable2.txt");
    clear();
    refresh();
    
    major = getch();
    gyoyang = getch();
    
    if(atoi(&major) > atoi(&gyoyang)) { // 전공이 더 많을 때
        hp -= 30;
        iq += 30;
        fileOpen("/Users/knuprime104/Desktop/OS/toomuchmajor.txt");
        sleep(1);
        clear();
        refresh();
        fileOpen("/Users/knuprime104/Desktop/OS/toomuchmajor2.txt");
        clear();
        refresh();
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

int main() {
    
    initscr();
    
    timeTable();
    
    endwin();

}
