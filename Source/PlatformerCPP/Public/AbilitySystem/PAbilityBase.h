// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/PAbilityData.h"
#include "PAbilityBase.generated.h"

struct FPAttributeSet;
/**
 * 
 */
UCLASS()
class PLATFORMERCPP_API UPAbilityBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName AbilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttributeCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPAttributeType ConsumedAttribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOnCooldown;

	virtual void ActivateAbility(AActor* Instigator, FPAttributeSet* Attributes);

	UFUNCTION(BlueprintCallable)
	bool CanActivate(const FPAttributeSet& Attributes);

protected:
	FTimerHandle CoolDownTimerHandle;

	void EndCoolDown();
	
};
