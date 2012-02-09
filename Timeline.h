
#ifndef _TIMELINE_H_
#define _TIMELINE_H_

#include "Channel.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * \brief	use Timeline to describe a timeline of light channels and associated analog inputs
 *
 *	channelCount should indicate the number of channels in aChannels
 * 	aChannels is an array of channels
 */
struct Timeline
{
	int channelCount;
	struct Channel* aChannels;
};

void Timeline_setup(struct Timeline* pTimeline);
void Timeline_update(struct Timeline* pTimeline, float elapsedTime);

#ifdef __cplusplus
}
#endif

#endif//_TIMELINE_H_
