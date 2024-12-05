// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/BuffAbilities/PBuffAbility.h"

#include "AbilitySystem/PEffectBase.h"

void UPBuffAbility::ActivateAbility(AActor* Instigator, FPAttributeSet* Attributes)
{
	Super::ActivateAbility(Instigator, Attributes);

	if (AssociatedEffect)
	{
		AssociatedEffect->ApplyEffect(*Attributes, Instigator);
	}
}
