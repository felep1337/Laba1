#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <cmath>
#include <vector>
#include <random>

//Глобальные переменные и пространство имен

double pi = 3.1415;
int n = 20;
double x[20];

using namespace std;

//Функции

void fillArray1(double* x, int n) {
	for (int i = 0; i < n; i++) {
		x[i] = i+3;
	}
}

void fillArray2(double* x, int n, int k, double pi) {
	for (int i = 0; i < n; i++) {
		x[i] = sin(pi * k * i / n);
	}
}

void fillArray3(double* x, double b, double c, double n) {
	for (int i = 0; i < n; i++) {
		x[i] = (b + ((c - b)/(n-1))*i);
	}
}

void fillArray4(double* x, double* y, int n) {
	for (int i = 0; i < n; i++) {
		x[i] = i;
		y[i] = i * i;
	}
}

void fillArray5(double* x, double* y, double a, double b, double c, double n) {
	fillArray3(x, 0, n, 20);
	for (int i = 0; i <= 20; i++) {
		y[i] = a * sin(x[i]) + b * sin(2 * x[i]) + c * sin(3 * x[i]);
	}
}

void fillArray6(double* x, double* y) {
	fillArray5(x, y, 5, -2, 1, pi);
}

void findMaxAndMinOfFunction(double* y, int n) {
	for (int i = 1; i < n; i++) {
		if ((y[i] < y[i + 1]) && (y[i] < y[i - 1])) {
			cout << "Local minimum of this functioin: " << y[i] << '\n';
		}
		if ((y[i] > y[i + 1]) && (y[i] > y[i - 1])) {
			cout << "Local maximum of this functioin: " << y[i] << '\n';
		}
	}
}
void fillArray7(double* x, double* y, int n) {
	findMaxAndMinOfFunction(y, n);
}

vector<int> findMaxAndMinOfFunctionVector(vector<int> &vector, double* y,int n) {
	for (int i = 1; i < n; i++) {
		if ((y[i] > y[i + 1]) && (y[i] > y[i - 1])) {
			vector.push_back(i);
		}
	}
	return vector;
}
vector<int> fillArray8(double* x, double* y, int n) {
	vector<int> local_max;
	findMaxAndMinOfFunctionVector(local_max, y, n);
	return local_max;
}

//Функции индивидуальных заданий

void MakeFunction(double* x, double* y,double n) { //создаем "случайную" функцию
	fillArray3(x, 0, n, 20);
	for (int i = 0; i < 20; i++) {
		y[i] = rand()%10;
	}
}
void fillArray10(double* x,double* y, double* derivative) {
	double dx = x[1]-x[0];
	for (int i = 1; i < 20; i++) {
		derivative[i] = (y[i + 1] - 2 * y[i] + y[i - 1]) / (dx*dx);
	}
	derivative[0] = derivative[1];
	derivative[19] = derivative[18];
}

// Вывод массива в консоль

void printArray(double* a, int n) {
	cout << "[" << n << "] ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << '/n';
}

//Сохраниние массивов

void saveArrayWith1Var(const char* fileName, double* a, int n) {

	ofstream f;
	f.open(fileName);
	for (int i = 0; i < n; i++) {
		f << i << '\t' << a[i] << '\n';
	}
	f.close();
}

void saveArrayWith2Var(const char* fileName, double* a, double* b, int n) {
	ofstream f;
	f.open(fileName);
	for (int i = 0; i < n; i++) {
		f << a[i] << '\t' << b[i] << '\n';
	}
	f.close();
}

void SaveMaxPoints(const char* fileName,double* x, double* y, double n) {
	ofstream f;
	f.open(fileName);
	for (int i = 1; i < n; i++) {
		if ((y[i] > y[i + 1]) && (y[i] > y[i - 1])) {
			f << x[i] << '\t' << y[i];
		}
	}
}

void SaveArrayWithDif(const char* fileName, double* x, double* y,double* derivative, double n) {
	ofstream f;
	f.open(fileName);
	for (int i = 1; i < n; i++) {
		f << x[i] << '\t' << abs(derivative[i] - y[i]) << '\n';
	}
}
//Рисование графиков

void plotFile(const char* fileName) {
	ofstream f;
	f.open("myplot.plt");
	f << "plot '" << fileName << "' with lines\n";
	f << "pause -1";
	f.close();
	system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" myplot.plt");
}

void showArrayWithPoints(const char* fileNameWithGraph, const char* fileNameWithPoints) {
	ofstream f;
	f.open("Secondmyplot.plt");
	f << "plot '" << fileNameWithGraph << "' with lines, '" << fileNameWithPoints << "'with points pt 7 ps 1\n";
	f << "pause -1";
	f.close();
	system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" Secondmyplot.plt");
}

void plotFileWith2Graphs(const char* fileNameWithGraph, const char* fileNameWithDerivative) {
	ofstream f;
	f.open("Secondmyplot.plt");
	f << "plot '" << fileNameWithGraph << "' with lines, '" << fileNameWithDerivative << "'with lines\n";
	f << "pause -1";
	f.close();
	system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" Secondmyplot.plt");
}

void showVector(vector<int>& vect){
	for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
		cout << *it;
} 

int main() {
	double* y = new double[20];
	double* yDerivative = new double[20];
	double* derivative = new double[20];
	vector<int> vect;
	int exercise;
	cin >> exercise;
	switch (exercise) 
	{
		case 1:
			fillArray1(x,n);
			saveArrayWith1Var("data.txt", x, n);
			plotFile("data.txt");
			break;
		case 2:
			int number;
			cin >> number;
			fillArray2(x, 20, number, pi);
			saveArrayWith1Var("data.txt", x, n);
			plotFile("data.txt");
			break;
		case 3:
			int from, to, step;
			cin >> from >> to >> step;
			fillArray3(x, from, to, step);
			for (int i = 0; i != step; i++) {
				cout << x[i] << '\n';
			}
			break;
		case 4:
			fillArray4(x, y, 20);
			saveArrayWith2Var("data.txt", x, y, n);
			plotFile("data.txt");
			break;
		case 5:
			int a, b, c;
			cin >> a >> b >> c;
			fillArray5(x, y, a, b, c, n);
			saveArrayWith2Var("data.txt", x, y, n);
			plotFile("data.txt");
			break;
		case 6:
			fillArray6(x, y);
			saveArrayWith2Var("data.txt", x, y, n);
			plotFile("data.txt");
			break;
		case 7:
			fillArray6(x, y);
			fillArray7(x, y, n);
			break;
		case 8:
			fillArray6(x, y);
			saveArrayWith2Var("data.txt", x, y, n);
			vect = fillArray8(x, y, n);
			showVector(vect);
		case 9:
			fillArray6(x, y);
			SaveMaxPoints("MaxPoints.txt", x, y, 20);
			showArrayWithPoints("data.txt", "MaxPoints.txt");
		case 10:
			MakeFunction(x, y, 20);
			saveArrayWith2Var("data.txt", x, y, 20);
			fillArray10(x, y, derivative);
			saveArrayWith2Var("DataDerivative.txt",x,derivative,20);
			plotFileWith2Graphs("DataDerivative.txt", "data.txt");
		case 11:
			fillArray6(x, y);
			MakeFunction(x, yDerivative, 3.1415);
			fillArray10(x, yDerivative, derivative);
			SaveArrayWithDif("data.txt", x, y, yDerivative, 20);
			plotFile("data.txt");
	}
}