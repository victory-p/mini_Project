#include "product.h"
#include "manager.h"

int selectMenu(){
  int menu;
  
  printf("\n=============Product Management=============\n");
  printf("1. 제품 정보 조회\n");
  printf("2. 제품 정보 추가\n");
  printf("3. 제품 정보 수정\n");
  printf("4. 제품 정보 삭제\n");
  printf("5. 제품 파일 저장\n");
  printf("6. 제품 정보 검색\n");
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴는? ");
  scanf("%d", &menu);

  return menu;
}

int main(){
  Product p[100];
  int curcount = 0;
  int count = 0;
  int menu;

  count = loadData(p);
  curcount = count;
  
  while(1){
    menu = selectMenu();
    if(menu == 0) break;
    if(menu == 1){
      if(count>0){
      #ifdef DEBUG
      printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
      #endif
        listProduct(p, curcount);
      }
      else{
        printf("No / Product Name / Weight / Price / Standard Price / Grade\n");
        printf("============================================\n");
	printf("=> 데이터 없음\n");
      }
    }
    else if(menu == 2){
      #ifdef DEBUG
      printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
      #endif
      count += createProduct(&p[curcount++]);
    }
    else if(menu == 3){
      #ifdef DEBUG
      printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
      #endif
      int num = selectProductNo(p, curcount);
      if(num == 0){
        printf("=> 선택 취소됨\n");
        continue;
      }
      #ifdef DEBUG
      printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
      #endif
      updateProduct(&p[num-1]);
    }
    else if(menu == 4){
      #ifdef DEBUG
      printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
      #endif
      int num = selectProductNo(p, curcount);
      if(num == 0){
        printf("=> 선택 취소됨\n");
        continue;
      }
      int check;
      printf("정말 삭제하시겠습니까?(Yes : 1) ");
      scanf("%d", &check);
      if(check == 1){
        #ifdef DEBUG
        printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
        #endif
        if(deleteProduct(&p[num-1])) count--;
      }
      else{
        printf("=> 삭제 취소됨\n");
      }
    }
    else if(menu == 5){
      if(count == 0) printf("=> 데이터 없음\n");
      else{
        #ifdef DEBUG
        printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
        #endif
        saveData(p, curcount);
      }
    }
    else if(menu == 6){
      int option;
      if(count == 0) printf("=> 데이터 없음\n");
      else{
        printf("=> 원하는 검색 옵션은?(1 : 이름검색 / 2 : 가격검색 / 3 : 별점검색) ");
        scanf("%d", &option);

        if(option == 1){
          #ifdef DEBUG
          printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
          #endif
          searchName(p, curcount);
        }
        else if(option == 2){
          #ifdef DEBUG
          printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
          #endif
          searchPrice(p, curcount);
        }
        else if(option == 3){
          #ifdef DEBUG
          printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
          #endif
          searchGrade(p, curcount);
        }
      }
    }
  }
  printf("=> 종료됨\n");

  return 0;
}
