#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector<bool> > matrix;

void write(const vector<int> v){
	for (int i = 0; i < (int)v.size(); ++i) {
		for (int j = 0; j < (int)v.size(); ++j) {
			if(v[i] == j)
				cout << "K";
			else
				cout << '.';
		}
		cout << endl;
	}
	cout << "----------" << endl;
}

void change(matrix& m, int i, int j, bool chang){
	int n = (int)m[0].size();
	m[j][i] = chang;
	if(j+1 < n) m[j+1][i] = chang;
	if(i+1 < n) m[j][i+1] = chang;
	if(j+1 < n and i+1 < n) m[j+1][i+1] = chang;
	if(j-1 > 0) m[j-1][i] = chang;
	if(i-1 > 0) m[j][i-1] = chang;
	if(j-1 > 0 and i-1 > 0) m[j-1][i-1] = chang;
}

void king(vector<int>& v, matrix& m,  int& kings, int i){
	int n = (int)v.size();
	if(i == n){
		write(v);
		return;
	}
	for(int k = 0; k < n and kings > 0; k++){
		if(not m[i][k]){
			v[i] = k;
			change(m, i, k, true);
			cout << "test" << endl;
			kings--;
			king(v, m, kings, i+1);
			change(m, i, k, false);
			kings++;
		}
	}
}

int main(){
	int kings, n;
	cin >> kings >> n;
	vector<int> v(n);
	matrix m(n, vector<bool> (n, false));
	king(v, m, kings, 0);
}
