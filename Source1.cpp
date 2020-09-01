#pragma warning(disable : 4996)
#include<iostream>
#include<fstream>
#include<cstring>
#include <string>
#include<string.h>
using namespace std;

class screenSize {
public:
	char p1[20] = "6.5 Inches", p2[20] = "5.8 Inches", p3[20] = "6.1 Inches", p4[20] = "6.9 Inches";
	void getScreen(char ph1[20], char ph2[20], char ph3[20], char ph4[20]) {
		strcpy(ph1, p1);
		strcpy(ph2, p2);
		strcpy(ph3, p3);
		strcpy(ph4, p4);
	}
}Screen;

class ram {
public:
	char p1[5] = "4GB", p2[5] = "3GB", p3[5] = "6GB", p4[5] = "12GB";
	void getRam(char ph1[5], char ph2[5], char ph3[5], char ph4[5]) {
		strcpy(ph1, p1);
		strcpy(ph2, p2);
		strcpy(ph3, p3);
		strcpy(ph4, p4);
	}
}Ram;

class battery {
public:
	char p1[10] = "3000mAH", p2[10] = "2783mAH", p3[10] = "3969mAH", p4[10] = "6000mAH";
	void getBattery(char ph1[10], char ph2[10], char ph3[10], char ph4[10]) {
		strcpy(ph1, p1);
		strcpy(ph2, p2);
		strcpy(ph3, p3);
		strcpy(ph4, p4);
	}
}Battery;

class megaPixels {
public:
	char p1[10] = "12MP", p2[10] = "16MP", p3[10] = "48MP", p4[10] = "64MP";
	void getMP(char ph1[10], char ph2[10], char ph3[10], char ph4[10]) {
		strcpy(ph1, p1);
		strcpy(ph2, p2);
		strcpy(ph3, p3);
		strcpy(ph4, p4);
	}
}MegaPixels;

class name {
public:
	char p1[100] = "iPhone 11 Pro Max", p2[100] = "Pixel 4A", p3[100] = "OnePlus 5", p4[100] = "Samsung Galaxy Note 20 Ultra 5G";
	void getName(char ph1[100], char ph2[100], char ph3[100], char ph4[100]) {
		strcpy(ph1, p1);
		strcpy(ph2, p2);
		strcpy(ph3, p3);
		strcpy(ph4, p4);
	}
}name;

class SoC {
public:
	char p1[100] = "A13 Bionic", p2[100] = "Snapdragon 730", p3[100] = "Snapdragon 835", p4[100] = "Exynos 990";
	void getSoC(char ph1[100], char ph2[100], char ph3[100], char ph4[100]) {
		strcpy(ph1, p1);
		strcpy(ph2, p2);
		strcpy(ph3, p3);
		strcpy(ph4, p4);
	}
}SoC;

int main() {
	char name1[100], name2[100], name3[100], name4[100];
	char SoC1[100], SoC2[100], SoC3[100], SoC4[100];
	char screen1[20], screen2[20], screen3[20], screen4[20];
	char ram1[5], ram2[5], ram3[5], ram4[5];
	char battery1[10], battery2[10], battery3[10], battery4[10];
	char MP1[10], MP2[10], MP3[10], MP4[10];

	ofstream nameOut;
	nameOut.open("name.txt");
	name.getName(name1, name2, name3, name4);
	nameOut << name1 << "\n" << name2 << "\n" << name3 << "\n" << name4;
	nameOut.close();

	ofstream SoCOut;
	SoCOut.open("SoC.txt");
	SoC.getSoC(SoC1, SoC2, SoC3, SoC4);
	SoCOut << SoC1 << "\n" << SoC2 << "\n" << SoC3 << "\n" << SoC4;
	SoCOut.close();

	ofstream ramOut;
	ramOut.open("RAM.txt");
	Ram.getRam(ram1, ram2, ram3, ram4);
	ramOut << ram1 << "\n" << ram2 << "\n" << ram3 << "\n" << ram4;
	ramOut.close();

	ofstream screenOut;
	screenOut.open("ScreenSize.txt");
	Screen.getScreen(screen1, screen2, screen3, screen4);
	screenOut << screen1 << "\n" << screen2 << "\n" << screen3 << "\n" << screen4;
	screenOut.close();

	ofstream batteryOut;
	batteryOut.open("Battery.txt");
	Battery.getBattery(battery1, battery2, battery3, battery4);
	batteryOut << battery1 << "\n" << battery2 << "\n" << battery3 << "\n" << battery4;
	batteryOut.close();

	ofstream MPOut;
	MPOut.open("MegaPixels.txt");
	MegaPixels.getMP(MP1, MP2, MP3, MP4);
	MPOut << MP1 << "\n" << MP2 << "\n" << MP3 << "\n" << MP4;
	MPOut.close();

	ifstream nameIn, SoCIn, ramIn, screenIn, batteryIn, MPIn;

	nameIn.open("name.txt");
	SoCIn.open("SoC.txt");
	ramIn.open("RAM.txt");
	screenIn.open("ScreenSize.txt");
	batteryIn.open("Battery.txt");
	MPIn.open("MegaPixels.txt");

	string search;
	cout << "Enter the name of the phone: ";
	cin >> search;

	bool isFound = 0;

	while (!nameIn.eof()) {
		string showName = "", showSoC = "", showRam = "", showMP = "", showScreen = "", showBattery = "";
		getline(nameIn, showName);
		getline(SoCIn, showSoC);
		getline(ramIn, showRam);
		getline(MPIn, showMP);
		getline(screenIn, showScreen);
		getline(batteryIn, showBattery);
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
			cout << "\nName: ";
			for (int i = 0; i < showName.size(); i++)
				cout << showName[i];
			cout << "\nProcessor: ";
			for (int i = 0; i < showSoC.size(); i++)
				cout << showSoC[i];
			cout << "\nRAM: ";
			for (int i = 0; i < showRam.size(); i++)
				cout << showRam[i];
			cout << "\nScreen Size: ";
			for (int i = 0; i < showScreen.size(); i++)
				cout << showScreen[i];
			cout << "\nBattery: ";
			for (int i = 0; i < showBattery.size(); i++)
				cout << showBattery[i];
			cout << "\nMegaPixels: ";
			for (int i = 0; i < showMP.size(); i++)
				cout << showMP[i];
			cout << "\n";
			break;
		}
	}

	if (nameIn.eof() && (!isFound))
		cout << "\nnot found";

	nameIn.close();
	SoCIn.close();
	ramIn.close();
	screenIn.close();
	batteryIn.close();
	MPIn.close();

	return 0;
}