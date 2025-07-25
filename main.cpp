/*
===============================================================================
    Author Info
===============================================================================
    Name       : Aniruddha Manmode
    Profession : Software Developer, Programmer & Computer Engineering Student
    Experience : 1+ year in Software Development & Programming Training
    Skills     : C, C++, Python, Java (Swing, AWT, JDBC), HTML, CSS, 
                 JavaScript, SQL, Linux, Networking, Red Hat Tools
    Interests  : Full Stack Development, Teaching Programming, Building Real-World Projects

===============================================================================
    Contact & Portfolio
===============================================================================
    🌐 Portfolio Website : https://aniruddhamanmode.in/
    📸 Instagram         : https://www.instagram.com/aniruddha_manmode
    💼 LinkedIn          : https://www.linkedin.com/in/aniruddha-manmode/

===============================================================================
    Project Info
===============================================================================
    Project Name : Inventory and Billing Management System
    Language     : C++
    Description  : A console-based software for managing products, billing,
                   and product database editing, with file storage support.
                   This system is ideal for small retail or medical stores.

    Features     :
    - Add New Products
    - Display Product List
    - Edit Product Database
    - Generate Bills
    - View Billing History
    - File-Based Data Persistence (Using .dat files)

===============================================================================
*/


#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
//#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD CRD; CRD.X = x; CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

class MainData {
private :
    string product_name[100];
    int quan[100], i, num, bill, len;
    int day[100], month[100], year[100];
    static int total, times;
    float price[100], st[100];
    char ch;


public :
    MainData();

    void mainMenu();
    void addProduct();
    void billing();
    void editDB();
    void display();
    void showProduct();
    void showBills();
    
//    ~MainData(){};
};
int MainData::total;
int MainData::times = 0;

MainData::MainData() { //constructor
    day[100] = month[100] = year[100] = 0;
}

//Main Menu
void MainData::mainMenu() { system("cls");
    char choice;

        cout << "-------------------------------------------------\n";
        cout << "Main Menu ------------->>\n";
        cout << "-------------------------------------------------\n";
        cout << "1. Add New Product\n";
        cout << "2. Show products\n";
        cout << "3. Edit Database\n";
        cout << "4. Make a Bill\n";
        cout << "5. Show Billing history\n";
        cout << "6. Exit\n";
        cout << "-------------------------------------------------\n";
        cout << "\nEnter your choice : ";
        choice = getch();

        switch (choice) {
            case '1': addProduct(); break;
            case '2': showProduct(); break;
            case '3': editDB(); break;
            case '4': billing(); break;
            case '5': showBills(); break;
            case '6': exit(0);
            default:
                cout << "Enter a valid option!\n";
                mainMenu();
                break;
        }
}

// 1. Add New Product
void MainData::addProduct() { system("cls");

    ofstream out("DATA\\Ad_N_PRO.dat", ios::binary | ios::app);
    
    cout << " Enter product name: ";
    cin >> product_name[i];

    cout << " Enter product quantity: ";
    cin >> quan[i];

    cout << " Enter product price (as per product): ";
    cin >> price[i];

    cout << " Enter the expiry date (day month year): ";
    cin >> day[i] >> month[i] >> year[i]; 
    
    st[i] = price[i] * quan[i];
    
    time_t t = time(0);
	tm *local_time = localtime(&t);
    out << "\n " << ctime(&t);
    out << "\n Product Name      : " << product_name[i];
    out << "\n Available Now     : " << quan[i] << " Products";
    out << "\n Price             : " << price[i] << " Per Product";
    out << "\n Price of Stock    : " << st[i];
    out << "\n Expity Date       : " << day[i] << "-" << month[i] << "-" << year[i] << "\n" <<endl;
    out << "-----------------------------------------------\n";
    
    total = 0;
    times++;
    i++;
    
    out.close();
    
    choice :
    	system("cls");
	    cout << "Add one more ? (Y/N) 'E' for exit : ";
	    cin >> ch;
	    
	    if ( ch == 'y' || ch == 'Y' ) {
	    	addProduct();
		} else if ( ch == 'n' || ch == 'N' ) {
			mainMenu();
		} else if (ch == 'e' || ch == 'Y') {
			exit(0);
		} else {
			cout << "Enter the valid option !" << endl;
			goto choice;
		}
    
}

// 2. Show products 
void MainData::showProduct() { system("cls");

	cout << " 1. Recent Added Products" << endl;
	cout << " 2. All Time" << endl;
	
	char chh;
	ifstream in;
	in.open("DATA\\Ad_N_PRO.dat",ios::in);
	char choice;
	cout << "Enter the choice : ";
	choice = getch();
	
	if(choice == '1') { system("cls");
		cout << "-------------------------------------------------\n";
	    cout << "Show Recently added Prodects ------------->>\n";
	    cout << "-------------------------------------------------\n\n";
	    
	    cout << " Product name" << "\t\t\t\t Quantity" << "\t\t\t Price" << "\t\t\t\t Expiry date \n" << endl;
		
		total = 0;
		for (int i = 0; i < times; i++) { total = total +1;
			cout << " " << total << ". " << product_name[i] << "\t\t\t\t " << quan[i] << "\t\t\t\t " << st[i]<< "\t\t\t\t " << day[i]<<"-"<<month[i]<<"-"<<year[i]<<endl<<endl;
		}
	    getch();
	} else if(choice == '2') { system("cls");
		cout << "-------------------------------------------------\n";
	    cout << "Show All Time Prodects ------------->>\n";
	    cout << "-------------------------------------------------\n\n";
	    
	    while(!in.eof()) {
	    	chh = in.get();
	    	cout << chh;
		}
		getch();
	} 
	    
    while(true) {
        system("cls");
        cout << "Return Main menu ?(Y/N) OR See other Products history (press any key) : ";
        ch = getch();

        if (ch == 'y' || ch == 'Y') {
            mainMenu();
        } else if (ch == 'n' || ch == 'N') {
                exit(0);
        } else {
            showProduct();
        }
	}
}

