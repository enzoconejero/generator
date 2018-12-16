
#!/bin/bash

if [ -f /usr/lib/libgenerator.so ]; then
	sudo rm /usr/lib/libgenerator.so;
fi

if [ -d /usr/include/generator ]; then
	sudo rm /usr/include/generator/*
	sudo rmdir /usr/include/generator
fi

echo "Librabry uninstaled";
