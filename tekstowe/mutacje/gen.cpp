#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
	srand(atoi(argv[1]));
	int n = atoi(argv[2]);
	int m = atoi(argv[3]);
	int q = atoi(argv[4]);
	cout<<n<<endl;
	for(int i = 0; i < n; i++){
		cout<<rand()%20 + 1<<" ";
	}
	cout<<endl<<m<<endl;
	for(int i = 0; i < m; i++){
		cout<<rand()%20 + 1<<" ";
	}
	cout<<endl<<q<<endl;
	for(int i = 0; i < q; i++){
		int r = rand()%min(n-1, m-1)+1;
		cout<<rand()%(n-r)+1<<" ";
		cout<<rand()%(m-r)+1<<" ";
		cout<<r<<endl;
	}
	return 0;
}
