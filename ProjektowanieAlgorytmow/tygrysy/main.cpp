#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	long long n; cin>>n;
	vector<pair<long long, long long>> tab;
	for(long long i = 0; i < n; i++){
		long long a, b; cin>>a>>b;
		tab.push_back(make_pair(a, a/b));
	}	
	sort(tab.begin(), tab.end());
	long long pt = -1;	
	long long wyn = 0;
	for(long long i = 0; i < tab.size(); i++){
		if(tab[i].second>=pt){
			wyn++;
			pt = tab[i].first;	
		}
	}
	cout<<wyn;
	return 0;
}
