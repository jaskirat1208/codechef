#include <iostream>
#include <vector>
#include <string>
using namespace std;
long int check(long int n, long int total, string str){
	long int size=0,flag=1;
	char ch;
	for(long int i=0;i<total;i++){
		if (size==0)
		{
			ch=str[i];
			// cout<<i;
		}
		if (str[i]!=ch)
		{
			flag=0;
			
		}
		size++;
		if (size==n)
		{
			if (flag==1)
			{
				return 1;
			}
			if (i!=total-1)
			{
				size=0;
				// cout<<" "<<flag<<" ";
				flag=1;
			}
		}
		
	}
	// cout<<flag;
	return flag;
}
long int compute(long int n, long int total, string str){
	long int count=0;
	while(n%2!=1){
		if (check(n,total, str))
		{
			return count;
		}
		n=n/2;
		count++;
	}
	if (n==1)
	{
		return count;
	}
	else{
		if (check(n,total, str))
		{
			return count;
		}
	}

	return -1;
}
int main(int argc, char const *argv[])
{
	long int n;
	cin>>n;
	string str;
	while(n--){
		cin>>str;
		cout<<compute(str.size(),str.size(),str)<<endl;
		// cout<<str;
	}
	return 0;
}