#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct{
	char hoten[30];
	int masv;
	float d1, d2, d3;
	
}Data;
typedef struct tagNote{
	Data infor;
	struct tagNote *link;
	
}Node;
typedef struct{
	Node *pHead;
	Node *pTail;
	int spt;
}LList;
void initList(LList *L){
	L->pHead =NULL;
	L->pTail = NULL;
	L->spt =0;
	
}
int emptyList(LList L){
	return (L.spt==0);
}
void insert_Head(LList *L, Data x){
	Node *pp;
	pp = (Node*)malloc (sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
	   L->pHead = pp;
	   L->pTail = pp;
	   
	}else{
		pp->link= L->pHead;
		L->pHead = pp;
		
	}
	L->spt++;
}
void nhap(Data *x){
	printf("Nhap ma sv: ");
	scanf("%d",&(x->masv));
	if(x->masv>0){
		printf("Nhap ma sv: ");
		scanf("%s",(x->hoten));
		printf("Nhap diem mon 1: ");
		scanf("%f",&(x->d1 ));
		printf("Nhap diem mon 2: ");
		scanf("%f",&(x->d2));
		printf("Nhap diem mon 3: ");
		scanf("%f",&(x->d3));
	}
}
void insert_Tail(LList *L, Data x){
    Node *pp = (Node*)malloc(sizeof(Node));

    pp->infor = x;
    pp->link = NULL;

    if(emptyList(*L)){
        L->pHead = pp;
        L->pTail = pp;
    }
    else{
        L->pTail->link = pp;
        L->pTail = pp;
    }

    L->spt++;
}
void xuat(Data x){
	printf("Ten: %s,Ma: %d, Diem 1: %.2f,Diem 2: %.2f,Diem 3: %.2f\n",x.hoten,x.masv,x.d1,x.d2,x.d3);
}
void sapxepten(LList *L){
	Node *p, *q;
	Data temp;
	for(p= L->pHead; p!=NULL; p=p->link){
		for(q=p->link;q!=NULL; q = q->link){
			if(strcmp(p->infor.hoten, q->infor.hoten)>0){
				temp =p->infor;
				p->infor = q->infor;
				q->infor = temp;
			}
		}
	}
}
void processList(LList L){
	Node *pp = L.pHead;
	while (pp!= NULL){
		xuat(pp->infor);
		pp= pp->link;
	}
}
void Insert_After(LList *L, int masv, Data x){
    Node *p = L->pHead;

    while(p != NULL && p->infor.masv != masv){
        p = p->link;
    }

    if(p == NULL){
        printf("Khong tim thay sinh vien co ma %d\n", masv);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->infor = x;
    newNode->link = p->link;
    p->link = newNode;

    if(p == L->pTail){
        L->pTail = newNode;
    }

    L->spt++;
}
int main(){
	LList L;
	int ktra =0;
	Data x;
	initList(&L);
	do{
		printf("\nChuong trinh lam viec voi DSLK don SV\n");
		printf("\n1: Them nut vao dau danh sach");
		printf("\n2: Them nut vao cuoi danh sach");
		printf("\n3: Them nut vao sau mot nut khac trong danh sach");
		printf("\n4: Sap xep sinh vien theo ten: "); 
		printf("\n9: Duyet danh sach");
		printf("\n0: Thoat");
		printf("\nMoi ban chon: ");
		int chon;
		scanf("%d",&chon);
		switch (chon){
			case 1: 
			printf("Nhap so thong tin sinh vien can them\n");
			nhap(&x);
			if(x.masv>0){
				insert_Head(&L,x);
			}
			break;
			case 2:
				printf("Nhap so thong tin sinh vien can them\n");
			nhap(&x);
			if(x.masv>0){
				insert_Tail(&L,x);
			}
				break;
			case 3:
				printf("Nhap so thong tin sinh vien can them\n");
				nhap(&x);
				int masvmoi;
				scanf("%d",&masvmoi);
				Insert_After(&L,masvmoi,x);
				break;
			case 4:
				sapxepten(&L);
				break;
			case 9:
			processList(L);
			break;
			case 0:
				printf("Siuuuuuuuuu\n");
			ktra =1 ;
			
		}
	}while(ktra ==0);
}
