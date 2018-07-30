// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpActor.generated.h"
class USoundBase;
class UStaticMeshComponent;
class UParticleSystem;
UCLASS()
class CLASSDEMO_API APickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* PickUpSound;
	UPROPERTY(EditAnywhere, Category = "ParticleSystem")
	UParticleSystem* PickUpParticle;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
	
};
