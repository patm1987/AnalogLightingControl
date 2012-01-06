
#include "Channel.h"

#include <math.h>

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
	pChannel->time += elapsedTime;

	// TODO: temporary, cache in Channel
	float duration = calculateChannelDuration(pChannel);
	pChannel->time = fmodf(pChannel->time, duration);

	// TODO: find which two keyframes to oscillate between
	// Calculate color at each keyframe
	// interpolate color between keyframes
	struct Color color = Keyframe_update(&pChannel->keyframes[0]);
	LightControl_apply(&pChannel->lightControl, &color);
}
