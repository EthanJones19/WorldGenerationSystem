// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGeneration.h"
#include "DrawDebugHelpers.h"

// Sets default values
AWorldGeneration::AWorldGeneration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);

	GridXSize = 5;
	GridYSize = 5;
	SquareWidth = 200.0f;

	TopLeftCorner = FVector(0.0f);
	BottomRightCorner = FVector(1000.0f, 1000.0f, 0.0f);

	GridHeight = 0.5f;
	WorldLength = 1000.0f;
	WorldWidth = 1000.0f;

	Radius = 100.0f;
	//SpawnAmount = 
	
}

// Called when the game starts or when spawned
void AWorldGeneration::BeginPlay()
{
	Super::BeginPlay();

	CreateFloorGrid();
	PlacePointsOnGrid();
	
	//SpawnItem(CubeClass);
	//SpawnItem(CubeClass);
	//SpawnItem(CubeClass);
	//SpawnItem(CubeClass);
	//SpawnItem(CubeClass);
	//SpawnItem(CubeClass);
	//SpawnItem(CubeClass);
	//SpawnItem(CubeClass);
	//SpawnItem(TreeClass);
	//SpawnItem(TreeClass);
	//SpawnItem(TreeClass);
}

// Called every frame
void AWorldGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AWorldGeneration::SpawnItem(UClass* ItemToSpawn)
//{
//	float XCoordinate = FMath::FRandRange(-1000.0f, 500.0f);
//	float YCoordinate = FMath::FRandRange(-1000.0f, 500.0f);
//	float ZCoordiante = FMath::FRandRange(-50.0f, 50.0f);
//
//	float Yaw = FMath::FRandRange(0.0f, 360.f);
//
//	FVector Location(XCoordinate, YCoordinate, ZCoordiante);
//	FRotator Rotation(0.0f, 0.0f, 0.0f);
//
//
//	GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location, Rotation);
//
//}

void AWorldGeneration::CreateFloorGrid()
{
	for (int32 i = 0; i < GridXSize + 1; i++)
	{
		FVector Start = TopLeftCorner + FVector(i * SquareWidth, 0.0f, GridHeight);
		FVector End = Start + FVector(0.0f, WorldLength, GridHeight);
		DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true);
	}

	for (int32 i = 0; i < GridXSize + 1; i++)
	{
		FVector Start = TopLeftCorner + FVector(0.0f, i * SquareWidth, GridHeight);
		FVector End = Start + FVector(WorldWidth, 0.0f, GridHeight);
		DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true);
	}
}

FVector AWorldGeneration::GetSpawnPoints(const FVector& TopLeft, const FVector& BottomRight)
{
	float SetXAxis = FMath::FRandRange(TopLeft.X, BottomRight.X);
	float SetYAxis = FMath::FRandRange(TopLeft.Y, BottomRight.Y);


	return FVector(SetXAxis, SetYAxis, 0.0f);
}

void AWorldGeneration::PlacePointsOnGrid()
{
	for (int32 i = 0; i < GridXSize; i++)
	{
		for (int32 j = 0; j < GridYSize; j++)
		{
			FVector TopLeft(i * SquareWidth + Radius, j * SquareWidth + Radius, GridHeight);
			FVector BottomRight(i * SquareWidth + SquareWidth - Radius, j * SquareWidth + SquareWidth - Radius, GridHeight);
			FVector SpawnPoints = GetSpawnPoints(TopLeft, BottomRight);

			DrawDebugPoint(GetWorld(), SpawnPoints, 5.0f, FColor::Red, true);
			DrawDebugCircle(GetWorld(), SpawnPoints, 25.0f, 48, FColor::Red, true, -1.0f, 0, 2.5f, FVector(0.0f, 1.0f, 0.0f), FVector(1.0f, 0.0f, 0.0f), true);

			//float Yaw = FMath::FRandRange(0.0f, 10.0f);
			GetWorld()->SpawnActor<AActor>(TreeClass, SpawnPoints, FRotator(0.0f, 0.0f, 0.0f));
			//GetWorld()->SpawnActor<AActor>(CubeClass, SpawnPoints, FRotator(0.0f, 0.0f, 0.0f));

			
		}
	}
}
