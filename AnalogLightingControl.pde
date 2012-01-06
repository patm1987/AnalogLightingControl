/*
 * Control a single sensor via analog input
 */

#include "LightBinding.h"
#include "Timeline.h"

#define MILLISECONDS_TO_SECONDS(x) (((float)x)/1000.f)

unsigned long lastUpdateTime;

struct Timeline timeline;

void setup()
{
	memset(&timeline, 0, sizeof(timeline));

	timeline.channels[0].lightControl.r = 11;
	timeline.channels[0].lightControl.g = 10;
	timeline.channels[0].lightControl.b = 9;
	timeline.channels[0].keyframes[0].weight = 1.f;
	timeline.channels[0].keyframes[0].lightBinding.analogPin = A0;
	timeline.channels[0].keyframes[0].lightBinding.colorLow.r = 255;
	timeline.channels[0].keyframes[0].lightBinding.colorLow.g = 255;
	timeline.channels[0].keyframes[0].lightBinding.colorLow.b = 255;
	timeline.channels[0].keyframes[0].lightBinding.colorHigh.r = 0;
	timeline.channels[0].keyframes[0].lightBinding.colorHigh.g = 0;
	timeline.channels[0].keyframes[0].lightBinding.colorHigh.b = 0;
	timeline.channels[0].keyframes[0].duration = 1.f;
	timeline.channels[0].keyframes[1].weight = 1.f;
	timeline.channels[0].keyframes[1].lightBinding.analogPin = A0;
	timeline.channels[0].keyframes[1].lightBinding.colorLow.r = 128;
	timeline.channels[0].keyframes[1].lightBinding.colorLow.g = 128;
	timeline.channels[0].keyframes[1].lightBinding.colorLow.b = 128;
	timeline.channels[0].keyframes[1].lightBinding.colorHigh.r = 64;
	timeline.channels[0].keyframes[1].lightBinding.colorHigh.g = 64;
	timeline.channels[0].keyframes[1].lightBinding.colorHigh.b = 64;
	timeline.channels[0].keyframes[1].duration = 1.f;
	timeline.channels[0].time = 0.f;

	timeline.channels[1].lightControl.r = 6;
	timeline.channels[1].lightControl.g = 5;
	timeline.channels[1].lightControl.b = 3;
	timeline.channels[1].keyframes[0].weight = 1.f;
	timeline.channels[1].keyframes[0].lightBinding.analogPin = A0;
	timeline.channels[1].keyframes[0].lightBinding.colorLow.r = 255;
	timeline.channels[1].keyframes[0].lightBinding.colorLow.g = 255;
	timeline.channels[1].keyframes[0].lightBinding.colorLow.b = 255;
	timeline.channels[1].keyframes[0].lightBinding.colorHigh.r = 0;
	timeline.channels[1].keyframes[0].lightBinding.colorHigh.g = 0;
	timeline.channels[1].keyframes[0].lightBinding.colorHigh.b = 0;
	timeline.channels[1].keyframes[0].duration = 1.f;
	timeline.channels[1].keyframes[1].weight = 1.f;
	timeline.channels[1].keyframes[1].lightBinding.analogPin = A0;
	timeline.channels[1].keyframes[1].lightBinding.colorLow.r = 128;
	timeline.channels[1].keyframes[1].lightBinding.colorLow.g = 128;
	timeline.channels[1].keyframes[1].lightBinding.colorLow.b = 128;
	timeline.channels[1].keyframes[1].lightBinding.colorHigh.r = 64;
	timeline.channels[1].keyframes[1].lightBinding.colorHigh.g = 64;
	timeline.channels[1].keyframes[1].lightBinding.colorHigh.b = 64;
	timeline.channels[1].keyframes[1].duration = 1.f;
	timeline.channels[1].time = 0.f;

	lastUpdateTime = millis();
}

void loop()
{
	unsigned long currentTime = millis();
	unsigned long elapsedTime = currentTime - lastUpdateTime;
	float elapsedTimeSeconds = MILLISECONDS_TO_SECONDS(elapsedTime);

	Timeline_update(&timeline, elapsedTimeSeconds);

	lastUpdateTime = currentTime;
}
 
