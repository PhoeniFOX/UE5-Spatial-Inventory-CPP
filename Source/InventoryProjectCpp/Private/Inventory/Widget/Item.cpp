// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Widget/Item.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Inventory/Items/ItemObject.h"

void UItem::RefreshItem()
{
	float Width = ItemObject->GetDimensions().X * TileSize;
	float Height = ItemObject->GetDimensions().Y * TileSize;
	Size = FVector2D(Width, Height);
	BackgroundSizeBox->SetWidthOverride(Width);
	BackgroundSizeBox->SetHeightOverride(Height);
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(ItemImage->Slot);
	if (CanvasSlot != nullptr)
	{
		CanvasSlot->SetSize(Size);
	}
}

void UItem::InitializeItem(UItemObject* InItemObject, float InSize)
{
	ItemObject = InItemObject;
	TileSize = InSize;
	GetItemIcon();
	RefreshItem();
}

void UItem::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
	if (UDragDropOperation* Operation = UWidgetBlueprintLibrary::CreateDragDropOperation(UDragDropOperation::StaticClass()))
	{
		Operation->Payload = ItemObject;
		Operation->DefaultDragVisual = this;
		OutOperation = Operation;

		OnRemoved.Broadcast(ItemObject);
		RemoveFromParent();
	}
}

void UItem::GetItemIcon() const
{
	if (ItemObject && ItemImage)
	{
		ItemImage->SetBrushFromMaterial(ItemObject->GetItemImage());
	}
}
