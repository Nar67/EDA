#include <iostream>
#include <queue>
using namespace std;



int main(){
	cout.setf( std::ios::fixed, std:: ios::floatfield );
	cout.precision(4);
	priority_queue<int , vector<int>, greater<int> > pq;
	string cmd;
	int min, max;
	min = max = 0;
	double sum = 0;
	bool primer = true;
	while(cin >> cmd){
		if(cmd == "number"){
			int num;
			cin >> num;
			pq.push(num);
			min = pq.top();
			if(primer or pq.empty()){
				max = min;
				sum = 0;
			}
			else
				if(max < num)
					max = num;
				sum += num;
			primer = false;
			cout << "minimum: " << min << ", maximum: " << max << ", average: " << sum/pq.size() << endl;
		}
		else if(cmd == "delete"){
			if(not pq.empty()){
				sum -= pq.top();
				pq.pop();
				if(not pq.empty()){
					min = pq.top();
					cout << "minimum: " << min << ", maximum: " << max << ", average: " << sum/pq.size() << endl;
				}
				else{
					sum = 0;
					primer = true;
					cout << "no elements" << endl;
				}
			}
			else{
				sum = 0;
				primer = true;
				cout << "no elements" << endl;
			}
		}
	}

}