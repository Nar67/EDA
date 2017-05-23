#include <iostream>
#include <vector>
using namespace std;


int fixed_p(const vector<int> vn, int m){
	for(int i = 1; i <= int(vn.size()); ++i){
		if(vn[i] + m == i)
			return vn[i];
	}
	return -1;
}

int main(){
	int n, m;
	int i = 1;
	while(cin >> n){
		vector<int> vn(n);
		for(int j = 0; j < n; ++j) 
			cin >> vn[j];
		cin >> m;
		vector<int> vm(m);
		for(int k = 0; k < m; ++k)
			cin >> vm[k];
		cout << "Sequence #" << i << endl;
		for(int q = 0; q < m; ++q){
			int x = fixed_p(vn, vm[q]);
			if(x == -1){
				cout << "no fixed point for " << vm[q] << endl;
			}
			else
				cout << "fixed point for " << vm[q] << ": " << x << endl;
		}
		cout << endl;
		i++;
	}
}