#include "init.h"

const char *IO_DIR1="/sys/class/gpio/gpio60/direction";015
const char *IO_DIR2="/sys/class/gpio/gpio30/direction";

FILE *periode_P9_14 = NULL;
FILE *periode_P9_16 =NULL;
FILE *duty_P9_14 = NULL;.cp
FILE *duty_P9_16 = NULL;Nov 12 19:18:09 2015
FILE *polarity_P9_14 = NULL;
FILE *polarity_P9_16 = NULL;
FILE *running = NULL;a
FILE *export_file = NULL; up with two different instances of the same
FILE *export_file1 =NULL;
FILE *unexport_file = NULL;
FILE *unexport_file1 =NULL;
FILE *IO_direction = NULL;
FILE *IO_direction1 = NULL;
    
int periode = 20000000;
int run1 = 1;
int rapport = 1400000;it anyway, (R)ecover, (D)elete it, (Q)uit, (A)bort:[   51.319726] libphy: PHY 4a101000.mdio:01 not found
int polarite = 0;

char str[]="60";
char str1[]="high";
char str2[]="low";
char str3[]="30";

void init_gpio ()
{
        cout << "Initialise GPIO\n" << endl;
        export_file = fopen("/sys/class/gpio/export", "w");
                        // Export GPIO60
        fwrite(str, sizeof(char), sizeof(str), export_file);
        fclose(export_file);

        export_file1 = fopen("/sys/class/gpio/export", "w");
                        // Export GPIO30
        fwrite(str3, 1, sizeof(str3), export_file1);
        fclose(export_file1);

        cout << "Initialisation en sortie" << endl;
                        // GPIO60 en sortie
        IO_direction = fopen(IO_DIR1, "w");
        fwrite(str2, 1, sizeof(str2), IO_direction);
        fclose(IO_direction);

        IO_direction1 = fopen(IO_DIR2, "w");
                        // GPIO30 en sortie
        fwrite(str2, 1, sizeof(str2), IO_direction1);
        fclose(IO_direction1);


}

void init_pwm()
{
        periode_P9_14 = fopen("/sys/devices/ocp.3/pwm_test_P9_14.10/period", "w");                      // Initialisation de la periode
        fseek(periode_P9_14, 0, SEEK_SET);
        fprintf(periode_P9_14, "%d", periode);
        fflush(periode_P9_14);

        periode_P9_16 = fopen("/sys/devices/ocp.3/pwm_test_P9_16.11/period", "w");
        fseek(periode_P9_16, 0, SEEK_SET);
        fprintf(periode_P9_16, "%d", periode);
        fflush(periode_P9_16);
        usleep(500000);

        cout << "Initialisation des periode a :" << periode << endl;

        duty_P9_14 = fopen("/sys/devices/ocp.3/pwm_test_P9_14.10/duty", "w");
                        // Initialisation du rapport
        fseek(duty_P9_14, 0, SEEK_SET);
        fprintf(duty_P9_14, "%d", rapport);
        fflush(duty_P9_14);

        duty_P9_16 = fopen("/sys/devices/ocp.3/pwm_test_P9_16.11/duty", "w");
        fseek(duty_P9_16, 0, SEEK_SET);
        fprintf(duty_P9_16, "%d", rapport);
        fflush(duty_P9_16);

        polarity_P9_14 = fopen("/sys/devices/ocp.3/pwm_test_P9_14.10/polarity", "w");                   // Initialisation de la polarite
        fseek(polarity_P9_14, 0, polarite);
        fprintf(polarity_P9_14, "%d", polarite);
        fflush(polarity_P9_14);

        polarity_P9_16 = fopen("/sys/devices/ocp.3/pwm_test_P9_16.11/polarity", "w");
        fseek(polarity_P9_16, 0, polarite);
        fprintf(polarity_P9_16, "%d", polarite);
        fflush(polarity_P9_16);
        cout << "Initialisation des polarites a:" << polarite << endl;

        running = fopen("/sys/devices/ocp.3/pwm_test_P9_14.10/run", "w");
        fseek(running, 0, SEEK_SET);
        fprintf(running, "%d", run1);
        fflush(running);

}

void close()
{
        fclose(periode_P9_14);
        fclose(periode_P9_16);
        fclose(duty_P9_14);
        fclose(duty_P9_16);
        fclose(running);
        //fclose(LEDHandle);
        fclose(polarity_P9_14);
        fclose(polarity_P9_16);
        fclose(IO_direction1);
}

void unexport()
{
        unexport_file=fopen("/sys/class/gpio/unexport", "w");
                        // Unexport des GPIO60
        fwrite (str, sizeof(char), sizeof(str), unexport_file);
        fclose(unexport_file);

        unexport_file1=fopen("/sys/class/gpio/unexport", "w");
                        // Unexport des GPIO30
        fwrite (str3, sizeof(char), sizeof(str3), unexport_file1);
        fclose(unexport_file1);

}
void Rapport_P9_14(int rapport)
                        // Configuration du rapport P9_14
{
        fseek(duty_P9_14, 0, SEEK_SET);
        fprintf(duty_P9_14, "%d", rapport);
        fflush(duty_P9_14);
        cout << "Rapport P9_14:" << rapport << endl;
}

void Rapport_P9_16(int rapport)
                        // Configuration du rapport P9_16
{
        fseek(duty_P9_16, 0, SEEK_SET);
        fprintf(duty_P9_16, "%d", rapport);
        fflush(duty_P9_16);
        cout << "Rapport P9_16:" << rapport << "\n" << endl;
}
