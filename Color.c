
#include "Color.h"

#include <WProgram.h>

void Color_print(struct Color* pColor)
{
	Serial.print("(");
	Serial.print(pColor->r);
	Serial.print(", ");
	Serial.print(pColor->g);
	Serial.print(", ");
	Serial.print(pColor->b);
	Serial.print(")");
}
