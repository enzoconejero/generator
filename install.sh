
#!/bin/bash

mkdir library;
cd library;
gcc -fPIC -Wall -c ../src/*.c -lm;
gcc -shared *.o -o libgenerator.so;
rm *.o;

if [ -f /usr/lib/libgenerator.so ]; then
	sudo rm /usr/lib/libgenerator.so
fi



sudo mv libgenerator.so /usr/lib/;
sudo chmod 755 /usr/lib/libgenerator.so

if [ -d /usr/include/generator ]; then
	sudo rm /usr/include/generator/*
	sudo rmdir /usr/include/generator
fi

sudo mkdir /usr/include/generator;
sudo cp ../src/*.h /usr/include/generator/;

cd ..;
rmdir library;
echo "Librabry instaled";
