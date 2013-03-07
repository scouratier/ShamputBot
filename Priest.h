class Priest : public Player {
public:
	Priest();

	void CastSmite();
	
	int	DoLogic(Dots);

	void CombatStart();
	void CombatEnd();

	void CombatDoOnce();

private:
};