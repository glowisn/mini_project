#include "product.h"

int createProduct(Product *s){
	printf("이름은? ");
	scanf(" %s",s->name);
	printf("무게는?(g) ");
	scanf("%d",&s->weight);
	printf("가격은?(won) ");
	scanf("%d",&s->price);
	printf("점수는?(1~5) ");
	scanf("%d",&s->score);
	return 1;
}

int updateProduct(Product *s){
	printf("이름은? ");
        scanf(" %s",s->name);
        printf("무게는?(g) ");
        scanf("%d",&s->weight);
        printf("가격은?(won) ");
        scanf("%d",&s->price);
        printf("점수는?(1~5) ");
        scanf("%d",&s->score);
	printf("수정성공\n");
        return 1;
}

void readProduct(Product s){
	if(s.price == -1) return;
	printf("%s   %5d %6d %3d\n",s.name,s.weight,s.price,s.score);
	return;
}

int deleteProduct(Product *s){
	s->price = -1;
	printf("삭제됨!\n");
	return 1;
}

int selectMenu(){
	int menu;
	printf("물품관리시스템\n");
        printf("1.조회\n");
        printf("2.추가\n");
        printf("3.수정\n");
        printf("4.삭제\n");
	printf("5.저장\n");
	printf("6.이름검색\n");
	printf("7.무게검색\n");
	printf("8.가격검색\n");
	printf("9.별점검색\n");
        printf("0.종료\n");
        printf("원하는 메뉴는?:");
	scanf(" %d",&menu);
	return menu;
}

void saveData(Product *s,int count){
	FILE *fp;

	fp = fopen("Product.txt","wt");
	for(int i=0;i < count; i++){
		if(s[i].price != -1)
			fprintf(fp," %s %d %d %d\n",s[i].name,s[i].weight,s[i].price,s[i].score);
	}
}

int loadData(Product s[]){
	int count = 0;
	FILE *fp;

	fp = fopen("Product.txt","rt");
	if(fp == NULL){
		printf("파일이 없음!\n");
		return 0;
	}

	for(;;count++){
		fscanf(fp,"%s %d %d %d",s[count].name,&s[count].weight,&s[count].price,&s[count].score);
		if(feof(fp))break;
	}

	fclose(fp);
	printf("로딩 성공!\n");

	return count;
}

void searchName(Product *s,int count){
	int sc = 0;
	char search[20];

	printf("검색할 이름?\n");
	scanf("%s", search);

	printf("\n번호 이름 무게 가격 별점\n");
	printf("============================\n");
	for(int i=0;i<count;i++){
		if(s[i].price != -1){
			if(strstr(s[i].name, search)){
				printf("%2d",i+1);
				readProduct(s[i]);
				sc++;
			}
		}
	}
	if(sc==0)
		printf("검색된 데이터 없음!\n");
}

void searchWeight(Product *s, int count){
	int sc = 0;
	int searchMin =0;
	int searchMax =0;

	printf("최소무게:");
	scanf(" %d",&searchMin);
	printf("최대무게:");
	scanf(" %d",&searchMax);

	printf("\n번호 이름 무게 가격 별점\n");
	printf("============================\n");
	for(int i=0;i<count;i++){
		if(s[i].price != -1){
			if(s[i].weight >= searchMin && s[i].weight <= searchMax){
				printf("%2d",i+1);
				readProduct(s[i]);
				sc++;
			}
		}
	}
	if(sc==0)
		printf("검색된 데이터 없음!\n");
}

 	
void searchPrice(Product *s, int count){
	int sc = 0;
	int searchMin =0;
	int searchMax =0;

	printf("최소가격:");
	scanf(" %d",&searchMin);
	printf("최대가격:");
	scanf(" %d",&searchMax);

	printf("\n번호 이름 무게 가격 별점\n");
	printf("============================\n");
	for(int i=0;i<count;i++){
		if(s[i].price != -1){
			if(s[i].price >= searchMin && s[i].price <= searchMax){
				printf("%2d",i+1);
				readProduct(s[i]);
				sc++;
			}
		}
	}
	if(sc==0)
		printf("검색된 데이터 없음!\n");
}

void searchScore(Product *s, int count){
	int sc = 0;
	int searchMin =0;
	int searchMax =0;

	printf("최소점수:");
	scanf(" %d",&searchMin);
	printf("최대점수:");
	scanf(" %d",&searchMax);

	printf("\n번호 이름 무게 가격 별점\n");
	printf("============================\n");
	for(int i=0;i<count;i++){
		if(s[i].price != -1){
			if(s[i].score >= searchMin && s[i].score <= searchMax){
				printf("%2d",i+1);
				readProduct(s[i]);
				sc++;
			}
		}
	}
	if(sc==0)
		printf("검색된 데이터 없음!\n");
}
