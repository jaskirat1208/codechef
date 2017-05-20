#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n,med;
	vector<int> v;
	cin>>t;
	while(t--){
		cin>>n;
		v.clear();
		for (int i = 0; i < 2*n; ++i)
		{
			int x;
			cin>>x;
			v.push_back(x);	
		}
		sort(v.begin(), v.end());
		cout<<v[3*n/2]<<endl;
		for (int i = 0; i < n; ++i)
		{
			cout<<v[i]<<" "<<v[n+i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}