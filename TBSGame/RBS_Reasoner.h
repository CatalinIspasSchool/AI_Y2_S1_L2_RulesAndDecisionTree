#pragma once
#include "../../AI_Framework/framework.h"
class RBS_Reasoner :
    public AIReasonerBase
{
public:

    ~RBS_Reasoner();

    // AIReasonerBase overrides
    bool Init(std::string _id, AIBrainBlackboardBase& _context) override;
    void Think() override;

private:
    //Global Access
    AIRandom_Global* Global_Random;
    AIMath_Global* Global_Math;

};

