
#include "Log.h"

#include <Arduino.h>

static const enum LogLevel kMinLogLevel = kLogLevel_Info;

template <typename T>
void log(T t, enum LogLevel level)
{
	if (level >= kMinLogLevel)
	{
		Serial.print(t);
	}
}

extern "C"
void logc(char i, enum LogLevel level)
{
	log(i, level);
}

extern "C"
void logi(int i, enum LogLevel level)
{
	log(i, level);
}

extern "C"
void logl(long i, enum LogLevel level)
{
	log(i, level);
}

extern "C"
void logsz(const char* str, enum LogLevel level)
{
	log(str, level);
}
