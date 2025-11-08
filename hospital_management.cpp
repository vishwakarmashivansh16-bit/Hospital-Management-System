/*
------------------------------------------------------------
|   Project Title : Hospital Management System (C++)        |
|   Author        : SHIVANSH VISHWAKARMA                    |
|   Language      : C++                                     |
|   Date Created  : November 2025                           |
|   Version       : 1.0                                     |
|-----------------------------------------------------------|
|   Description:                                            |
|   This project is a console-based Hospital Management     |
|   System that allows the user to manage Patients,         |
|   Doctors, Appointments, and Billing Information using    |
|   File Handling in C++.                                   |
|                                                           |
|   Features:                                               |
|   1. Add and View Patient Records                         |
|   2. Add and View Doctor Records                          |
|   3. Schedule Appointments                                |
|   4. Generate and View Bills                              |
|   5. Data persistence using text files                    |
|-----------------------------------------------------------|
*/

#include<bits/stdc++.h>
using namespace std;

/*------------------------------------------------------------
| Helper Function: split()                                    |
| Splits a string using a given delimiter (default '|') and   |
| returns a vector of separated fields. Used for file parsing.|
-------------------------------------------------------------*/
vector<string> split(const string &line, char delimiter = '|') {

    vector<string> result;     // Vector to store all separated fields (output list)
    stringstream ss(line);     // Create a string stream object from the input line
    string field;              // Temporary string to hold each extracted field

    // Loop runs until all fields separated by the delimiter are extracted
    while (getline(ss, field, delimiter))
        result.push_back(field);   // Add each extracted field to the vector

    return result;             // Return the vector containing all separated parts
}

/*------------------------------------------------------------
| Class: hospital
| Contains all attributes and functions related to
| Patient, Doctor, Appointment, and Billing management.
-------------------------------------------------------------*/
class hospital {
public:
    // Common Attributes
    string namep, named, gender, disease, roomno, specialisation, availability, patientid, date, time;
    char idd[20], idp[20], appointmentid[20];
    float age = 0, doctorfees = 0, roomcharge = 0, total = 0;
    long long contact = 0;

    /*------------------ PATIENT SECTION -------------------*/
    void patient() {
        cout << "Enter The Name of The Patient : ";
        cin.ignore();
        getline(cin, namep);

        cout << "Enter The ID of The Patient : ";
        cin >> idp;

        cout << "Enter The Age of The Patient : " ;
        cin >> age;

        cout << "Enter The Gender of The patient :" ;
        cin >> gender;

        cout << "Enter The Disease of The Patient :" ;
        cin.ignore();
        getline(cin, disease);

        cout << "Enter The RoomNo of The Patient :" ;
        getline(cin, roomno);

        cout << "Enter The Doctor Who is Attending :";
        getline(cin, named);
    }

    /*------------------ DOCTOR SECTION -------------------*/
    void doctor() {
        cout << "Enter The Doctor Name :" ;
        cin.ignore();
        getline(cin, named);

        cout << "Enter The ID of The Doctor :" ;
        cin >> idd;

        cout << "Enter The Specialisation of The doctor : ";
        cin.ignore();
        getline(cin, specialisation);

        cout << "Enter The Availability of The doctor : " ;
        getline(cin, availability);
    }

    /*------------------ APPOINTMENT SECTION -------------------*/
    void appointment() {
        cout << "Enter The AppointmentID of Patient :" ;
        cin.ignore();
        cin >> appointmentid;

        cout << "Enter The Patient ID :";
        cin >> idp;

        cout << "Enter The ID of The Doctor :" ;
        cin >> idd;

        cout << "Date of The Appointment :" ;
        cin.ignore();
        getline(cin, date);
    }

    /*------------------ BILLING SECTION -------------------*/
    void bill() {
        cout << "Enter The Name of The Patient :";
        cin.ignore();
        getline(cin, namep);

        cout << "Enter The ID of The Patient : " ;
        cin >> idp;
        cin.ignore();

        cout << "Enter The Doctor Name :" ;
        getline(cin, named);

        cout << "Enter The ID of The Doctor :" ;
        cin >> idd;

        cout << "Doctor Fees :" ;
        cin >> doctorfees;

        cout << "Room Charge :" ;
        cin >> roomcharge;

        // Calculate total bill
        total = doctorfees + roomcharge;
        cout << "Total :" << total << endl;
    }

