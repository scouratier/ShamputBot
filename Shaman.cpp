#include "common.h"

Shaman::Shaman(){
	this->selfWindFury_ = 0;	
	this->windFury_ = 0;
	this->mana_ = 0;
	this->strenght_ = 0;
	this->fire_ = 0;
}

void Shaman::CastWindfury(){
	if(this->windFury_ == 0)
	{
		this->nextKey_ = '3';
		this->windFury_ = 1;
	}
}
void Shaman::CastMana(){
}
void Shaman::CastStrength(){
	if (this->strenght_ == 0)
	{
		this->nextKey_ = '4';
		this->strenght_ = 1;
	}
}
void Shaman::CastFire(){
}

void Shaman::CastBolt(){
	this->nextKey_ = '8';	
}

void Shaman::CastTotemicCall(){
	this->windFury_ = 0;
	this->mana_ = 0;
	this->strenght_ = 0;
	this->fire_ = 0;
	this->nextKey_ = '7';
}

int Shaman::GetWindFury(){
	return this->windFury_;
}
int	Shaman::GetMana(){
	return this->mana_;
}
int	Shaman::GetStrength(){
	return this->strenght_;
}
int Shaman::GetFire(){
	return this->fire_;
}

int	Shaman::SyncWindFury(){
	return 1;
}
int	Shaman::SyncMana(){
	return 1;
}
int	Shaman::SyncStrength(){
	return 1;
}
int	Shaman::SyncFire(){
	return 1;
}

void Shaman::CastSelfWindFury(){
}
int	Shaman::GetSelfWindFury(){
	return this->selfWindFury_;
}
int	Shaman::SyncSelfWindFury(){
	return 1;
}

int	Shaman::DoLogic(Dots in){
	this->nextKey_ = '.';
	int				r1,g1,b1, r2,g2,b2, r3,g3,b3;

/*	r1 = in.GetR1();
	g1 = in.GetG1();
	b1 = in.GetB1();

	r2 = in.GetR2();
	g2 = in.GetG2();
	b2 = in.GetB2();

	r3 = in.GetR3();
	g3 = in.GetG3();
	b3 = in.GetB3();

	this->target_ = "";
	this->spell_ = "";

	if (b3 == 1)
	{
		if (!this->InCombat()){
			this->CombatStart();
		}
	}
	else
	{
		if (this->InCombat()){
			this->CombatEnd();
		}
	}		
	
	// select the right target
	if(g3 > 0 && g3 < 41){
		this->target_ = "raid"+IntToString(g3);
	}
	if(g3 > 40 && g3 < 46){
		this->target_ = "party"+IntToString(g3-40);
	}
	if(g3 == 128){
		this->target_ = "player";
	}

	if (b2 != 255)
	{ // on cooldown, no combat casting
	
		// cast the right spell
		switch (r3)
		{
			case 1:
			{
				this->spell_ = "Greater Healing Wave";
				return 1;
			}
			case 2:
			{
				this->spell_ = "Healing Surge";
				return 1;
			}
		}*/
		/*printf("1 values %d %d %d\n",r1,g1,b1);
		if (r1 == 128)
		{
			this->target_ = "player";
			this->spell_ = "Great Purple Elekk";
		}
		if (r1 == 255)
		{
			this->target_ = "player";
			this->spell_ = "Reins of the Cobalt Netherwing Drake";
		}*/
		/*if (this->InCombat_ == 1)
		{
		//	this->CastBolt();
		}
		return 1;
	}*/

	this->nextKey_ = '.';
	return 0;
}

void Shaman::CombatStart()
{
	this->SetCombat(1);
	printf("Combat set on %d\n",this->GetCombat());
	// FullKeyPress('W');	// stop following
	FullKeyPress('3');	// windfury totem
	Sleep(1100);
	FullKeyPress('4');
	//this->target_ = "/clearfocus";
}

void Shaman::CombatEnd()
{
	this->SetCombat(0);
	printf("Combat set off %d\n",this->GetCombat());
	FullKeyPress(VkKeyScan('='));	// following
	FullKeyPress('7');	// totem recal
}

void Shaman::CombatDoOnce(){

}