#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	string a, b; cin>>a>>b;
	string wyn = "";	
	int carry = 0;
	for(int i = 0; i < max(a.size(), b.size()); i++){
		wyn.push_back('0'+((carry+((i<a.size())?a[a.size()-i-1]-'0':0)+((i<b.size())?b[b.size()-i-1]-'0':0)))%10);
		carry = (((carry+((i<a.size())?a[a.size()-i-1]-'0':0)+((i<b.size())?b[b.size()-i-1]-'0':0)))/10);
	}
	if(carry>0)
		wyn.push_back('0'+carry);
	for(int i = wyn.size()-1; i >= 0; i--){
		cout<<wyn[i];
	}
			
	return 0;
}
