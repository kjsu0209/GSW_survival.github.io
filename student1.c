#include <stdio.h>
#include <stdlib.h>

#define MAX_COLS 32768

int hp = 100, iq = 0, fs = 0;

void ST();
void MT();
void RP();
void Fst();
void Home(); // 이불밖은 위험해
void HPIQ(); // hp 가 0일때

// txt파일 화면에 출력
void fileOpen(char name[]) {
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
}

void student_1()
{
    ST(); // 새터
    MT(); // 엠티
    RP(); // 과대(화면으로 보여줌)
    Fst(); // 축제
}

void ST()
{
    int choice; // 1.간다, 2.안간다
    
    fileOpen("ST.txt");
    
    // 새터 갈지 말지 선택
    fscanf(stdin, "%d", &choice);
    if (choice == 1) // 1번 선택
    {
        fileOpen("ST_go.txt");
        
        hp -= 10; iq -= 10; fs += 20; // stat 변화
    }
    if (choice == 2) // 2번 선택
        Home();
    
    if (hp == 0) // 죽음
        HPIQ();
    if (hp > 100) hp = 100;
    
    return;
}

void MT()
{
    int choice; // 1.간다, 2.안간다
    
    fileOpen("MT.txt");
    
    // 엠티 갈지 말지 선택
    fscanf(stdin, "%d", &choice);
    if (choice == 1) // 1번 선택
    {
        fileOpen("MT_go.txt");
        
        hp -= 10; iq -= 10; fs += 20; // stat 변화
    }
    if (choice == 2) // 2번 선택
        Home();
    
    if (hp == 0) // 죽음
        HPIQ();
    if (hp > 100) hp = 100;
    
    return;
}

void RP()
{
    fileOpen("RT.txt");
}

void Fst()
{
    int choice; // 1.간다, 2.안간다
    
    fileOpen("Festival.txt");
    
    // 축제 갈지 말지 선택
    fscanf(stdin, "%d", &choice);
    if (choice == 1) // 1번 선택
    {
        fileOpen("Fst_go.txt");
        
        hp -= 10; iq -= 10; fs += 20; // stat 변화
    }
    if (choice == 2) // 2번 선택
        Home();
    
    if (hp == 0) // 죽음
        HPIQ();
    if (hp > 100) hp = 100;
    
    return;
}

void Home() {
    fileOpen("Home.txt");
    hp += 10; fs -= 10;
}

void HPIQ() {
    fileOpen("Die.txt");
    exit(0);
}
