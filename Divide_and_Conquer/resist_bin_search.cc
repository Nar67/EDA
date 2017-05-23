#include <iostream>
#include <vector>
using namespace std;


bool resistant_search(double x, const vector<double>& v)
{
  if (v.size() == 0) return false;
  int l = 0, r = v.size() - 1, mid;
  while (l + 1 < r) {
    mid = (l+r)/2;
    if (v[mid] == x or v[mid-1] == x or v[mid+1] == x) return true;
    else if (v[mid] > x) r = mid;
    else l = mid;
  }
  return ((x == v[l]) or (x == v[r]));
}


int main(){
	int n;
	cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	double x;
	cin >> x;
	cout  << boolalpha << resistant_search(x, v) << endl;



}