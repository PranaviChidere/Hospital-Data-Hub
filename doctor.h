#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "utils.h"

using namespace std;

class Doctor {
public:
    static void addDoctor(int id, string name, string specialization, int slots) {
        lock_guard<mutex> lock(doctorMutex);
        ofstream file("doctors.txt", ios::app);
        file << id << "," << name << "," << specialization << "," << slots << endl;
        file.close();
        cout << "Doctor added successfully.\n";
    }

    static bool assignDoctor(string specialization, int &doctorId) {
        lock_guard<mutex> lock(doctorMutex);

        ifstream file("doctors.txt");
        vector<string> lines;
        string line;
        bool assigned = false;

        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, spec, slotsStr;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, spec, ',');
            getline(ss, slotsStr, ',');

            int slots = stoi(slotsStr);

            if (!assigned && spec == specialization && slots > 0) {
                slots--;
                doctorId = stoi(id);
                assigned = true;
            }

            lines.push_back(id + "," + name + "," + spec + "," + to_string(slots));
        }

        file.close();

        ofstream outFile("doctors.txt");
        for (auto &l : lines)
            outFile << l << endl;

        outFile.close();
        return assigned;
    }
};

#endif