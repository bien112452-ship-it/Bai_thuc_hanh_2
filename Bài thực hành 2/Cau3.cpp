#include <stdio.h>
#include <string.h>
typedef struct{
	char ten[30];
	int masv;
	float d1, d2, d3;
	
}SV;
void nhap( SV *p, int n){
	for(int i =0; i< n; i++){
		scanf("%s", (p+i)->ten);
		scanf("%d",&(p+i)->masv);
		scanf("%f",&(p+i)->d1); 
		scanf("%f",&(p+i)->d2); 
		scanf("%f",&(p+i)->d3); 
	}
} 
void xuat(SV *p, int n){
	for(int i = 0; i<n; i++){
		printf("Danh sach sinh vien: ");
	printf("Ten : %s\n",(p+i)->ten);
	printf("Ma sinh vien %d\n", (p+i)-> masv);
	printf("D1: %.2f\n",(p+i)-> d1);
	printf("D2: %.2f\n",(p+i)-> d2);
	printf("D3: %.2f\n",(p+i)-> d3);
	
	}
	
}
int main(){
	int n;
	SV ds[100];
	scanf("%d",&n);
	nhap(ds, n);
	xuat(ds, n);
	return 0;
}
