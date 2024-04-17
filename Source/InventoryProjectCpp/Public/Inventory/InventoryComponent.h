// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


class UItemObject;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYPROJECTCPP_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryChanged);
	// Sets default values for this component's properties
	UInventoryComponent();
	
	// Getter and Setter for Columns and Rows
	UFUNCTION(BlueprintCallable)
	int32 GetColumns() const { return Columns; }
	
	UFUNCTION(BlueprintCallable)
	void SetColumns(int NewColumns) { Columns = NewColumns; }
	
	UFUNCTION(BlueprintCallable)
	int32 GetRows() const { return Rows; }
	
	UFUNCTION(BlueprintCallable)
	void SetRows(int NewRows) { Rows = NewRows; }

	void RemoveItem(UItemObject* ItemObject);

	// Try to add item
	bool TryAddItem(UItemObject* ItemObject);
	void AddItemAt(UItemObject* ItemObject, int32 TopLeftIndex);

	bool IsRoomAvailable(UItemObject* ItemObject, int32 TopLeftIndex) const;

	TMap<UItemObject*, FVector2D> GetAllItems() const;

	FVector2D IndexToTile(int32 Index) const;
	int32 TileToIndex(FVector2D Tile) const;

	FOnInventoryChanged OnInventoryChanged;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Columns = 0;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Rows = 0;



	
private:
	
	bool IsDirty = false;
	TArray<UItemObject*> Items;
};
