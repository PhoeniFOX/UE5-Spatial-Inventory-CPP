// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Item.generated.h"

class UItemObject;
class UImage;
class UBorder;
class USizeBox;
/**
 * 
 */
UCLASS()
class INVENTORYPROJECTCPP_API UItem : public UUserWidget
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoved, UItemObject*, ItemObject);

	void RefreshItem();
	void GetItemIcon() const;

	void InitializeItem(UItemObject* InItemObject, float InSize);

	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	
	FOnRemoved OnRemoved;
protected:
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	USizeBox* BackgroundSizeBox;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UBorder* BackgroundBorder;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UImage* ItemImage;

	UPROPERTY()
	UItemObject* ItemObject;

	FVector2D Size;

private:

	float TileSize = 50.f;
};
