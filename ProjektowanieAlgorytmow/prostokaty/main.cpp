#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n; cin>>n;
	long long maxX = -1, minX = 1e9, maxY = -1, minY = 1e9;
	for(int i = 0; i < n; i++){
		long long a, b; cin>>a>>b;
		maxX = max(maxX, a);
		minX = min(minX, a);
		maxY = max(maxY, b);
		minY = min(minY, b);
	}
	cout<<max(1LL, (maxX-minX))*max(1LL,(maxY-minY));
	return 0;
}
