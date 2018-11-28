
#include "logger.h"

void log_screen(const char* format, ...){
	if(debug_mode){
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		NL;
		va_end(args);
	}
}