// 3. Edit Database 
void MainData::editDB() { system("cls");

    ifstream inputFile("DATA\\Ad_N_PRO.dat", ios::in);
    ofstream tempFile("DATA\\Temp.dat", ios::out);
    bool productFound;
    
    string pname;
    cout << "Enter the product name to edit: ";
    cin >> pname;
    
    times++;
	productFound = false;
    for (int idx = 0; idx < times; ++idx) {
        inputFile >> product_name[idx] >> quan[idx] >> price[idx] >> day[idx] >> month[idx] >> year[idx];

        if (product_name[idx] == pname) {
            cout << "Enter new product name: ";
            cin >> product_name[idx];
            cout << "Enter new quantity: ";
            cin >> quan[idx];
            cout << "Enter new price: ";
            cin >> price[idx];
            cout << "Enter the expiry date (day month year): ";
            cin >> day[idx] >> month[idx] >> year[idx];
            productFound = true;
        }

        tempFile << product_name[idx] << " " << quan[idx] << " " << price[idx] << " " << day[idx] << " " << month[idx] << " " << year[idx] << "\n";
    } 

    if (!productFound) {
        cout << "Product not found." << endl;
    } else {
        cout << "Product edited successfully." << endl;
    }

    inputFile.close();
    tempFile.close();

    remove("DATA\\Ad_N_PRO.dat");
    rename("DATA\\Temp.dat", "DATA\\Ad_N_PRO.dat");

    getch();
    mainMenu();
}

// 4. Billing section 
void MainData::billing() { system("cls");

	ofstream ob;

    cout << "-------------------------------------------------\n";
    cout << "Billing ------------->>\n";
    cout << "-------------------------------------------------\n\n";

    cout << "Enter the number of products: ";
    cin >> num;

    for(i = 0; i < num; i++) {
        cout << "\nEnter name of product : ";
        cin >> product_name[i];

        cout << "Enter the quantity : ";
        cin >> quan[i];
        
        cout << "Enter the price : ";
        cin >> price[i];
    }
    display();
    getch();
    
/*------------------Save Bills--------------------*/    
    save : system("cls");
    
	char sv;	
	time_t t = time(0);
	tm *local_time = localtime(&t);
    
	cout << "Do you want to save bill ? (Y/N) : ";
	sv = getch();
	
	if(sv == 'y' || sv == 'Y') {
		ob.open("DATA\\Bills.dat", ios::out | ios::app);
		
		for(i = 0; i < num; i++) {
			ob << ctime(&t) << endl;
			ob << "Product  : " << product_name[i] << endl;
			ob << "Quantity : " << quan[i] << endl;
			ob << "Price    : " << price[i] << "\n" << endl;
			ob << "-----------------------------------------" << "\n" << endl;
		}
		
		system("cls");
		
		ob.close();
		cout << "Bill is saved !" << endl;
		system("pause");
	} else if(sv == 'n' || sv == 'N') {
		goto choice;
	} else {
		goto save;
		
	}
    
    choice :
    	system("cls");
	    cout << "Make one more bill ? (Y/N) 'E' for exit : ";
	    ch = getch();
	    
	    if ( ch == 'y' || ch == 'Y' ) {
	    	billing();
		} else if ( ch == 'n' || ch == 'N' ) {
			mainMenu();
		} else if (ch == 'e' || ch == 'Y') {
			exit(0);
		} else {
			cout << "Enter the valid option !" << endl;
			goto choice;
		}
		
}

// display the elements which is entered in billing section 
void MainData::display() { system("cls");
	int j = 1, y = 5;
	
    gotoxy(4,2);
    cout << "Product name";

    gotoxy(35, 2);
    cout << "Quantity";

    gotoxy(55, 2);
    cout << "Price";

	// cout << " Product name " << "\t\t\t\t\t Quantity " << "\t\t Price \n" << endl;
	
	for(i = 0; i < num; i++ ) {
		// cout << " " << j << ". " << product_name[i] << "\t\t\t\t\t    " << quan[i] << "\t\t\t  " << price[i] << endl;

        gotoxy(4, y);
        cout << j << ". " << product_name[i];

        gotoxy(35, y);
        cout << quan[i];

        gotoxy(55, y);
        cout << price[i];
        
		j++;
        y = y + 2;
		bill += price[i];
	}
	
	cout << "\n\n\n    Total price : " << bill;
}

void MainData::showBills() { system("cls");
	char chh;
	ifstream in;
	in.open("DATA\\Bills.dat",ios::in);
	
	cout << "\n-------------------------------------------------\n";
	cout << "Billing History ------------->>\n";
	cout << "-------------------------------------------------\n\n";
	    
	    while(!in.eof()) {
	    	chh = in.get();
	    	cout << chh;
		}
	getch();
}

int main() { 
	int j;
    MainData m1[200];
    
    m1[j].mainMenu();
    
    return 0;
}
