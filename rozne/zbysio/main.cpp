#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	vector<bool> sito(1000010, false);
	unordered_map<long long, bool> mp;
	for(long long i = 2; i < sito.size(); i++){
		if(!sito[i]){
			mp[i*i] = true;
			for(long long j = i; j < sito.size(); j+=i){
				sito[j] = true;
			}
		}
	}
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		long long a; cin>>a;
		if(mp[a]) cout<<"TAK\n";
		else cout<<"NIE\n";
	}
	return 0;
}
