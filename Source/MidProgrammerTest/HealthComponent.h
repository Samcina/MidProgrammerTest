// All Rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MIDPROGRAMMERTEST_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Getters and setters
	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetCurrentHealth() const;
	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetMaxHealth() const;
	void TakeDamage(float damage);

private:
	float MaxHealth;
	float CurrentHealth;

public:
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
};
