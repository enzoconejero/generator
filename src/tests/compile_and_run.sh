
#!/bin/bash

gcc *.c ../*.c -o run_tests -lcunit -lm -lpthread;
./run_tests;
