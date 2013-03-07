#include "common.h"

Priest::Priest(){
}

void Priest::CastSmite(){
	this->nextKey_ = '7';	
}

int	Priest::DoLogic(Dots in){
	this->nextKey_ = '.';
	int				r1,g1,b1, r2,g2,b2, r3,g3,b3;

	r1 = in.GetR1();
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

	if (b2 != 255)
	{ // on cooldown, no combat casting
	
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
	
		// cast the right spell
		switch (r3)
		{
			case 1:
			{
				this->spell_ = "Flash Heal";
				return 1;
			}
			case 2:
			{
				this->spell_ = "Prayer of Mending";
				return 1;
			}
			case 3:
			{
				this->spell_ = "Renew";
				return 1;
			}
		}
		if (this->InCombat_ == 1)
		{
			//this->CastSmite();
		}
		return 1;
	}

	this->nextKey_ = '.';
	return 0;
}

void Priest::CombatStart()
{
	this->SetCombat(1);
	printf("Combat set dfgdfgdfto %d\n",this->GetCombat());
	FullKeyPress('W');	// stop following
	//FullKeyPress('6');	// windfury totematta
	//FullKeyPress(VkKeyScan('-'));	// attack
	this->target_ = "/clearfocus";
}

void Priest::CombatEnd()
{
	this->SetCombat(0);
	this->target_ = "/clearfocus";
	printf("Combat set ggrdrgdto %d\n",this->GetCombat());
	FullKeyPress(VkKeyScan('='));	// start following
}

void Priest::CombatDoOnce(){

}