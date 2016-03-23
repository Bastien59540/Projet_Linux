#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
#include<math.h>
using namespace std;

#include "led.h"
#include "init.h"
#include "forme.h"
#include "math.h"
int flag = 0;
float angle_en_radian = 0;
long angle_en_degre = 0;
int j = 0;
void carre()
{
if (flag == 0)
{
        cout << "En haut a gauche" << endl;
        Rapport_P9_14(1400000);
        Rapport_P9_16(1500000);
        LED_BB(1); 
        LED_VERTE(0);   
        LED_ROUGE(0);
        usleep(300000);
        flag = 1;
}

if (flag == 1)
{
        cout << "En bas a gauche" << endl;
        Rapport_P9_14(1500000);
        Rapport_P9_16(1500000);
        LED_VERTE(0);
        LED_ROUGE(1);
        usleep(300000);
        flag = 2;
}

if (flag == 2)
{
        cout << "En bas a droite" << endl;
        Rapport_P9_14(1500000);
        Rapport_P9_16(1700000);
        LED_BB(0);
        LED_VERTE(1);
        LED_ROUGE(1);
        usleep(300000);
        flag = 3;
}

if (flag == 3)
{
        cout << "En haut a droite" << endl;
        Rapport_P9_14(1400000);
        Rapport_P9_16(1700000);
        LED_BB(0);
        LED_VERTE(1);
        LED_ROUGE(0);
        usleep(300000);
        flag = 0;
}
}
