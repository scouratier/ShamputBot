#include "common.h"

void FullKeyPress(SHORT in){
	// does the full DOWN/UP of a keypress
	//printf("Hitting key %c\n",in);
	INPUT			input[2];
	KEYBDINPUT		keyi0,keyi1;

	ZeroMemory(input, sizeof(input));
	
	keyi0.wVk = in;
	keyi0.wScan = 0;
	keyi0.dwFlags = 0;
	keyi0.time = 0;
	keyi0.dwExtraInfo = 0;

	keyi1.wVk = in;
	keyi1.wScan = 0;
	keyi1.dwFlags = KEYEVENTF_KEYUP;
	keyi1.time = 0;
	keyi1.dwExtraInfo = 0;

	input[0].type = INPUT_KEYBOARD;
	input[1].type = INPUT_KEYBOARD;
	input[0].ki = keyi0;
	input[1].ki = keyi1;

	SendInput(2,input,sizeof(INPUT));
}

void KeyDown(SHORT in){
	// does the full DOWN of a keypress
	INPUT			input[1];
	KEYBDINPUT		keyi0;

	ZeroMemory(input, sizeof(input));
	
	keyi0.wVk = in;
	keyi0.wScan = 0;
	keyi0.dwFlags = 0;
	keyi0.time = 0;
	keyi0.dwExtraInfo = 0;

	input[0].type = INPUT_KEYBOARD;
	input[0].ki = keyi0;

	SendInput(1,input,sizeof(INPUT));
}
void KeyUp(SHORT in){
	// does UP of a keypress
	INPUT			input[1];
	KEYBDINPUT		keyi0;

	ZeroMemory(input, sizeof(input));
	
	keyi0.wVk = in;
	keyi0.wScan = 0;
	keyi0.dwFlags = KEYEVENTF_KEYUP;
	keyi0.time = 0;
	keyi0.dwExtraInfo = 0;

	input[0].type = INPUT_KEYBOARD;
	input[0].ki = keyi0;
	
	SendInput(1,input,sizeof(INPUT));
}

void SendInputString(const char *in,int n){
	char		current;
	int			max;

	max = n;
	FullKeyPress(VK_RETURN);
	for(int i=0;i<max;i++){
		current = VkKeyScan(in[i]);
		FullKeyPress(current);
	}
	FullKeyPress(VK_RETURN);
}

std::string IntToString ( int number )
{
  std::ostringstream oss;

  // Works just like cout
  oss<< number;

  // Return the underlying string
  return oss.str();
}