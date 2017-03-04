#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		std::transform(str.begin(),str.end(),str.begin(),::tolower);
		//cout<<str; 	
		int arr[256];
		for(int i=0;i<256;i++)	arr[i]=0;
		for(int i=0;i<str.size();i++){
			arr[str[i]]++;
		}
		int odd_ct=0;
		for(int i=0;i<256;i++){
			if(arr[i]%2!=0){
				odd_ct++;
			}
		}
		// for(int i=0;i<256;i++){
		// 	cout<<" "<<arr[i]<<" ";
		// }
		if(odd_ct<=1 )	cout<<"Yes\n";
		else	cout<<"No\n";
		//else if(odd_ct==1){}
	}
	return 0;
}