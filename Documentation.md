# Documentation

## WorldGeneration.h/cpp:

### Includes:

- CoreMinimal.h
- GameFramework/Actor.h
- WorldGeneration.generated.h

### UProperties:
- Type: private
- UStaticMeshComponent* Floor
- UStaticMeshComponent* CubeClass
- UStaticMeshComponent* TreeClass

### Functions/Variables:

- Name: AWorldGeneration()

- Type: public

- Use: Sets the default values.
___

- Name: BeginPlay()

- Type: protected
virtual void override

- Use: Starts the game when called
___

- Name: Tick()

- Type: public
virtual void override

- Use: Calls every frame
___

- Name: SquareWidth

- Type: float

- Use: Sets the values of the square width
___

- Name: GridFloorHeight

- Type: float

- Use: Sets the values of the grid floor height
___

- Name: GridTopFloorHeight

- Type: float

- Use: Sets the values of the grid top floor height
___

- Name: WorldLength

- Type: float

- Use: Sets the values of the world length
___

- Name: WorldWidth

- Type: float

- Use: Sets the values of the world width
___

- Name: TopLeftCorner

- Type: FVector

- Use: Sets the axis of the top left corner of the grid
___

- Name: BottomRightCorner

- Type: FVector

- Use: Sets the axis of the bottom right corner of the grid
___

- Name: GridXSize

- Type: int32

- Use: Sets the values of the grid X axis
___

- Name: GridYSize

- Type: int32

- Use: Sets the values of the grid Y axis
___

- Name: Radius

- Type: float

- Use: Sets the values of the radius
___

- Name: SpawnAmount

- Type: int

- Use: Sets the values of the spawn amount
___

- Name: TopSpawnAmount

- Type: int

- Use: Sets the values of the top spawn amount
___

- Name: CreateFloorGrid()

- Type: void

- Use: Creates the floor grid with the square width and height. Gets the world's length for the grid. 
___

- Name: GetSpawnPoints

- Type: FVector

- Use: Gets the axis in a random range for the spawn point
___

- Name: PlacePointsOnGrid()

- Type: void

- Use: Places the points within the radius of the grid
___

- Name: PlacePointsAboveTheGrid()

- Type: void

- Use: Places the points within the radius of the top grid
