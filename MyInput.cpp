#include "common.h"

MyInput::MyInput(){
	this->key_ = '.';
	this->targetChanged_ = 0;
	this->oldTarget_ = "something silly";
}

int MyInput::SetKey(char in){
	this->key_ = in;
	return 1;
}

char MyInput::GetKey(){
	return this->key_;
}

int MyInput::DoKeyInput(){
	
	if (this->key_ != '.'){
		FullKeyPress(VkKeyScan(this->key_));
		return 1;
	}
	return 0;
}

int MyInput::DoInputs(Player in){
	string temp="";
	// /cast [target=in.MyTarget()] in.MyKey()
	if (in.MyTarget() != "" && in.MySpell() != ""){
		temp = "/cast [target="+ in.MyTarget() +"] "+ in.MySpell() ;
		printf("%s\n",temp.c_str());
		SendInputString(temp.c_str(),temp.length());
	}
	return 1;
}