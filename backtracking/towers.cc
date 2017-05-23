#include <iostream>
#include <vector>
using namespace std;

int f, c;

void write(const vector<int>& v){
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			if(v[i] == j)
				cout << "R";
			else
				cout << '.';
		}
		cout << endl;
	}
	cout << endl;
}

void towers(vector<int>& v, vector<bool>& rows, vector<bool>& col, int i, int& ntow){
	if(i == c and ntow == f){
		write(v);
		return;
	}
	for(int j = 0; j <= f; j++){
		cout << "i = " << i << " j = " << j << endl;
		//write(v);
		if(not col[j] and not rows[j]){
		//	cout << "test" << endl;
			v[i] = j;
			rows[j] = true;
			col[j] = true;
			ntow++;
			towers(v, rows, col, i+1, ntow);
			rows[j] = false;
			col[j] = false;
			ntow--;
		}
	}
}

int main(){
	cin >> f >> c;
	vector<int> v(c, -1);
	vector<bool> rows(f, false);
	vector<bool> col(c, false);
	int tow = 0;
	towers(v, rows, col,  0, tow);	
}