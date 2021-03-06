// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "ObstaculoBolaActor2.h"


// Sets default values
AObstaculoBolaActor2::AObstaculoBolaActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;




	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MeshComp"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);

	}

	MeshComp->SetWorldLocation(FVector(.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
	MeshComp->AttachTo(RootComponent);


}

// Called when the game starts or when spawned
void AObstaculoBolaActor2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculoBolaActor2::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );



	FVector LocalizacaoAtual = GetActorLocation();

	float DeltaRange = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	LocalizacaoAtual.Y += DeltaRange * 650.0f;
	RunningTime += DeltaTime;


	SetActorLocation(LocalizacaoAtual);


}

