
#include "Color.h"

#include "Log.h"

void Color_print(struct Color* pColor)
{
	logsz("(", kLogLevel_Debug);
	logi(pColor->r, kLogLevel_Debug);
	logsz(", ", kLogLevel_Debug);
	logi(pColor->g, kLogLevel_Debug);
	logsz(", ", kLogLevel_Debug);
	logi(pColor->b, kLogLevel_Debug);
	logsz(")\n", kLogLevel_Debug);
}
