// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inventory/Items/ItemObject.h"
#include "InventoryGrid.generated.h"

class USlateBrushAsset;
class UItem;
struct FLine;
class UCanvasPanel;
class UBorder;
class UInventoryComponent;
/**
 * 
 */
UCLASS()
class INVENTORYPROJECTCPP_API UInventoryGrid : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void InitializeGrid(UInventoryComponent* InventoryComponent, float TileSize);

	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

	UFUNCTION()
	void OnItemRemoved(UItemObject* ItemObject);

	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual bool NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual void NativeOnDragEnter(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual void NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	
	UFUNCTION()
	void RefreshGrid();
protected:
	UFUNCTION(BlueprintCallable)
	void DrawGrid(FPaintContext& Context) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	UItem* CreateItemWidget();

	UFUNCTION(BlueprintCallable)
	void RotateItem();

	UItemObject* GetPayload(const UDragDropOperation& InDragDropEvent) const;

	bool IsRoomAvailable(UItemObject* Payload) const;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UBorder* GridBorder;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* GridCanvasPanel;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float TileSize = 50.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor LineColor = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool AntiAliasing = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float LineThickness = 1.f;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<FLine> Lines;

	UPROPERTY(VisibleAnywhere, Category=Private)
	UInventoryComponent* InventoryComponent;

	FIntPoint DraggedItemTopLeftTile;

	bool bDrawDropLocation = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USlateBrushAsset* ItemBackgroundColor;
private:
	void CreateLineSegments();

	/*
	 * @return Pair<isRight, isDown>
	 */
	Chaos::Pair<bool,bool> MousePositionInTile(FVector2D MousePosition) const;
};
