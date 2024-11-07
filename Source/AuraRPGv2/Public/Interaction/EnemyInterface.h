// Copyright Awie

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};


class AURARPGV2_API IEnemyInterface
{
	GENERATED_BODY()

	
public:
	//if there is =0 it means this function became ABSTRACT. if not you need to create the definition to work
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
