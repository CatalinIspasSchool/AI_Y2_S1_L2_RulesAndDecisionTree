#include "AIBrain_TBS.h"
#include "RBS_Reasoner.h"
#include "DT_Reasoner.h"

void AIBrain_TBS::Update()
{
	// call the reasoner to get the selected action
	brainReasoner->Update();

}

bool AIBrain_TBS::Init(AIConstructorBase& _constructor, AIActorBase& _actorContext)
{
	brainBlackboard = std::make_unique<AIBrainBlackboard>();
	brainBlackboard->Init(_actorContext);


	// create the brain based on the constructor method
	if (_constructor.method == AIConstructorBase::Method::RBS)
	{
		brainReasoner = std::make_unique < RBS_Reasoner >();

		brainReasoner->SetOptions(_constructor);

		brainReasoner->Init("RBS Reasoner", *brainBlackboard);

	}
	else
	{
		brainReasoner = std::make_unique<DT_Reasoner>();

		// the reasoner must be called 'Root' is using the helper functions for construction
		brainReasoner->Init("Root", *brainBlackboard);
		brainReasoner->SetOptions(_constructor);


	}

	return true;

}