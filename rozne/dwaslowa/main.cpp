#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin>>n;
	string s, t; cin>>s>>t;
	set<int> mp;
	for(int i = 0; i < n; i++){
		if(s[i]!=t[i]) mp.insert(i);
	}
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		int a, b; cin>>a>>b;
		swap(s[a], t[b]);
		if(s[a]==t[a]) mp.erase(a);
		else mp.insert(a);
		if(s[b]==t[b]) mp.erase(b);
		else mp.insert(b);
		if(mp.size()==0) cout<<0<<'\n';
		else{
			int pt = *mp.begin();
			if(s[pt]>t[pt]) cout<<1<<'\n';
			else cout<<2<<'\n';
		}
	}
	
	return 0;
}
