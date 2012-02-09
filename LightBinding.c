
#include "LightBinding.h"

// DEBUG!
#include "Log.h"

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
	int inputValue = analogRead(pLightBinding->analogPin);
	float inputPercent = (float)inputValue/(float)kAnalogInMax;
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
