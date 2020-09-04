#pragma warning(disable : 4996)
#include<iostream>
#include<fstream>
#include<cstring>
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

int main() {
	char name1[100], name2[100], name3[100], name4[100];
	char SoC1[100], SoC2[100], SoC3[100], SoC4[100];
	char screen1[20], screen2[20], screen3[20], screen4[20];
	char ram1[5], ram2[5], ram3[5], ram4[5];
	char battery1[10], battery2[10], battery3[10], battery4[10];
	char MP1[10], MP2[10], MP3[10], MP4[10];
	int c, brand;
	cout<<"Select 1 or 2: \n1)Search by name \n2)Search by brand."<<endl;
	cin >> c;
	switch(c) {
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
				cout<<"\nChoose from one of the brands listed below. \n1) Apple \n2) Google \n3) OnePlus \n4) Redmi \n5) Samsung"<<endl;
				cin >> brand;
				switch(brand) {
					case 1: 
					{		
							cout<<"\nChoose one option:"<<endl;
							ifstream appleIn;
							string showApple = " ";
							appleIn.open("apple.txt");
							while(!appleIn.eof()) { 
							getline(appleIn, showApple);
							cout<<"\n";
							for (int i = 0; i < showApple.size(); i++)
								cout << showApple[i];

							}
							int phone; cin>>phone;
							switch(phone) {
								case 1:
								{
									ifstream phoneIn;
									string search = "Name: iPhone 11 Pro Max", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("iPhone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "1") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 2:
								{
									ifstream phoneIn;
									string search = "Name: iPhone 11 Pro", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("iPhone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "2") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}

								case 3:
								{
									ifstream phoneIn;
									string search = "Name: iPhone 11", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("iPhone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "3") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 4:
								{
									ifstream phoneIn;
									string search = "Name: iPhone XR", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("iPhone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "4") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
								case 5:
								{
									ifstream phoneIn;
									string search = "Name: iPhone X", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("iPhone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "5") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
							}
							break;
					}
					case 2:
					{		
							cout<<"\nChoose one option:"<<endl;
							ifstream googleIn;
							string showGoogle = " ";
							googleIn.open("pixel.txt");
							while(!googleIn.eof()) { 
							getline(googleIn, showGoogle);
							cout<<"\n";
							for (int i = 0; i < showGoogle.size(); i++)
								cout << showGoogle[i];

							}
							int phone; cin>>phone;
							switch(phone) {
								case 1:
								{
									ifstream phoneIn;
									string search = "Name: Pixel 4A", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("pixelphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "1") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 2:
								{
									ifstream phoneIn;
									string search = "Name: Pixel 4 XL", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("pixelphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "2") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}

								case 3:
								{
									ifstream phoneIn;
									string search = "Name: Pixel 4", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("pixelphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "3") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 4:
								{
									ifstream phoneIn;
									string search = "Name: Pixel 3A XL", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("pixelphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "4") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
								case 5:
								{
									ifstream phoneIn;
									string search = "Name: Pixel 3A", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("pixelphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "5") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
							}
							break;
					}
					case 3:
					{		
							cout<<"\nChoose one option:"<<endl;
							ifstream opIn;
							string showOp = " ";
							opIn.open("oneplus.txt");
							while(!opIn.eof()) { 
							getline(opIn, showOp);
							cout<<"\n";
							for (int i = 0; i < showOp.size(); i++)
								cout << showOp[i];
							cout<<"\n";

							}
							int phone; cin>>phone;
							switch(phone) {
								case 1:
								{
									ifstream phoneIn;
									string search = "Name: OnePlus 7", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("oneplusphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "1") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 2:
								{
									ifstream phoneIn;
									string search = "Name: OnePlus 7 Pro", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("oneplusphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "2") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}

								case 3:
								{
									ifstream phoneIn;
									string search = "Name: OnePlus 8", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("oneplusphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "3") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 4:
								{
									ifstream phoneIn;
									string search = "Name: OnePlus 8 Pro", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("oneplusphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "4") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
								case 5:
								{
									ifstream phoneIn;
									string search = "Name: OnePlus Nord", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("oneplusphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "5") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
							}
							break;
					}
					case 4:
					{		
							cout<<"\nChoose one option:"<<endl;
							ifstream redmiIn;
							string showRedmi = " ";
							redmiIn.open("redmi.txt");
							while(!redmiIn.eof()) { 
							getline(redmiIn, showRedmi);
							cout<<"\n";
							for (int i = 0; i < showRedmi.size(); i++)
								cout << showRedmi[i];

							}
							cout<<"\n";
							int phone; cin>>phone;
							switch(phone) {
								case 1:
								{
									ifstream phoneIn;
									string search = "Name: Redmi 9", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("redmiphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "1") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 2:
								{
									ifstream phoneIn;
									string search = "Name: Redmi 9A", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("redmiphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "2") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}

								case 3:
								{
									ifstream phoneIn;
									string search = "Name: Redmi note 9", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("redmiphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "3") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 4:
								{
									ifstream phoneIn;
									string search = "Name: Redmi note 9 Pro", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("redmiphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "4") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
								case 5:
								{
									ifstream phoneIn;
									string search = "Name: Redmi note 9 Pro Max", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("redmiphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "5") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
							}
							break;
					}
					case 5:
					{		
							cout<<"\nChoose one option:"<<endl;
							ifstream samIn;
							string showSam = " ";
							samIn.open("samsung.txt");
							while(!samIn.eof()) { 
							getline(samIn, showSam);
							cout<<"\n";
							for (int i = 0; i < showSam.size(); i++)
								cout << showSam[i];

							}
							cout<<"\n";
							int phone; cin>>phone;
							switch(phone) {
								case 1:
								{
									ifstream phoneIn;
									string search = "Name: Samsung Galaxy S20", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("samsungphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "1") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 2:
								{
									ifstream phoneIn;
									string search = "Name: Samsung Galaxy S20+", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("samsungphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "2") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}

								case 3:
								{
									ifstream phoneIn;
									string search = "Name: Samsung Galaxy Z Fold 2", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("samsungphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "3") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i]; 
											cout<<"\n\n";
										}

									}
									break;
								}
								case 4:
								{
									ifstream phoneIn;
									string search = "Samsung Galaxy M21", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("samsungphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "4") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
								case 5:
								{
									ifstream phoneIn;
									string search = "Name: Samsung Galaxy A31", showPhone = " ";
									bool isFound = 0;
									phoneIn.open("samsungphone.txt");
									while(!phoneIn.eof()) {
										getline(phoneIn, showPhone);
										if(showPhone == search) 
											isFound = 1;
										else { 
											if(showPhone == "5") {
												isFound = 0;
												break;
											}
										}
										if(isFound == 1) { 
											for (int i = 0; i < showPhone.size(); i++)
												cout << showPhone[i];
											cout<<"\n\n"; 
										}

									}
									break;
								}
							}
							break;
					}

					default: cout<<"\nWrong choice.";
			break;
		}
		}		
		//default: cout<<"\nWrong Choice!";
	}

	return 0;
}