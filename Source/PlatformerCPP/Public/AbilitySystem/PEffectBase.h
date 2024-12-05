// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PEffectBase.generated.h"


enum class EPAttributeType : uint8;
struct FPAttributeSet;
/**
 * 
 */
UCLASS()
class PLATFORMERCPP_API UPEffectBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPAttributeType TargetAttribute;
	
	virtual  void ApplyEffect(FPAttributeSet& Attributes, UObject* Instigator);

protected:
	FTimerHandle EffectTimerHandle;

	virtual void EndEffect(FPAttributeSet& Attributes);

	void ModifyAttribute(FPAttributeSet& Attributes, float Modifier) const;
};





