
#!/bin/bash

gcc *.c ../language.c ../element.c ../equal.c ../logger.c -o run_tests -lcunit -lm;
