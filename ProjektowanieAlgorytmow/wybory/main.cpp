#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	long long n, k; cin>>n>>k;
	vector<long long> tab;
	for(long long i = 0; i < n; i++){
		long long a; cin>>a;
		tab.push_back(a);
	}
	
	vector<long long> vec;
	for(long long i = 0; i < n; i++){
		long long a; cin>>a;	
		vec.push_back(((tab[i]+1)/2)*a);	
	}
	sort(vec.begin(), vec.end());
	long long wyn = 0;	
	for(long long i = 0; i < vec.size(); i++){
		if(k-vec[i]>=0) wyn++;
		else break;
		k-=vec[i];
	}
	cout<<wyn;	
	return 0;
}
