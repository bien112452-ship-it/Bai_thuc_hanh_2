#include <stdio.h>
int main(){
	int m ,n;
	float a[100][100];
	scanf("%d%d", &m, &n);
	for(int i=0; i< m ; i++){
		for(int j =0;j< n; j++){
			scanf("%f", (*( a+i)+ j));
		}
	}
	printf("Ma tran vua nhap la: ");
	for(int i =0; i< m ; i++){
		for(int j =0; j<n;j++){
			printf("%.2f ",*(*(a+i)+j));
		}
		printf("\n");
	}
	return 0;
}
