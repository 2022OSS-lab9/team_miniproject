#include "book.h"

int main(void){
    Book slist[100];
    int curcount = 0;
    int count = 0, menu;

    //count = loadData(slist);
    curcount = count;
 
    while (1){
        menu = selectMenu();

        if (menu == 0) break;
        if (menu == 1){
            if(count > 0){
                listBook(slist,curcount);
            }else{
                printf("데이터가 없습니다! \n");
            }
        }
        else if (menu == 2){
            count += newBook(&slist[curcount]);
            curcount ++;
        }
        else if (menu == 3){
            int no = selectDataNo(slist,curcount);
            if(no == 0){
                printf("=> 취소됨 ! \n");
                continue;
            }
            updateBook(&slist[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(slist,curcount);
            if(no == 0){
                printf("=> 취소됨 ! \n");
                continue;
            }

            int deleteok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(deleteBook(&slist[no-1])){
                    count--;
                }
            }
        }
        else if (menu == 5){
            if(count == 0)
                printf("=> 데이터 없음!\n");
            else 
                saveData(slist, curcount);
        }
        else if (menu == 6){
            if(count == 0)
                printf("=> 데이터 없음!\n");
            else 
                searchName(slist, curcount);
        }
    }
    printf("종료됨!\n");
    return 0;
}
