#include <stdio.h>
#include <string.h>
#include "b.h"
//#define DEBUG

int main(){
#ifdef DEBUG
        printf("==>DEBUGMODE\n");
#endif
        Fruit flist[100];
        int count = 0, menu;
        int index = 0;

        count = loadData(flist);
        index = count;

        while(1){
                int i = 0;
                menu = SelectNumber();
                if(menu == 0){
                        break;
                }
                if((menu == 1 || menu == 3 || menu ==4) && flist[i].star_num == 0){
                        continue;
                }
                if(menu == 2){
                        count += addFruit(&flist[index++]);
                        i++;
                }
                else if(menu == 1){
                        listFruit(flist, index);
                        printf("\n");
                }
                else if(menu == 3){
                        int no = SelectFruit(flist, index);
                        if(no == 0){
                                printf("=>취소되었습니다.\n");
                                continue;
                        }
                        updateFruit(&flist[no-1]);
                }
                else if(menu == 4){
                        int no = SelectFruit(flist, index);
                        if(no == 0){
                                printf("=> 취소되었습니다.\n");
                        }
                        else{
                                int delete;
                                delete = deleteFruit(&flist[no-1]);
                                if(delete == 1){
                                        printf("=> 삭제되었습니다.\n");
                                        count--;
                                        }
                                else
                                        printf("=> 취소되었습니다.\n");
                        }
                        printf("\n");
                }
                else if(menu == 5){
                        saveData(flist, index);
                }
                else if(menu == 6){
                        searchFruit(flist, index);
                }
                else if(menu == 7){
                        colorFruit(flist, index);
                }
                else if(menu == 8){
                        starFruit(flist, index);
                }
        }
        printf("=> 종료\n");
        return 0;
}

