#include <iostream>
#include <vector>
#include <string>
using namespace std;
std::vector<long int> v;
std::vector<long long int> v1;

void update(int i,long int k){
	v[i-1]=k;
}
long long int sum_f(int l,int r){
	int sum=0;
	for(int i=l;i<r;i++){
		sum+=v[i];
	}
	return sum;
}
long long int max_f(int l,int r){
	int max=v[l];
	for(int i=l;i<r;i++){
		if(max < v[i])	max=v[i];
	}
	return max;
}
long long int min_f(int l,int r){
	int min=v[l];
	for(int i=l;i<r;i++){
		if(min > v[i])	min=v[i];
	}
	return min;
}
long long int sec_max_f(int l,int r){
	long int max=v[l];
	long long int sec_max=v[l+1];
	if(max<sec_max)
	{
		long int k=max;
		max=sec_max;
		sec_max=k;	
	}
	for(int i=l+2;i<r;i++){
		if(v[i] > max){
			sec_max=max;
			max=v[i];
		}
		else if(v[i] > sec_max){
			sec_max=v[i];	
		}
	}
	return sec_max;
}

long long int sec_min_f(int l,int r){
	long int min=v[l];
	long long int sec_min=v[l+1];
	if(min>sec_min)
	{
		long int k=min;
		min=sec_min;
		sec_min=k;	
	}
	for(int i=l+2;i<r;i++){
		if(v[i] < min){
			sec_min=min;
			min=v[i];
		}
		else if(v[i] < sec_min){
			sec_min=v[i];	
		}
	}
	return sec_min;
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string residue;
	for(int i=0;i<n;i++){
		long int x;
		cin>>x;
		v.push_back(x);
		/*if(v1.size()==0){
			v1.push_back(x);
		}
		else{
			v1.push_back(v1[i-1] + v[i]);
		}*/
	}
	int q;
	cin>>q;
	while(q--){
		char a;
		int l,r;

		cin>>a;
		//cout<<a;
		switch(a){
			case 'U':
				cin>>l>>r;
				update(l,r);
				break;
			case 'A':
				cin>>l>>r;
				//sum out
				cout<<sum_f(l-1,r)<<endl;
				break;
			case 'M':
				cin>>l>>r;
				//Max
				cout<<max_f(l-1,r)<<endl;
				break;
			case 'm':
				cin>>l>>r;
				cout<<min_f(l-1,r)<<endl;
				//min
				break;
			case 'S':
				cin>>l>>r;
				cout<<sec_max_f(l-1,r)<<endl;
				//second max
				break;
			case 's':
				cin>>l>>r;
				cout<<sec_min_f(l-1,r)<<endl;
				//xcout<<v[l-1];
				//second min
				break;
			default:
				std::getline (std::cin,residue);
				cout<<"!!!"<<endl;
		}
		//cout<<endl;
	}
	return 0;
}