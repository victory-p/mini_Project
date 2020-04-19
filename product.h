#pragma once
#include <stdio.h>
#include <string.h>

typedef struct{
  char name[100]; //제품명
  float gram; //제품 중량(g단위)
  float price; //제품 가격
  int price_per_gram; //제품의 그램 당 가격
  float grade; //제품 별점
} Product;

int createProduct(Product *p); //제품 추가
void readProduct(Product p); //하나의 제품 출력
int updateProduct(Product *p); //등록된 제품 수정
int deleteProduct(Product *p); //등록된 제품 삭제
