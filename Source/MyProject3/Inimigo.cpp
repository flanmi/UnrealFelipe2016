// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "Inimigo.h"
#include "MyCharacter.h"
#include "ProjectyleActor.h"


// Sets default values
AInimigo::AInimigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	
	//Root->SetCollisionProfileName("BlockAll");
	//Root->OnComponentHit.AddDynamic(this, &AInimigo::OnHit);

	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &AInimigo::OnOverlapBegin);


	RootComponent = Root;

	MeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MeshComp"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	MeshComp->SetCollisionProfileName("NoCollision");
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
void AInimigo::SetLife(int NewLife) {
	Life = NewLife;
}
int AInimigo::GetLife() {
	return Life;
}


void AInimigo::Die() {
	
		Destroy();
	
}




//void AInimigo::OnHit(UPrimitiveComponent* HitComponent, AActor*OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	
//	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
		//{
//		UE_LOG(LogTemp, Warning, TEXT("HIT"));
//		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
//		MyCharacter->SetLife(MyCharacter->GetLife() - DamageAmount);
//		MyCharacter->OnDeath();
//		UE_LOG(LogTemp, Warning, TEXT("Life = %d"), MyCharacter->GetLife());
		

	//}
//


	

//}


void AInimigo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherActor->IsA(AMyCharacter::StaticClass())) && (OtherComp != nullptr))
	{
		UE_LOG(LogTemp, Warning, TEXT("HIT"));
		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetLife(MyCharacter->GetLife() - DamageAmount);
		MyCharacter->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("Life = %d"), MyCharacter->GetLife());


	}

	
	
	
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherActor->IsA(AProjectyleActor::StaticClass())) && (OtherComp != nullptr)) {

		
		
		AProjectyleActor* ProjectyleActor = Cast<AProjectyleActor>(OtherActor);
		UE_LOG(LogTemp, Warning, TEXT("OverlapBegin"));
		Die();
			

		}


	
}