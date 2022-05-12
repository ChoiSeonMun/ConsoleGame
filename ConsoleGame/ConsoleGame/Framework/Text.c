#include "Text.h"

void TextCopy(Text* dest, const WCHAR* src)
{
	while (*src)
	{
		dest->Char.UnicodeChar = *src;
		dest->Attributes = TEXT_COLOR_WHITE;
		
		++dest;
		++src;
	}
}

int32 TextLen(const Text* text)
{
	int32 result = 0;
	while (text->Char.UnicodeChar)
	{
		++result;
		++text;
	}

	return result;
}