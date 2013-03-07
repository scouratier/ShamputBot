#include "common.h"



void main(void){
	Dots			dots;
	Sleep(4000);

	Shaman			me;
	
	int				af = 0;
	MyInput			input;

	GameTimer		input_timer;
	GameTimer		dots_timer;
	
	// fills in values for the timer.
	printf("Input Bot v2.1\n");

	input_timer.tick();
	dots_timer.tick();
	//Sleep(1);
	input_timer.savetick();
	dots_timer.savetick();
	double keybt;
	double dotst;

	dots.MakeHDC();
	dots.ShowAndSampleDots();
	while(1){
		Sleep(10);
		input_timer.tick();
		dots_timer.tick();
		keybt = input_timer.time_span;
		dotst = dots_timer.time_span;
		if (keybt > 0.1)
		{
			input_timer.savetick();
		}
		if (dotst > 0.1)
		{
			dots_timer.savetick();
			dots.ShowAndSampleDots();
  			me.DoLogic(dots);		
			input.DoInputs(me);
		}
	}
}

