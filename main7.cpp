#include <iostream>
#include <vector>
using namespace std;

int main (){
vector<int> vector1; 
vector<int> :: iterator itr; 

vector1.reserve(10);
 
vector1.push_back(3); 
vector1.push_back(5); 
vector1.push_back(7); 
vector1.push_back(10); 
cout << vector1.capacity();
for (itr = vector1.begin(); itr != vector1.end(); itr++) {
	cout << *itr << " "; }


return 0;
}
