#include "common.h"

Player::Player(){
	this->InCombat_ = false;
	this->autoFollow_ = false;
	this->nextKey_ = '.';
	this->spell_ = "";
	this->IGautoFollow_ = false;

	sotc_ = soc_ = bow_ = ca_ = jotc_ = 0;
}

void Player::StartCombat(){
	this->InCombat_ = true;
}

void Player::OutOfCombat(){
	this->InCombat_ = false;
}

int Player::InCombat(){
	return this->InCombat_;
}

int Player::SetCombat(int in){
	this->InCombat_ = in;
	return this->InCombat_;
}

int Player::SetIGCombat(int in){
	this->IGInCombat_ = in;
	return this->IGInCombat_;
}

int	Player::GetCombat(){
	return this->InCombat_;
}

int	Player::GetIGCombat(){
	return this->IGInCombat_;
}

int Player::AutoFollow(int in){
	this->autoFollow_ = in;
	return this->autoFollow_;
}

int Player::IGAutoFollow(int in){
	this->IGautoFollow_ = in;
	return this->IGautoFollow_;
}

int Player::GetAutoFollow(){
	return this->autoFollow_;
}

int Player::GetIGAutoFollow(){
	return this->IGautoFollow_;
}

int	 Player::FollowOutOfSync(){
	if(this->autoFollow_ < this->IGautoFollow_)
		return -1;
	if(this->autoFollow_ > this->IGautoFollow_)
		return 1;
	return 0;
}

char Player::DoCombat(){
	/*
	// Assume the autofollow is on, so turn it off
	//if (this->autoFollow_ == 1)
	//	this->autoFollow_ = 0;
	// if my aura is down (or the wrong one, turn it on:
	if (this->ca_ == 0)
		return '9';
	// if my target is not judged with Crusader and I don't have it on (soct)
	if (this->sotc_ == 0 && this->jotc_ == 0)
		return '8';
	// if I have crusader up, but not on target (judg)
	if (this->sotc_ == 1 && this->jotc_ == 0)
		return '7';
	// turn on SoC
	if (this->soc_ == 0 && this->jotc_ == 1)
		return '6';
	// Heals
	*/	
	return ' ';

}

int Player::SetSOTC(int in){
	this->sotc_ = in;
	return 1;
}

int Player::SetSOC(int in){
	this->soc_ = in;
	return 1;
}
int Player::SetBOW(int in){
	this->bow_ = in;
	return 1;
}
int Player::SetCA(int in){
	this->ca_ = in;
	return 1;
}

int Player::GetSOTC(){
	return this->sotc_;
}

int Player::GetSOC(){
	return this->soc_;
}

int Player::GetBOW(){
	return this->bow_;
}

int Player::GetCA(){
	return this->ca_;
}

int Player::SetJOTC(int in){
	this->jotc_ = in;
	return 1;
}

int Player::GetJOTC(){
	return this->jotc_;
}

string Player::MyTarget(){
	return this->target_;
}

string Player::MySpell(){
	return this->spell_;
}

char Player::MyKey(){
	return this->nextKey_;
}

void Player::CombatStart(){}
void Player::CombatEnd(){}
void Player::CombatDoOnce(){}