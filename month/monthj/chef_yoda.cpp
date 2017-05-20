#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;
float fact(int n){
    if(n==0) return 1;
    if (n>0) return n*fact(n-1);
};

float NCR(int n,int r){
    if(n==r) return 1;
    if (r==0&&n!=0) return 1;
    else return (fact(n))/(fact(r)*fact(n-r));
};

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		double ans=0;
		int m,n,p,k;
		cin>>m>>n>>p>>k;
		if(m*n%2==1)	ans=0;
		else if(m%2==0 && n%2==0)	ans=1;
		else{
			double sum=0;
			for(int i=0;i<p;i++){
				sum+=NCR(k,i);
				//cout<<sum<<" ";
			}

			sum=sum/pow(2,k);
			//cout<<``
			ans=1-sum;
		}
		printf("%.6f\n",ans );
	}
	return 0;
}