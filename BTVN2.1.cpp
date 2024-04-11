#include <iostream>
using namespace std; 

void swap (int& a, int& b) {
	int tmp = a; 
	a = b; 
	b = tmp; }

void Partition (int*& a, int first, int last) {
	if (first >= last) return; 
	int pivot = a[first]; 
	int i = first + 1;
	int j = last; 
	while (i <= j) {
		while (a[i] <= pivot && i <= j) i++; 
		while (a[j] > pivot && i <= j) j--;
		if (i < j) swap (a[i], a[j]); }
	swap (a[first], a[j]); 
	Partition (a, first, j-1); 
	Partition (a, j+1, last); } 

void Quicksort (int*& a, int n) {
	Partition (a, 0, n-1); }
			

int main (){
	int n; 
	cout << "Hay nhap so luong doi tuong: "; 
	cin >> n; 
	cin.ignore(); 
	
	string *input = new string [n]; 
	for (int i = 0; i < n; i++) {
		cout << "Hay nhap mau cua doi tuong thu " << i << " :"; 
		getline (cin, input[i]); 
		cout << endl; }
		

	int *encoded = new int [n]; 
	for (int i = 0; i < n; i++) {
		if (input[i] == "do") encoded[i] = 0;
		else if (input[i] == "trang") encoded[i] = 1;
		else if ( input[i] == "xanh") encoded[i] = 2; }
	
	Quicksort (encoded, n); 
	string *output = new string [n]; 
	for (int i = 0; i < n; i++) {
		if (encoded [i] == 0) output [i] = "Do"; 
		else if (encoded [i] == 1) output [i] = "Trang"; 
		else if (encoded [i] == 2) output [i] = "Xanh"; }
		
	cout << "Day doi tuong sau khi sap xep la: " << endl;
	for (int i = 0; i < n ; i++) {
	cout << output [i] << " ";  }
	
	delete [] input; 
	delete [] encoded; 
	delete [] output; }
