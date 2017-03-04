#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,sum1=0,sum2=0;
		cin>>n;
		int N=n;
		while(n>0){
			int x,y;
			cin>>x;
			if(n==1){
				sum1+=x;
				break;
			}
			cin>>y;
			sum1+=x;
			sum2+=y;
			
			

			
			n=n-2;
		}
		while(N>0){
			int x,y;
			cin>>x;
			if(N==1){
				sum2+=x;
				break;
			}
			cin>>y;
			sum1+=y;
			sum2+=x;			
			N=N-2;
		}
		if(sum1<sum2)	cout<<sum1<<endl;
		else	cout<<sum2<<endl;
//		cout<<sum1<<" "<<sum2<<endl;
	}
	return 0;
}