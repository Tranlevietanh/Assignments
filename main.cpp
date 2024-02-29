#include <iostream>
#include <string>
#include <cmath>
using namespace std; 

class Shape {
	string color; 
	bool filled; 
	
public: 
Shape (string a = "", bool b = false) {
	color = a; 
	filled = b; }

string getColor () {
	return color; }

void setColor (string a) {
	color = a; }

void setFilled (bool b) {
	filled = b; }

bool isFilled () {
	return filled; }

virtual double getArea (); 
virtual double getPerimeter (); }; 

class Circle: public Shape {
	double radius; 
	
public: 
Circle (string a = "", bool b = false, double c = 0.0) : Shape (a,b) {
	radius = c; }

double getRadius () {
	return radius; }
	
void setRadius (double c) {
	radius = c; }
	
double getArea() {
	return 3.14*pow(radius,2); }
	
double getPerimeter() {
	return 2*3.14*radius; }

}; 

class Rectangle: public Shape {
double width; 
double height; 

public: 
Rectangle (string a = "", bool b = false, double d = 0.0, double e = 0.0) : Shape (a,b) {
width = d; 
height = e; }

double getWidth () {
return width; }

void setWidth (double d) {
width = d; }

double getHeight () {
return height; }

void setHeight (double e) {
height = e; }

double getArea() {
return width*height; }

double getPerimeter() {
return 2*(width + height); }

};

int main () {
Circle circle1 ("", false, 3.0); 
bool a = circle1.isFilled();
cout << a << endl; 
double b = circle1.getArea();	
double c = circle1.getPerimeter(); 
cout << b << endl << c << endl; }
