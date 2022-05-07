#include "book.h"

int newBook(Book *s){

    printf("이름이 무엇입니까? ");
    getchar();
    scanf("%[^\n]s", s->name);

    printf("원하는 좌석은 어디입니까? ");
    scanf("%d", &s->seat);

    printf("원하는 날짜는 언제입니까? (ex. 5월 6일 -> 0506) ");
    scanf("%d", &s->date);

    printf("원하는 시간는 언제입니까? (ex. 오후 1시 13분 -> 1313) ");
    scanf("%d", &s->b_time);

    printf("휴대폰 번호 뒷자리는 무엇입니까? ");
    scanf("%d", &s->p_num);

    printf("=> 예약되었습니다 :)\n");

    return 1;
}


void readBook(Book s){
    
    if(s.seat == -1) return;
     
    printf("%s %3d %3d %3d %3d", s.name, s.seat, s.date, s.b_time, s.p_num);

}

int updateProduct(Book *b){

    printf("\n");
    printf("이름이 무엇입니까? ");
    scanf("%[^\n]s",b->name);

    printf("원하는 좌석은 어디입니까? ");
    scanf("%d",&b->seat);

    printf("원하는 날짜는 언제입니까? (5월 5일 -> 0505)");
    scanf("%d",&b->date);
    
    printf("원하는 시간은 언제입니까? (17시 50분 -> 1750)");
    scanf("%d",&b->b_time);


    printf("휴대폰 번호 뒷자리는 무엇입니까? ");
    scanf("%d",&b->p_num);
    
    printf("==> 예약이 수정되셨습니다 :) \n");
    return 1;
};

int deleteBook(Book *b){
    b->seat = -1;
    b->date = -1;
    b->b_time = -1;
    b->p_num = -1;

    printf("==> 예약이 삭제되셨습니다 :)\n");
    return 0;
}



int selectMenu(){
    int menu; 
    printf("\n** 유망스터디카페 **\n");
    printf("1. 예약조회\n");
    printf("2. 새 예약\n");
    printf("3. 예약수정\n");
    printf("4. 예약삭제\n");
    printf("5. 파일저장\n");
    printf("6. 예약확인\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}


void listBook(Book *s, int count){
    printf("No 이름 좌석번호 예약날짜 예약날짜 휴대폰번호\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if(s[i].seat == -1) continue;
        printf("%d ", i+1);
        readBook(s[i]);
    }
    printf("\n");
}


int selectDataNo(Book *s, int count){
    int no;
    listBook(s,count);
    printf("원하는 번호는(취소 :0) ? ");
    scanf("%d",&no);
    return no;
}


void searchName(Book *s, int count){
    int scount = 0;
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);

    printf("\n유망 스터디카페 예약 내용\n");
    printf("No 이름 좌석번호 예약날짜 예약날짜 휴대폰번호\n");
    printf("================================\n");
    for(int i = 0; i < count; i++){
        if(s[i].b_time == -1) continue;
        if(strstr(s[i].name, search)){
            printf("%2d ", i + 1);
            readBook(s[i]);
            count++;
        }
    }
    if(count == 0) printf("=> 예약된 내용 없습니다");
    printf("\n");

}

void saveData(Book *s, int count){
    FILE *fp;

    fp = fopen("Book.txt", "wt");
    for(int i = 0; i< count; i++){
        if(s[i].seat == -1) continue;
        fprintf("%s %3d %d %d %d", s[i].name, s[i].seat, s[i].date, s[i].b_time, s[i].p_num);
    }
    fclose(fp);
    printf("==> 저장됨 \n");
}

int loadData(Book *s){
    FILE *fp;

    fp = fopen("Book.txt", "rt");
    if(fp == NULL){
        printf("==> 파일이 없음\n");
        return 0;
    }

    int count = 0;
    for(;;count++){
        fscanf("%s %3d %d %d %d", s[count].name, s[count].seat, s[count].date, s[count].b_time, s[count].p_num);
        if(feof(fp)) break;
    }
    fclose(fp);
    printf("==> 로딩성공!!\n");
    return count;
}




 

