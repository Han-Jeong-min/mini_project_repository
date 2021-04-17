#include <stdio.h>
#include <string.h>
#include "b.h"

void listFruit(Fruit *p, int count){
        printf("번호\t과일이름\t중량(kg)\t가격\t별점(1~5개)\t별점개수\t색\n");
        for(int i=0; i<count; i++){
                printf("%2d\t", i+1);
                showFruit(p[i]);
        }
}

int SelectFruit(Fruit *p, int count){
        int no;
        listFruit(p, count);
        printf("수정할 번호는?(취소: 0) ");
        scanf("%d", &no);

        return no;
}

void saveData(Fruit *p, int count){
        FILE *fp = fopen("fruit.txt", "wt");

        for(int i=0; i<count; i++){
                if(p[i].price == 0)
                        continue;
                fprintf(fp, "%s %.1f %d %d %d %c\n", p[i].name, p[i].num, p[i].price, p[i].star, p[i].star_num, p[i].color);
        }
        fclose(fp);
        printf("=> 저장됨!\n");
        printf("\n");
}

int loadData(Fruit* p){
        int count = 0, i = 0;
        FILE *fp = fopen("fruit.txt", "rt");

        if(fp == NULL){
                printf("\n");
                printf("=> 파일없음\n");
                return 0;
        }
        for(i=0; i<100; i++){
                fscanf(fp, "%s", p[i].name);
                if(feof(fp))
                        break;
                fscanf(fp, "%f", &p[i].num);
                fscanf(fp, "%d", &p[i].price);
                fscanf(fp, "%d", &p[i].star);
                fscanf(fp, "%d", &p[i].star_num);
                fscanf(fp, "%c", &p[i].color);
        }
        fclose(fp);
        printf("\n");
        printf("=> 로딩 성공!\n");
        printf("\n");
        return i;
}

void colorFruit(Fruit* p, int count){
        int scnt = 0;
        char search;

        getchar();
        printf("검색할 색깔은?");
        scanf("%c", &search);

        printf("번호\t과일이름\t중량(kg)\t가격\t별점(1~5개)\t별점개수\t색\n");
        printf("=======================================================\n");
        for(int i=0; i<count; i++){
                if(p[i].price == 0)
                        continue;
                if(p[i].color == search || p[i].color + 32 == search || p[i].color - 32== search){
                        printf("%2d\t", i+1);
                        showFruit(p[i]);
                        scnt++;
                }
        }
        if(scnt == 0)
                printf("=> 검색한 색의 과일이 없습니다!\n");
        printf("\n");
}

void searchFruit(Fruit* p, int count){
        int scnt = 0;
        char search[20];

        printf("검색할 이름?");
        scanf("%s", search);

        printf("번호\t과일이름\t중량(kg)\t가격\t별점(1~5개)\t별점개수\t색\n");
        printf("=======================================================\n");
        for(int i=0; i<count; i++){
                if(p[i].price == 0)
                        continue;
                if(strstr(p[i].name, search)){
                        printf("%2d\t", i+1);
                        showFruit(p[i]);
                        scnt++;
                }
        }
        if(scnt == 0)
                printf("=> 검색한 과일이 없습니다!");
        printf("\n");
}

void starFruit(Fruit* p, int count){
        int scnt = 0;
        int search;

        printf("몇 개이상의 별점평가?");
        scanf("%d", &search);

        printf("번호\t과일이름\t중량(kg)\t가격\t별점(1~5개)\t별점개수\t색\n");
        printf("=======================================================\n");
        for(int i=0; i<count; i++){
                if(p[i].price == 0)
                        continue;
                if(p[i].star_num >= search){
                        printf("%2d\t", i+1);
                        showFruit(p[i]);
                        scnt++;
                }
        }
        if(scnt == 0)
                printf("=> 검색한 과일이 없습니다!");
        printf("\n");
}
