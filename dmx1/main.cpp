#include "pilotageLumiere.h"
int main(int argc, char *argv[])
{
	pilotageLumiere * obj = new pilotageLumiere();
	int value = 0;
	int variation = 1;
	while (1)
	{
		obj->dmxBlock[0] = 0; //rouge
		obj->dmxBlock[1] = 0; //vert
		obj->dmxBlock[2] = 250; //bleu
		obj->dmxBlock[3] = 0; //blanc

		value += variation;
		if (value >= 255)
		{
			value = 255;
			variation *= -1;
		}
		else if (value <= 0)
		{
			value = 0;
			variation *= -1;
		}

		obj->SendTrame();
		Sleep(20);
	}
	return 0;
}