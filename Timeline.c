
#include "Timeline.h"

// DEBUG:
#include "Log.h"

/*!
 * \brief	sets up a timeline, currently chains down setting up the channels
 * \param	pTimeline the Timeline to setup
 */
void Timeline_setup(struct Timeline* pTimeline)
{
	logsz("Configuring timeline...\n", kLogLevel_Debug);
	Channel_setup(&pTimeline->channels[0]);
	Channel_setup(&pTimeline->channels[1]);
}

/*!
 * \brief	progresses the timeline by some elapsed time
 * \param	pTimeline the timeline to update
 * \param	elapsedTime the time over which the provided Timeline is updating
 */
void Timeline_update(struct Timeline* pTimeline, float elapsedTime)
{
	int i;
	for (i = 0; i < CHANNEL_COUNT; i++)
	{
		Channel_update(&pTimeline->channels[i], elapsedTime);
	}
}
