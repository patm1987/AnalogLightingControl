
#include "Keyframe.h"

/*!
 * \brief	sets up the provided \a pKeyframe
 * \param	pKeyframe a Keyframe to setup
 */
void Keyframe_setup(struct Keyframe* pKeyframe)
{
	LightBinding_setup(&pKeyframe->lightBinding);
}

/*!
 * \brief	updates the provided \a pKeyframe
 * \param	pKeyframe keyframe to update
 * \return	the current color of \a pKeyframe
 */
struct Color Keyframe_update(struct Keyframe* pKeyframe)
{
	return LightBinding_update(&pKeyframe->lightBinding);
}
