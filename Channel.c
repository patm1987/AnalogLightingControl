
#include "Channel.h"

#include <math.h>
#include <stddef.h>

// DEBUG!
#include "Log.h"

/*!
 * \brief	calculates the total duration of one execution of \a pChannel
 * \param	pChannel the Channel whose duration will be calculated
 * \return	the duration of time it takes to complete one cycle of \a pChannel
 */
float calculateChannelDuration(struct Channel* pChannel)
{
	float duration = 0.f;
	int i;
	for (i = 0; i < KEYFRAME_COUNT; i++)
	{
		duration += pChannel->keyframes[i].duration;
	}
	return duration;
}

/*!
 * \brief	given a channel, figures out what keyframes it is currently between and stores them in pK0 and pK1.
 * \param	pChannel the Channel to operate on
 * \param[out]	pK0 after execution, the keyframe at the beginning of the mix
 * \param[out]	pK1 after execution, the keyframe at the end of the mix
 * \return	a value from 0 to 1 indicating the mix between pK0 and pK1. A value of 0 would indicate that we're exactly on pK0 and a value of 1 means we're entirely on pK1
 */
float calculateChannelMix(
	struct Channel* pChannel,
	struct Keyframe** pK0,
	struct Keyframe** pK1)
{
	float runningTime = pChannel->time;
	int i;

	*pK0 = NULL;
	*pK1 = NULL;

	// figure out the time 
	for (i = 0; i < KEYFRAME_COUNT; i++)
	{
		struct Keyframe* pCurrent = pChannel->keyframes + i;
		if (pCurrent->duration > runningTime)
		{
			pK0 = pCurrent;
			pK1 = pChannel->keyframes + (i%KEYFRAME_COUNT);
			return (float)runningTime/(float)pCurrent->duration;
		}
		runningTime -= pCurrent->duration;
	}

	// time is outside the range of keyframes, this should never happen
	pK0 = pChannel->keyframes + KEYFRAME_COUNT - 1;
	pK1 = pChannel->keyframes;
	return 1.f;
}

/*!
 * \brief	initializes the provided \a pChannel
 * \param	pChannel the channel to update
 */
void Channel_setup(struct Channel* pChannel)
{
	int i;
	LightControl_setup(&pChannel->lightControl);

	for (i = 0; i < KEYFRAME_COUNT; i++)
	{
		Keyframe_setup(&pChannel->keyframes[i]);
	}
}

/*!
 * \brief	updates \a pChannel over the provided \a elapsedTime
 * \param	pChannel the channel to update
 * \param	elapsedTime the time duration over which \a pChannel will be updated
 */
void Channel_update(struct Channel* pChannel, float elapsedTime)
{
	float duration;
	struct Keyframe* pK0;
	struct Keyframe* pK1;
	float channelMix;
	struct Color c0;
	struct Color c1;
	struct Color outColor;

	pChannel->time += elapsedTime;

	// TODO: temporary, cache in Channel
	duration = calculateChannelDuration(pChannel);
	pChannel->time = fmodf(pChannel->time, duration);

	channelMix = calculateChannelMix(pChannel, &pK0, &pK1);

	c0 = Keyframe_update(pK0);
	c1 = Keyframe_update(pK1);
	outColor = (struct Color){
		c0.r + channelMix*(c1.r - c0.r),
		c0.g + channelMix*(c1.g - c0.g),
		c0.b + channelMix*(c1.b - c0.b)
	};
	LightControl_apply(&pChannel->lightControl, &outColor);
}
