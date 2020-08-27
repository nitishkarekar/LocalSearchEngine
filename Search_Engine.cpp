#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
using namespace std;

class screenSize {
public:
	float p1 = 6.5, p2 = 5.8, p3 = 6.1, p4 = 6.9;
}ss1;
class ram {
public:
	int p1 = 4, p2 = 3, p3 = 6, p4 = 12;
}rm1;
class battery {
public:
	int p1 = 3000, p2 = 2783, p3 = 3969, p4 = 6000;
}bat1;
class megaPix {
public:
	int p1 = 12, p2 = 16, p3 = 48, p4 = 64;
}mp1;
class name {
public:
	char p1[100] = "iPhone 11 Pro Max", p2[100] = "Pixel 4A", p3[100] = "OnePlus 5", p4[100] = "Samsung Galaxy Note 20 Ultra 5G";
	void get(char ph1[100], char ph2[100], char ph3[100], char ph4[100]) {
		strcpy(ph1, p1);
		strcpy(ph2, p2);
		strcpy(ph3, p3);
		strcpy(ph4, p4);
	}
}na1;

class SoC {
public:
	string p1 = "A13 Bionic", p2 = "Snapdragon 730", p3 = "Snapdragon 835", p4 = "Exynos 990";
}so1;
int main() {
	char name1[100], name2[100], name3[100], name4[100];
	ofstream fout;
	fout.open("name.txt");
	na1.get(name1, name2, name3, name4);
	fout << name1 << "\n" << name2 << "\n" << name3 << "\n" << name4;
	fout.close();
	ifstream na;
	na.open("name.txt");
	string search;
	cout << "enter the name of the phone: ";
	cin >> search;
	bool isFound = 0;
	while (!na.eof()) {
		string temp = "";
		getline(na, temp);
		for (int i = 0; i < search.size(); i++) {
			if (temp[i] == search[i])
				isFound = 1;
			else {
				isFound = 0;
				break;
			}
		}
		if (isFound == 1) {
			for (int i = 0; i < temp.size(); i++)
				cout << temp[i];
			break;
		}
	}
	if (na.eof() && (!isFound))
		cout << "not found";
	na.close();
}