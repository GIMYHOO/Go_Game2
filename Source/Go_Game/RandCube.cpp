// Fill out your copyright notice in the Description page of Project Settings.

#include "RandCube.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "ConstructorHelpers.h"

// Sets default values
ARandCube::ARandCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//////////////////////////////////////////*큐브들 설정*///////////////////////////////////////////////////
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(RootComponent);

	Cube_First = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_First"));
	Cube_First->SetupAttachment(Arrow);

	Cube_Second = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_Second"));
	Cube_Second->SetupAttachment(Arrow);

	Cube_Third = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_Third"));
	Cube_Third->SetupAttachment(Arrow);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("StaticMesh'/Game/03_Mesh+Materials/Meshes/1M_Cube.1M_Cube'"));
	if (Cube.Succeeded())
	{
		Cube_First->SetStaticMesh(Cube.Object);
		Cube_Second->SetStaticMesh(Cube.Object);
		Cube_Third->SetStaticMesh(Cube.Object);
	}

	Cube_Second->SetRelativeLocation(FVector(100, 0, 0));
	Cube_Third->SetRelativeLocation(FVector(200, 0, 0));

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// 처음 생성했을 땐 전부다 보이게 설정.
	bFirstCube = true;
	bSecondCube = true;
	bThirdCube = true;

	total = 0;
}

// Called when the game starts or when spawned
void ARandCube::BeginPlay()
{
	Super::BeginPlay();

	// 전부다 켜져있을경우 다시 랜덤함수를 돌림.
	while (true)
	{
		if ((bFirstCube && bSecondCube && bThirdCube) || (!bFirstCube && !bSecondCube && !bThirdCube))
		{
			CheckCube();
			total++;
		}
		else
		{
			break;
		}
		UE_LOG(LogClass, Warning, TEXT("%d"), total);
	}
}

// Called every frame
void ARandCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ARandCube::CheckCube()
{
	Check = FMath::FRandRange(1, 10);
	//UE_LOG(LogClass, Warning, TEXT("%d"), Check);

	if (Check % 2 == 0)
	{
		bFirstCube = true;
		Cube_First->SetVisibility(true);
	}
	else
	{
		bFirstCube = false;
		Cube_First->SetVisibility(false);
		Cube_First->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	Check = FMath::FRandRange(1, 10);
	//UE_LOG(LogClass, Warning, TEXT("%d"), Check);

	if (Check % 2 == 0)
	{
		bSecondCube = true;
		Cube_Second->SetVisibility(true);
	}
	else
	{
		bSecondCube = false;
		Cube_Second->SetVisibility(false);
		Cube_Second->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	Check = FMath::FRandRange(1, 10);
	//UE_LOG(LogClass, Warning, TEXT("%d"), Check);
	if (Check % 2 == 0)
	{
		bThirdCube = true;
		Cube_Third->SetVisibility(true);
	}
	else
	{
		bThirdCube = false;
		Cube_Third->SetVisibility(false);
		Cube_Third->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

