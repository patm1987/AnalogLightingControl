#ifndef _LIGHT_BINDING_H_
#define _LIGHT_BINDING_H_

#include "Color.h"
#include "LightControl.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * \brief	Binds a light to an analog input
 */
struct LightBinding
{
	int analogPin;				//!< \brief	pin to read from
	struct Color colorLow;		//!< \brief	color for when pin is low
	struct Color colorHigh;		//!< \brief	color for when pin is high
};

void LightBinding_setup(struct LightBinding* pLightBinding);
struct Color LightBinding_update(struct LightBinding* pLightBinding); // return the color from the analog pin

#ifdef __cplusplus
}
#endif

#endif//_LIGHT_BINDING_H_
