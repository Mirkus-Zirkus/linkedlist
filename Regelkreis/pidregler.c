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

