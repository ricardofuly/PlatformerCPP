#pragma once

#include "CoreMinimal.h"
#include "PAttributeSet.generated.h"

USTRUCT(BlueprintType)
struct PLATFORMERCPP_API FPAttributeSet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Stamina;

	FPAttributeSet()
		: Health(100.0f), Mana(50.0f), Stamina(100.0f){}
	
};
