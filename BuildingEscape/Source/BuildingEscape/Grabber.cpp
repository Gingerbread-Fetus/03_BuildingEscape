// Copyright Ben Tristem 2016.
#include "BuildingEscape.h"
#include "DrawDebugHelpers.h"
#include "Grabber.h"



#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandleComponent();
	SetupInputComponent();
}

//Look for attached Input Handle
void UGrabber::SetupInputComponent()
{

	InputHandle = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputHandle)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input component found."));
		/// Bind the input axis
		InputHandle->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputHandle->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing input handle component"), *GetOwner()->GetName());
	}
}

void UGrabber::FindPhysicsHandleComponent()
{
	//Look for attached Physics Handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{
		//Physics handle is found
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName());
	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//If the physics handle is attached.
		// move the object we're holding.

}

void UGrabber::Grab() 
{
	UE_LOG(LogTemp, Warning, TEXT("Grab pressed."));

	//lINE TRACE and try and see if we reach any actors with physics body collision channel set
	GetFirstPhysicsBodyInReach();

	//If we hit something then attach a physics handle
	///TODO: Attach physics handle
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab released."));
	///TODO: Release physics handle
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	//Get player view point this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	//Setup query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	FHitResult Hit;
	//Line-trace (AKA ray-cast) out to reach distance
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	//See what we hit
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit on: %s"),
			*(ActorHit->GetName()));
	}
	return Hit;
}
