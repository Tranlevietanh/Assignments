#include <iostream>
#include <cmath>
using namespace std; 

int check_prime(int n) {
	int count = 0;
	for (int i = 2; i <= n; i++)
	if (n % i == 0) count++;
	if (count == 1) return 1;
	else return 0;
}

int check_blum(int n) {
	int count = 1;
	for (int i = 2; i < sqrt(n); i++) {
		if (check_prime(i) && check_prime(n / i) && (i * (n / i) == n)) count++;	
	}
	return count;
}	

int main () {
	int n; 
	cout << "Hay nhap so n: "; 
	cin >> n; 
	
	int count = 0;
	for (int i = 2; i < n; i++) {
		if (check_blum(i) != 1) count++;}
	int* blum_array = new int [count]; 
	
	int j = 0;
	for (int i = 2; i < n; i++) {
		if (check_blum(i) != 1) {blum_array [j] = i; 
		j++; } }
	
	for (int i = 0; i < count; i++) {
		cout << blum_array [i] << " "; }
	
	for (int i = 0; i < count; i++) {
		for (int j = i; j < count; j++) {
		int sum = blum_array[i] + blum_array[j]; 
		if (check_blum (sum) != 1 && sum < n)  cout << endl << "Cap so blum la: " << blum_array [i] << " va " << blum_array[j] << endl; } }
	
	int m; 
	cout << "Hay nhap so m: "; 
	cin >> m; 
	if (check_blum (m) != 1) {
		for (int i = 0; i< count; i++) { 
		if (m == blum_array[i]) cout << endl << "So nay co trong day so Blum"; }
	}
	else cout << endl << "So nay khong trong day so Blum"; 
	
	delete [] blum_array;
	}
		
	
