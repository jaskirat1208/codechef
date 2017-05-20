#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		int counter=0,flag=1;
		while(k--){
			char ch;
			cin>>ch;
			if (ch=='H')
			{
				counter++;
				if (counter>1)
				{
					// cout<<"Invalid"<<endl;]
					flag=0;	
				}
			}
			else if (ch=='T')
			{
				counter--;
				if (counter<0)
				{
					flag=0;
				}
			}
		}
		// cout<<flag<<counter;
		if (flag==0)
		{
			cout<<"Invalid"<<endl;
		}
		else if(flag==1 && counter != 0){
			cout<<"Invalid"<<endl;
		}
		else{
			cout<<"Valid"<<endl;
		}
	}
	return 0;
}