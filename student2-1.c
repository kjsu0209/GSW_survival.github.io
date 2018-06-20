#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//cc freshman.c -o freshman -lcurses

// cc student2-1.c -o student2-1 -lcurses

//scene

int hp = 100, iq = 50, fs = 50;

void fileOpen(char fname[]) {
    
    clear();
    
    int fd;
    char ch;
    
    move(0,0);
    
    fd = open(fname, O_RDONLY );  // 읽기 전용을 파일을 연다.
    
    while( read( fd, &ch, 1 ) )
        write( 1, &ch, 1 );
    
    close(fd);
    
    sleep(2);
    
    refresh();
    
    return;
    
}

void timeTable() {
    char major, gyoyang;
    
    fileOpen("/Users/knuprime104/Desktop/OS/timetable.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/timetable2.txt");
    
    major = getch();
    gyoyang = getch();
    
    if(major > gyoyang) { // 전공이 더 많을 때
        hp -= 30;
        iq += 30;
        fileOpen("/Users/knuprime104/Desktop/OS/toomuchmajor.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/toomuchmajor2.txt");
    }
    
    else if(strcmp(&major, &gyoyang) < 0) { // 교양이 더 많을 때
        hp -= 20;
        fileOpen("/Users/knuprime104/Desktop/OS/toomuchgyoyang.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/toomuchgyoyang2.txt");
    }
    
    else { // 교양과목 == 전공과목
        hp -= 10;
        iq += 50;
        fileOpen("/Users/knuprime104/Desktop/OS/balance.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/balance2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/balance3.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/balance4.txt");
    }
}

void dogriver_2() { // 개강
    fileOpen("/Users/knuprime104/Desktop/OS/start2.txt");
    hp -= 5;
}

int midterm() { // 중간고사

    hp -= 15;

    fileOpen("/Users/knuprime104/Desktop/OS/midterm.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/midterm2.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/midterm3.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/midterm4.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/midterm5.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/midterm6.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/midterm7.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/midterm8.txt");
    
    int choice;
    choice = getch();
    
    if(choice == '1') {
        iq -= 20;
        fs += 10;
        
        fileOpen("/Users/knuprime104/Desktop/OS/go.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/go2.txt");

    }
    
    else if(choice == '2') {
        iq += 20;
        fs -= 10;
        
        fileOpen("/Users/knuprime104/Desktop/OS/notgo.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/notgo2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/notgo3.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/notgo4.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/notgo5.txt");
    }
    
    return 0;
}

void getgrade() {
    if(iq >= 50) { // 아이큐 50 이상 -> A
        fileOpen("/Users/knuprime104/Desktop/OS/good.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/good2.txt");
    }
    
    else if(iq < 50) { // 아이큐 50 미만 -> C+
        fileOpen("/Users/knuprime104/Desktop/OS/bad.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/bad2.txt");
        
    }
}

void finterm() { // 기말고사
    int choice;
    
    hp -= 15;
    
    fileOpen("/Users/knuprime104/Desktop/OS/finterm.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/finterm2.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/finterm3.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/finterm4.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/finterm5.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/finterm6.txt");

    choice = getch();
    
    if(choice == '1') {
        iq -= 20;
        fs += 10;
        
        fileOpen("/Users/knuprime104/Desktop/OS/fingo.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/fingo2.txt");
    }
    
    else if(choice == '2') {
        iq += 20;
        fs -= 10;
        
        fileOpen("/Users/knuprime104/Desktop/OS/finnotgo.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/finnotgo2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/finnotgo3.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/finnotgo4.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/finnotgo5.txt");
    }
    
    getgrade();
}

void dead() {
    
    fileOpen("/Users/knuprime104/Desktop/OS/dead.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/dead2.txt");
    
    if(hp <= 0) {
        fileOpen("/Users/knuprime104/Desktop/OS/tired.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/tired2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/tired3.txt");
        
    }
    
    else if(iq <= 0) {
        fileOpen("/Users/knuprime104/Desktop/OS/out.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/out2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/out3.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/out4.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/out5.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/out6.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/out7.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/out8.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/out9.txt");
    }
    
    else if(fs <= 0) {
        fileOpen("/Users/knuprime104/Desktop/OS/lonely.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/lonely2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/lonely3.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/lonely4.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/lonely5.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/lonely6.txt");
    }
    
    fileOpen("/Users/knuprime104/Desktop/OS/ending.txt");
    endwin();

}

void home() {
    
    hp+=10;
    
    fileOpen("/Users/knuprime104/Desktop/OS/home.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/home2.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/home3.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/home4.txt");
    
    if(hp > 100) {
        hp = 100;
    }
}

