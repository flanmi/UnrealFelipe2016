// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "Abismo.h"
#include "MyCharacter.h"

// Sets default values
AAbismo::AAbismo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &AAbismo::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AAbismo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbismo::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AAbismo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherActor->IsA(AMyCharacter::StaticClass())) && (OtherComp != nullptr)) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetLife(0);
		MyCharacter->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("OverlapBegin"));
		

	}

}