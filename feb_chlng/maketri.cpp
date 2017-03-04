
//SolvedFINAL

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef unsigned long long int ull;
ull size(vector<pair<ull,ull> > v,ull l , ull r){
    stack<ull> s;
    //std::iterator
    if(v[0].first < l)  v[0].first=l;
    if(v[0].second > r)  v[0].second =r;
    s.push(v[0].first);
    s.push(v[0].second);
    for(int i=1;i<v.size();i++){
  //      cout<<s.top()<<endl;   
        if(v[i].first < l)  v[i].first=l;
        if(v[i].second > r)  v[i].second =r;    
        if(s.top()>=v[i].first){
            if(s.top()<v[i].second){
                s.pop();
                s.push(v[i].second);
            }
 
        }
        else{
            s.push(v[i].first);
            //cout<<v[i].first<<endl   ;
            s.push(v[i].second);
            //cout<<v[i].second<<endl;
        }
//        cout<<s.top()<<endl;
    }
    ull sum =0;
    while(s.size()>=2){
        sum+=s.top();
        s.pop();
        sum-=s.top();
        s.pop();
        sum+=1;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    ull n,l,r,min_diff=0,max,range_min,range_max;
    cin>>n>>l>>r;
    vector<ull> v;
    //cou/t<<n;
    while(n--){
        ull x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    vector<pair<ull,ull> > interval;
    for(int i=0;i<v.size()-1;i++)
    {
        ull left =v[i+1]-v[i]+1;
        ull right=v[i+1]+v[i]-1;
        if(left<=l){
            if(right>=l){
                left=l;
                interval.push_back(make_pair(left,right))    ;
            }
        }
        else if(right>=r){
            if(left<=r){
                right=r;
                interval.push_back(make_pair(left,right))    ;
            }
        }
        else{
            interval.push_back(make_pair(left,right))    ;
        }
    }
    sort(interval.begin(),interval.end());
    cout<<size(interval,l,r);
    // for(int i=0;i<interval.size();i++){
    //  cout<<interval[i].first<<" "<<interval[i].second<<" ";
    // }
    return 0;
    } 