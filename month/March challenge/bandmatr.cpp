#include <iostream>
#include <vector>
using  namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,one_ct=0;
		cin>>n;
		int N=n;
		n=n*n;
		while(n--){
			int x;
			cin>>x;
			if(x!=0)
			one_ct++;
		}
		one_ct=one_ct-N;
		int bandwidth=0;
		int i=1;
		while(one_ct>0){
			one_ct-=2*(N-i);
			i++;
			bandwidth++;
		}
		cout<<bandwidth<<endl;
	}
	return 0;
}