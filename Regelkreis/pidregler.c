#include "ReglerHeader.h"

void pid_init(PIDRegler *pid, double kp, double ki, double kd,
              double dt, double outMin, double outMax) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->dt = dt;
    pid->outMin = outMin;
    pid->outMax = outMax;
    pid->integral = 0.0;
    pid->letzterFehler = 0.0;
    pid->initialisiert = 0;
}

double pid_berechne(PIDRegler *pid, double istZustand, double sollZustand) {
    double fehler = sollZustand - istZustand;

    double p = pid->kp * fehler;

    pid->integral += fehler * pid->dt;
    if (pid->ki != 0.0) {

        double iMin = pid->outMin / pid->ki;
        double iMax = pid->outMax / pid->ki;

        if (pid->integral > iMax) {
            pid->integral = iMax;
        }
        if (pid->integral < iMin) {
            pid->integral = iMin;
        }
    }
    double i = pid->ki * pid->integral;

    double d = 0.0;
    if (pid->initialisiert) {
        d = pid->kd * (fehler - pid->letzterFehler) / pid->dt;
    }
    pid->letzterFehler = fehler;
    pid->initialisiert = 1;

    double u = p + i + d;
    if (u > pid->outMax) u = pid->outMax;
    if (u < pid->outMin) u = pid->outMin;
    return u;
}
