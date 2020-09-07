#pragma warning(disable : 4996)
#include<iostream>
#include<fstream>
#include <cstring>
using namespace std;

void wirteToFile(string fileName, string phone, string soc, string ram, string bat, string ss, string mp) {
	ofstream fout;
	fout.open(fileName, ios::app);
	fout << phone <<"\n"<< soc<<"\n"<<ram<<"\n"<<bat<<"\n"<<ss<<"\n"<<mp;
	fout << "\nx";
}

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
void search_by_word(string search, string fileName) {
	string showPhone = " ", end = "x";
	bool isFound = 0;
	ifstream phoneIn;
	phoneIn.open(fileName);
	while (!phoneIn.eof()) {
		getline(phoneIn, showPhone);
		if (showPhone == search)
			isFound = 1;
		if (showPhone == end && isFound == 1) {
			isFound = 0;
			break;
		}				
		if (isFound == 1) {
			for (int i = 0; i < showPhone.size(); i++)
				cout << showPhone[i];
			cout << "\n\n";
		}
	}
}

int main() {
	int ch;
	cout << "Select 1 or 2: \n1)Search by name \n2)Search by brand." << endl;
	cin >> ch;
	switch (ch) {
	case 1:
	{
		string search;
		cout << "Enter the name of the phone: ";
		std::cin.clear();
  		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, search);
		search_by_word(search, "allphones.txt");
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
	default: cout << "\nWrong Choice!";
	}
	return 0;
}
