// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/PEffectBase.h"
#include "AbilitySystem/PAbilityData.h"
#include "AbilitySystem/PAttributeSet.h"

void UPEffectBase::ApplyEffect(FPAttributeSet& Attributes, UObject* Instigator)
{
	ModifyAttribute(Attributes, Value);

	if (Duration > 0.0f)
	{
		if (UWorld* World = Instigator->GetWorld())
		{
			World->GetTimerManager().SetTimer(
				EffectTimerHandle, 
				[this, &Attributes] () {this->EndEffect(Attributes);}, Duration, false
			);
		}
	}
}

void UPEffectBase::EndEffect(FPAttributeSet& Attributes)
{
	ModifyAttribute(Attributes, -Value);
}

void UPEffectBase::ModifyAttribute(FPAttributeSet& Attributes, float Modifier) const
{
	switch (TargetAttribute)
    {
        case EPAttributeType::Health:
            Attributes.Health += Modifier;
            break;
        case EPAttributeType::Mana:
            Attributes.Mana += Modifier;
            break;
        case EPAttributeType::Stamina:
            Attributes.Stamina += Modifier;
            break;
        default:
            break;
    }
}
