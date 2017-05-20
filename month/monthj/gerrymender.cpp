#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int o1,o2;
		cin>>o1>>o2;
		std::vector<int> v,v1;
		for(int i=0;i<o1*o2;i++){
			int l; 
			cin>>l;
			v.push_back(l);
		}
		int n=o1*o2;
		//queue<int> Q;
	//	std::vector< vector<int> > states(o1);
		int one_ct=0,flag=0;
		for(int i=0;i<o2;i++){
			if(v[i]==1)		one_ct++;
		}
    //    cout<<one_ct<<" ";
		if(one_ct>o2/2)		flag=1;
		v1.push_back(flag);
		for(int j=0;j<n;j++){
			if(v[j]==1)		one_ct--;
			if(v[(j+o2)%n]==1)		one_ct++;
			if(one_ct>o2/2)		flag=1;
			else    flag=0;
			v1.push_back(flag);
	//		cout<<one_ct<<" ";
		}
// 		for(int i=0;i<n;i++){
// 			cout<<v1[i]<<" ";
// 		}
// 		cout<<endl;
		int flag1=0;
		for(int i=0;i<o2;i++){
			int sum=0;
			for(int j=i;j<o1*o2;j+=o2){
				sum+=v1[j];
			}
			if(sum>o1/2){
			    flag1=1;
			    break;
			}	
		}
		cout<<flag1<<endl;
	}
	return 0;
}