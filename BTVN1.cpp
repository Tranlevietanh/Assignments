#include <iostream>
using namespace std; 

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
		if (input[i] == "Do" || input[i] == "do") encoded[i] = 0;
		else if (input[i] == "Trang" || input[i] == "trang") encoded[i] = 1;
		else if (input[i] == "Xanh" || input[i] == "xanh") encoded[i] = 2; }
	
	int tmp;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (encoded[i] < encoded[j]) {tmp = encoded[j]; 
			encoded[j] = encoded [i]; 
			encoded[i] = tmp; } } }
	
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
