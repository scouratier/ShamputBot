#define SOTC	1
#define SOC		2
#define BOW		4
#define CA		8

class Player
{
public:
	Player();
	void StartCombat();
	void OutOfCombat();
	int InCombat();
	int	SetCombat(int);
	int	SetIGCombat(int);
	int GetCombat();
	int	GetIGCombat();
	char DoCombat();

	int AutoFollow(int in);
	int IGAutoFollow(int in);
	int GetAutoFollow();
	int GetIGAutoFollow();
	int	FollowOutOfSync();

	int SetSOTC(int);
	int SetSOC(int);
	int SetBOW(int);
	int SetCA(int);

	int GetSOTC();
	int GetSOC();
	int GetBOW();
	int GetCA();

	int SetJOTC(int);
	int GetJOTC();

	int InCombat_;
	int autoFollow_;
	int IGautoFollow_;
	int	IGInCombat_;

	string	MyTarget();
	string	MySpell();
	char	MyKey();

	virtual void CombatStart();
	virtual void CombatEnd();

	virtual void CombatDoOnce();

protected:
	// PLACE HOLDERS FOR PALADIN STUFF
	int	sotc_;
	int soc_;
	int bow_;
	int ca_;

	int	jotc_;	// if I applied a judg on my target

	// REAL STUFF UNDER HERE
	string	target_;
	char	nextKey_;
	string	spell_;
};