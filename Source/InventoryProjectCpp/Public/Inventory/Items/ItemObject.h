// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemObject.generated.h"

class UImage;
/**
 * 
 */
UCLASS(BlueprintType)
class INVENTORYPROJECTCPP_API UItemObject : public UObject
{
	GENERATED_BODY()

public:
	UItemObject();
	
	UFUNCTION(BlueprintCallable)
	void InitializeItemObject(int32 dimensionX, int32 dimensionY, class UMaterialInterface* InIcon,  UMaterialInterface* InRIcon, TSubclassOf<class AItemActor> itemClass);
	
	FIntPoint GetDimensions() const;

	UMaterialInterface* GetItemImage() const;

	TSubclassOf<AItemActor> GetItemClass() const { return ItemActorClass; }

	void Rotate() { bRotated = !bRotated; }
	bool IsRotated() const { return bRotated; }
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FIntPoint Dimensions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* Icon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* RIcon;
	
	bool bRotated;

	UPROPERTY()
	TSubclassOf<AItemActor> ItemActorClass;
};
