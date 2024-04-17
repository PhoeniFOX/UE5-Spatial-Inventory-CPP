// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "InventoryGameStateBase.generated.h"

class UItemObject;
/**
 * 
 */
UCLASS()
class INVENTORYPROJECTCPP_API AInventoryGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	void SpawnItemFromActor(AActor* Actor, UItemObject* ItemObject, bool GroundClamp = true) const;
};
