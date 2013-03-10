class Shaman : public Player {
public:
	Shaman();

	int	DoLogic(Dots);

	void CombatStart();
	void CombatEnd();

	void CombatDoOnce();

private:
};