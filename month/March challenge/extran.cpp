#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	std::vector<long long int> v;

	while(t--){
		int n;
		///	std::vector<long long int> v;

		cin>>n;
		while(n--){
			long long int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		if(v[1] - v[0] != 1)	cout<<v[0]<<endl;
		else{
			int flag=0;
			for(int i=0;i<v.size()-1;i++){
				if(v[i+1]==v[i]){
					cout<<v[i]<<endl;
					flag=1;
					break;
				}
			}
			if(flag==0){
				cout<<v[v.size()-1]<<endl;
			}
		}		
		v.clear();
	}
	
	return 0;
}