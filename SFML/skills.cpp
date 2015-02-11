#include "skills.h"

void Skills::SkillExpReqInc()
{
	skill_exp_req = skill_exp_req * skill_level;
};

void Skills::SkillExpInc(int value)
{
	skill_exp = skill_exp + value;
	if (skill_exp > skill_exp_req)
	{
		skill_exp = skill_exp - skill_exp_req;
		skill_level++;
		SkillExpReqInc();
	}
}

int Skills::SkillPercent()
{
	return (skill_exp * 100 / skill_exp_req);
}
