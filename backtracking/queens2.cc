#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& v){
	int n = (int)v.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(v[i] == j)
				cout << "Q";
			else
				cout << ".";
		}
		cout << endl;
	}
	cout << endl;

}

void queens(vector<int>& v, vector<bool>& rows, vector<bool>& diag1, vector<bool>& diag2, int i){
	int n = (int)v.size();
	if(n == i){
		write(v);
		return;
	}
	for(int k = 0; k < n; k++){
		if(not rows[k] and not diag1[i+k] and not diag2[n-1-k+i]){
			v[i] = k;
			rows[k] = true;
			diag1[i+k] = true;
			diag2[n-1-k+i] = true;
			queens(v, rows, diag1, diag2, i+1);
			rows[k] = false;
			diag1[i+k] = false;
			diag2[n-1-k+i] = false;
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n, -1);
	vector<bool> rows(n, false);
	vector<bool> diag1(2*n - 1, false);
	vector<bool> diag2(2*n - 1, false);
	queens(v, rows, diag1, diag2, 0);

}