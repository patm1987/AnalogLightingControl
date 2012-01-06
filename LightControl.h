
#ifndef _LIGHT_CONTROL_H_
#define _LIGHT_CONTROL_H_

#include "Color.h" // must be included for kChannel_count

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * \brief	associates "lights" with hardware.
 *
 * Each "pin" is assumed to map to a pin on the arduino capable of analog output. A
 * value of 0-255 is written into each channel assuming that it will be mixed to the
 * appropriate color.
 */
 
struct LightControl
{
	union
	{
		int pins[kColorChannel_count];	//!< \brief	array of rgb pins to lights
		struct
		{
			int r,g,b;				//!< \brief	named pins to lights
		};
	};
};

void LightControl_setup(struct LightControl* pLightControl);
void LightControl_apply(struct LightControl* pLightControl, struct Color* pColor);

#ifdef __cplusplus
}
#endif
 
#endif//_LIGHT_CONTROL_H_
 
