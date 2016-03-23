<b> Installation <b>

Sur la Beaglebone dans le même dossier insérer les fichier source:
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
  - optargv =...

