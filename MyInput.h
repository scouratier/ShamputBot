class MyInput {
public:
	MyInput();

	int				SetKey(char);
	char			GetKey();

	int				DoKeyInput();
	int				DoInputs(Player);

private:
	string		oldTarget_;
	char		key_;
	int			targetChanged_;
};