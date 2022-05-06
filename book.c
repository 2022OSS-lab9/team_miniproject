#include "book.h"

int updateProduct(Book *b){

    printf("\n");
    printf("이름이 무엇입니까? ");
    scanf("%[^\n]s",b->name);

    printf("원하는 좌석은 어디입니까? ");
    scanf("%d",&b->seat);

    printf("원하는 날짜는 언제입니까? (5월 5일 -> 0505)");
    while(1){
        scanf("%d",&b->date);
        if(sizeof(b->date) > 4){
            printf("입력이 잘못되었습니다. 4자리로 입력해주세요");
        }
        else break;
    }
    
    printf("원하는 시간은 언제입니까? (17시 50분 -> 1750)");
    while(1){
        scanf("%d",&b->b_time);
        if(sizeof(b->date) > 4){
            printf("입력이 잘못되었습니다. 4자리로 입력해주세요");
        }
        else break;
    }

    printf("휴대폰 번호 뒷자리는 무엇입니까? ");
    while(1){
        scanf("%d",&b->p_num);
        if(sizeof(b->date) > 4){
            printf("입력이 잘못되었습니다. 4자리로 입력해주세요");
        }
        else break;
    }
    
    printf("==> 수정됨!\n");
    return 1;
};

int deleteProduct(Book *b){
    b->b_time[0] = -1;
    b->p_num[0] = -1;
    printf("==> 삭제됨!\n");
    return 0;
}