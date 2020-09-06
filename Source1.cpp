#pragma warning(disable : 4996)
#include<iostream>
#include<fstream>
#include <string>
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

void search_display(string search, string fileName, string end) {
	string showPhone = " ";
	bool isFound = 0;
	ifstream phoneIn;
	phoneIn.open(fileName);
	while (!phoneIn.eof()) {
		getline(phoneIn, showPhone);
		if (showPhone == search)
			isFound = 1;
		else {
			if (showPhone == end) {
				isFound = 0;
				break;
			}
		}
		if (isFound == 1) {
			for (int i = 0; i < showPhone.size(); i++)
				cout << showPhone[i];
			cout << "\n\n";
		}
	}
}

int main() {
	char name1[100], name2[100], name3[100], name4[100];
	char SoC1[100], SoC2[100], SoC3[100], SoC4[100];
	char screen1[20], screen2[20], screen3[20], screen4[20];
	char ram1[5], ram2[5], ram3[5], ram4[5];
	char battery1[10], battery2[10], battery3[10], battery4[10];
	char MP1[10], MP2[10], MP3[10], MP4[10];
	int c, brand;
	cout << "Select 1 or 2: \n1)Search by name \n2)Search by brand." << endl;
	cin >> c;
	switch (c) {
	case 1:
	{
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

		nameIn.close(); SoCIn.close(); ramIn.close(); screenIn.close(); batteryIn.close(); MPIn.close();
		break;
	}

	case 2:
	{
		int brand;
		cout << "\nChoose from one of the brands listed below. \n1) Apple \n2) Google \n3) OnePlus \n4) Redmi \n5) Samsung" << endl;
		cin >> brand;
		switch (brand) {
		case 1:
		{
			cout << "\nChoose one option:" << endl;
			ifstream appleIn;
			string showApple = " ";
			appleIn.open("apple.txt");
			while (!appleIn.eof()) {
				getline(appleIn, showApple);
				cout << "\n";
				for (int i = 0; i < showApple.size(); i++)
					cout << showApple[i];
			}
			appleIn.close();
			int phone; cin >> phone;
			switch (phone) {
				case 1:	search_display("Name: iPhone 11 Pro Max", "iPhone.txt", "1");
					break;
				case 2: search_display("Name: iPhone 11 Pro", "iPhone.txt", "2");
					break;
				case 3: search_display("Name: iPhone 11", "iPhone.txt", "3");
					break;
				case 4: search_display("Name: iPhone XR", "iPhone.txt", "4");
					break;
				case 5: search_display("Name: iPhone X", "iPhone.txt", "5");
					break;
				default: cout << "\nWorng Choice!";
					break;
			}
			break;
		}
		case 2:
		{
			cout << "\nChoose one option:" << endl;
			ifstream googleIn;
			string showGoogle = " ";
			googleIn.open("pixel.txt");
			while (!googleIn.eof()) {
				getline(googleIn, showGoogle);
				cout << "\n";
				for (int i = 0; i < showGoogle.size(); i++)
					cout << showGoogle[i];
			}
			googleIn.close();
			int phone; cin >> phone;
			switch (phone) {
			case 1: search_display("Name: Pixel 4A", "pixelphone.txt", "1");
				break;
			case 2: search_display("Name: Pixel 4 XL", "pixelphone.txt", "2");
				break;
			case 3: search_display("Name: Pixel 4", "pixelphone.txt", "3");
				break;
			case 4: search_display("Name: Pixel 3A XL", "pixelphone.txt", "4");
				break;
			case 5: search_display("Name: Pixel 3A", "pixelphone.txt", "5");
				break;
			default: cout << "\nWorng Choice!";

			}
			break;
		}
		case 3:
		{
			cout << "\nChoose one option:" << endl;
			ifstream opIn;
			string showOp = " ";
			opIn.open("oneplus.txt");
			while (!opIn.eof()) {
				getline(opIn, showOp);
				cout << "\n";
				for (int i = 0; i < showOp.size(); i++) 
					cout << showOp[i];
			}
			opIn.close();
			int phone; cin >> phone;
			switch (phone) {
			case 1: search_display("Name: OnePlus 7", "oneplusphone.txt", "1");
				break;
			case 2: search_display("Name: OnePlus 7 Pro", "oneplusphone.txt", "2");
				break;
			case 3: search_display("Name: OnePlus 8", "oneplusphone.txt", "3");
				break;
			case 4: search_display("Name: OnePlus 8 Pro", "oneplusphone.txt", "4");
				break;
			case 5: search_display("Name: OnePlus Nord", "oneplusphone.txt", "5");
				break;
			default: cout << "\nWorng Choice!";
			}
			break;
		}
		case 4:
		{
			cout << "\nChoose one option:" << endl;
			ifstream redmiIn;
			string showRedmi = " ";
			redmiIn.open("redmi.txt");
			while (!redmiIn.eof()) {
				getline(redmiIn, showRedmi);
				cout << "\n";
				for (int i = 0; i < showRedmi.size(); i++)
					cout << showRedmi[i];
			}
			redmiIn.close();
			cout << "\n";
			int phone; cin >> phone;
			switch (phone) {
			case 1: search_display("Name: Redmi 9", "redmiphone.txt", "1");
				break;
			case 2: search_display("Name: Redmi 9A", "redmiphone.txt", "2");
				break;
			case 3: search_display("Name: Redmi Note 9", "redmiphone.txt", "3");
				break;
			case 4: search_display("Name: Redmi Note 9 Pro", "redmiphone.txt", "4");
				break;
			case 5: search_display("Name: Redmi Note 9 Pro Max", "redmiphone.txt", "5");
				break;
			default: cout << "\nWorng Choice!";
			}
			break;
		}
		case 5:
		{
			cout << "\nChoose one option:" << endl;
			ifstream samIn;
			string showSam = " ";
			samIn.open("samsung.txt");
			while (!samIn.eof()) {
				getline(samIn, showSam);
				cout << "\n";
				for (int i = 0; i < showSam.size(); i++)
					cout << showSam[i];
			}
			samIn.close();
			cout << "\n";
			int phone; cin >> phone;
			switch (phone) {
			case 1: search_display("Name: Samsung Galaxy S20", "samsungphone.txt", "1");
				break;
			case 2: search_display("Name: Samsung Galaxy S20+", "samsungphone.txt", "2");
				break;
			case 3: search_display("Name: Samsung Galaxy Z Fold 2", "samsungphone.txt", "3");
				break;
			case 4: search_display("Name: Samsung Galaxy M21", "samsungphone.txt", "4");
				break;
			case 5: search_display("Name: Samsung Galaxy A31", "samsungphone.txt", "5");
				break;
			default: cout << "\nWorng Choice!";
			}
			break;
		}
		break;
		default: cout << "\nWrong choice.";
			break;
		}
	}
	break;
	default: cout<<"\nWrong Choice!";
	}

	return 0;
}
