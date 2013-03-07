class Shaman : public Player {
public:
	Shaman();

	void CastWindfury();
	void CastMana();
	void CastStrength();
	void CastFire();
	void CastTotemicCall();

	void CastBolt();

	int GetWindFury();
	int	GetMana();
	int	GetStrength();
	int GetFire();

	int	SyncWindFury();
	int	SyncMana();
	int	SyncStrength();
	int	SyncFire();

    void CastSelfWindFury();
	int	GetSelfWindFury();
	int	SyncSelfWindFury();

	int	DoLogic(Dots);

	void CombatStart();
	void CombatEnd();

	void CombatDoOnce();

private:
	int	selfWindFury_;
	int windFury_;
	int mana_;
	int strenght_;
	int	fire_;
};