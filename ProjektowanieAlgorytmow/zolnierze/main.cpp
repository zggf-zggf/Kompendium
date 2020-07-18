#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin>>n;
	vector<int> t1, t2;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		t1.push_back(a);
		cin>>a;
		t2.push_back(a);
	}
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	int wyn = 0;
	for(int i = 0; i < n; i++){
		wyn+=t2[i]-t1[i];
		if(t2[i]<t1[i]){ cout<<"NIE"; return 0;}
	}
	cout<<wyn;
	return 0;
}
