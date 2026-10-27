//
// Created by mirko on 10/27/26.
//

#include "ReglerHeader.h"

#ifndef REGELKREIS_REGLERHEADER_H
#define REGELKREIS_REGLERHEADER_H

int zweipunkt_regler(double istZustand, double sollZustand, double epsilon, int aktuellerZustand);

#endif //REGELKREIS_REGLERHEADER_H
