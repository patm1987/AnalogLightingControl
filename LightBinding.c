
#include "LightBinding.h"

static const int kAnalogInMax = 1023;
static const int kAnalogInMin = 0;
static const int kAnalogOutMax = 255;
static const int kAnalogOutMin = 0;

/*!
 * \brief	Performs any initialization needed for a LightBinding
 * \param	pLightBinding a LightBinding to initialize
 */
void LightBinding_setup(struct LightBinding* pLightBinding)
{
}

/*!
 * \brief	updates a \a pLightBinding, determining the current color
 * \param	pLightBinding the LightBinding to update
 * \return	the current color of the provided \a pLightBinding
 */
struct Color LightBinding_update(struct LightBinding* pLightBinding)
{
	float inputPercent = pLightBinding->analogReadCallback(pLightBinding->pAnalogReadUserData);
	struct Color colorDelta = {
		pLightBinding->colorHigh.r - pLightBinding->colorLow.r,
		pLightBinding->colorHigh.g - pLightBinding->colorLow.g,
		pLightBinding->colorHigh.b - pLightBinding->colorLow.b
	};
	struct Color outColor =	{
		pLightBinding->colorLow.r + inputPercent*colorDelta.r,
		pLightBinding->colorLow.g + inputPercent*colorDelta.g,
		pLightBinding->colorLow.b + inputPercent*colorDelta.b
	};
	return outColor;
}

/*!
 * \brief	takes a ReadAnalogPinData as a user data pointer and returns a vlaue from 0 to 1 based on how high the pin is
 * \param	pUserData user data to read, should be a ReadAnalogPin
 * \return	0 if the pin is low through to a 1 if the pin is high
 */
float readAnalogPin(void* pUserData)
{
	struct ReadAnalogPinData* pPinData = (struct ReadAnalogPinData*)pUserData;
	int inputValue = analogRead(pPinData->analogPin);
	return (float)inputValue/(float)kAnalogInMax;
}
