#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <termios.h>
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
void MT(); // 엠티
void RP(); // 과대(화면으로 보여줌)
void Fst(); // 축제
void Enjoy(); // 즐거웠다
void Home(); // 이불밖은 위험해
void Die(); // 사망인지 확인
void fileOpen1(char[]); // txt 파일 open

int main()
{
    student_1();
    return 0;
}

void student_1()
{
    Start();
    ST();
    MT();
    RP();
    Fst();
}

void Start()
{
    int ch;
    
    fileOpen1("1.TXT");
    fileOpen1("2.TXT");
    fileOpen1("3.TXT");
    fileOpen1("4.TXT");
    fileOpen1("5.TXT");
    fileOpen1("6.TXT");
    fileOpen1("7.TXT");
    fileOpen1("8.TXT");
    fileOpen1("9.TXT");
    fileOpen1("10.TXT");
    fileOpen1("11.TXT");
    
    ch = getchar();
    if (ch == '\n')
    {
        fileOpen1("0-1.TXT");
        fileOpen1("0-2.TXT");
        fileOpen1("0-3.TXT");
        fileOpen1("0-4.TXT");
    }
    fflush(stdin);
    //tcflush(0, TCIFLUSH);
}

void ST()
{
    int choice; // 1.간다, 2.안간다
    
    fileOpen1("1-1.TXT");
    sleep(1);
    fileOpen1("1-2.TXT");
    sleep(1);
    fileOpen1("1-3.TXT");
    sleep(1);
    
    // 엠티 갈지 말지 선택
    choice = getch();
    if (choice == '1') // 1번 선택
    {
        fileOpen1("1-4-1.TXT");
        sleep(1);
        Enjoy();
        
        hp -= 10; iq -= 10; fs += 25; // stat 변화
    }
    else if (choice == '2') // 2번 선택
    {
        fileOpen1("1-4-2.TXT");
        sleep(1);
        Home();
    }
    
    Die();
}

void MT()
{
    int choice; // 1.간다, 2.안간다
    
    fileOpen1("3-1.TXT");
    sleep(1);
    fileOpen1("3-2.TXT");
    sleep(1);
    fileOpen1("3-3.TXT");
    sleep(1);
    
    // 엠티 갈지 말지 선택
    choice = getch();
    if (choice == '1') // 1번 선택
    {
        fileOpen1("3-4-1.TXT");
        sleep(1);
        Enjoy();
        
        hp -= 10; iq -= 10; fs += 25; // stat 변화
    }
    if (choice == '2') // 2번 선택
    {
        fileOpen1("3-4-2.TXT");
        sleep(1);
        Home();
    }
    
    Die();
}

void RP()
{
    fileOpen1("4-1.TXT");
    sleep(1);
    fileOpen1("4-2.TXT");
    sleep(1);
    fileOpen1("4-3.TXT");
    sleep(1);
    fileOpen1("4-4.TXT");
    sleep(1);
    fileOpen1("4-5.TXT");
    sleep(1);
    fileOpen1("4-6.TXT");
    sleep(1);
    
    if (fs == 100) // 당선
    {
        fileOpen1("4-7-1-1.TXT");
        sleep(1);
        fileOpen1("4-7-1-2.TXT");
        sleep(1);
        fileOpen1("4-7-1-3.TXT");
        sleep(1);
        fileOpen1("4-7-1-4.TXT");
        sleep(1);
        fileOpen1("4-7-1-5.TXT");
        sleep(1);
    }
    else // 낙선
    {
        fileOpen1("4-7-2-1.TXT");
        sleep(1);
        fileOpen1("4-7-2-2.TXT");
        sleep(1);
        fileOpen1("4-7-2-3.TXT");
        sleep(1);
        fileOpen1("4-7-2-4.TXT");
        sleep(1);
        fileOpen1("4-7-2-5.TXT");
        sleep(1);
    }
}

void Fst()
{
    int choice; // 1.간다, 2.안간다
    
    fileOpen1("7-1.TXT");
    sleep(1);
    fileOpen1("7-2.TXT");
    sleep(1);
    
    // 엠티 갈지 말지 선택
    choice = getch();
    if (choice == '1') // 1번 선택
    {
        fileOpen1("7-3-1.TXT");
        sleep(1);
        
        hp -= 10; iq -= 20; fs += 20; // stat 변화
    }
    if (choice == '2') // 2번 선택
    {
        Home();
    }
    
    Die();
}

void Home() {
    fileOpen1("H-1.TXT");
    sleep(1);
    fileOpen1("H-2.TXT");
    sleep(1);
    fileOpen1("H-3.TXT");
    sleep(1);
    fileOpen1("H-4.TXT");
    sleep(1);
    hp += 10; fs -= 10;
}

void Enjoy()
{
    fileOpen1("E-1.TXT");
    sleep(1);
    fileOpen1("E-2.TXT");
    sleep(1);
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
        fileOpen1("D-1.TXT");
        sleep(1);
        fileOpen1("D-2.TXT");
        sleep(1);
        fileOpen1("HPD-1.TXT");
        sleep(1);
        fileOpen1("HPD-2.TXT");
        sleep(1);
        fileOpen1("HPD-3.TXT");
        return student_1();
    }
    if (iq <= 0) // 퇴학
    {
        fileOpen1("D-1.TXT");
        sleep(1);
        fileOpen1("D-2.TXT");
        sleep(1);
        fileOpen1("IQD-1.TXT");
        sleep(1);
        fileOpen1("IQD-2.TXT");
        sleep(1);
        fileOpen1("IQD-3.TXT");
        sleep(1);
        fileOpen1("IQD-4.TXT");
        sleep(1);
        fileOpen1("IQD-5.TXT");
        sleep(1);
        fileOpen1("IQD-6.TXT");
        sleep(1);
        fileOpen1("IQD-7.TXT");
        sleep(1);
        fileOpen1("IQD-8.TXT");
        sleep(1);
        fileOpen1("IQD-9.TXT");
        return student_1();
    }
    if (fs <= 0)
    {
        fileOpen1("D-1.TXT");
        sleep(1);
        fileOpen1("D-2.TXT");
        sleep(1);
        fileOpen1("FSD-1.TXT");
        sleep(1);
        fileOpen1("FSD-2.TXT");
        fileOpen1("FSD-3.TXT");
        fileOpen1("FSD-4.TXT");
        fileOpen1("FSD-5.TXT");
        fileOpen1("FSD-6.TXT");
        return student_1();
    }
}

void fileOpen1(char name[]) {
    
    clear();
    
    FILE *f;
    char s[MAX_COLS]; // 행이 1줄씩 임시로 저장될 버퍼
    
    // fopen() 함수로 파일 열기
    if ( (f = fopen(name, "rt")) == NULL) {
        fputs("Cannot open input file...\n", stderr);
        exit(1); // 모든 파일 닫고, 프로그램 종료
    }
    
    // 읽기 시작: 프로그램의 본체
    while (fgets(s, MAX_COLS, f) != NULL) {
        printf("%s", s); // 한 줄씩 화면에 출력
    }
    
    fclose(f); // 모든 파일 닫기
    sleep(2);
    refresh();
}
