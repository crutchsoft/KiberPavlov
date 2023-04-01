// Fill out your copyright notice in the Description page of Project Settings.


#include "NumericKeyboardWidget.h"
#include "KeyboardKeyWidget.h"


void UNumericKeyboardWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void UNumericKeyboardWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	CurrentTextTB->SetText(FText::FromString(CurrentString));

	TArray<UWidget*> Children;
	Children = KeysUniformGridPanel->GetAllChildren();

	for (auto Child : KeysUniformGridPanel->GetAllChildren())
	{
		Cast<UKeyboardKeyWidget>(Child)->OnLetter.AddDynamic(this, &UNumericKeyboardWidget::HandleLetter);
		Cast<UKeyboardKeyWidget>(Child)->OnAction.AddDynamic(this, &UNumericKeyboardWidget::HandleAction);
	}
}

void UNumericKeyboardWidget::HandleLetter(FString KeyLetter)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, KeyLetter);

	if (CurrentString.Len() >= TextMask.Len()) {
		return;
	}

	CurrentString.Append(KeyLetter);
	ApplyMask();
	HandleCurrentStringChange();

}

void UNumericKeyboardWidget::HandleAction(FString KeyAction)
{
	if (KeyAction == "Erase") {
		if (CurrentString.Len() > 0) {
			CurrentString = CurrentString.Mid(0, CurrentString.Len() - 1);
			HandleCurrentStringChange();
		}
	}
	else if (KeyAction == "Clear") {
		CurrentString = "";
		HandleCurrentStringChange();
	}
}

void UNumericKeyboardWidget::ApplyMask()
{

	if (CurrentString.Len() >= TextMask.Len()) {
		return;
	}

	FString MaskLetter = TextMask.Mid(CurrentString.Len(), 1);
	if (MaskLetter == ".") {
		CurrentString.Append(".");
		HandleCurrentStringChange();
	}
}

void UNumericKeyboardWidget::HandleCurrentStringChange()
{
	CurrentTextTB->SetText(FText::FromString(CurrentString));
	OnChange.Broadcast(CurrentString);
}
