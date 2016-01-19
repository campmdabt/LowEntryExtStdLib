#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryExecutionQueue.h"


// init >>
	ULowEntryExecutionQueue::ULowEntryExecutionQueue(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryExecutionQueue* ULowEntryExecutionQueue::Create()
	{
		return NewObject<ULowEntryExecutionQueue>();
	}

	ULowEntryExecutionQueue* ULowEntryExecutionQueue::Create(const int32 Count, const bool Next)
	{
		ULowEntryExecutionQueue* Instance = NewObject<ULowEntryExecutionQueue>();
		Instance->Count = Count;
		Instance->Next = Next;
		return Instance;
	}
// init <<
