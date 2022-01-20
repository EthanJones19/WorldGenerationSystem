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

	//Sets the grid size
	GridXSize = 5;
	GridYSize = 5;

	//Sets the size for squares of the grid
	SquareWidth = 200.0f;
	TopLeftCorner = FVector(0.0f);
	BottomRightCorner = FVector(1000.0f, 1000.0f, 0.0f);

	GridFloorHeight = 0.5f;
	GridTopFloorHeight = 100.0f;
	WorldLength = 1000.0f;
	WorldWidth = 1000.0f;

	Radius = 100.0f;
	SpawnAmount = 0;
	TopSpawnAmount = 0;
	
}

// Called when the game starts or when spawned
void AWorldGeneration::BeginPlay()
{
	Super::BeginPlay();

	CreateFloorGrid();
	PlacePointsOnGrid();
	PlacePointsAboveTheGrid();
	
}

// Called every frame
void AWorldGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AWorldGeneration::CreateFloorGrid()
{
	for (int32 i = 0; i < GridXSize + 1; i++)
	{
		FVector Start = TopLeftCorner + FVector(i * SquareWidth, 0.0f, GridFloorHeight);
		FVector End = Start + FVector(0.0f, WorldLength, GridFloorHeight);
		DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true);
	}

	for (int32 i = 0; i < GridXSize + 1; i++)
	{
		FVector Start = TopLeftCorner + FVector(0.0f, i * SquareWidth, GridFloorHeight);
		FVector End = Start + FVector(WorldWidth, 0.0f, GridFloorHeight);
		DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true);
	}
}


FVector AWorldGeneration::GetSpawnPoints(const FVector& TopLeft, const FVector& BottomRight, const FVector& MiddleTop)
{
	float SetXAxis = FMath::FRandRange(TopLeft.X, BottomRight.X);
	float SetYAxis = FMath::FRandRange(TopLeft.Y, BottomRight.Y);
	float SetZAxis = FMath::FRandRange(MiddleTop.Z, MiddleTop.Z);

	return FVector(SetXAxis, SetYAxis, SetZAxis);
}


void AWorldGeneration::PlacePointsOnGrid()
{
	for (int32 i = 0; i < GridXSize; i++)
	{
		for (int32 j = 0; j < GridYSize; j++)
		{
			FVector TopLeft(i * SquareWidth + Radius, j * SquareWidth + Radius, GridFloorHeight);
			FVector BottomRight(i * SquareWidth + SquareWidth - Radius, j * SquareWidth + SquareWidth - Radius, GridFloorHeight);
			FVector MiddleTop(0.5f);
			FVector SpawnPoints = GetSpawnPoints(TopLeft, BottomRight, MiddleTop);


			DrawDebugPoint(GetWorld(), SpawnPoints, 5.0f, FColor::Red, true);
			DrawDebugCircle(GetWorld(), SpawnPoints, 25.0f, 48, FColor::Red, true, -1.0f, 0, 2.5f, FVector(0.0f, 1.0f, 0.0f), FVector(1.0f, 0.0f, 0.0f), true);

			
			if (SpawnAmount < FMath::FRandRange(0, 25))
			{
				GetWorld()->SpawnActor<AActor>(CubeClass, SpawnPoints, FRotator(0.0f, 0.0f, 0.0f));
				SpawnAmount += 1;
			}
			
		}
	}
}

void AWorldGeneration::PlacePointsAboveTheGrid()
{
	for (int32 i = 0; i < GridXSize; i++)
	{
		for (int32 j = 0; j < GridYSize; j++)
		{
			FVector TopLeft(i * SquareWidth + Radius, j * SquareWidth + Radius, GridTopFloorHeight);
			FVector BottomRight(i * SquareWidth + SquareWidth - Radius, j * SquareWidth + SquareWidth - Radius, GridTopFloorHeight);
			FVector MiddleTop(100.0f);
			FVector TopSpawnPoints = GetSpawnPoints(TopLeft, BottomRight, MiddleTop);


			DrawDebugPoint(GetWorld(), TopSpawnPoints, 5.0f, FColor::Red, true);
			DrawDebugCircle(GetWorld(), TopSpawnPoints, 25.0f, 48, FColor::Red, true, -1.0f, 0, 2.5f, FVector(0.0f, 1.0f, 0.0f), FVector(1.0f, 0.0f, 0.0f), true);


			if (TopSpawnAmount < FMath::FRandRange(0, 15))
			{
				GetWorld()->SpawnActor<AActor>(TreeClass, TopSpawnPoints, FRotator(0.0f, 0.0f, 0.0f));
				TopSpawnAmount += 1;
			}

		}
	}
}
