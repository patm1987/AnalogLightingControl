
#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "Keyframe.h"
#include "LightControl.h"

#ifdef __cplusplus
extern "C"
{
#endif

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
