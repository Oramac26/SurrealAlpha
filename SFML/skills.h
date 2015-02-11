#ifndef SKILLS_H_   
#define SKILLS_H_

#include <string>
#define MIN_VALUE 1
#define MAX_VALUE 100


class Skills
{
protected:
	std::string skill_name;
	int skill_level;
	int skill_exp;
	int skill_exp_req;
public:
	Skills(std::string name) : skill_level(MIN_VALUE), skill_exp(MIN_VALUE), skill_exp_req(MAX_VALUE), skill_name(name) {};
	std::string ViewName() { return skill_name; };
	int ViewSkillLevel() { return skill_level; }
	int ViewSkillExp() { return skill_exp; }
	int ViewSkillExpReq() { return skill_exp_req; }
	void SkillExpInc(int value);
	void SkillExpReqInc();
	int SkillPercent();

};

#endif