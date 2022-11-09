#include <Windows.h>
#include "DasHard.h"

#define DMX_MAXCHANNEL 512


class pilotageLumiere
{
	HINSTANCE g_dasusbdll;
private: // Declarations utilisateur
	
public: // Declarations utilisateur
	pilotageLumiere();
	
	typedef int(*DASHARDCOMMAND)(int, int, unsigned char*);
	DASHARDCOMMAND DasUsbCommand;
	int interface_open;
	unsigned char dmxBlock[512];
	void SendTrame();



