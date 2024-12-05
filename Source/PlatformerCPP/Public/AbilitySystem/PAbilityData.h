#pragma once

UENUM(BlueprintType)
enum class EPAttributeType : uint8
{
	Health UMETA(DisplayName = "Health"),
	Mana UMETA(DisplayName = "Mana"),
    Stamina UMETA(DisplayName = "Stamina")
};
