#include "product.h"
#include "manager.h"

void listProduct(Product *p, int count){
  printf("No / Product Name / Weight / Price / Standard Price / Grade\n");
  printf("============================================\n");
  
  for(int i=0; i<count; i++){
    if(p[i].gram == -1) continue;
    printf("%d ", i+1);
    readProduct(p[i]);
  }
  printf("\n");
}

int selectProductNo(Product *p, int count){
  int num;
  listProduct(p, count);
  printf("선택할 제품 번호는?(취소 : 0) ");
  scanf("%d", &num);

  return num;
}

void searchName(Product *p, int count){
  int scount = 0;
  char search[30];
  printf("검색할 제품명은? ");
  scanf("%s", search);
  printf("\n No Name Kor Eng Math Sum Avg\n");
  printf("============================\n");
  for(int i=0; i<count; i++){
    if(p[i].price != -1){
      if(strstr(p[i].name, search)){
        printf("%2d ", i+1);
        readProduct(p[i]);
        scount++;
      }
    }
  }
  if(scount==0) printf("=> 검색된 제품 정보 없음\n");
}

void searchPrice(Product *p, int count){
  int scount = 0;
  int search;
  printf("검색할 제품가격은? ");
  scanf("%d", &search);
  printf("\n No Name Kor Eng Math Sum Avg\n");
  printf("============================\n");
  for(int i=0; i<count; i++){
    if(p[i].price != -1){
      if(p[i].price == search){
        printf("%2d ", i+1);
        readProduct(p[i]);
        scount++;
      }
    }
  }
  if(scount==0) printf("=> 검색된 제품 정보 없음\n");
}

void searchGrade(Product *p, int count){
  int scount = 0;
  double search;
  printf("=> 검색할 제품별점은? ");
  scanf("%lf", &search);
  printf("No / Product Name / Weight / Price / Standard Price / Grade\n");
  printf("============================================\n");
  for(int i=0; i<count; i++){
    if(p[i].price != -1){
      if(p[i].grade == search){
        printf("%2d ", i+1);
        readProduct(p[i]);
        scount++;
      }
    }
  }
  if(scount==0) printf("=> 검색된 제품 정보 없음\n");
}

void saveData(Product *p, int count){
  FILE *savefile;

  savefile = fopen("product.txt", "wt");
  for(int i=0; i<count; i++){
    if(p[i].price != -1) fprintf(savefile, "%s %.1f %.1f %.1f\n", p[i].name, p[i].gram, p[i].price, p[i].grade);
  }
  fclose(savefile);
  printf("=> 파일 저장됨\n");
}
