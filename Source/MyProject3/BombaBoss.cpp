// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "BombaBoss.h"
#include "MyCharacter.h"


// Sets default values
ABombaBoss::ABombaBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->SetWorldScale3D(FVector(3.5f, 3.5f, 3.5f));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &ABombaBoss::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, 0.0f));
	MeshComp->SetWorldScale3D(FVector(0.09f, 0.09f, 0.09f));
	MeshComp->AttachTo(RootComponent);

	InitialLifeSpan = 2.0f;
	// ^^^^
}

// Called when the game starts or when spawned
void ABombaBoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABombaBoss::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );



	
	Explodir++;

}

void ABombaBoss::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherActor->IsA(AMyCharacter::StaticClass())) && (OtherComp != nullptr)){

		UE_LOG(LogTemp, Warning, TEXT("OverlapBegin"));
		if (InitialLifeSpan == 2.0f) {
			///if( acabar lifespawn)
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
			MyCharacter->SetLife(MyCharacter->GetLife() - DamageAmount);
			MyCharacter->OnDeath();
			UE_LOG(LogTemp, Warning, TEXT("Life = %d"), MyCharacter->GetLife());
			
		}


	}
}