int Vacation(int season){
    int choice = -1;
    
    if(season == 0)//여름 계절학기
    {
        fileOpen("/Users/knuprime104/Desktop/OS/summer.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/summer2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/summer3.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/summer4.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/summer5.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/summer6.txt");
        
        choice = getch();
        if(choice == '1')//인도
        {
            hp += 10;
            iq += 10;
            fs += 10;
            
            fileOpen("/Users/knuprime104/Desktop/OS/india.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/india2.txt");
        }
        else if(choice == '2')//미국
        {
            hp += 10;
            iq += 10;
            fs += 10;

            fileOpen("/Users/knuprime104/Desktop/OS/america.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/america2.txt");
        }
        else if(choice == '3')//계절
        {
            hp -= 20;
            iq += 20;
            
            fileOpen("/Users/knuprime104/Desktop/OS/seasonSemester.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/seasonSemester2.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/seasonSemester3.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/seasonSemester4.txt");
        }
        else if(choice == '4')//이불
        {
            home();
        }
        else
        {
            return -1;
        }
    }
    
    else{
        
        fileOpen("/Users/knuprime104/Desktop/OS/winter.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/winter2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/winter3.txt");
        
        choice = getch();
        
        if(choice == '1')//글리
        {
            iq += 10;
            hp += 10;
            fs += 10;
            
            fileOpen("/Users/knuprime104/Desktop/OS/leader.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/leader2.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/leader3.txt");
        }
        else if(choice == '2')//계절
        {
            hp -= 20;
            iq += 20;
            
            fileOpen("/Users/knuprime104/Desktop/OS/seasonSemester.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/seasonSemester2.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/seasonSemester3.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/seasonSemester4.txt");
        }
        else if(choice == '3')//이불
        {
            home();
        }
        else
        {
            return -1;
        }
    }
    
    return 0;
}

void choice() {
    int choice;
    
    fileOpen("/Users/knuprime104/Desktop/OS/choice.txt");
    fileOpen("/Users/knuprime104/Desktop/OS/choice2.txt");
    
    choice = getch();
    
    if(choice == '1') {
        fileOpen("/Users/knuprime104/Desktop/OS/project.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/project2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/project3.txt");
        
        if(fs >= 30 && iq >= 30) {
            fileOpen("/Users/knuprime104/Desktop/OS/success.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/success2.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/success3.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/success4.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/success5.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/success6.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/success7.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/success8.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/success9.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/ending.txt");
            endwin();
        }
        
        else {
            fileOpen("/Users/knuprime104/Desktop/OS/fail.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/fail2.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/fail3.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/fail4.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/fail5.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/fail6.txt");
            fileOpen("/Users/knuprime104/Desktop/OS/ending.txt");
            endwin();
        }
    }
    
    else if(choice == '2') {
        fileOpen("/Users/knuprime104/Desktop/OS/global.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global3.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global4.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global5.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global6.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global7.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global8.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global9.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global10.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global11.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global12.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global13.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global14.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/global15.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/ending.txt");
        endwin();
    }
    
    else if(choice == '3') {
        fileOpen("/Users/knuprime104/Desktop/OS/master.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master3.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master4.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master5.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master6.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master7.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master8.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master9.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master10.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master11.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master12.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master13.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master14.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/master15.txt");
        
        fileOpen("/Users/knuprime104/Desktop/OS/tired.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/tired2.txt");
        fileOpen("/Users/knuprime104/Desktop/OS/tired3.txt");
        
        fileOpen("/Users/knuprime104/Desktop/OS/ending.txt");
        endwin();
    }
    
}

void student2() {
    
    timeTable();
    
    if(hp <= 0 || iq <= 0 || fs <= 0) {
        dead();
    }
    
    dogriver_2();
    
    if(hp <= 0 || iq <= 0 || fs <= 0) {
        dead();
    }
    
    midterm();
    
    if(hp <= 0 || iq <= 0 || fs <= 0) {
        dead();
    }
    
    finterm();
    
    if(hp <= 0 || iq <= 0 || fs <= 0) {
        dead();
    }
    
    Vacation(0);
    
    if(hp <= 0 || iq <= 0 || fs <= 0) {
        dead();
    }
    
    timeTable();
    
    if(hp <= 0 || iq <= 0 || fs <= 0) {
        dead();
    }

    midterm();
    
    if(hp <= 0 || iq <= 0 || fs <= 0) {
        dead();
    }
    
    finterm();
    
    if(hp <= 0 || iq <= 0 || fs <= 0) {
        dead();
    }

    Vacation(1);
    
    if(hp <= 0 || iq <= 0 || fs <= 0) {
        dead();
    }
    
    choice();
    
}

int main() {
    
    initscr();
    
    student2();
    
    endwin();
    
}
