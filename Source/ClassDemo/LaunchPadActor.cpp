// Fill out your copyright notice in the Description page of Project Settings.

#include "LaunchPadActor.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ALaunchPadActor::ALaunchPadActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LaunchPadBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaunchPadBase"));
	LanuchPanal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaunchPanal"));
	BoxCom = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));
	RootComponent = LaunchPadBase;
	LanuchPanal->SetupAttachment(LaunchPadBase);
	BoxCom->SetupAttachment(LanuchPanal);
	BoxCom->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCom->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BoxCom->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPadActor::ActiveLaunch);
	LaunchStrengh = 1500.f;
	LaunchAngle = 45.f;
}

void ALaunchPadActor::ActiveLaunch(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	FRotator LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch += LaunchAngle;
	FVector LaunchVelocity = LaunchDirection.Vector()*LaunchStrengh;
	ACharacter *Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ActiveParticle, GetActorLocation());
		UGameplayStatics::PlaySoundAtLocation(this, ActiveSound, GetActorLocation());
		Character->LaunchCharacter(LaunchVelocity, true, true);
	}
	else if (OtherComp&&OtherComp->IsSimulatingPhysics())
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ActiveParticle, GetActorLocation());
		UGameplayStatics::PlaySoundAtLocation(this, ActiveSound, GetActorLocation());
		OtherComp->AddImpulse(LaunchVelocity, NAME_None, true);
	}
}