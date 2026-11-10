//
// Created by mirko on 10/27/26.
//


#ifndef REGELKREIS_REGLERHEADER_H
#define REGELKREIS_REGLERHEADER_H

int zweipunkt_regler(double istZustand, double sollZustand, double epsilon, int aktuellerZustand);


typedef struct {
    double kp;
    double ki;
    double kd;
    double dt;
    double integral;
    double letzterFehler;
    double outMin;
    double outMax;
    int initialisiert;
} PIDRegler;

void pid_init(PIDRegler *pid, double kp, double ki, double kd,
                double dt, double outMin, double outMax);
double pid_berechne(PIDRegler *pid, double istZustand, double sollZustand);

#endif

