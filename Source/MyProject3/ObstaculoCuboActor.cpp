// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "ObstaculoCuboActor.h"


// Sets default values
AObstaculoCuboActor::AObstaculoCuboActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject < UStaticMeshComponent>(TEXT("MeshComp"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);

	}

	MeshComp->SetWorldLocation(FVector(.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(0.6f, 0.6f, 0.6f));
	MeshComp->AttachTo(RootComponent);



}

// Called when the game starts or when spawned
void AObstaculoCuboActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculoCuboActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector LocalizacaoAtual = GetActorLocation();

	float DeltaRange = 5.0f;

		LocalizacaoAtual.X -= DeltaRange;


		if (LocalizacaoAtual.X == 50) {
			LocalizacaoAtual.Y = DeltaRange;
		}


		
	RunningTime += DeltaTime;
	
	SetActorLocation(LocalizacaoAtual);



}

