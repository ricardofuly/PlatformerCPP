// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PAttributeSet.h"
#include "Components/ActorComponent.h"
#include "PAbilityComponent.generated.h"


struct FPAttributeSet;
class UPAbilityBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLATFORMERCPP_API UPAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPAbilityComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UPAbilityBase*> Abilities;

	FPAttributeSet Attributes;

	UFUNCTION(BlueprintCallable)
	void ActivateAbilityByName(FName Name);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
