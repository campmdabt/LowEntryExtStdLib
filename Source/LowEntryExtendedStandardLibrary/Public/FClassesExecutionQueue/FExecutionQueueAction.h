#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"

#include "LowEntryExecutionQueue.h"


class FExecutionQueueAction : public FPendingLatentAction
{
public:
	ULowEntryExecutionQueue* Queue;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	FExecutionQueueAction(ULowEntryExecutionQueue* Queue0, const FLatentActionInfo& LatentInfo)
		: Queue(Queue0)
		, ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if(Queue->Count > 0)
		{
			if(Queue->Next)
			{
				Queue->Count--;
				Queue->Next = false;
				Response.TriggerLink(ExecutionFunction, OutputLink, CallbackTarget);
			}
		}
		else
		{
			Response.DoneIf(true);
		}
	}

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return FString::Printf(TEXT("Queued (%i executions remaining)"), Queue->Count);
	}
#endif
};