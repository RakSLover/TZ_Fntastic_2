
#include "My_BaseTurtle.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

AMy_BaseTurtle::AMy_BaseTurtle()
{

	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = false; 
	GetCharacterMovement()->MaxWalkSpeed = 400;

	AudioEngineComp_ = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	//AudioEngineComp_->SetupAttachment(RootComponent);

}


void AMy_BaseTurtle::BeginPlay()
{
	Super::BeginPlay();
	AudioEngineComp_->AttachTo(RootComponent);
	Start();
	

}


void AMy_BaseTurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMy_BaseTurtle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AMy_BaseTurtle::Start()
{

	Move();
	inMovement = true;
	EngineSound(true);
	if (StartSound_)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), StartSound_, this->GetActorLocation());

}

void AMy_BaseTurtle::Finish()
{
	if (StartSound_)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), FinishSound_, this->GetActorLocation());

	EngineSound(false);
	inMovement = false;
}

void AMy_BaseTurtle::EngineSound(const bool on_off)
{
	if (on_off) 
		AudioEngineComp_->Play();
	else
		AudioEngineComp_->Stop();
}

bool AMy_BaseTurtle::GetInMovement()
{
	return inMovement;
}
