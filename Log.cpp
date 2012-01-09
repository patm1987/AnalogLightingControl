
#include "Log.h"

#include <Arduino.h>

static const enum LogLevel kMinLogLevel = kLogLevel_Info;

/*!
 * \brief	Logs any value (supported by Serial.print) to the serial connector
 * \param	t the value to log
 * \param	level the log level at which to log \a t. If the level does not meet
 *			kMinLogLevel, then nothing is logged
 * \tparam	T the type of the value to be logged
 */
template <typename T>
void log(T t, enum LogLevel level)
{
	if (level >= kMinLogLevel)
	{
		Serial.print(t);
	}
}

//! \brief	log a character
extern "C"
void logc(char i, enum LogLevel level)
{
	log(i, level);
}

//! \brief	log an integer (16 bits in Arduino)
extern "C"
void logi(int i, enum LogLevel level)
{
	log(i, level);
}

//! \brief	log a long (32 bits in Arduino)
extern "C"
void logl(long i, enum LogLevel level)
{
	log(i, level);
}

/*!
 * \brief	logs a floating point value
 * \note	logf cannot be used as math uses it for... computing the log of a float 
 */
extern "C"
void logfp(float i, enum LogLevel level)
{
	log(i, level);
}

//! \brief	logs a zero terminated string
extern "C"
void logsz(const char* str, enum LogLevel level)
{
	log(str, level);
}
