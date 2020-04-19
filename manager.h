#pragma once
#include "product.h"

void listProduct(Product *p, int count); //등록된 제품 전체 출력
int selectProductNo(Product *p, int count); //제품 번호 선택
void searchName(Product *p, int count); //제품 이름 검색
void searchPrice(Product *p, int count); //제품 가격 검색
void searchGrade(Product *p, int count); //제품 별점 검색
void saveData(Product *p, int count); //제품 리스트 파일 저장
int loadData(Product p[]); //등록된 제품 리스트 데이터 불러오기
