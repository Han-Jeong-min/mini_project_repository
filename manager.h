//manager.h
#include "c.h"

void listFruit(Fruit *p, int count);//전체 제품을 보여주는 함수
int SelectFruit(Fruit *p, int count);//수정할 제품 번호 검색 함수
void saveData(Fruit* p, int count);//데이터를 저장 함수
int loadData(Fruit* p);//데이터를 불러오는 함수
void colorFruit(Fruit* p, int count);//색갈에 따른 과일을 검색하는 함수
void searchFruit(Fruit* p, int count);//과일이름 검색 함수
void starFruit(Fruit* p, int count);//별점 횟수로 검색 함수
