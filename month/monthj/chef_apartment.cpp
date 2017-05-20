#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,x,zstart=-1,zcount=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x==0){
				zcount++;
				if(zstart==-1)		zstart=i;
			}
		}
		cout<<zcount*1000+(n-zstart+1)*100<<endl;
	}
	return 0;
}