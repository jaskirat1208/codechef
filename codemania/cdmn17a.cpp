#include <iostream>
#include <vector>
using namespace  std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		long long int k,n,sum=0;
		cin>>n>>k;
		std::vector<long long int > v;
		while(n--){
			long long int x;
			cin>>x;
			if(x%k!=0){
				if(x>k)
					v.push_back(x%k+k);
				else{
					v.push_back(x);
				}
			}
		}
		for(int i=0;i<v.size();i++){
			//cout<<v[i]<<" ";
			if(v[i]>k)
				sum+=min(v[i]-k,2*k - v[i]);
				// cout<<<<" ";
			else	sum+=k- v[i]; //cout<< <<" ";
		}

		cout<<sum<<endl;
	}
	return 0;
}