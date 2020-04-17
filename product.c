#include "product.h"

int createProduct(Product *p){
  printf("제품명은? ");
  getchar();
  scanf("%[^\n]s", p->name);
  printf("제품 중량은? ");
  scanf("%f", &p->gram);
  printf("제품 가격은? ");
  scanf("%f", &p->price);
  printf("제품 별점은? ");
  scanf("%f", &p->grade);
  printf("=> 추가 완료\n");

  return 1;
}

void readProduct(Product p){
  if(p.gram == -1 && p.price == -1) return;
  p.price_per_gram = p.price/p.gram*10;

  printf("%s / %4.fg / %4.f원 / 10g당 %4d원 / %4.1f\n", p.name, p.gram, p.price, p.price_per_gram, p.grade);
}

int updateProduct(Product *p){
  printf("제품명은? ");
  getchar();
  scanf("%[^\n]s", p->name);
  printf("제품 중량은? ");
  scanf("%f", &p->gram);
  printf("제품 가격은? ");
  scanf("%f", &p->price);
  printf("제품 별점은? ");
  scanf("%f", &p->grade);
  printf("=> 수정 완료\n");

  return 1;
}

int deleteProduct(Product *p){
  p->gram = -1;
  p->price = -1;
    
  printf("=> 삭제 완료\n");

  return 1;
}
