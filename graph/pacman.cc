#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector< vector<char> > matrix;
typedef pair<int,int> par;

void check(matrix& m, matrix& vis, stack<par>& s, int i, int j){
	int f = m.size();
	int c = m[0].size();
	if(i < f and i >= 0 and j < c and j >= 0){
		cout << "i: " << i << " j: " << j << endl;
		cout << "m[i][j] = " << m[i][j] << endl;
		if(m[i][j] != 'X' and not vis[i][j] and m[i][j] != 'F'){
			s.push({i, j});
		}
	}

}

bool pacman(matrix& m, int init_i, int init_j){
	int f = m.size();
	int c = m[0].size();
	stack<par> s;
	matrix vis(f, vector<char> (c, false));
	s.push({init_i, init_j});
	while(not s.empty()){
		int i = s.top().first;
		int j = s.top().second;
		s.pop();
		if(not vis[i][j]){
			vis[i][j] = true;
			if(m[i][j] == 'B') return true;
			check(m, vis, s, i+1, j); check(m, vis, s, i, j+1);
			check(m, vis, s, i-1, j); check(m, vis, s, i, j-1);
			check(m, vis, s, i+1, j+1); check(m, vis, s, i-1, j-1);
			check(m, vis, s, i+2, j); check(m, vis, s, i, j+2);
			check(m, vis, s, i-2, j); check(m, vis, s, i, j-2);
			check(m, vis, s, i+2, j-1); check(m, vis, s, i-1, j+2);
			check(m, vis, s, i-2, j+1); check(m, vis, s, i+2, j-2);
		}
	}
	return false;

}

int main(){
	int f, c, init_i, init_j;
	while(cin >> f >> c){
		matrix lvl(f, vector<char> (c));
		for(int i = 0; i < f; i++){
			for(int j = 0; j < c; j++){
				cin >> lvl[i][j];
				if(lvl[i][j] == 'P'){
					init_i = i; init_j = j;
				}
			}
		}
		if(pacman(lvl, init_i, init_j)) cout << "yes" << endl;
		else cout << "no" << endl;
	}

}