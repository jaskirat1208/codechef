#include <iostream>
#include <vector>
using namespace std;
int d(int x1,int x2,std::vector<int> v){
	int d=0;
	for(int i=x1;i<x2;i++){
		d+=v[i];
	}
	return d;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::vector<int> v;
		for( int i=0;i < n-1 ; i++){
			int x;
			cin>>x; 
			v.push_back(x);
		}
		for( int i=0;i < n-2 ; i++){
			int x;
			cin>>x; 
			//v.push_back(x);
		}
		for( int i=0;i < n-3 ; i++){
			int x;
			cin>>x; 
		//	v.push_back(x);
		}
		int sum=0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				sum+=d(i,j,v);
			}
		}
		cout<<sum<<endl;

	}
	return 0;
}