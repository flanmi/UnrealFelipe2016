// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "Parede.h"


// Sets default values
AParede::AParede()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);


}

// Called when the game starts or when spawned
void AParede::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParede::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

