#ifndef UTILS_H
#define UTILS_H

#include <mutex>

extern std::mutex patientMutex;
extern std::mutex doctorMutex;
extern std::mutex appointmentMutex;
extern std::mutex billingMutex;

#endif