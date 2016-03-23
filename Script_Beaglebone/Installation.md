### Installation

Sur la Beaglebone dans le même dossier insérer les fichiers source:
  - main.cpp
  - init.cpp
  - led.cpp
  - forme.cpp
  
et les fichiers Header :
  - init.h
  - led.h
  - forme.h

Une fois ces fichiers ajouter, nous devons activer le support des PWM dans la beaglebone. Pour qu'elle s'ajoute à chaque démarrage de la Beaglebone, nous devons ouvrir le fichier uEnv.txt:
  - cd /boot/uEnv.txt
  - vi uEnv.txt 

Dans le fichier uEnv.txt, rajouter la commande suivante:
  - optargs=run_hardware_tests quiet capemgr.enable_partno=am33xx_pwm,bone_pwm_P9_14,bone_pwm_P9_16
Les numéros des PWM dépendra du branchement sur la beaglebone (P9_14, P9_16).


