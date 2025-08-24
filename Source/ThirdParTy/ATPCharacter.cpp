// Fill out your copyright notice in the Description page of Project Settings.


#include "ATPCharacter.h"

// Sets default values
AATPCharacter::AATPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AATPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AATPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

