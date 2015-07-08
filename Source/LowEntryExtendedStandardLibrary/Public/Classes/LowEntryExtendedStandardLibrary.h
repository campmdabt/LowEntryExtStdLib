#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "Base64.h"
#include "DelayAction.h"
#include "Engine/LatentActionManager.h"

#include "LowEntryExtendedStandardLibrary.generated.h"


UCLASS()
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryExtendedStandardLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()



public:
	static void KismetSystemLibraryPrintString(UObject* WorldContextObject, const FString& InString, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor);



public:
	/**
	* Returns true if this is a debug build (UE_BUILD_DEBUG), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Debug Build", Keywords = "compile export mode version type"))
		static bool DebugBuild();

	/**
	* Returns true if this is a debug build (UE_BUILD_DEVELOPMENT), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Development Build", Keywords = "compile export mode version type"))
		static bool DevelopmentBuild();

	/**
	* Returns true if this is a debug build (UE_BUILD_TEST), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Test Build", Keywords = "compile export mode version type"))
		static bool TestBuild();

	/**
	* Returns true if this is a debug build (UE_BUILD_SHIPPING), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Shipping Build", Keywords = "compile export mode version type"))
		static bool ShippingBuild();



	/**
	* Converts a String into a Byte Array (using UTF-8 encoding).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "String To Bytes (Utf 8)", Keywords = "byte array string utf-8"))
		static TArray<uint8> StringToBytesUtf8(const FString& String);

	/**
	* Tries to convert a Byte Array into a String (using UTF-8 encoding). Will return an empty String on failure.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To String (Utf 8)", Keywords = "byte array string utf-8"))
		static FString BytesToStringUtf8(const TArray<uint8>& ByteArray);


	/**
	* Tries to convert a Hexadecimal (Base16) String into a Byte Array. Will return an empty Array on failure.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Hex To Bytes", Keywords = "byte array hex hexadecimal base16"))
		static TArray<uint8> HexToBytes(const FString& String);

	/**
	* Converts a Byte Array into a Hexadecimal (Base16) String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Hex", Keywords = "byte array hex hexadecimal base16"))
		static FString BytesToHex(const TArray<uint8>& ByteArray);


	/**
	* Tries to convert a Base64 String into a Byte Array. Will return an empty Array on failure.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Base64 To Bytes", Keywords = "byte array base64"))
		static TArray<uint8> Base64ToBytes(const FString& Base64);

	/**
	* Converts a Byte Array into a Base64 String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Base64", Keywords = "byte array base64"))
		static FString BytesToBase64(const TArray<uint8>& ByteArray);
		
		
		
	/**
	* Generates a MD5 hash, always returns 16 bytes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Md5)"))
		static TArray<uint8> Md5(const TArray<uint8>& ByteArray);
	
	/**
	* Generates a SHA1 hash, always returns 20 bytes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Sha1)"))
		static TArray<uint8> Sha1(const TArray<uint8>& ByteArray);
	
	
	
	/**
	* Returns a newline character (\n).
	* 
	* This blueprint will always return a \n character, no matter what Operating System it is running on.
	* 
	* Note: It is actually called a line feed, the blueprint is called Newline Character for recognition purposes.
	* On *nix systems \n is used as a newline character, on Windows \r\n is used as a newline character.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (DisplayName = "Newline Character (\\n)", CompactNodeTitle = "\\n"))
		static FString NewlineCharacter();

	/**
	* Returns a Windows newline character (\r\n).
	* 
	* This blueprint will always return a \r\n character, no matter what Operating System it is running on.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (DisplayName = "Windows Newline Character (\\r\\n)", CompactNodeTitle = "\\r\\n"))
		static FString WindowsNewlineCharacter();

	/**
	* Returns a carriage return (\r).
	* 
	* This blueprint will always return a \r character, no matter what Operating System it is running on.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (DisplayName = "Carriage Return Character (\\r)", CompactNodeTitle = "\\r"))
		static FString CarriageReturnCharacter();

	/**
	* Returns a tab character (\t).
	* 
	* This blueprint will always return a \t character, no matter what Operating System it is running on.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (DisplayName = "Tab Character (\\t)", CompactNodeTitle = "\\t"))
		static FString TabCharacter();



	/**
	* Returns the minimum value of the given values.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Min (String)", CompactNodeTitle = "MIN", CommutativeAssociativeBinaryOperator = "true"))
		static FString MinString(const FString& A, const FString& B);

	/**
	* Returns the maximum value of the given values.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Max (String)", CompactNodeTitle = "MAX", CommutativeAssociativeBinaryOperator = "true"))
		static FString MaxString(const FString& A, const FString& B);

	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "String < String", CompactNodeTitle = "<"))
		static bool LessStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "String > String", CompactNodeTitle = ">"))
		static bool GreaterStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "String <= String", CompactNodeTitle = "<="))
		static bool LessEqualStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "String >= String", CompactNodeTitle = ">="))
		static bool GreaterEqualStringString(const FString& A, const FString& B);



	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer < Float", CompactNodeTitle = "<"))
		static bool LessIntegerFloat(const int32 A, const float B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer > Float", CompactNodeTitle = ">"))
		static bool GreaterIntegerFloat(const int32 A, const float B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer <= Float", CompactNodeTitle = "<="))
		static bool LessEqualIntegerFloat(const int32 A, const float B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer >= Float", CompactNodeTitle = ">="))
		static bool GreaterEqualIntegerFloat(const int32 A, const float B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer < Byte", CompactNodeTitle = "<"))
		static bool LessIntegerByte(const int32 A, const uint8 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer > Byte", CompactNodeTitle = ">"))
		static bool GreaterIntegerByte(const int32 A, const uint8 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer <= Byte", CompactNodeTitle = "<="))
		static bool LessEqualIntegerByte(const int32 A, const uint8 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer >= Byte", CompactNodeTitle = ">="))
		static bool GreaterEqualIntegerByte(const int32 A, const uint8 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float < Integer", CompactNodeTitle = "<"))
		static bool LessFloatInteger(const float A, const int32 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float > Integer", CompactNodeTitle = ">"))
		static bool GreaterFloatInteger(const float A, const int32 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float <= Integer", CompactNodeTitle = "<="))
		static bool LessEqualFloatInteger(const float A, const int32 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float >= Integer", CompactNodeTitle = ">="))
		static bool GreaterEqualFloatInteger(const float A, const int32 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float < Byte", CompactNodeTitle = "<"))
		static bool LessFloatByte(const float A, const uint8 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float > Byte", CompactNodeTitle = ">"))
		static bool GreaterFloatByte(const float A, const uint8 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float <= Byte", CompactNodeTitle = "<="))
		static bool LessEqualFloatByte(const float A, const uint8 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float >= Byte", CompactNodeTitle = ">="))
		static bool GreaterEqualFloatByte(const float A, const uint8 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte < Integer", CompactNodeTitle = "<"))
		static bool LessByteInteger(const uint8 A, const int32 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte > Integer", CompactNodeTitle = ">"))
		static bool GreaterByteInteger(const uint8 A, const int32 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte <= Integer", CompactNodeTitle = "<="))
		static bool LessEqualByteInteger(const uint8 A, const int32 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte >= Integer", CompactNodeTitle = ">="))
		static bool GreaterEqualByteInteger(const uint8 A, const int32 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte < Float", CompactNodeTitle = "<"))
		static bool LessByteFloat(const uint8 A, const float B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte > Float", CompactNodeTitle = ">"))
		static bool GreaterByteFloat(const uint8 A, const float B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte <= Float", CompactNodeTitle = "<="))
		static bool LessEqualByteFloat(const uint8 A, const float B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte >= Float", CompactNodeTitle = ">="))
		static bool GreaterEqualByteFloat(const uint8 A, const float B);



	/**
	* Rounds to the given Decimals.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (DisplayName = "Round (With Decimals)"))
		static float RoundDecimals(float Number, int32 Decimals);

	/**
	* Ceil to the given Decimals.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (DisplayName = "Ceil (With Decimals)"))
		static float CeilDecimals(float Number, int32 Decimals);

	/**
	* Floor to the given Decimals.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (DisplayName = "Floor (With Decimals)"))
		static float FloorDecimals(float Number, int32 Decimals);



	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MaxOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMaxValue, FString& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MinOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMinValue, FString& MinValue);

	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MaxOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMaxValue, FDateTime& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MinOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMinValue, FDateTime& MinValue);

	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MaxOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMaxValue, FTimespan& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MinOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMinValue, FTimespan& MinValue);



	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (String Array)"))
		static TArray<FString> SortStringArray(const TArray<FString>& StringArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Integer Array)"))
		static TArray<int32> SortIntegerArray(const TArray<int32>& IntegerArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Float Array)"))
		static TArray<float> SortFloatArray(const TArray<float>& FloatArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Byte Array)"))
		static TArray<uint8> SortByteArray(const TArray<uint8>& ByteArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (DateTime Array)"))
		static TArray<FDateTime> SortDateTimeArray(const TArray<FDateTime>& DateTimeArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Timespan Array)"))
		static TArray<FTimespan> SortTimespanArray(const TArray<FTimespan>& TimespanArray, const bool Reversed = false);



	/**
	* Perform a latent action with a random delay (specified in seconds).  Calling again while it is counting down will be ignored.
	*
	* @param WorldContext	World context.
	* @param MinDuration 	minimum length of delay (in seconds).
	* @param MaxDuration 	maximum length of delay (in seconds).
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Flow Control", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void	RandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, struct FLatentActionInfo LatentInfo);

	/**
	* Perform a latent action with a retriggerable random delay (specified in seconds).  Calling again while it is counting down will reset the countdown to a new random Duration.
	*
	* @param WorldContext	World context.
	* @param MinDuration 	minimum length of delay (in seconds).
	* @param MaxDuration 	maximum length of delay (in seconds).
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Flow Control", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void RetriggerableRandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, FLatentActionInfo LatentInfo);



	/**
	* Creates a String of the given length.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Create String"))
		static FString CreateString(const int32 Length, const FString& Filler = TEXT(" "));



	/**
	* Removes all characters except the characters chosen to keep.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Remove Characters"))
		static FString RemoveCharactersExcept(const FString& String, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep);

	/**
	* Replaces all characters with the given replacement character except the characters chosen to keep.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Replace Characters"))
		static FString ReplaceCharactersExcept(const FString& String, const FString& ReplacementCharacter, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep);



	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Float"))
		static float LocalFloat(float Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Integer"))
		static int32 LocalInteger(int32 Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Byte"))
		static uint8 LocalByte(uint8 Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Boolean"))
		static bool LocalBoolean(bool Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local String"))
		static FString LocalString(const FString& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Name"))
		static FName LocalName(const FName& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Text"))
		static FText LocalText(const FText& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Vector"))
		static FVector LocalVector(const FVector& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Rotator"))
		static FRotator LocalRotator(const FRotator& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Date Time"))
		static FDateTime LocalDateTime(const FDateTime& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Timespan"))
		static FTimespan LocalTimespan(const FTimespan& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Class"))
		static UClass* LocalClass(UClass* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Object"))
		static UObject* LocalObject(UObject* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Actor"))
		static AActor* LocalActor(AActor* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Actor Component"))
		static UActorComponent* LocalActorComponent(UActorComponent* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Pawn"))
		static APawn* LocalPawn(APawn* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Enum"))
		static UEnum* LocalEnum(UEnum* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Struct"))
		static UStruct* LocalStruct(UStruct* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Interface"))
		static TScriptInterface<IInterface> LocalInterface(TScriptInterface<IInterface> Value);



	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Float Array"))
		static TArray<float> LocalFloatArray(const TArray<float>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Integer Array"))
		static TArray<int32> LocalIntegerArray(const TArray<int32>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Byte Array"))
		static TArray<uint8> LocalByteArray(const TArray<uint8>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Boolean Array"))
		static TArray<bool> LocalBooleanArray(const TArray<bool>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local String Array"))
		static TArray<FString> LocalStringArray(const TArray<FString>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Name Array"))
		static TArray<FName> LocalNameArray(const TArray<FName>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Text Array"))
		static TArray<FText> LocalTextArray(const TArray<FText>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Vector Array"))
		static TArray<FVector> LocalVectorArray(const TArray<FVector>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Rotator Array"))
		static TArray<FRotator> LocalRotatorArray(const TArray<FRotator>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Date Time Array"))
		static TArray<FDateTime> LocalDateTimeArray(const TArray<FDateTime>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Timespan Array"))
		static TArray<FTimespan> LocalTimespanArray(const TArray<FTimespan>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Class Array"))
		static TArray<TSubclassOf<UObject>> LocalClassArray(const TArray<TSubclassOf<UObject>>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Object Array"))
		static TArray<UObject*> LocalObjectArray(const TArray<UObject*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Actor Array"))
		static TArray<AActor*> LocalActorArray(const TArray<AActor*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Actor Component Array"))
		static TArray<UActorComponent*> LocalActorComponentArray(const TArray<UActorComponent*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Pawn Array"))
		static TArray<APawn*> LocalPawnArray(const TArray<APawn*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Enum Array"))
		static TArray<UEnum*> LocalEnumArray(const TArray<UEnum*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Struct Array"))
		static TArray<UStruct*> LocalStructArray(const TArray<UStruct*>& Value);



	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Float)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static float PurePrintFloat(UObject* WorldContextObject, float Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Integer)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static int32 PurePrintInteger(UObject* WorldContextObject, int32 Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Byte)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static uint8 PurePrintByte(UObject* WorldContextObject, uint8 Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Boolean)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static bool PurePrintBoolean(UObject* WorldContextObject, bool Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (String)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static FString PurePrintString(UObject* WorldContextObject, const FString& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Name)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static FName PurePrintName(UObject* WorldContextObject, const FName& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Text)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static FText PurePrintText(UObject* WorldContextObject, const FText& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Vector)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static FVector PurePrintVector(UObject* WorldContextObject, const FVector& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Rotator)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static FRotator PurePrintRotator(UObject* WorldContextObject, const FRotator& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Date Time)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static FDateTime PurePrintDateTime(UObject* WorldContextObject, const FDateTime& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Timespan)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static FTimespan PurePrintTimespan(UObject* WorldContextObject, const FTimespan& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Class)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static UClass* PurePrintClass(UObject* WorldContextObject, UClass* Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Object)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static UObject* PurePrintObject(UObject* WorldContextObject, UObject* Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Actor)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static AActor* PurePrintActor(UObject* WorldContextObject, AActor* Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Actor Component)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static UActorComponent* PurePrintActorComponent(UObject* WorldContextObject, UActorComponent* Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Pawn)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static APawn* PurePrintPawn(UObject* WorldContextObject, APawn* Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Enum)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static UEnum* PurePrintEnum(UObject* WorldContextObject, UEnum* Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Struct)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static UStruct* PurePrintStruct(UObject* WorldContextObject, UStruct* Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Interface)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TScriptInterface<IInterface> PurePrintInterface(UObject* WorldContextObject, TScriptInterface<IInterface> Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));



	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Float Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<float> PurePrintFloatArray(UObject* WorldContextObject, const TArray<float>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Integer Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<int32> PurePrintIntegerArray(UObject* WorldContextObject, const TArray<int32>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Byte Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<uint8> PurePrintByteArray(UObject* WorldContextObject, const TArray<uint8>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Boolean Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<bool> PurePrintBooleanArray(UObject* WorldContextObject, const TArray<bool>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (String Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<FString> PurePrintStringArray(UObject* WorldContextObject, const TArray<FString>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Name Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<FName> PurePrintNameArray(UObject* WorldContextObject, const TArray<FName>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Text Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<FText> PurePrintTextArray(UObject* WorldContextObject, const TArray<FText>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Vector Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<FVector> PurePrintVectorArray(UObject* WorldContextObject, const TArray<FVector>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Rotator Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<FRotator> PurePrintRotatorArray(UObject* WorldContextObject, const TArray<FRotator>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Date Time Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<FDateTime> PurePrintDateTimeArray(UObject* WorldContextObject, const TArray<FDateTime>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Timespan Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<FTimespan> PurePrintTimespanArray(UObject* WorldContextObject, const TArray<FTimespan>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Class Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<TSubclassOf<UObject>> PurePrintClassArray(UObject* WorldContextObject, const TArray<TSubclassOf<UObject>>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Object Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<UObject*> PurePrintObjectArray(UObject* WorldContextObject, const TArray<UObject*>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Actor Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<AActor*> PurePrintActorArray(UObject* WorldContextObject, const TArray<AActor*>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Actor Component Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<UActorComponent*> PurePrintActorComponentArray(UObject* WorldContextObject, const TArray<UActorComponent*>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Pawn Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<APawn*> PurePrintPawnArray(UObject* WorldContextObject, const TArray<APawn*>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Enum Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<UEnum*> PurePrintEnumArray(UObject* WorldContextObject, const TArray<UEnum*>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));

	/**
	* Passes the parameter and prints a message, this can be really useful if you want to print a message whenever a Pure blueprint is called.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Pure Print", Meta = (DisplayName = "Pure Print (Struct Array)", WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "3"))
		static TArray<UStruct*> PurePrintStructArray(UObject* WorldContextObject, const TArray<UStruct*>& Value, const FString& Message, const float ScreenDurationTime = 5.0f, const bool bPrintToScreen = true, const bool bPrintToLog = true, const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0));



	/**
	* Causes a crash.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (CompactNodeTitle = "- CRASH -", DisplayName = "Crash"))
		static void Crash();



	/**
	* Hosts a game.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Game", meta = (WorldContext = "WorldContextObject", DisplayName = "Host Game"))
		static void HostGame(UObject* WorldContextObject, const FString& Map, const FString& Args, class APlayerController* SpecificPlayer = NULL);

	/**
	* Joins a game.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Game", meta = (WorldContext = "WorldContextObject", DisplayName = "Join Game"))
		static void JoinGame(UObject* WorldContextObject, const FString& ServerAddress, const FString& Args, class APlayerController* SpecificPlayer = NULL);

	/**
	* Changes the map of the server, and with that, everyone that is playing on the server. 
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Game", meta = (WorldContext = "WorldContextObject", DisplayName = "Change Map (Server)"))
		static void ServerChangeMap(UObject* WorldContextObject, const FString& Map, const FString& Args, class APlayerController* SpecificPlayer = NULL);

	/**
	* Changes the map.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Game", meta = (WorldContext = "WorldContextObject", DisplayName = "Change Map"))
		static void ChangeMap(UObject* WorldContextObject, const FString& Map, const FString& Args, class APlayerController* SpecificPlayer = NULL);
};
