#include "Tools.h"
#include <cstdlib>

namespace tool
{
	int RandomInt(int min, int max)
	{
		return rand() % (max - min + 1) + min;
	}
}
