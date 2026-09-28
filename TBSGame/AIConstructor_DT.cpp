#include "AIConstructor_DT.h"
#include "AIActor_Unit.h"
#include "DT_Reasoner.h"


bool AIConstructor_DT::Init() {

	method = AIConstructorBase::Method::DT;
	return true;
}


/*
DefineActions creates all the possible actions that the AI can perform
*/
void AIConstructor_DT::DefineActions()
{
	// TASK TODO
	// Add all Actions you will need


}

/*
   DefineConsiderations creates all Considerations that will be linked to Options
// Options will only be selected if the Condition is true
*/
void AIConstructor_DT::DefineConsiderations()
{
	// TASK TODO
	// Add all Considerations you will need

	
}


/*
* DefineOptions links the Options with Considerations and Actions
*/
void AIConstructor_DT::DefineOptions()
{

	// TASK TODO
	// Add Leaf Node Actions using AddOptionByName()
	// Add Decision Tree Node Options (Sub Reasoner) using AddTreeNodeOptionByName()




	// TASK TODO
	// Add Considerations to Options using AddOptionConsideration()







	// TASK TODO
	// Create Tree Structure by adding Options to the Root and any Sub Reasoner Tree Node Option
	// Start with the Root - e.g. 	AddOptionToTreeNode("Root", "OptionMelee");
	// You will not need to create the Root, it is already created
	// Add Options to any SubReasoner Option - e.g. 	AddOptionToTreeNode("OptionMoveEval", "OptionMoveToEnemy");
	






}

