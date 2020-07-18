#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin>>n;
	vector<long long> tab, pref(n+1);
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		tab.push_back(a);
	}

	sort(tab.begin(), tab.end());
	for(int i = 0;i  < n ;i++){
		pref[i] = tab[i];
		if(i>0) pref[i]+=pref[i-1];
	}
	int q; cin>>q;
	for(int i = 0;i  < q; i++){
		int a; cin>>a; a--;
		cout<<pref[a]<<endl;
	}	
	return 0;
}
