#include "product.h"
#include "manager.h"

void listProduct(Product *slist, int count){
	printf("\n번호 이름 무게 가격 별점\n");
	printf("===========================\n");
	for(int i=0; i <count; i++){
		if(slist[i].price == -1) continue;
		printf("%2d ",i+1);
		readProduct(slist[i]);
	}
}


int selectDataNo(Product *s, int count){
	int no;
	listProduct(s, count);
	printf("번호는?(취소:0)?");
	scanf(" %d",&no);
	return no;
}


