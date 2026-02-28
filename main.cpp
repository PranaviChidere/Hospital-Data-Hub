#include <iostream>
#include <thread>
#include "patient.h"
#include "doctor.h"
#include "appointment.h"
#include "billing.h"
#include "utils.h"

using namespace std;

mutex patientMutex;
mutex doctorMutex;
mutex appointmentMutex;
mutex billingMutex;

void bookFlow(int patientId, string specialization) {
    int doctorId;
    if (Doctor::assignDoctor(specialization, doctorId)) {
        Appointment::bookAppointment(patientId, doctorId);
    } else {
        cout << "No doctor available.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Book Appointment\n";
        cout << "4. Generate Bill\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age;
            string name;
            cout << "Enter ID Name Age: ";
            cin >> id >> name >> age;
            Patient::addPatient(id, name, age);
        }
        else if (choice == 2) {
            int id, slots;
            string name, specialization;
            cout << "Enter ID Name Specialization Slots: ";
            cin >> id >> name >> specialization >> slots;
            Doctor::addDoctor(id, name, specialization, slots);
        }
        else if (choice == 3) {
            int patientId;
            string specialization;
            cout << "Enter Patient ID and Specialization: ";
            cin >> patientId >> specialization;
            thread t1(bookFlow, patientId, specialization);
            t1.join();
        }
        else if (choice == 4) {
            int patientId, amount;
            cout << "Enter Patient ID and Amount: ";
            cin >> patientId >> amount;
            thread t2(Billing::generateBill, patientId, amount);
            t2.join();
        }
        else {
            break;
        }
    }

    return 0;
}
