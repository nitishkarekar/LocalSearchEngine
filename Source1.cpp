#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
using namespace std;

class screenSize {
public:
	float p1 = 6.5, p2 = 5.8, p3 = 6.1, p4 = 6.9;
	void get(float ph1, float ph2, float ph3, float ph4) {
		ph1 = p1;
		ph2 = p2;
		ph3 = p3;
		ph4 = p4;
	}
}ss1;
class ram {
public:
	int p1 = 4, p2 = 3, p3 = 6, p4 = 12;
	void get(int ph1,int ph2,int ph3,int ph4) {
		ph1 = p1;
		ph2 = p2;
		ph3 = p3;
		ph4 = p4;
		cout<<ph1;
	}
}Ram;
class battery {
public:
	int p1 = 3000, p2 = 2783, p3 = 3969, p4 = 6000;
	void get(int ph1,int ph2,int ph3,int ph4) {
		ph1 = p1;
		ph2 = p2;
		ph3 = p3;
		ph4 = p4;
	}
}bat1;
class megaPix {
public:
	int p1 = 12, p2 = 16, p3 = 48, p4 = 64;
	void get(int ph1,int ph2,int ph3,int ph4) {
		ph1 = p1;
		ph2 = p2;
		ph3 = p3;
		ph4 = p4;
	}
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
}name;

class SoC {
public:
	char p1[100] = "A13 Bionic", p2[100] = "Snapdragon 730", p3[100] = "Snapdragon 835", p4[100] = "Exynos 990";
	void get(char ph1[100], char ph2[100], char ph3[100], char ph4[100]) {
		strcpy(ph1, p1);
		strcpy(ph2, p2);
		strcpy(ph3, p3);
		strcpy(ph4, p4);
	}
}SoC;
int main() {
	char name1[100], name2[100], name3[100], name4[100];
	char SoC1[100], SoC2[100], SoC3[100], SoC4[100];
	int ram1, ram2, ram3, ram4;

	ofstream nameOut;
	nameOut.open("name.txt");
	name.get(name1, name2, name3, name4);
	nameOut << name1 << "\n" << name2 << "\n" << name3 << "\n" << name4;
	nameOut.close();

	ofstream SoCOut;
	SoCOut.open("SoC.txt");
	SoC.get(SoC1, SoC2, SoC3, SoC4);
	SoCOut << SoC1 << "\n" << SoC2 << "\n" << SoC3 << "\n" << SoC4;
	SoCOut.close();

	ofstream ramOut;
	ramOut.open("RAM.txt");
	Ram.get(ram1, ram2, ram3, ram4);
	ramOut << ram1 << "\n" << ram2 << "\n" << ram3 << "\n" << ram4;
	cout << ram1 << "\n" << ram2 << "\n" << ram3 << "\n" << ram4;
	ramOut.close();

	ifstream nameIn, SoCIn, ramIn;

	nameIn.open("name.txt");
	SoCIn.open("SoC.txt");

	string search;
	cout << "enter the name of the phone: ";
	cin >> search;

	bool isFound = 0;

	while (!nameIn.eof()) {
		string showName = "", showSoC = "";
		int showRam;
		getline(nameIn, showName);
		getline(SoCIn, showSoC);
		ramIn >> showRam;
		for (int i = 0; i < search.size(); i++) {
			if (showName[i] == search[i]) {
				isFound = 1;
			}
			else {
				isFound = 0;
				break;
			}
		}
		if (isFound == 1) {
			for (int i = 0; i < showName.size(); i++)
				cout << showName[i];
			cout<<"\n";
			for (int i = 0; i < showSoC.size(); i++)
				cout << showSoC[i];
			cout<<"\nRam:" << showRam;
			cout<<"\n";
			break;
		}
	}

	if (nameIn.eof() && (!isFound))
		cout << "not found";

	nameIn.close();
	SoCIn.close();
}
