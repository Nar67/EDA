#include <iostream>
#include <vector>
using namespace std;



void consonants_i_vocals(const string& cons, const string& voc, string res,  int i){
	int n = (int)cons.size() * 2;
	if(i == n){
		cout << res << endl;
		return;
	}
	for (int j = 0; j < n/2; ++j){
		if(i%2 == 0 and res.find(cons[j]) == -1){
			res[i] = cons[j];
			consonants_i_vocals(cons, voc, res, i+1);
		}
		else if(i%2 != 0 and res.find(voc[j]) == -1){
			res[i] = voc[j];
			consonants_i_vocals(cons, voc, res, i+1);
		}
	}
}


int main(){
	int n;
	string c, v;
	cin >> n;
	string res(2*n, ' ');
	cin >> c >> v;
	consonants_i_vocals(c, v, res, 0);
}