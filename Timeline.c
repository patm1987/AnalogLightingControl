
#include "Timeline.h"

// DEBUG:
#include "Log.h"

/*!
 * \brief	sets up a timeline, currently chains down setting up the channels
 * \param	pTimeline the Timeline to setup
 */
void Timeline_setup(struct Timeline* pTimeline)
{
	int channel = 0;
	logsz("Configuring timeline...\n", kLogLevel_Debug);

	for (channel = 0; channel < pTimeline->channelCount; channel++)
	{
		Channel_setup(pTimeline->aChannels + channel);
	}
}

/*!
 * \brief	progresses the timeline by some elapsed time
 * \param	pTimeline the timeline to update
 * \param	elapsedTime the time over which the provided Timeline is updating
 */
void Timeline_update(struct Timeline* pTimeline, float elapsedTime)
{
	int i;
	for (i = 0; i < pTimeline->channelCount; i++)
	{
		Channel_update(pTimeline->aChannels + i, elapsedTime);
	}
}
