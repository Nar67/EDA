#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<vector<char>> Matrix;
typedef pair<int,int> intpair;
struct trint {
	int first;
	int second;
	int dist;
};

void check(int i, int j, const Matrix& M, const Matrix& enc, int dist, queue<trint>& q){
	int n = M.size();
	int m = M[0].size();
	if(i >= 0 and i < n and j >= 0 and j < m) {
		if(M[i][j] != 'X' and not enc[i][j]){
			q.push({i, j, dist+1});

		}
	} 		
}

int min_distance(Matrix& M, int si, int sj){
	int n = M.size();
	int m = M[0].size();
	queue<trint> q;
	Matrix enc(n, vector<char>(m ,false));
	q.push({si, sj, 0});
	int max = -1;
	while(not q.empty()){
		trint a = q.front();
		q.pop();
		if(not enc[a.first][a.second]){
			enc[a.first][a.second] = true;
			if(M[a.first][a.second] == 't'){
				M[a.first][a.second] = '.';
				enc[a.first][a.second] = false;
				max = a.dist;

			}
			check(a.first+1, a.second, M, enc, a.dist, q);
			check(a.first-1, a.second, M, enc, a.dist, q);
			check(a.first, a.second+1, M, enc, a.dist, q);
			check(a.first, a.second-1, M, enc, a.dist, q);
		}

	}
	return max;
}

int main(){
	int n, m;
	cin >> n >> m;
	Matrix M(n, vector<char>(m));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> M[i][j];
		}
	}
	int si, sj;
	cin >> si >> sj;
	--si; --sj;
	int x = min_distance(M, si, sj);
	if(x != -1) cout << "distancia minima: " << x << endl;
	else cout << "no es pot arribar a cap tresor" << endl;
}