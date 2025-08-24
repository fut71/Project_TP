// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ATPPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class THIRDPARTY_API AATPPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TArray<UInputMappingContext*> DefaultMappingContexts;

	virtual void SetupInputComponent() override;

};
