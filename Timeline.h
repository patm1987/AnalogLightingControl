
#ifndef _TIMELINE_H_
#define _TIMELINE_H_

#include "Channel.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define CHANNEL_COUNT 2

struct Timeline
{
	struct Channel channels[CHANNEL_COUNT]; // in the future, a dynamically sized list
};

void Timeline_setup(struct Timeline* pTimeline);
void Timeline_update(struct Timeline* pTimeline, float elapsedTime);

#ifdef __cplusplus
}
#endif

#endif//_TIMELINE_H_
