// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

class UItemObject;
class USphereComponent;

UCLASS()
class INVENTORYPROJECTCPP_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// Sets default values for this actor's properties
	AItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USphereComponent* SphereComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UItemObject* ItemObject;

	UFUNCTION(BlueprintImplementableEvent)
	UItemObject* GetDefaultItemObject();
};
