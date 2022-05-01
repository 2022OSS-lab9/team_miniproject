#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char name[100]; //사용자 이름
    char seat[100]; //사용할 좌석
    int date[100]; //예약할 날짜
    int time; // 예약 시간(사용시간)
    int p_num; // 전화번호(4자리)
} Book;

int newBook(Book *s);
void readBook(Book s);
int updateBook(Book *s);
int deleteBook(Book *s);
int selectMenu();
void listBook(Book *s,int count); //예약되어있는 좌석을 보여주는 함수
int selectDataNo(Book *s, int count); // 원하는 번호를 선택하는 함수
void searchName(Book *s, int count); // 예약되었는지 확인할 수 있도록 이름을 검색하는 함수
void saveData(Book *s, int count); // File에 데이터를 저장하는 함수
int loadData(Book *s); // File에서 데이터를 불러오는 함수 