#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	string s1,flag;
	int c,s,e;
	cin>>t;
	while(t--){
		cin>>s1;
		c=0,s=0,e=0,flag="yes";
		for (int i = 0; i < s1.size(); ++i)
		{
			if (s1[i]=='C' && c==0 && s==0 && e==0)
			{
				c=1;
			}
			if (s1[i]=='E' && s==0 && e==0)
			{
				e=1;
			}
			if (s1[i]=='S' && s==0 )
			{
				s=1;
			}
			if (s1[i]=='C' &&  (e==1 || s==1) )
			{
				flag="no";
				break;
			}
			if (s1[i]=='E' &&  (s==1) )
			{
				flag="no";
				break;
			}

		}
		cout<<flag<<endl;
	}	
	return 0;
}