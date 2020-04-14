#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];  //이름
    int weight;     //중량
    int price;      //가격
    int score;      //별점
} Product;

int createProduct(Product *s); //제품을 추가하는 함수
int updateProduct(Product *s); //제품을 수정하는 함수
void readProduct(Product s); //하나의 제품 출력 함수
int deleteProduct(Product *s); //제품을 삭제하는 함수
//void listProduct(Product *slist, int count); // 제품 리스트 출력 함수
void saveData(Product *s, int count); // 데이터 저장 함수
int loadData(Product s[]); //데이터 불러오기 함수
void searchName(Product *s, int count); // 이름으로 검색
void searchWeight(Product *s, int count); // 중량으로 검색
void searchPrice(Product *s, int count); // 가격으로 검색
void searchScore(Product *s, int count); // 별점으로 검색
int selectMenu();
