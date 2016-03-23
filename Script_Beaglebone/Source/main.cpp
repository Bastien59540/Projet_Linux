#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
using namespace std;

#include"led.h"
#include"init.h"
#include"forme.h"

int input;
int compteur;

int main()
{
while(1)
{       
        
cout << "Choisissez une forme : \n" << endl;                            // Menu
cout << "1. Carre\n" << endl;
cout << "2. Cercle\n" << endl;
cout << "3. Triangle\n" << endl;
cout << "CTRL + C pour quitter" << endl;
cin >> input;

init_gpio();                                                            // Initialisation des GPIO
init_pwm();                                                             // Initialisation de la PWM

LED_VERTE(0);                                                           // Led Verte eteinte
LED_ROUGE(0);                                                           // Led Rouge eteinte

switch (input)
{
case 1:                                                                 // Forme
 Carre
        cout << "\t Nombre de carre : " << endl;
        cin >> compteur;
        carre(compteur);
        break;
case 2:                                                                 // Forme
 Cercle
        cout << "\t Nombre de cercle:" << endl;
        cin >> compteur;
        cercle(compteur);
        break;
case 3:                                                                 // Forme
 Triangle
        cout << "\t Nombre de triangle:" << endl;
        cin >> compteur;
        triangle(compteur);
        break;
default:
        cout << "************ERROR*************" << endl;               // Erreu
r
        break;

}
unexport();
cin.get();
}
return 1;
}
