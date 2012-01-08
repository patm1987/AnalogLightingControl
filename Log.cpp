
#include "Log.h"

#include <WProgram.h>

static const enum LogLevel kMinLogLevel = kLogLevel_Info;

template <typename T>
void log(T t, enum LogLevel level)
{
	if (level >= kMinLogLevel)
	{
		Serial.print(t);
	}
}

void logc(char i, enum LogLevel level)
{
	log(i, level);
}

void logi(int i, enum LogLevel level)
{
	log(i, level);
}

void logl(long i, enum LogLevel level)
{
	log(i, level);
}

void logsz(const char* str, enum LogLevel level)
{
	log(str, level);
}