    /*------------------ DISPLAY FUNCTIONS -------------------*/
    void showdata1() {
        cout << left
             << setw(25) << namep
             << setw(15) << idp
             << setw(10) << age
             << setw(12) << gender
             << setw(20) << disease
             << setw(12) << roomno
             << setw(20) << named
             << endl;
    }

    void showdata2() {
        cout << left
             << setw(25) << named
             << setw(15) << idd
             << setw(25) << specialisation
             << setw(15) << availability
             << endl;
    }

    void showdata3() {
        cout << left
             << setw(15) << idp
             << setw(20) << appointmentid
             << setw(15) << idd
             << setw(15) << date
             << endl;
    }

    void showdata4() {
        cout << left
             << setw(25) << namep
             << setw(15) << idp
             << setw(20) << named
             << setw(15) << idd
             << setw(15) << doctorfees
             << setw(15) << roomcharge
             << setw(15) << total
             << endl;
    }

    /*------------------ GETTER FUNCTIONS -------------------*/
    const char* getIDP() { return idp; }
    const char* getIDD() { return idd; }
    string getAPP() { return appointmentid; }
    float BILL() { return total; }
};

/*------------------------------------------------------------
| Function Prototypes
-------------------------------------------------------------*/
void addpatient();
void viewpatient(string idp);
void adddoctor();
void viewdoctor(string idd);
void scheduleappointment();
void viewappointment(string idp);
void generatebill();
void viewbill(string idp);

