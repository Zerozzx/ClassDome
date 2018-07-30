// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaunchPadActor.generated.h"
class UBoxComponent;
class UStaticMeshComponent;
class UParticleSystem;
class USoundBase;
UCLASS()
class CLASSDEMO_API ALaunchPadActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaunchPadActor();

protected:
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* LaunchPadBase;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* LanuchPanal;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* BoxCom;
	UPROPERTY(EditInstanceOnly, Category = "LaunchPad")
		float LaunchAngle;
	UPROPERTY(EditInstanceOnly, Category = "LaunchPad")
		float LaunchStrengh;
	UPROPERTY(EditDefaultsOnly, Category = "LaunchPad")
		UParticleSystem* ActiveParticle;
	UPROPERTY(EditDefaultsOnly, Category = "LaunchPad")
		USoundBase* ActiveSound;
	UFUNCTION()
		void ActiveLaunch(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
public:	
	

	
	
};
