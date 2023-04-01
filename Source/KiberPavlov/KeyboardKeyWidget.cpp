// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyboardKeyWidget.h"


void UKeyboardKeyWidget::NativeConstruct()
{
	Super::NativeConstruct();

}


void UKeyboardKeyWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	KeyBTN->OnClicked.AddDynamic(this, &UKeyboardKeyWidget::HandleClick);
	KeyTB->SetText(FText::FromString(KeyDisplayText));
}



void UKeyboardKeyWidget::HandleClick()
{

	if (KeyAction != "") {
		OnAction.Broadcast(KeyAction);
	}

	if (KeyLetter != "") {
		OnLetter.Broadcast(KeyLetter);
	}
}
