#include <iostream>
#include <vector>
using namespace std;
std::vector<long long int> v,v1;
long long int check(long long int l,long long int r,long long int k){
	long long int mid=(l+r)/2;
	if( v1[mid] >= mid-l+1 ){
		//cout<<" "<<<<" "<<<<endl;
		if(v1[mid+k-v1[mid]+v1[l]-1]>=k+v1[l]-1 && v[mid+k-v1[mid]+v1[l]-1]==v[mid])	return v[mid];
	}
	else {
		if(v1[mid+k-v1[mid]]==k)	return v[mid];
	}
	//
	return -1;
}
int main(int argc, char const *argv[])
{
	long long int n,m;
	cin>>n>>m;
	for(long long int  i=0;i<n;i++){
		v1.push_back(1);
	}
	while(n--){
		long long int x;
		cin>>x;
		v.push_back(x);
	}
	for(long long int i=1;i<v.size();i++){
		if(v[i]==v[i-1])	v1[i]=v1[i-1]+1;
	}
	while(m--){
		long long int l,r,k;
		cin>>l>>r>>k;
		cout<<check(l-1,r-1,k)<<endl;
 
	}	
	return 0;
}  