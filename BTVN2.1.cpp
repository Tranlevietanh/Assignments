#include <iostream>
using namespace std; 

int* input (int& n) {
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
	
	delete [] input; 
	return encoded;}

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
			
void output (int* a, int n) {
	string *output = new string [n]; 
	for (int i = 0; i < n; i++) {
		if (a [i] == 0) output [i] = "Do"; 
		else if (a [i] == 1) output [i] = "Trang"; 
		else if (a [i] == 2) output [i] = "Xanh"; }
		
	cout << "Day doi tuong sau khi sap xep la: " << endl;
	for (int i = 0; i < n ; i++) {
	cout << output [i] << " ";  }
	delete [] output;  }
	
void MergeArrays (int*& a, int m, int n, int p) {
	int i = m, j = n + 1; 
	while (i < j && j <= p) {
		if (a[i] <= a[j]) i++; 
		else {
			int x = a[j]; 
			for (int k = j-1; k>=i; k--) a[k+1] = a[k]; 
				a[i] = x; 
				i++; j++; }
		}
	}

void Split_Merge (int*& a, int first, int last) {
	if (first >= last) return; 
	int m = (first + last)/2; 
	Split_Merge (a, first, m); 
	Split_Merge (a, m+1, last); 
	MergeArrays (a,first, m, last); }

void Merge_Sort (int*& a, int n) {
if (n < 2) return; 
Split_Merge (a, 0, n-1) ;}

int main (){
	int n; 
	int* encoded1 = input (n); 
	Quicksort (encoded1, n); 
	output (encoded1, n); 
	
	int m; 
	int* encoded2 = input (m);
	
	int* encoded = new int [n+m]; 
	for (int i = 0; i < n; i++) {
		encoded[i] = encoded1 [i]; }
	for (int i = 0; i < m; i++) {
		encoded[i+n] = encoded2 [i]; }		
	Merge_Sort (encoded, n+m); 
	output (encoded, n+m);
	
	delete [] encoded1;
	delete [] encoded2; 
	delete [] encoded; }
