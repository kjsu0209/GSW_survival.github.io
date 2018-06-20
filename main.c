#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <curses.h>

#define MAX_COLS 32768
# define BUFFER_SIZE 512

int hp = 100, iq = 50, fs = 50;

void student_1();
void Start(); // 시작
void ST(); // 새터
void timeTable(); // 시간표
void MT(); // 엠티
void RP(); // 과대(화면으로 보여줌)
int Vacation(int); // 방학
void Fst(); // 축제
void Enjoy(); // 즐거웠다
void Home(); // 이불밖은 위험해
void Die(); // 사망인지 확인
void fileOpen(char[]); // txt 파일 open

int main()
{
    initscr();
    student_1();
    endwin();
}

void student_1()
{
    Start();
    ST();
    timeTable();
    MT();
    RP();
    midterm();
    Fst();
    finterm();
    Vacation(0); // 여름방학
    timeTable();
    midterm();
    finterm();
    Vacation(1);
}

void Start()
{
    fileOpen("1.TXT");
    fileOpen("2.TXT");
    fileOpen("3.TXT");
    fileOpen("4.TXT");
    fileOpen("5.TXT");
    fileOpen("6.TXT");
    fileOpen("7.TXT");
    fileOpen("8.TXT");
    fileOpen("9.TXT");
    fileOpen("10.TXT");
    fileOpen("11.TXT");
    
    sleep(2);
    fileOpen("0-1.TXT");
    fileOpen("0-2.TXT");
    fileOpen("0-3.TXT");
    fileOpen("0-4.TXT");

    //tcflush(0, TCIOFLUSH);
}

void ST()
{
    int choice; // 1.간다, 2.안간다
    
    fileOpen("1-1.TXT");
    fileOpen("1-2.TXT");
    fileOpen("1-3.TXT");
    
    // 새터 갈지 말지 선택
    choice = getch();
    if (choice == '1') // 1번 선택
    {
        fileOpen("1-4-1.TXT");
        Enjoy();
        
        hp -= 10; iq -= 10; fs += 25; // stat 변화
    }
    else if (choice == '2') // 2번 선택
    {
        fileOpen("1-4-2.TXT");
        Home();
    }
    
    Die();
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

void MT()
{
    int choice; // 1.간다, 2.안간다
    
    fileOpen("3-1.TXT");
    fileOpen("3-2.TXT");
    fileOpen("3-3.TXT");
    
    // 엠티 갈지 말지 선택
    choice = getch();
    if (choice == '1') // 1번 선택
    {
        fileOpen("3-4-1.TXT");
        Enjoy();
        
        hp -= 10; iq -= 10; fs += 25; // stat 변화
    }
    if (choice == '2') // 2번 선택
    {
        fileOpen("3-4-2.TXT");
        Home();
    }
    
    Die();
}

void RP()
{
    fileOpen("4-1.TXT");
    fileOpen("4-2.TXT");
    fileOpen("4-3.TXT");
    fileOpen("4-4.TXT");
    fileOpen("4-5.TXT");
    fileOpen("4-6.TXT");
    
    if (fs == 100) // 당선
    {
        fileOpen("4-7-1-1.TXT");
        fileOpen("4-7-1-2.TXT");
        fileOpen("4-7-1-3.TXT");
        fileOpen("4-7-1-4.TXT");
        fileOpen("4-7-1-5.TXT");
    }
    else // 낙선
    {
        fileOpen("4-7-2-1.TXT");
        fileOpen("4-7-2-2.TXT");
        fileOpen("4-7-2-3.TXT");
        fileOpen("4-7-2-4.TXT");
        fileOpen("4-7-2-5.TXT");
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

void Fst()
{
    int choice; // 1.간다, 2.안간다
    
    fileOpen("7-1.TXT");
    fileOpen("7-2.TXT");
    
    // 엠티 갈지 말지 선택
    choice = getch();
    if (choice == '1') // 1번 선택
    {
        fileOpen("7-3-1.TXT");
        
        hp -= 10; iq -= 20; fs += 20; // stat 변화
    }
    if (choice == '2') // 2번 선택
    {
        Home();
    }
    
    Die();
}

void Home() {
    fileOpen("H-1.TXT");
    fileOpen("H-2.TXT");
    fileOpen("H-3.TXT");
    fileOpen("H-4.TXT");
    hp += 10; fs -= 10;
}

void Enjoy()
{
    fileOpen("E-1.TXT");
    fileOpen("E-2.TXT");
}

void Die() {
    if (hp > 100)
        hp = 100;
    if (iq > 100)
        iq = 100;
    if (fs > 100)
        fs = 100;
    
    if (hp <= 0) // 과로사
    {
        fileOpen("D-1.TXT");
        fileOpen("D-2.TXT");
        fileOpen("HPD-1.TXT");
        fileOpen("HPD-2.TXT");
        fileOpen("HPD-3.TXT");
        return student_1();
    }
    if (iq <= 0) // 퇴학
    {
        fileOpen("D-1.TXT");
        fileOpen("D-2.TXT");
        fileOpen("IQD-1.TXT");
        fileOpen("IQD-2.TXT");
        fileOpen("IQD-3.TXT");
        fileOpen("IQD-4.TXT");
        fileOpen("IQD-5.TXT");
        fileOpen("IQD-6.TXT");
        fileOpen("IQD-7.TXT");
        fileOpen("IQD-8.TXT");
        fileOpen("IQD-9.TXT");
        return student_1();
    }
    if (fs <= 0)
    {
        fileOpen("D-1.TXT");
        fileOpen("D-2.TXT");
        fileOpen("FSD-1.TXT");
        fileOpen("FSD-2.TXT");
        fileOpen("FSD-3.TXT");
        fileOpen("FSD-4.TXT");
        fileOpen("FSD-5.TXT");
        fileOpen("FSD-6.TXT");
        return student_1();
    }
}

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
