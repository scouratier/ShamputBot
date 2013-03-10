class Dot
{
public:
	Dot();
	Dot( int , int );

	int			X_;
	int			Y_;
	COLORREF	color_;

	int	GetR();
	int	GetG();
	int	GetB();

};

class Dots
{
public:
	Dots();
	Dots( int );

	void ShowAndSampleDots();
	void MakeHDC();
	void getWindowInfo();




	HDC				hdc_;
	Dot*			allDots_;// = new Dot[42];
	int				nDots_;
	HWND			nHwnd_;
	RECT			size_;
	RECT			screenSize_;
	int				hSize_;
	int				vSize_;
	int				hScreenSize_;
	int				vScreenSize_;
	int				border_width_;
	int				caption_height_;
	int				border_height_;

	int				offset_;
	int				interval_;
};