#include "common.h"

Dots::Dots()
{
	this->nDots_ = 42;
	this->allDots_ = new Dot[this->nDots_];
	this->red_ = RGB(255,0,0);

	this->nHwnd_ = FindWindow( NULL , "World of Warcraft" );
    if ( this->nHwnd_ == NULL)
        printf("Unable to find the Notepad window.\n");

	GetWindowRect( this->nHwnd_ , &this->size_ );
	int caption_height = GetSystemMetrics(SM_CYCAPTION);
	int border_height = GetSystemMetrics(SM_CYSIZEFRAME);
	int border_width = GetSystemMetrics(SM_CXSIZEFRAME);
	printf("Height of caption = %d\n", caption_height );
	//GetClientRect( this->nHwnd_ , &this->size_ );
	this->hSize_ = this->size_.right - this->size_.left;
	this->vSize_ = this->size_.bottom - this->size_.top;
	printf("Size of the window is %d and %d \n", this->hSize_ , this->vSize_ );

	this->allDots_[0].color_ = RGB(255,255,255);
	this->allDots_[0].X_ = this->size_.left + border_width;
	this->allDots_[0].Y_ = this->size_.top + caption_height + border_height;
}

Dot::Dot()
{

}

void Dots::MakeHDC(){
	this->hdc_ = CreateDC("DISPLAY",NULL,NULL,NULL);
}

void Dots::ShowAndSampleDots(){
	// Loop at dots
	// Draw crosshair about their location
	int i;
	GetWindowRect( this->nHwnd_ , &this->size_ );
	//GetClientRect( this->nHwnd_ , &this->size_ );
	int caption_height = GetSystemMetrics(SM_CYCAPTION);
	int border_height = GetSystemMetrics(SM_CYSIZEFRAME);
	int border_width = GetSystemMetrics(SM_CXSIZEFRAME);
	printf("Height of caption = %d\n", caption_height );
	this->hSize_ = this->size_.right - this->size_.left;
	this->vSize_ = this->size_.bottom - this->size_.top;
	printf("Size of the window is %d and %d \n", this->hSize_ , this->vSize_ );

	this->allDots_[0].X_ = this->size_.left + border_width;
	this->allDots_[0].Y_ = this->size_.top + caption_height + border_height;
	for( i=0 ; i<this->nDots_ ; i++ )
	{
		SetPixel( this->hdc_ , this->allDots_[i].X_-1  , this->allDots_[i].Y_   , this->red_ );
		SetPixel( this->hdc_ , this->allDots_[i].X_    , this->allDots_[i].Y_-1 , this->red_ );
		SetPixel( this->hdc_ , this->allDots_[i].X_+1  , this->allDots_[i].Y_   , this->red_ );
		SetPixel( this->hdc_ , this->allDots_[i].X_    , this->allDots_[i].Y_+1 , this->red_ );
		this->allDots_[i].color_ = GetPixel( this->hdc_ , this->allDots_[i].X_ , this->allDots_[i].Y_ );
	}
}

int	Dot::GetR(){
	return GetRValue( this->color_ );
}

int	Dot::GetG(){
	return GetGValue( this->color_ );
}

int	Dot::GetB(){
	return GetBValue( this->color_ );
}