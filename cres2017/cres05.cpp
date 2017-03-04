#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::vector<int> v,w;
		int lamda = 1;
		int flag=0;
		while(n--){
			int k;
			cin>>k;
			v.push_back(k);
		}
		for(int i=0;i<v.size();i++){
			int k;
			cin>>k;
			w.push_back(k);
			if(w[i]>=v[i])		flag = -1 ;
		}
		if(flag==-1)	cout<<0<<endl;
		else{
			int i=0;
			while(flag!=1)
			{
				i=0;
				while(i<v.size())
				{
					if((lamda-w[i])%v[i]!=0)	break;
					i++;
				}
				if(i==v.size())		flag=1;
				lamda++;
			}
		}
		if(flag==1)		cout<<(lamda-1)<<endl;

	}
	return 0;
}