/*------------------------------------------------------------
| Function: main()
| Displays menu and calls the appropriate functions based
| on user’s choice.
-------------------------------------------------------------*/
int main() {
    int choice;
    string idp, idd;
    do {
        cout << "========================================================" << endl;
        cout << "              HOSPITAL MANAGEMENT SYSTEM                " << endl;
        cout << "========================================================" << endl;
        cout << "1. ADD PATIENT" << endl;
        cout << "2. VIEW PATIENT" << endl;
        cout << "3. ADD DOCTOR" << endl;
        cout << "4. VIEW DOCTOR" << endl;
        cout << "5. APPOINTMENT SCHEDULE" << endl;
        cout << "6. VIEW APPOINTMENT" << endl;
        cout << "7. GENERATE BILL" << endl;
        cout << "8. VIEW BILL" << endl;
        cout << "9. EXIT PROGRAM" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addpatient();
                break;
            case 2:
                cout << "Enter The Patient ID" << endl;
                cin.ignore();
                getline(cin, idp);
                viewpatient(idp);
                break;
            case 3:
                adddoctor();
                break;
            case 4:
                cout << "Enter The Doctor ID" << endl;
                cin.ignore();
                getline(cin, idd);
                viewdoctor(idd);
                break;
            case 5:
                scheduleappointment();
                break;
            case 6:
                cout << "Enter The Patient ID" << endl;
                cin.ignore();
                getline(cin, idp);
                viewappointment(idp);
                break;
            case 7:
                generatebill();
                break;
            case 8:
                cout << "Enter The Patient ID" << endl;
                cin.ignore();
                getline(cin, idp);
                viewbill(idp);
                break;
            case 9:
                cout << "EXITING PROGRAM..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 9);
    return 0;
}

/*------------------------------------------------------------
| Function: addpatient()
| Takes patient details from user and writes to 'patient.txt'
-------------------------------------------------------------*/
void addpatient() {
    ofstream file("patient.txt", ios::app);
    hospital p;
    p.patient();
    file << p.idp << "|" << p.namep << "|" << p.age << "|" << p.gender << "|"
         << p.disease << "|" << p.roomno << "|" << p.named << "\n";
    file.close();
    cout << "\nPatient data recorded successfully.\n";
}

/*------------------------------------------------------------
| Function: viewpatient()
| Displays patient details by matching ID from 'patient.txt'
-------------------------------------------------------------*/
void viewpatient(string idp) {
    ifstream file("patient.txt");
    string line;
    bool found = false;

    cout << left << setw(15) << "ID" << setw(20) << "NAME"
         << setw(10) << "AGE" << setw(12) << "GENDER"
         << setw(20) << "DISEASE" << setw(12) << "ROOM"
         << setw(20) << "DOCTOR" << endl;
    cout << "-----------------------------------------------------------------------------------------------------\n";

    while (getline(file, line)) {
        auto data = split(line, '|');
        if (data.size() >= 7 && data[0] == idp) {
            cout << left << setw(15) << data[0]
                 << setw(20) << data[1]
                 << setw(10) << data[2]
                 << setw(12) << data[3]
                 << setw(20) << data[4]
                 << setw(12) << data[5]
                 << setw(20) << data[6] << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Record not found!\n";
    file.close();
}

/*------------------------------------------------------------
| Function: adddoctor()
| Records doctor details and saves to 'doctor.txt'
-------------------------------------------------------------*/
void adddoctor() {
    ofstream file("doctor.txt", ios::app);
    hospital d;
    d.doctor();
    file << d.idd << "|" << d.named << "|" << d.specialisation << "|" << d.availability << "\n";
    file.close();
    cout << "\nDoctor data recorded successfully.\n";
}

/*------------------------------------------------------------
| Function: viewdoctor()
| Displays doctor details by ID from 'doctor.txt'
-------------------------------------------------------------*/
void viewdoctor(string idd) {
    ifstream file("doctor.txt");
    string line;
    bool found = false;

    cout << left << setw(15) << "ID" << setw(20) << "NAME"
         << setw(25) << "SPECIALISATION" << setw(15) << "AVAILABILITY" << endl;
    cout << "------------------------------------------------------------------------------------------------------\n";

    while (getline(file, line)) {
        auto data = split(line, '|');
        if (data.size() >= 4 && data[0] == idd) {
            cout << left << setw(15) << data[0]
                 << setw(20) << data[1]
                 << setw(25) << data[2]
                 << setw(15) << data[3] << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Record not found!\n";
    file.close();
}

/*------------------------------------------------------------
| Function: scheduleappointment()
| Creates and saves appointment details in 'appointment.txt'
-------------------------------------------------------------*/
void scheduleappointment() {
    ofstream file("appointment.txt", ios::app);
    hospital a;
    a.appointment();
    file << a.appointmentid << "|" << a.idp << "|" << a.idd << "|" << a.date << "\n";
    file.close();
    cout << "\nAppointment scheduled successfully.\n";
}

/*------------------------------------------------------------
| Function: viewappointment()
| Displays appointment details for a given Patient ID
-------------------------------------------------------------*/
void viewappointment(string idp) {
    ifstream file("appointment.txt");
    string line;
    bool found = false;

    cout << left << setw(20) << "APPOINTMENT ID"
         << setw(15) << "PATIENT ID"
         << setw(15) << "DOCTOR ID"
         << setw(15) << "DATE" << endl;
    cout << "------------------------------------------------------------------------------------------------------\n";

    while (getline(file, line)) {
        auto data = split(line, '|');
        if (data.size() >= 4 && data[1] == idp) {
            cout << left << setw(20) << data[0]
                 << setw(15) << data[1]
                 << setw(15) << data[2]
                 << setw(15) << data[3] << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Record not found!\n";
    file.close();
}

/*------------------------------------------------------------
| Function: generatebill()
| Creates a bill entry and writes it to 'bill.txt'
-------------------------------------------------------------*/
void generatebill() {
    ofstream file("bill.txt", ios::app);
    hospital b;
    b.bill();
    file << b.idp << "|" << b.namep << "|" << b.named << "|" << b.idd << "|"
         << b.doctorfees << "|" << b.roomcharge << "|" << b.total << "\n";
    file.close();
    cout << "\nBill generated successfully.\n";
}

/*------------------------------------------------------------
| Function: viewbill()
| Displays patient billing information from 'bill.txt'
-------------------------------------------------------------*/
void viewbill(string idp) {
    ifstream file("bill.txt");
    string line;
    bool found = false;

    cout << left << setw(15) << "PATIENT ID"
         << setw(20) << "PATIENT NAME"
         << setw(20) << "DOCTOR NAME"
         << setw(15) << "DOCTOR ID"
         << setw(15) << "FEES"
         << setw(15) << "ROOM"
         << setw(15) << "TOTAL" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------\n";

    while (getline(file, line)) {
        auto data = split(line, '|');
        if (data.size() >= 7 && data[0] == idp) {
            cout << left << setw(15) << data[0]
                 << setw(20) << data[1]
                 << setw(20) << data[2]
                 << setw(15) << data[3]
                 << setw(15) << data[4]
                 << setw(15) << data[5]
                 << setw(15) << data[6] << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Record not found!\n";
    file.close();
}
//THANKS!!