
#ifndef _KEYFRAME_H_
#define _KEYFRAME_H_

#include "Color.h"
#include "LightBinding.h"

#ifdef __cplusplus
extern "C"
{
#endif

struct Keyframe
{
	float weight;
	struct LightBinding lightBinding;
	float duration;
};

void Keyframe_setup(struct Keyframe* pKeyframe);
struct Color Keyframe_update(struct Keyframe* pKeyframe);

#ifdef __cplusplus
}
#endif

#endif//_KEYFRAME_H_
