#include "convert.h"
#include <vector>

typedef unsigned char u8;
typedef unsigned short u16;

void convertColor(ImU32 color, float& r, float& g, float& b, float& a)
{
	r = (color & 0xFF) / 255.0f;
	g = ((color >> 8) & 0xFF) / 255.0f;
	b = ((color >> 16) & 0xFF) / 255.0f;
	a = (color >> 24) / 255.0f;
}

std::string unicodeToUTF8(vstring* hl_string)
{
	std::string result;

	for (int i = 0; i < hl_string->length; i++)
	{
		auto code = ((unsigned short*)hl_string->bytes)[i];
		if (code <= 0x7F)
		{
			result += char(code);
		}
		else if (code <= 0x7FF) 
		{
			result += char(0xC0 | (code >> 6));            /* 110xxxxx */
			result += char(0x80 | (code & 0x3F));          /* 10xxxxxx */
		}
		else 
		{
			result += char(0xE0 | (code >> 12));           /* 1110xxxx */
			result += char(0x80 | ((code >> 6) & 0x3F));   /* 10xxxxxx */
			result += char(0x80 | (code & 0x3F));          /* 10xxxxxx */
		}
	}

	return result;
}
