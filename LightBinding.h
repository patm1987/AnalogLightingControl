#ifndef _LIGHT_BINDING_H_
#define _LIGHT_BINDING_H_

#include "Color.h"
#include "LightControl.h"

#ifdef __cplusplus
extern "C"
{
#endif

// callback for some analog read, takes a user data pointer and returns some value from 0 to 1
// a value of 0 will output all colorLow and a value of 1 will output all colorHigh
typedef float(*AnalogReadCallback)(void*);

/*!
 * \brief	Binds a light to an analog input
 */
struct LightBinding
{
	AnalogReadCallback analogReadCallback; //! \brief	callback to determine how much to mix colorLow and colorHigh
	void* pAnalogReadUserData;	//!< \brief	user data to pass into analogReadCallback
	struct Color colorLow;		//!< \brief	color for when pin is low
	struct Color colorHigh;		//!< \brief	color for when pin is high
};

void LightBinding_setup(struct LightBinding* pLightBinding);
struct Color LightBinding_update(struct LightBinding* pLightBinding); // return the color from the analog pin

// structure to pass into readAnalogPin as user data, indicates which pin to read
struct ReadAnalogPinData
{
	int analogPin;
};
float readAnalogPin(void* pUserData);

#ifdef __cplusplus
}
#endif

#endif//_LIGHT_BINDING_H_
