#include <iostream>
#include <vector>
using namespace std;
int water;
int fill(int start, int end,vector<int> v){
	int next_gt,largest_small=0,largest_small_index,j,tofillindex,tofill	;
	for(int i=start+1;i<=end;){
		if(v[i]>largest_small && v[i]<v[start]){	
			largest_small=v[i];
			largest_small_index=i;
		}
		if(v[i]>=v[start]){
			next_gt=i;
			break;
		}
		i++;
	}
	/***************************************************************************/
	if(next_gt==end+1){
		tofill=largest_small;
		tofillindex=largest_small_index;
	}
	else{
		tofillindex=next_gt;
		tofill=v[next_gt];
	}
	/***************************************************************************/
	/***************************************************************************/
	//filling the water
	int fill_bar;
	if(v[start]>tofill){
		fill_bar=tofill;
	}
	else{
		fill_bar=v[start];
	}

	for(int i=start+1;i<tofillindex;i++){
		water+=fill_bar-v[i];
	}
	/***************************************************************************/

	///cout<<next_gt<<endl;
	return tofillindex;	
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::vector<int> v;
		while(n--){
			int x;
			cin>>x;
			v.push_back(x);
		}
		int min=v[0];
		for(int i=0;i<v.size();i++){
			if(min > v[i])	min=v[i]; 
		}
		for(int i=0;i<v.size();i++){
			v[i]-=min;
		}
		int j1=0;
		for(int i=0;i<v.size();i++){
			//j1=fill(j1,v.size()-1,v);
			//cout<<v[i]<<" ";	
		}
		water=0;int start_i=0;
		while(start_i!=v.size()-1){
			start_i=fill(start_i,v.size()-1,v);
		}
		cout<<water<<endl;
	}
	return 0;
}