#include <stdio.h>
#include <string.h>
#include "c.h"

int SelectNumber(){
        int select;
        printf("메뉴판**************\n");
        printf("0. 종료\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("5. 저장\n");
        printf("6. 이름으로검색\n");
        printf("7. 색으로검색\n");
        printf("8. 별점평가횟수로검색\n");
        printf("원하는 메뉴는? ");
        scanf("%d", &select);
        printf("\n");

        return select;
}

int addFruit(Fruit *p){
        printf("과일 이름은? ");
        scanf("%s", p->name);
        printf("중량은?(kg) ");
        scanf("%f", &p->num);
        printf("가격은? ");
        scanf("%d", &p->price);
        printf("별점은?(1~5개) ");
        scanf("%d", &p->star);
        printf("별점평가횟수는? ");
        scanf("%d", &p->star_num);
        getchar();
        printf("색깔은?(R,G,B) ");
        scanf("%c", &p->color);
        printf("\n");

        return 1;
}

void showFruit(Fruit p){
        printf("%-s\t\t%-.1f\t\t%-4d\t%-4d\t\t%-4d\t\t%-4c\n",p.name,p.num,p.price,p.star,p.star_num,p.color);
}

int updateFruit(Fruit *p){
        printf("새 과일 이름은? ");
        scanf("%s", p->name);
        printf("새 중량은?(kg) ");
        scanf("%f", &p->num);
        printf("새 가격은? ");
        scanf("%d", &p->price);
        printf("새 별점은?(1~5개) ");
        scanf("%d", &p->star);
        printf("새 별점평가횟수는? ");
        scanf("%d", &p->star_num);
        getchar();
        printf("새 색깔은?(R,G,B) ");
        scanf("%c", &p->color);
        printf("\n");

        return 1;
}

int deleteFruit(Fruit *p){
        int check;
        printf("정말로 삭제하시겠습니까?(취소: 0, 삭제: 1) ");
        scanf("%d", &check);
        if(check == 1){
                strcpy(p->name, "NULL");
                p->num = 0;
                p->price = 0;
                p->star = 0;
                p->star_num = 0;
        }
        printf("\n");

        return check;
}

