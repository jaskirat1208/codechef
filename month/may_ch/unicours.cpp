#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n,max,x;
	// int *arr;
	// int *mark;
	cin>>t;
	while(t--){
		cin>>n;
		max=0;
		// arr=(int*)calloc(n,sizeof(int));
// 		mark=(int*)calloc(n,sizeof(int));
		for (int i = 0; i < n; ++i)
		{
			cin>>x;
			if (x >= max)
			{
				max=x;
			}		
		}
		cout<<n-max<<endl;
	}
	return 0;
}