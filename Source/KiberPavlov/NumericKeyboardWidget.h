// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "NumericKeyboardWidget.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNumericKeyboardWidgetDelegate, FString, MessageString);



UCLASS()
class KIBERPAVLOV_API UNumericKeyboardWidget : public UUserWidget
{
	GENERATED_BODY()


protected:
	virtual void NativeConstruct() override;

	virtual void NativePreConstruct() override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUniformGridPanel* KeysUniformGridPanel;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CurrentTextTB;

public:
	UFUNCTION()
	void HandleLetter(FString LetterString);

	UFUNCTION()
	void HandleAction(FString ActionString);

	UFUNCTION()
	void ApplyMask();

	UFUNCTION()
	void HandleCurrentStringChange();

	UPROPERTY(BlueprintAssignable)
	FNumericKeyboardWidgetDelegate OnChange;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CurrentString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TextMask = "000.000.0.0";
};
