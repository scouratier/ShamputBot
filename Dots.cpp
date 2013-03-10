#include "common.h"

Dots::Dots()
{
	this->nDots_ = 42;
	this->offset_ =  4;
	this->interval_ = 16;
	this->allDots_ = new Dot[this->nDots_];

	this->nHwnd_ = FindWindow( NULL , "World of Warcraft" );
    if ( this->nHwnd_ == NULL)
        printf("Unable to find the Notepad window.\n");

	this->MakeHDC();

	this->getWindowInfo();

}

Dots::Dots( int n )
{
	this->nDots_ = n;
	this->allDots_ = new Dot[this->nDots_];

	this->nHwnd_ = FindWindow( NULL , "World of Warcraft" );
    if ( this->nHwnd_ == NULL)
        printf("Unable to find the Notepad window.\n");

	this->getWindowInfo();
}

Dot::Dot( int x , int y )
{
	this->X_ = x;
	this->Y_ = y;
	this->color_ = RGB( 255 , 0 , 0 );
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
	
	this->getWindowInfo();

	for( i=0 ; i<this->nDots_ ; i++ )
	{
		this->allDots_[i].X_ = this->size_.left + this->border_width_ + this->offset_ + this->interval_*i;
		this->allDots_[i].Y_ = this->size_.top + this->caption_height_ + this->border_height_ + this->offset_;
		SetPixel( this->hdc_ , this->allDots_[i].X_    , this->allDots_[i].Y_-1-this->offset_ , this->allDots_[i].color_ );
		this->allDots_[i].color_ = GetPixel( this->hdc_ , this->allDots_[i].X_ , this->allDots_[i].Y_ );
	}
}

void Dots::getWindowInfo(){
	GetWindowRect( this->nHwnd_ , &this->size_ );
	this->caption_height_ = GetSystemMetrics(SM_CYCAPTION);
	this->border_height_ = GetSystemMetrics(SM_CYSIZEFRAME);
	this->border_width_ = GetSystemMetrics(SM_CXSIZEFRAME);
	GetClientRect( this->nHwnd_ , &this->screenSize_ );
	this->hSize_ = this->size_.right - this->size_.left;
	this->vSize_ = this->size_.bottom - this->size_.top;
	this->hScreenSize_ = this->screenSize_.right  - this->screenSize_.left;
	this->vScreenSize_ = this->screenSize_.bottom - this->screenSize_.top;
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