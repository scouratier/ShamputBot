#include "common.h"

Shaman::Shaman(){

}

int	Shaman::DoLogic(Dots in){
	this->nextKey_ = '.';
	this->spell_ = "";
	this->target_ = "";
	
	// test to see if we are already casting
	if ( GetBValue( in.allDots_[0].color_ ) == 255 )
	{
		return 0;
	}

	//printf("PH for player: %d\n", GetRValue( in.allDots_[1].color_ ) );

	int i;
	int smalest = -1;				// 0
	int smalest_health = 100;		// 100
	int percentHealth = 0;

	for( i=1 ; i<in.nDots_ ; i++ )
	{
		percentHealth = GetRValue( in.allDots_[i].color_ );
		// If the target is not dead/out of range, and below X% health
		if( percentHealth > 0 && percentHealth < 80 )
		{
			if( percentHealth < smalest_health )
			{
				smalest = i-1;
				smalest_health = percentHealth;
			}
		}
	}

	if( smalest < 0 )
		// nothing to do
		return 0;

	// raid or not?
	this->target_ = "party";
	if ( GetBValue( in.allDots_[1].color_ ) == 1 )
	{	
		this->target_ = "raid";
	}

	// is it the player?
	if( smalest == 0 )
		this->target_ = "player";



	// party or raid member then
	if( smalest > 0 )
		this->target_ = this->target_+IntToString( smalest );
		
	// is riptide ready?
	if ( GetGValue( in.allDots_[1].color_ ) == 1 )
		this->spell_ = "Riptide";
	else
		this->spell_ = "Greater Healing Wave";

/*	
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
	//FullKeyPress('3');	// windfury totem
	//Sleep(1100);
	//FullKeyPress('4');
	//this->target_ = "/clearfocus";
}

void Shaman::CombatEnd()
{
	this->SetCombat(0);
	printf("Combat set off %d\n",this->GetCombat());
	FullKeyPress(VkKeyScan('='));	// following
	//FullKeyPress('7');	// totem recal
}

void Shaman::CombatDoOnce(){

}