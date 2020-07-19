#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> t1, t2;
	for(int i = 0; i < n/2; i++){
		int a; cin>>a;
		t1.push_back(a);
	}	
	for(int i = n/2; i < n; i++){
		int a; cin>>a;
		t2.push_back(a);
	}
	int s;
	cin>>s;
	map<int, int> mp;

	for(int i = 0; i < (1<<(t1.size())); i++){
		int tmp = 0;
		for(int bit =0; bit < t1.size(); bit++){
			if(i&(1<<bit)) tmp+=t1[bit];
		}
		if(tmp==s){
			for(int j = 0; i < t1.size(); j++) cout<<(i&(1<<j)>0); 
			for(int j = 0; j < t2.size(); j++) cout<<0;
			return 0;
		}			
		mp[tmp] = i;
	}
	for(int i = 0; i < (1<<(t2.size())); i++){
		int tmp = 0;
		for(int bit =0; bit < t2.size(); bit++){
			if(i&(1<<bit)) tmp+=t2[bit];
		}
		if(tmp==s){
			for(int j = 0; j < t1.size(); j++) cout<<0;
			for(int j = 0; j < t2.size(); j++) cout<<(i&(1<<j)>0); 
			
			return 0;
		}			
		if(mp[s-tmp]>0){
			for(int j = 0; j < t1.size(); j++) cout<<((mp[s-tmp]&(1<<j))>0); 
			for(int j = 0; j < t2.size(); j++) cout<<((i&(1<<j))>0); 
			
			return 0;
		}
	}
	return 0;
}
