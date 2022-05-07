#include "book.h"

int newBook(Book *s){

    printf("이름이 무엇입니까? ");
    getchar();
    scanf("%[^\n]s", s->name);

    printf("원하는 좌석은 어디입니까? ");
    while(1){
        scanf("%d", &s->seat);
        if(1>s->seat || s->seat>25){
            pritf("존재하지 않는 좌석입니다. 다시 입력해주세요 \n");
        }
        else break;
    }

    printf("원하는 날짜는 언제입니까? (ex. 5월 6일 -> 0506) ");
    while(1){
        scanf("%d", &s->date);
        if(sizeof(s->date)>16){
            printf("입력이 잘못되었습니다. 4자리로 입력해주세요 \n");
        }
        else break;
    }

    printf("원하는 시간는 언제입니까? (ex. 오후 1시 13분 -> 1313) ");
    while(1){
        scanf("%d", &s->b_time);
        if(sizeof(s->b_time)>16){
            printf("입력이 잘못되었습니다. 4자리로 입력해주세요 \n");
        }
        else break;
    }

    printf("휴대폰 번호 뒷자리는 무엇입니까? ");
    while(1){
        scanf("%d", &s->p_num);
        if(sizeof(s->p_num)>16){
            printf("입력이 잘못되었습니다. 4자리로 입력해주세요 \n");
        }
        else break;
    }

    printf("=> 예약되었습니다 :)\n");

    return 1;
}


void readBook(Book s){
    
    if(s.seat == -1) return;
     
    printf("%s %3d %d %d %d", s.name, s.seat, s.date, s.b_time, s.p_num);

}

int updateProduct(Book *b){

    printf("\n");
    printf("이름이 무엇입니까? ");
    scanf("%[^\n]s",b->name);

    printf("원하는 좌석은 어디입니까? ");
    scanf("%d",&b->seat);

    printf("원하는 날짜는 언제입니까? (5월 5일 -> 0505)");
    while(1){
        scanf("%d",&b->date);
        if(sizeof(b->date) > 16){
            printf("입력이 잘못되었습니다. 4자리로 입력해주세요");
        }
        else break;
    }
    
    printf("원하는 시간은 언제입니까? (17시 50분 -> 1750)");
    while(1){
        scanf("%d",&b->b_time);
        if(sizeof(b->date) > 16){
            printf("입력이 잘못되었습니다. 4자리로 입력해주세요");
        }
        else break;
    }

    printf("휴대폰 번호 뒷자리는 무엇입니까? ");
    while(1){
        scanf("%d",&b->p_num);
        if(sizeof(b->date) > 16){
            printf("입력이 잘못되었습니다. 4자리로 입력해주세요");
        }
        else break;
    }
    
    printf("==> 예약이 수정되셨습니다 :) \n");
    return 1;
};

int deleteProduct(Book *b){
    b->b_time[0] = -1;
    b->p_num[0] = -1;
    printf("==> 예약이 취소되었습니다 :) \n");
    return 0;
}


int selectMenu(){
    int menu; 
    printf("\n** 유망스터디카페 **\n");
    printf("1. 예약조회\n");
    printf("2. 예약\n");
    printf("3. 예약수정\n");
    printf("4. 예약삭제\n");
    printf("5. 파일저장\n");
    printf("6. 예약확인\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

void listBook(Book *s,int count){
    
    printf("\n유망 스터디카페 예약 내용\n");
    printf("================================\n");
    for(int i = 0; i < count; i++){
        if(s[i].b_time == -1) continue;
        if(strstr(s[i].name, search)){
            printf("%2d ", i + 1);
            readBook(b[i]);
            count++;
        }

}


int selectDataNo(Book *s, int count){
    int no;
    listProduct(s, count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

void searchName(Book *s, int count){
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);

    printf("\n유망 스터디카페 예약 내용\n");
    printf("================================\n");
    for(int i = 0; i < count; i++){
        if(s[i].s_time == -1) continue;
        if(strstr(s[i].name, search)){
            printf("%2d ", i + 1);
            readBook(s[i]);
            count++;
        }
    }
    if(count == 0) printf("=> 예약된 내용이 없습니다 :)");
    printf("\n");
}

void saveData(Product *s, int count){
    FILE *fp;

    fp = fopen("product.txt", "wt");
    for(int i = 0; i< count; i++){
        if(s[i].price == -1) continue;
        fprintf(fp, "%s %3d %d %d %d", s[i].name, s[i].seat, s[i].date, s[i].b_time, s[i].p_num);
    }
    fclose(fp);
    printf("==> 저장됨 \n");
}

int  loadData(Product*s){
    FILE *fp;

    fp = fopen("book.txt", "rt");
    if(fp == NULL){
        printf("==> 파일이 없음\n");
        return 0;
    }

    int count = 0;
    for(;;count++){
        fscanf(fp, "%s %3d %d %d %d", s[count].name, s[count].seat, s[count].date, s[count].b_time, s[count].p_num);
        if(feof(fp)) break;
    }
    fclose(fp);
    printf("==> 로딩성공!!\n");
    return count;
}


