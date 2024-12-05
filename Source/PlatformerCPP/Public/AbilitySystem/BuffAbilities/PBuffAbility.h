// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/PAbilityBase.h"
#include "PBuffAbility.generated.h"

class UPEffectBase;
/**
 * 
 */
UCLASS()
class PLATFORMERCPP_API UPBuffAbility : public UPAbilityBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPEffectBase* AssociatedEffect;

	virtual void ActivateAbility(AActor* Instigator, FPAttributeSet* Attributes) override;
};
