#pragma once
#include "System.h"

class GameInitializeSystem final : public System
{
public:
	virtual void Initialize(AMechanism* Mechanism) override;
};
