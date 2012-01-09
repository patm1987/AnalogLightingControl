
#ifndef _LOG_H
#define _LOG_H

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * \file Log.h
 *
 *	A series of logging utilities, primarily because Serial.out is C++
 */

enum LogLevel
{
	kLogLevel_Info,
	kLogLevel_Debug,
	kLogLevel_Warn,
	kLogLevel_Error,
	kLogLevel_Count,

	kLogLevel_Default = kLogLevel_Info
};

void logc(char i, enum LogLevel level); 
void logi(int i, enum LogLevel level);
void logl(long i, enum LogLevel level);
void logfp(float i, enum LogLevel level);
void logsz(const char* str, enum LogLevel level);

#ifdef __cplusplus
}
#endif

#endif//_LOG_H
