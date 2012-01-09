
#include "LightControl.h"

#include <Arduino.h> // for the definition of OUTPUT

// DEBUG:
#include "Log.h"

/*!
 * \brief	performs any initialization needed for this light control
 * \param	pLightControl a pointer to the LightControl to intialize
 * \note	this puts the pins in the correct state for manipulation, must be called whenever pin bindings are changed.
 * \note 	pins should not be reused unless you really know what you're doing!
 */
void LightControl_setup(struct LightControl* pLightControl)
{
	pinMode(pLightControl->r, OUTPUT);
	pinMode(pLightControl->g, OUTPUT);
	pinMode(pLightControl->b, OUTPUT);
	
	logsz("Light Control initialized (", kLogLevel_Debug);
	logi(pLightControl->r, kLogLevel_Debug);
	logsz(", ", kLogLevel_Debug);
	logi(pLightControl->g, kLogLevel_Debug);
	logsz(", ", kLogLevel_Debug);
	logi(pLightControl->b, kLogLevel_Debug);
	logsz(")\n", kLogLevel_Debug);
}

/*!
 * \brief	applies a \a pColor to the provided \a pLightControl
 * \param	pLightControl the LightControl whose color will be changed
 * \param	pColor the new Color for \a pLightControl
 */
void LightControl_apply(struct LightControl* pLightControl, struct Color* pColor)
{
	analogWrite(pLightControl->r, pColor->r);
	analogWrite(pLightControl->g, pColor->g);
	analogWrite(pLightControl->b, pColor->b);
}
