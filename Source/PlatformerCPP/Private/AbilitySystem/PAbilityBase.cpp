// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/PAbilityBase.h"
#include "AbilitySystem/PAbilityData.h"
#include "AbilitySystem/PAttributeSet.h"

void UPAbilityBase::ActivateAbility(AActor* Instigator, FPAttributeSet* Attributes)
{
	if (bIsOnCooldown) return;

	switch (ConsumedAttribute)
	{
		case EPAttributeType::Health:
			Attributes->Health -= AttributeCost;
		    break;
		case EPAttributeType::Mana:
			Attributes->Mana -= AttributeCost;
            break;
        case EPAttributeType::Stamina:
        	Attributes->Stamina -= AttributeCost;
            break;
        default:
        	return;
	}

	bIsOnCooldown = true;

	if (Cooldown > 0.0f)
	{
		Instigator->GetWorld()->GetTimerManager().SetTimer(
				CoolDownTimerHandle, this, &UPAbilityBase::EndCoolDown, Cooldown, false
			);
	}
}

bool UPAbilityBase::CanActivate(const FPAttributeSet& Attributes)
{
	if (bIsOnCooldown) return false;

	switch (ConsumedAttribute)
	{
		case EPAttributeType::Health:
            return Attributes.Health >= AttributeCost;
        case EPAttributeType::Mana:
            return Attributes.Mana >= AttributeCost;
		case EPAttributeType::Stamina:
			return Attributes.Stamina >= AttributeCost;
        default:
            return false;
	}
}

void UPAbilityBase::EndCoolDown()
{
	bIsOnCooldown = false;
}
