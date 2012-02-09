
#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "Keyframe.h"
#include "LightControl.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * \brief	represents one "Channel" of keyframe data (one bank of LED's)
 *
 *	use lightControl to define the pins on which to output (should be analog)
 *	use keyframeCount to indicate the sizer of aKeyframes
 *	use aKeyframes to define the array of Keyframes, each of which describes the relationship between an analog pin and its high and low states
 *	use time to describe the duration of time over which this keyframe maintains control. At the end of time this keyframe is 100% active.
 */
struct Channel
{
	struct LightControl lightControl;
	int keyframeCount;
	struct Keyframe *aKeyframes;
	float time;
};

void Channel_setup(struct Channel* pChannel);
void Channel_update(struct Channel* pChannel, float elapsedTime);

#ifdef __cplusplus
}
#endif

#endif//_CHANNEL_H_
