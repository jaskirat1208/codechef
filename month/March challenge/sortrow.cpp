#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	std::vector<int> v;
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		v.clear();
		cout<<endl;
	}
	return 0;
}