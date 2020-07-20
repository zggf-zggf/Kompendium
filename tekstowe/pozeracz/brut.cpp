#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> tab;
	int n; cin>>n;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		tab.push_back(a);
	}
	vector<set<int>> coc;
	for(int i = 0; i < n; i++){
		set<int> cur;
		for(int j = i; j < n; j++){
			cur.insert(tab[j]);
			bool pos = true;
			for(auto it:coc) if(it==cur){pos = false; break;}
			if(pos) coc.push_back(cur);
		}
	}
	cout<<coc.size();
			
	return 0;
}
