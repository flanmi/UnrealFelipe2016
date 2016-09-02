// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "Inimigo.h"
#include "MyCharacter.h"


// Sets default values
AInimigo::AInimigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	
	Root->SetCollisionProfileName("OnHit");
	//Root->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	Root->OnComponentHit.AddDynamic(this, &AInimigo::OnHit);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MeshComp"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);

	}

	MeshComp->SetWorldLocation(FVector(.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(0.9f, 0.9f, 0.9f));
	MeshComp->AttachTo(RootComponent);



}

// Called when the game starts or when spawned
void AInimigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInimigo::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );



	FVector LocalizacaoAtual = GetActorLocation();

	float DeltaRange = 6.0f;

	if (ContadorDistancia >= 0 && ContadorDistancia < 80) {

		LocalizacaoAtual.X -= DeltaRange;

	}
	else if (ContadorDistancia >= 80 && ContadorDistancia < 160) {
		LocalizacaoAtual.X += DeltaRange;
	}

	else if (ContadorDistancia == 160) {
		ContadorDistancia = 0.0f;

	}

	ContadorDistancia++;


	RunningTime += DeltaTime;

	SetActorLocation(LocalizacaoAtual);




}

void AInimigo::OnHit(UPrimitiveComponent* HitComponent, AActor*OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)
		&& (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetLife(MyCharacter->GetLife() - DamageAmount);
		MyCharacter->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("Life = %d"), MyCharacter->GetLife());
		Destroy();

	}
}