#ifndef _COLOR_H_
#define _COLOR_H_

enum ColorChannel
{
 	kColorChannel_red,
 	kColorChannel_green,
 	kColorChannel_blue,

 	kColorChannel_count
};

struct Color
{
	union
	{
		int values[kColorChannel_count];
		struct
		{
			int r,g,b;
		};
	};
};

void Color_print(struct Color* pColor);

#endif//_COLOR_H_