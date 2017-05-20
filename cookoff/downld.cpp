#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--){
		int n,k,t=0,flag=0,cost=0;
		cin>>n>>k;
		std::vector<pair<int,int> > v;
		for (int i = 0; i < n; ++i)
		{
			int t1,d1;
			cin>>t1>>d1;
			t+=t1;
			if(flag==1){
				cost+=t1*d1;
			}
			else if(t>k){
				cost+=(t-k)*d1;
				flag=1;
			}
		}
		cout<<cost<<endl;
	}
	return 0;
}