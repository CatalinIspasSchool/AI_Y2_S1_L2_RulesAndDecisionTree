#include "RBS_Reasoner.h"



RBS_Reasoner::~RBS_Reasoner()
{


}


bool RBS_Reasoner::Init(std::string _id, AIBrainBlackboardBase& _context) {
	actorBlackboard = &_context;
	reasonerID = _id;

	// obtain Math and Random singletons
	Global_Random = AIRandom_Global::getInstance();
	Global_Math = AIMath_Global::getInstance();

	return true;
}



/*
Think is called on demand to choose from the possible Options that AI has.

The function should implement the logic of the AI method to choose one Option as the selectedOption.
*/
void RBS_Reasoner::Think()
{
	selectedOption = nullptr;

	//for all options, check if they can be Triggered, and select one to Fire
	for (const auto& option : options)
	{
		// get all Consideration for the Option
		std::vector<std::shared_ptr<AIConsiderationBase>> ruleList = option->GetOptionConsiderations();

		//TASK TODO: Complete Think() logic
		//  Check if all Considerations in the ruleList are TRUE
		//  Call Calculate() on each Consideration to get a boolean true/false return value if the condition is met
		//  Pass the blackboard to the Calculate function  e.g. Calculate(*actorBlackboard))
		//		
		// 
		//  If a rule's conditions are all met, then it may be selected
		//  Use option.get() to obtain a copy of the option to set selectedOption pointer
		
		//AIConsiderationBase::Calculate()

		bool flag = true;
		for (auto rule : ruleList)
		{
			if (! rule->Calculate(*actorBlackboard))
			{
				flag = false;
			}
		}
		if (flag && (selectedOption ==nullptr || option->GetPriority() > selectedOption->GetPriority()))
		{
			selectedOption = option.get();
		}


	}


	


	// TASK TODO - By the end of the function,  'selectedOption' should be set to the option that is to be Fired
	//  Use option.get() to obtain a copy of the option to set selectedOption pointer
	// (the Firing will happen automatically later)


}



