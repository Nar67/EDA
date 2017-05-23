#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
	if(esq > dre)
		return -1;
	int m = (esq+dre)/2;
	if(x < v[m])
		return posicio(x, v, esq, m-1);
	if(x > v[m])
		return posicio(x, v, m+1, dre);
	return m;
}

int first(double x, const vector<double>& v, int l, int r){
	if(l >= r)
		return r;
	int m = (r+l)/2;
	if(v[m] == x)
		return first(x, v, l, m);
	return first(x, v, m+1, r);
}

int first_occurrence(double x, const vector<double>& v){
	int a = posicio(x, v, 0, v.size()-1);
	if(a > 0) {
		a = first(x, v, 0, a);
	}
	return a;
}


int main(){
	vector<double> v(5);
	double x;
	cin >> x;
	for (int i = 0; i < 5; ++i){
		cin >> v[i];
	}

	cout << first_occurrence(x, v) << endl;



}