// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryGameStateBase.h"

#include "Inventory/Items/ItemActor.h"
#include "Inventory/Items/ItemObject.h"

void AInventoryGameStateBase::SpawnItemFromActor(AActor* Actor, UItemObject* ItemObject, bool GroundClamp) const
{
	FVector SpawnLocation = Actor->GetActorLocation() + Actor->GetActorForwardVector() * 150.f;
	if (GroundClamp)
	{
		FHitResult HitResult;
		FVector Start = SpawnLocation;
		FVector End = SpawnLocation - FVector::UpVector * 1000.f;
		FCollisionQueryParams CollisionQueryParams;
		CollisionQueryParams.AddIgnoredActor(Actor);
		if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility, CollisionQueryParams))
		{
			SpawnLocation = HitResult.Location;
		}
	}
	if (UWorld* World = GetWorld())
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		SpawnLocation.Z += 50.f;
		World->SpawnActor<AItemActor>(ItemObject->GetItemClass(), SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	}
}
