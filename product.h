//product.h
typedef struct{
        char name[30];
        float num;
        int price;
        int star;
        int star_num;
        char color;
}Fruit;

int SelectNumber();//메뉴 고르기 함수
int addFruit(Fruit *p);//제품을 추가하는 함수
void showFruit(Fruit p);//제품 하나를 보여주는 함수
int updateFruit(Fruit *p);//추가된 제품을 수정하는 함수
int deleteFruit(Fruit *p);//제품 삭제 함수
