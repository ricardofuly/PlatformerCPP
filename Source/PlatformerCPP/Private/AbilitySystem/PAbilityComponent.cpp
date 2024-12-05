// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/PAbilityComponent.h"

#include "AbilitySystem/PAbilityBase.h"

// Sets default values for this component's properties
UPAbilityComponent::UPAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UPAbilityComponent::ActivateAbilityByName(FName Name)
{
	for (UPAbilityBase* Ability : Abilities)
	{
		if (Ability && Ability->AbilityName == Name)
		{
			if (Ability->CanActivate(Attributes))
			{
				Ability->ActivateAbility(GetOwner(), &Attributes);
			}
			break;
		}
	}
}

// Called when the game starts
void UPAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

