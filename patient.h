#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"

using namespace std;

class Patient {
public:
    static void addPatient(int id, string name, int age) {
        lock_guard<mutex> lock(patientMutex);
        ofstream file("patients.txt", ios::app);
        file << id << "," << name << "," << age << endl;
        file.close();
        cout << "Patient added successfully.\n";
    }
};

#endif