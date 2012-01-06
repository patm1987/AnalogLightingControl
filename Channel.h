
#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "Keyframe.h"
#include "LightControl.h"

#ifdef __cplusplus
extern "C"
{
#endif

// TODO: temporary, in the future have a variable keyframe count
#define KEYFRAME_COUNT 2

struct Channel
{
	struct LightControl lightControl;
	struct Keyframe keyframes[KEYFRAME_COUNT]; // in the future, a linked list of keyframes
	float time;
};

void Channel_setup(struct Channel* pChannel);
void Channel_update(struct Channel* pChannel, float elapsedTime);

#ifdef __cplusplus
}
#endif

#endif//_CHANNEL_H_
