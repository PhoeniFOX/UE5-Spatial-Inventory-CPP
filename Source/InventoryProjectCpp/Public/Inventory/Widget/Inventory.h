// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inventory.generated.h"

class UInventoryComponent;
/**
 * 
 */
UCLASS()
class INVENTORYPROJECTCPP_API UInventory : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitializeInventory(UInventoryComponent* inventoryComponent, float tileSize);

	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UInventoryComponent* InventoryComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TileSize = 50.f;

private:
};
