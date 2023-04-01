// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "KeyboardKeyWidget.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKeyWidgetDelegate, FString, MessageString);



UCLASS()
class KIBERPAVLOV_API UKeyboardKeyWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString KeyDisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString KeyAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString KeyLetter;

	UPROPERTY(BlueprintAssignable)
	FKeyWidgetDelegate OnLetter;

	UPROPERTY(BlueprintAssignable)
	FKeyWidgetDelegate OnAction;

protected:
	
	virtual void NativeConstruct() override;

	
	virtual void NativePreConstruct() override;
	

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UButton* KeyBTN;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* KeyTB;

public:
	UFUNCTION()
	void HandleClick();
};
