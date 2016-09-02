// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "TiroCanhao.h"


// Sets default values
ATiroCanhao::ATiroCanhao()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, 0.0f));
	MeshComp->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	MeshComp->AttachTo(RootComponent);


	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = Root;
	ProjectileMovement->InitialSpeed = 3000.0f;
	ProjectileMovement->MaxSpeed = 3000.0f;


	InitialLifeSpan = 5.0f;



}

// Called when the game starts or when spawned
void ATiroCanhao::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATiroCanhao::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );


	FVector Location = GetActorLocation();
	Location.Z = DefaultZ;
	SetActorLocation(Location);


}

