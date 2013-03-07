class Dot
{
public:
	Dot();

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

	void ShowAndSampleDots();
	void MakeHDC();



private:
	HDC				hdc_;
	Dot*			allDots_;// = new Dot[42];
	int				nDots_;
	COLORREF		red_;
	HWND			nHwnd_;
	RECT			size_;
	int				hSize_;
	int				vSize_;
};