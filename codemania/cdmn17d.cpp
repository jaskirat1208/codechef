#include <stdio.h>
 
long int a,b;
 
void swap(long int a , long int b){
	long int temp;
	temp=a; a=b; b=temp;
	return; }
 
int main(){
	int t;
	//scanf("%d",&t);
	//while(t--){
		long int zz,n,k,i,j;
		scanf("%ld",&n);
		scanf("%ld",&k);
		long int array[num+1],numberr=0;
		int x;
		for (i = 0; i < num; ++i){
			scanf("%d",array+i);
		}
 
		for (i = 0; i < k; ++i){
			scanf("%ld %ld",&a,&b);
			x=0;
			if(a>b){
				swap(a,b); }
			while(x==0){
 
				if(array[a]==a){
					array[a]=array[b];
					x=1;}
				else{ //array[a]!=a
					zz = array[a];
					array[a]= array[b]; 
					a = zz;
					}
				//printf(" yupp ");
			}
			//printf("while end :D \n");
		}
		for (i = 0; i < num; ++i){
			if(array[i]==i){
				numberr++;
			}
		}
		printf("%ld\n",numberr);
	//}
 
	return 0;	
} 
//Comments 
