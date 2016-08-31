// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD2.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API AMyHUD2 : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD2();
	UPROPERTY(EditAnywhere)
		UFont* HUDFont;
	UPROPERTY(EditAnywhere)
		UTexture2D* MyTexture;

	virtual void DrawHUD() override;
	
	
};
