
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "My_BaseTurtle.generated.h"



UCLASS()
class TESTTASK2_FNTASTIC_API AMy_BaseTurtle : public ACharacter
{
	GENERATED_BODY()


private:

	bool inMovement;

public:

	AMy_BaseTurtle();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta = (ExposeOnSpawn = true))
		AActor* StartPoint;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Meta = (ExposeOnSpawn = true))
		AActor* EndPoint;
	
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundBase* StartSound_;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundBase* FinishSound_;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Sound")
		UAudioComponent* AudioEngineComp_;
	


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
		void Move();

	UFUNCTION(BlueprintCallable)
		void Start();

	UFUNCTION(BlueprintCallable)
		void Finish();

	UFUNCTION(BlueprintCallable)
		void EngineSound(const bool on_off);

	UFUNCTION(BlueprintPure)
		bool GetInMovement();
	
};
