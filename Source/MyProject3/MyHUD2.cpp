// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "MyHUD2.h"
#include "Engine/Font.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "Boss.h"

AMyHUD2::AMyHUD2() {
	static ConstructorHelpers::FObjectFinder<UFont>Font(TEXT("Font'/Engine/EngineFonts/RobotoDistanceField.RobotoDistanceField'"));
	if (Font.Succeeded()) {
		HUDFont = Font.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D>Texture(TEXT("Texture2D'/Game/Texturas/coracao1.coracao1'"));
		if (Texture.Succeeded()) {
			MyTexture = Texture.Object;
		}
}

void AMyHUD2::DrawHUD() {
	Super::DrawHUD();


	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	FString LifeString = FString::Printf(TEXT("Life: "), MyCharacter->GetLife());
	DrawText(LifeString, FColor::Red, 50, 50, HUDFont);


	FString CoinString = FString::Printf(TEXT("Coins: %d/10"), MyCharacter->GetContadorMoedinha());
	DrawText(CoinString, FColor::Yellow, 50, 70, HUDFont);

	if (MyCharacter->GetContadorMoedinha() == 10) {
		FString Kill = FString::Printf(TEXT("MATE O BOSS!!"));
		DrawText(Kill, FColor::Red, 80, 80, HUDFont);
		
	}
	if (MyCharacter->GetLife() == 0) {
		FString Fim = FString::Printf(TEXT("GAME OVER"));
		DrawText(Fim, FColor::Red, 180, 180, HUDFont);
	}

	

	if (MyCharacter->GetLife() == 3) {
		DrawTextureSimple(MyTexture, 200, 50, 1.0f, false);
		DrawTextureSimple(MyTexture, 230, 50, 1.0f, false);
		DrawTextureSimple(MyTexture, 260, 50, 1.0f, false);
	}
	else if (MyCharacter->GetLife() == 2) {
		DrawTextureSimple(MyTexture, 200, 50, 1.0f, false);
		DrawTextureSimple(MyTexture, 230, 50, 1.0f, false);
	}
	else if (MyCharacter->GetLife() == 1) {
		DrawTextureSimple(MyTexture, 200, 50, 1.0f, false);
	}

	


	//DrawTextureSimple(MyTexture, 300, 50, 1.0f, false);

	//DrawTexture(MyTexture, 200, 50, MyCharacter->GetLife()*4, MyTexture->GetSizeY(), 200, 50, MyCharacter->GetLife()*4, MyTexture->GetSizeY(),
	//	FLinearColor::White, EBlendMode::BLEND_Translucent, 1.0f, false, 0.0f, FVector2D::ZeroVector);
	
		
	
	//checar
	//ABoss* Boss = Cast<ABoss>(UGameplayStatics::GetPlayerPawn(this, 0));
		//if (Boss != nullptr) {
		//FString LifeString2 = FString::Printf(TEXT("Boss Life: %d"), ABoss->GetBossLife());
		//DrawText(LifeString2, FColor::Red, 70, 50, HUDFont);
		//}

	//if (Boss->GetBossLife() == 0) {
	//	FString Kill = FString::Printf(TEXT("PARABENS"));
	//	DrawText(Kill, FColor::Blue, 200, 200, HUDFont);
	//}

}






	


	

	


	
