// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "Boss.h"
#include "BombaBoss.h"


// Sets default values
ABoss::ABoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MeshComp"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);

	}

	MeshComp->SetWorldLocation(FVector(.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ABoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoss::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector LocalizacaoAtual = GetActorLocation();

	float DeltaRange = 5.0f;

	if (ContadorDistancia >= 0 && ContadorDistancia < 45) {

		LocalizacaoAtual.X -= DeltaRange;

	}
	else if (ContadorDistancia >= 45 && ContadorDistancia < 75) {
		LocalizacaoAtual.Y += DeltaRange;

	}
	else if (ContadorDistancia >= 75 && ContadorDistancia < 150) {
		LocalizacaoAtual.X -= DeltaRange;

	}
	else if (ContadorDistancia >= 150 && ContadorDistancia < 190) {
		LocalizacaoAtual.Y += DeltaRange;

	}

	else if (ContadorDistancia >= 190 && ContadorDistancia < 310) {
		LocalizacaoAtual.X += DeltaRange;

	}

	else if (ContadorDistancia >= 310 && ContadorDistancia < 380) {
		LocalizacaoAtual.Y -= DeltaRange;

	}


	else if (ContadorDistancia == 380) {
		ContadorDistancia = 0.0f;

	}

	ContadorDistancia++;


	RunningTime += DeltaTime;

	SetActorLocation(LocalizacaoAtual);



	if (ContadorTiro == 120.0f) {
		DropProjectile();
		ContadorTiro = 0;
	}


	ContadorTiro++;
	BossDerrotado();


}

void ABoss::DropProjectile() {
	FActorSpawnParameters SpawnParameters;
	UWorld* World = GetWorld();
	if (World != nullptr) {
		FRotator Rotation = MeshComp->GetComponentRotation();
		ABombaBoss* Proj = World->SpawnActor<ABombaBoss>(GetActorLocation(), Rotation, SpawnParameters);
		if (Proj != nullptr) {
			//UE_LOG(LogTemp, Warning, TEXT("Spawn OK!"));
		}
	}

}



void ABoss::SetBossLife(int NewBossLife) {
	BossLife = NewBossLife;
}
int ABoss::GetBossLife() {
	return BossLife;
}


void ABoss::BossDerrotado(){
if (BossLife <= 0) {
	
	Destroy();
	
}

}