// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetActor.h"
#include "Kismet/GameplayStatics.h"
#include "ClassDemoCharacter.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ATargetActor::ATargetActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComp;
	MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}




void ATargetActor::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if (OtherActor)
	{
		AClassDemoCharacter*M_Character = Cast<AClassDemoCharacter>(OtherActor);
		M_Character->bIsCarry = true;
		UGameplayStatics::PlaySoundAtLocation(this, PickUpSound, GetActorLocation());
		UGameplayStatics::SpawnEmitterAtLocation(this, PickUpParticle, GetActorLocation());
	}
	Destroy();
}