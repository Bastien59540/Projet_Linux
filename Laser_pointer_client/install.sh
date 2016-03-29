#!/bin/bash
# (c) 2016 - Quentin Berdal
clear
echo "##############################################"
echo "##/----------------------------------------\##"
echo "#<                INSTALLER                 >#"
echo "##\----------------------------------------/##"
echo "##############################################"
echo 
echo -e "$(<disclamer)"
echo 
echo "Do you want to install dependencies ? [Y/n] "
echo -n "> "
read choice
echo 
if [ $choice == "Y" ]; then
	./DEPENDENCIES
fi

qtchooser -run-tool=qmake -qt=5
make
echo 
echo "Do you want to clean the directory ? [Y/n] "
echo -n "> "
read choice
echo 
if [ $choice == "Y" ]; then
	make clean
fi
echo -e "\n -- DONE --\n"
