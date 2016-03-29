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
int cmpt=0;

void carre(int boucle)
// Fonction carre
{
for (cmpt=0; cmpt < boucle; cmpt++)
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
        LED_BB(0);
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
        LED_BB(1);
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
}

void triangle(int boucle)
// Fonction Triangle
{
cmpt = 0;
for(cmpt=0; cmpt < boucle; cmpt++)
{
        Rapport_P9_14(1400000);
        Rapport_P9_16(1700000);
        LED_BB(0);
        LED_VERTE(0);
        LED_ROUGE(0);
        usleep(500000);

        Rapport_P9_14(1450000);
        Rapport_P9_16(1600000);
        LED_BB(1);
        LED_VERTE(1);
        LED_ROUGE(1);
        usleep(500000);

        Rapport_P9_14(1400000);
        Rapport_P9_16(1500000);
        LED_BB(0);
        LED_VERTE(0);
        LED_ROUGE(0);
        usleep(500000);
}
}

void cercle(int boucle)
// Fonction cercle
{
cmpt = 0;
while (cmpt < boucle)
{
        angle_en_degre = j;
        angle_en_radian = angle_en_degre * 3.14 / 180;
        
        float x = cos(angle_en_radian);
        long xl = (long)((x * 180000) + 1600000);
        cout << xl <<  endl;

        float y = sin(angle_en_radian);
        long yl =(long)((y * 100000) + 1450000);

        if (j == 359)
        {
                j = 0;
                cmpt++;
        }
        else j = j + 1;

        Rapport_P9_14(yl);
        Rapport_P9_16(xl);
        usleep(2000);
}
}
