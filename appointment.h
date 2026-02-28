#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <fstream>
#include <iostream>
#include "utils.h"

using namespace std;

class Appointment {
public:
    static void bookAppointment(int patientId, int doctorId) {
        lock_guard<mutex> lock(appointmentMutex);
        ofstream file("appointments.txt", ios::app);
        file << patientId << "," << doctorId << endl;
        file.close();
        cout << "Appointment booked successfully.\n";
    }
};

#endif