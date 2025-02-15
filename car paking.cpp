#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h> // For _getch() on Windows

using namespace std;

class ParkingSystem {
public:
    int vno;
    float count;
    char dname[50], timeSlot[20], date[11];
    time_t now; 
    char dt[20]; 
    tm* ltm;

    void input() {
        cout << "\n\n\t\tEnter the name of driver: ";
        cin.ignore();
        cin.getline(dname, 50);
        cout << "\n\n\t\tEnter the car no: ";
        cin >> vno;
        cout << "\n\n\t\tEnter the number of hours of stay: ";
        cin >> count;
        cout << "\n\n\t\tEnter the date of reservation (dd/mm/yyyy): ";
        cin >> date;
        cout << "\n\n\t\tEnter the time slot (choose between 06:00 - 22:00): ";
        cin >> timeSlot;

        now = time(0);
        ltm = localtime(&now); 
        strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M:%S", ltm);
        
        if (count <= 8) {
            cout << "\n\n\t\tParking Available! Your parking slot has been reserved.";
        } else {
            cout << "\n\n\t\tParking not possible!!";
        }
    }

    void output() {
        cout << "\n\n\t\tThe Driver Name: " << dname;
        cout << "\n\n\t\tThe Car No: " << vno;
        cout << "\n\n\t\tThe Hours Of Stay: " << count;
        cout << "\n\n\t\tThe Date of Parking: " << date;
        cout << "\n\n\t\tThe Time Slot Of Parking: " << timeSlot;
        cout << "\n\n\t\tThe Time and Date of Reservation: " << dt;
    }
};

class Car : public ParkingSystem {
public:
    void calculateCharges() {
        char x;
        cout << "\n\t\n\tAre you a V.I.P (y/n): ";
        cin >> x;
        float rate = (x == 'y') ? 20.0 : 25.0;
        cout << "\n\t\n\tThe total expense during parking: " << (count * rate) << " rupees";
    }
};

class ParkingOperations {
public:
    void deleteRecord() {
        int n, flag = 0;
        cout << "\n\n\t\tEnter the car number you want to cancel reservation: ";
        cin >> n;

        ifstream inFile("parking3.csv", ios::binary);
        ofstream outFile("temp.csv", ios::out | ios::binary);
        
        Car a;
        while (inFile.read((char*)&a, sizeof(a))) {
            if (a.vno == n) {
                flag = 1;
            } else {
                outFile.write((char*)&a, sizeof(a));
            }
        }
        if (flag == 1) {
            cout << "\n\n\t\tReservation cancelled.";
        } else {
            cout << "\n\n\t\tReservation not found.";
        }

        inFile.close();
        outFile.close();
        remove("parking3.csv");
        rename("temp.csv", "parking3.csv");
    }
};

class ParkingSystemMenu : public ParkingOperations {
public:
    void displayMenu() {
        int choice;
        Car a;
        while (true) {
            cout << "\n\n\t\t ====== CAR PARKING RESERVATION SYSTEM ======";
            cout << "\n\n\t\t\t======================";
            cout << "\n\n\t\t\t  1. Reservation of Parking space";
            cout << "\n\n\t\t\t  2. Total no of Parking spots reserved";
            cout << "\n\n\t\t\t  3. Parking charges a car with details";
            cout << "\n\n\t\t\t  4. Total parking charges of all cars with details";
            cout << "\n\n\t\t\t  5. Cancellation of Reservation of a car";
            cout << "\n\n\t\t\t  6. Exit Program";
            cout << "\n\t\t\t======================";
            cout << "\n\n";
            cout << "\t\t\tSelect Your Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    char f;
                    cout << "\n\n\t\t==Do You Want to continue==y/n ";
                    cin >> f;
                    if (f == 'y') {
                        ofstream f1("parking3.csv", ios::binary | ios::app);
                        a.input();
                        f1.write((char*)&a, sizeof(a));
                        f1.close();
                    }
                    break;
                }
                case 2: {
                    cout << "\n\n\t\t=== View the Records in the Parking Reservation Database ===";
                    ifstream infile("parking3.csv", ios::binary);
                    int d = 1;
                    bool carsParked = false;
                    while (infile.read((char*)&a, sizeof(a))) {
                        cout << "\n\n\tThe Car position in parking lot: " << d++;
                        carsParked = true;
                        a.output();
                        cout << "\n";
                        system("PAUSE");
                    }
                    infile.close();
                    if (!carsParked) cout << "\n\n\t\tNo cars Reserved.\n";
                    break;
                }
                case 5: {
                    deleteRecord();
                    break;
                }
                case 3: {
                    ifstream infile("parking3.csv", ios::binary);
                    int n, flag = 0;
                    cout << "\n\tCar number to search for: ";
                    cin >> n;
                    while (infile.read((char*)&a, sizeof(a))) {
                        if (a.vno == n) {
                            a.output();
                            a.calculateCharges();
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        cout << "\n\n\t\tNo car reservation found!!!";
                    }
                    infile.close();
                    break;
                }
                case 4: {
                    ifstream infile("parking3.csv", ios::binary);
                    while (infile.read((char*)&a, sizeof(a))) {
                        a.output();
                        a.calculateCharges();
                        cout << "\n";
                    }
                    infile.close();
                    break;
                }
                case 6: {
                    cout << "\t\t\tThank you\n";
                    exit(0);
                }
                default: {
                    cout << "\n\n\t\tInvalid input";
                    cout << "\n\n\t\tPress Enter to continue";
                }
            }
            cin.ignore(); 
            cin.get();        
        }
    }
};

int login() {
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\t\t\t\t\tCar Parking Reservation System Login";
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13) { // character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pass") {
        cout << "\n\n\n\n\t\t\t\t\tAccess Granted! Welcome To Our System \n\n";
        system("PAUSE");
        system("CLS");
    } else {
        cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
        system("PAUSE");
        system("CLS");
        return login(); // Recursively call for retry
    }
    return 0; // Return success
}

int main() {
    login();
    ParkingSystemMenu parkingMenu;
    parkingMenu.displayMenu();
    return 0;
}

