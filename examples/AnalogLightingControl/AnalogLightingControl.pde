/*
 * Control a single sensor via analog input
 */

#include "LightBinding.h"
#include "Timeline.h"

#define MILLISECONDS_TO_SECONDS(x) (((float)x)/1000.f)

unsigned long lastUpdateTime;

struct Timeline timeline;

#define CHANNEL_COUNT 2
#define KEYFRAME_COUNT 4

struct Channel channels[CHANNEL_COUNT];
struct Keyframe keyframes[CHANNEL_COUNT][KEYFRAME_COUNT];

struct ReadAnalogPinData readA0 = {A0};
struct ReadAnalogPinData readA5 = {A5};

void setup()
{
	Serial.begin(9600);

	memset(&timeline, 0, sizeof(timeline));
	memset(&channels, 0, sizeof(channels));
	memset(&keyframes, 0, sizeof(keyframes));

	keyframes[0][0].weight = 1.f;
	keyframes[0][0].lightBinding.analogReadCallback = readAnalogPin;
	keyframes[0][0].lightBinding.pAnalogReadUserData = &readA0;
	keyframes[0][0].lightBinding.colorLow.r = 255;
	keyframes[0][0].lightBinding.colorLow.g = 0;
	keyframes[0][0].lightBinding.colorLow.b = 0;
	keyframes[0][0].lightBinding.colorHigh.r = 0;
	keyframes[0][0].lightBinding.colorHigh.g = 255;
	keyframes[0][0].lightBinding.colorHigh.b = 255;
	keyframes[0][0].duration = 10.f;
	keyframes[0][1].weight = 1.f;
	keyframes[0][1].lightBinding.analogReadCallback = readAnalogPin;
	keyframes[0][1].lightBinding.pAnalogReadUserData = &readA0;
	keyframes[0][1].lightBinding.colorLow.r = 0;
	keyframes[0][1].lightBinding.colorLow.g = 255;
	keyframes[0][1].lightBinding.colorLow.b = 0;
	keyframes[0][1].lightBinding.colorHigh.r = 255;
	keyframes[0][1].lightBinding.colorHigh.g = 0;
	keyframes[0][1].lightBinding.colorHigh.b = 255;
	keyframes[0][1].duration = 1.f;
	keyframes[0][2].weight = 1.f;
	keyframes[0][2].lightBinding.analogReadCallback = readAnalogPin;
	keyframes[0][2].lightBinding.pAnalogReadUserData = &readA0;
	keyframes[0][2].lightBinding.colorLow.r = 0;
	keyframes[0][2].lightBinding.colorLow.g = 0;
	keyframes[0][2].lightBinding.colorLow.b = 255;
	keyframes[0][2].lightBinding.colorHigh.r = 255;
	keyframes[0][2].lightBinding.colorHigh.g = 255;
	keyframes[0][2].lightBinding.colorHigh.b = 0;
	keyframes[0][2].duration = 10.f;
	keyframes[0][3].weight = 1.f;
	keyframes[0][3].lightBinding.analogReadCallback = readAnalogPin;
	keyframes[0][3].lightBinding.pAnalogReadUserData = &readA0;
	keyframes[0][3].lightBinding.colorLow.r = 255;
	keyframes[0][3].lightBinding.colorLow.g = 255;
	keyframes[0][3].lightBinding.colorLow.b = 255;
	keyframes[0][3].lightBinding.colorHigh.r = 0;
	keyframes[0][3].lightBinding.colorHigh.g = 0;
	keyframes[0][3].lightBinding.colorHigh.b = 0;
	keyframes[0][3].duration = 1.f;

	channels[0].lightControl.r = 11;
	channels[0].lightControl.g = 10;
	channels[0].lightControl.b = 9;
	channels[0].keyframeCount = KEYFRAME_COUNT;
	channels[0].aKeyframes = keyframes[0];
	channels[0].time = 0.f;

	keyframes[1][0].weight = 1.f;
	keyframes[1][0].lightBinding.analogReadCallback = readAnalogPin;
	keyframes[1][0].lightBinding.pAnalogReadUserData = &readA5;
	keyframes[1][0].lightBinding.colorLow.r = 255;
	keyframes[1][0].lightBinding.colorLow.g = 255;
	keyframes[1][0].lightBinding.colorLow.b = 255;
	keyframes[1][0].lightBinding.colorHigh.r = 0;
	keyframes[1][0].lightBinding.colorHigh.g = 0;
	keyframes[1][0].lightBinding.colorHigh.b = 0;
	keyframes[1][0].duration = 1.f;
	keyframes[1][1].weight = 1.f;
	keyframes[1][1].lightBinding.analogReadCallback = readAnalogPin;
	keyframes[1][1].lightBinding.pAnalogReadUserData = &readA5;
	keyframes[1][1].lightBinding.colorLow.r = 128;
	keyframes[1][1].lightBinding.colorLow.g = 128;
	keyframes[1][1].lightBinding.colorLow.b = 128;
	keyframes[1][1].lightBinding.colorHigh.r = 64;
	keyframes[1][1].lightBinding.colorHigh.g = 64;
	keyframes[1][1].lightBinding.colorHigh.b = 64;
	keyframes[1][1].duration = 10.f;
	keyframes[1][2].weight = 1.f;
	keyframes[1][2].lightBinding.analogReadCallback = readAnalogPin;
	keyframes[1][2].lightBinding.pAnalogReadUserData = &readA5;
	keyframes[1][2].lightBinding.colorLow.r = 255;
	keyframes[1][2].lightBinding.colorLow.g = 255;
	keyframes[1][2].lightBinding.colorLow.b = 255;
	keyframes[1][2].lightBinding.colorHigh.r = 0;
	keyframes[1][2].lightBinding.colorHigh.g = 0;
	keyframes[1][2].lightBinding.colorHigh.b = 0;
	keyframes[1][2].duration = 1.f;
	keyframes[1][3].weight = 1.f;
	keyframes[1][3].lightBinding.analogReadCallback = readAnalogPin;
	keyframes[1][3].lightBinding.pAnalogReadUserData = &readA5;
	keyframes[1][3].lightBinding.colorLow.r = 128;
	keyframes[1][3].lightBinding.colorLow.g = 128;
	keyframes[1][3].lightBinding.colorLow.b = 128;
	keyframes[1][3].lightBinding.colorHigh.r = 64;
	keyframes[1][3].lightBinding.colorHigh.g = 64;
	keyframes[1][3].lightBinding.colorHigh.b = 64;
	keyframes[1][3].duration = 10.f;

	channels[1].lightControl.r = 6;
	channels[1].lightControl.g = 5;
	channels[1].lightControl.b = 3;
	channels[1].keyframeCount = KEYFRAME_COUNT;
	channels[1].aKeyframes = keyframes[1];
	channels[1].time = 0.f;

	timeline.channelCount = 2;
	timeline.aChannels = channels;

	Timeline_setup(&timeline);

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
