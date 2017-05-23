#include <iostream>
#include <vector>
using namespace std;

void zeros_uns(vector<int>& v, int i, int n_uns){
	int n = (int)v.size();
	if(i == n and n_uns == 0){
		for (int j = 0; j < n; ++j) {
			if(j != 0)
				cout << ' ' << v[j];
			else
				cout << v[j];
				
		}
		cout << endl;
		return;
	}
	if(n - i >= n_uns){
		v[i] = 0;	
		zeros_uns(v, i+1, n_uns);
		if(n_uns > 0){
			v[i] = 1;
			zeros_uns(v, i+1, n_uns-1);
		}
	}
}




int main(){
	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	zeros_uns(v, 0, m);

}