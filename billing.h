#ifndef BILLING_H
#define BILLING_H

#include <fstream>
#include <iostream>
#include "utils.h"

using namespace std;

class Billing {
public:
    static void generateBill(int patientId, int amount) {
        lock_guard<mutex> lock(billingMutex);
        ofstream file("billing.txt", ios::app);
        file << patientId << "," << amount << endl;
        file.close();
        cout << "Bill generated successfully.\n";
    }
};

#endif