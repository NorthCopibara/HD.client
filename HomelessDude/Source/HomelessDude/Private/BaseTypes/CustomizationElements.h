#pragma once

#include "CustomizationElements.generated.h"

UENUM(BlueprintType)
enum class ECustomizationElement : uint8
{
	HD_Hair = 0	UMETA(DisplayName = "Hair"),
	HD_Head = 1	UMETA(DisplayName = "Head"),
	HD_Beard = 2	UMETA(DisplayName = "Beard"),
	HD_Body = 3	UMETA(DisplayName = "Body"),
	HD_Hands = 4	UMETA(DisplayName = "Hands"),
	HD_Legs = 5	UMETA(DisplayName = "Legs")
};