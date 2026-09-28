#include "AIConstructor_RBS.h"
#include "AIActor_Unit.h"

bool AIConstructor_RBS::Init() {

	method = AIConstructorBase::Method::RBS;
	return true;
}


/*
DefineActions creates all the possible actions that the AI can perform
*/
void AIConstructor_RBS::DefineActions()
{

	//Define the function for close range Melee Attack
	auto attackMeleeFunction = [](AIBrainBlackboardBase& bb) -> ActionStatus {
		AIActor_Unit* actor = static_cast<AIActor_Unit*>(bb.GetActorContext());

		// Call behaviour functions here
		actor->MeleeAttackNearest();


		return ActionStatus::ACTION_SUCCESS;
	};


	// Link the function to an identifier
	AddActionByName("ActionAttackMelee", attackMeleeFunction);


	//Define the function for Ranged Attack
	auto attackRangedFunction = [](AIBrainBlackboardBase& bb) -> ActionStatus {
		AIActor_Unit* actor = static_cast<AIActor_Unit*>(bb.GetActorContext());

		// Call behaviour functions here
		actor->RangedAttackNearest();


		return ActionStatus::ACTION_SUCCESS;
	};


	// Link the function to an identifier
	AddActionByName("ActionAttackRanged", attackRangedFunction);


	// TASK TODO - add any more Actions you need below
	auto moveCloserFunction = [](AIBrainBlackboardBase& bb) -> ActionStatus {
		AIActor_Unit* actor = static_cast<AIActor_Unit*>(bb.GetActorContext());

		actor->MoveToClosestEnemy();

		return ActionStatus::ACTION_SUCCESS;
	};

	AddActionByName("ActionApproach", moveCloserFunction);


	auto moveAwayFunction = [](AIBrainBlackboardBase& bb) -> ActionStatus {
		AIActor_Unit* actor = static_cast<AIActor_Unit*>(bb.GetActorContext());

		actor->MoveAwayFromClosestEnemy();

		return ActionStatus::ACTION_SUCCESS;
	};

	AddActionByName("ActionFlee", moveAwayFunction);





}


/*
	DefineConsiderations creates all Considerations that will be linked to Options
// Options will only be selected if the Condition is true
*/
void AIConstructor_RBS::DefineConsiderations()
{

	// Consideration - Is there an enemy within 1 tile?
	auto cEnemyAdjacent = [](AIBrainBlackboardBase& bb) -> bool {

		bool enemyAdjacent = (bb.GetValue<int>("NearestEnemyDist") ==1);
		return(enemyAdjacent);

	};

	AddConsiderationByName("ConsiderationEnemyAdjacent", cEnemyAdjacent);


	auto cEnemyNotAdjacent = [](AIBrainBlackboardBase& bb) -> bool {

		bool enemyAdjacent = (bb.GetValue<int>("NearestEnemyDist") == 1);
		return(! enemyAdjacent);

		};

	AddConsiderationByName("ConsiderationEnemyNotAdjacent", cEnemyNotAdjacent);

	// TASK TODO - add more Considerations below
	//  - function should always return TRUE or FALSE



	auto cEnemyNear = [](AIBrainBlackboardBase& bb) ->bool {
		bool enemyNear = (bb.GetValue<int>("NearestEnemyDist") <= 4);
		return enemyNear;
	};

	AddConsiderationByName("ConsiderationEnemyNear", cEnemyNear);


	auto cEnemyNotNear = [](AIBrainBlackboardBase& bb) ->bool {
		bool enemyNear = (bb.GetValue<int>("NearestEnemyDist") <= 4);
		return !enemyNear;
		};

	AddConsiderationByName("ConsiderationEnemyNotNear", cEnemyNotNear);



	auto cHealthLow = [](AIBrainBlackboardBase& bb) ->bool {
		bool health = (bb.GetValue<int>("Health") <= 6);
		return health;
		};

	AddConsiderationByName("ConsiderationHealthLow", cHealthLow);

	auto cHealthNotLow = [](AIBrainBlackboardBase& bb) ->bool {
		bool health = (bb.GetValue<int>("Health") < 10);
		return !health;
		};

	AddConsiderationByName("ConsiderationHealthNotLow", cHealthNotLow);
}



/*
* DefineOptions links the Options with Considerations and Actions
*/
void AIConstructor_RBS::DefineOptions()
{
	// TASK TODO - add any additional Options you need to create, linking them with an Action
	AddOptionByName("OptionAttackRanged", "ActionAttackRanged", 1);
	AddOptionByName("OptionAttackMelee", "ActionAttackMelee",3);
	AddOptionByName("OptionRunAway", "ActionFlee", 4);
	AddOptionByName("OptionApproach", "ActionApproach", 2);

	

	// TASK TODO - add Considerations to Options by calling 'AddOptionConsideration()'
	// Options will only be selected if the Condition is true
	AddOptionConsideration("OptionAttackMelee", "ConsiderationEnemyAdjacent");

	AddOptionConsideration("OptionRunAway", "ConsiderationHealthLow");
	AddOptionConsideration("OptionRunAway", "ConsiderationEnemyAdjacent");

	AddOptionConsideration("OptionApproach", "ConsiderationEnemyNear");
	AddOptionConsideration("OptionApproach", "ConsiderationHealthNotLow");

	//odd issue, once they start running. they don't stop running, but they do heal

}







