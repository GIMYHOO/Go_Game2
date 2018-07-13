// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandCube.generated.h"

UCLASS()
class GO_GAME_API ARandCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandCube();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	/////////////////* 필요한 언리얼 컴포넌트 선언 *////////////////////
	UPROPERTY(Visibleanywhere, BlueprintReadOnly)				////////
		class UArrowComponent* Arrow;							////////
																////////
	UPROPERTY(Visibleanywhere, BlueprintReadOnly)				////////
		class UStaticMeshComponent* Cube_First;					////////
																////////
	UPROPERTY(Visibleanywhere, BlueprintReadOnly)				////////
		class UStaticMeshComponent* Cube_Second;				////////
																////////
	UPROPERTY(Visibleanywhere, BlueprintReadOnly)				////////
		class UStaticMeshComponent* Cube_Third;					////////
	////////////////////////////////////////////////////////////////////


	int Check, total;// 쓸모없음

	// 큐브가 켜져있는지 꺼져있는지 알아볼 bool값
	bool bFirstCube, bSecondCube, bThirdCube;

	// 큐브 랜덤으로 켜고 끌 함수
	void CheckCube();
};
