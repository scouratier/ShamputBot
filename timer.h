class GameTimer {
private:
	char					errorbuffer[64];
	double					time_factor;
	LONGLONG				freq;
	LONGLONG				now;
	LONGLONG				then;


public:
	double					time_span;
	GameTimer();

	void tick();
	void savetick();
};