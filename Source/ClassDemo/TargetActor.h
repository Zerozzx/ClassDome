// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"
class UStaticMeshComponent;
class USoundBase;
class UParticleSystem;

UCLASS()
class CLASSDEMO_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetActor();

protected:
	
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundBase* PickUpSound;
	UPROPERTY(EditDefaultsOnly, Category = "ParticleSystem")
		UParticleSystem*PickUpParticle;
public:	
	

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};
