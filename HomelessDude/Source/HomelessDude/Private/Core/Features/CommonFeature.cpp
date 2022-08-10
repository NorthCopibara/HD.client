#include "CommonFeature.h"

#include "Game/Systems/Initialize/GameInitializeSystem.h"

CommonFeature::CommonFeature()
{
	Add(MakeShared<GameInitializeSystem>());
}
