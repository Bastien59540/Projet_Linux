#ifndef INIT_H
#define INIT_H

#include<iostream>
#include<stdio.h>
#include<unistd.h>

using namespace std;

void init_gpio();
void init_pwm();
void close();
void unexport();
void Rapport_P9_14(int rapport);
void Rapport_P9_16(int rapport);
#endif
