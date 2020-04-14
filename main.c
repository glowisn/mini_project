#include <stdio.h>
#include "product.h"
#include "manager.h"

int main(void){
	Product slist[100];
	int curcount = 0;

	//Product s;
	int count = 0 , menu;

	count = loadData(slist);
	curcount = count;	

	while(1){
		#ifdef DEBUG
			printf("Debug: %s call selectMenu\n",__FILE__);
		#endif
		menu = selectMenu();
		if (menu == 0) break;
		else if (menu == 1){
			if(count > 0){
			#ifdef DEBUG
				printf("Debug: %s call listProduct\n",__FILE__);
			#endif
				listProduct(slist,curcount);
			}else{
				printf("데이터가 없습니다!\n");
			}
		}else if (menu == 2){
			#ifdef DEBUG
				printf("Debug: %s call createProduct\n",__FILE__);
			#endif
			count += createProduct(&slist[curcount++]);
		}else if (menu == 3){
			#ifdef DEBUG
				printf("Debug: %s call selectDataNo\n",__FILE__);
			#endif
			int no = selectDataNo(slist,curcount);
			if(no == 0){
				printf("취소됨!\n");
				continue;
			}
		#ifdef DEBUG
			printf("Debug: %s call updateProduct\n",__FILE__);
		#endif
		 updateProduct(&slist[no-1]);
		}
		else if (menu == 4) {
			#ifdef DEBUG
				printf("Debug: %s call selectDataNo\n",__FILE__);
			#endif
			int no = selectDataNo(slist, curcount);
			if(no == 0){
				printf("취소됨!");
				continue;
			}
			#ifdef DEBUG
				printf("Debug: %s call deleteProduct\n",__FILE__);
			#endif	
		deleteProduct(&slist[no-1]);
		count--;
		}else if(menu == 5){
			if(count == 0)
				printf("데이터가 없습니다!\n");
			else
			#ifdef DEBUG
				printf("Debug: %s call saveData\n",__FILE__);
			#endif
				saveData(slist, curcount);
				printf("저장성공!\n");
		}else if(menu == 6){
			#ifdef DEBUG
				printf("Debug: %s call searchName\n",__FILE__);
			#endif
				searchName(slist,curcount);
		}else if(menu ==7){
			#ifdef DEBUG
				printf("Debug: %s call searchWeight\n",__FILE__);
			#endif
				searchWeight(slist,curcount);
		}else if(menu == 8){
			#ifdef DEBUG
				printf("Debug: %s call searchPrice\n",__FILE__);
			#endif
				searchPrice(slist,curcount);
		}else if(menu == 9){
			#ifdef DEBUG
				printf("Debug: %s call searchScore\n",__FILE__);
			#endif
				searchScore(slist,curcount);
		}
	}

	printf("종료됨!\n");
	return 0;
}
