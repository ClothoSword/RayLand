// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Subsystems/WorldSubsystem.h"
#include "RayLandSubsystem.generated.h"

class URayLandComponent;

UCLASS(MinimalAPI)
class URayLandSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	URayLandSubsystem();
	virtual ~URayLandSubsystem();

	void RegisterComponent(URayLandComponent* InRayLandComponent);
	void UnregisterComponent(URayLandComponent* InRayLandComponent);

	// Begin FTickableGameObject overrides
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickableInEditor() const override { return true; }
	virtual ETickableTickType GetTickableTickType() const override;
	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;
	virtual TStatId GetStatId() const override;
	// End FTickableGameObject overrides

//	void PrioritizeGrassCreation(bool bPrioritizeGrassCreation) { bIsGrassCreationPrioritized = bPrioritizeGrassCreation; }
//	bool IsGrassCreationPrioritized() const { return bIsGrassCreationPrioritized; }
//
//#if WITH_EDITOR
//	LANDSCAPE_API void BuildAll();
//	LANDSCAPE_API void BuildGrassMaps();
//	LANDSCAPE_API int32 GetOutdatedGrassMapCount();
//	LANDSCAPE_API void BuildGIBakedTextures();
//	LANDSCAPE_API int32 GetOutdatedGIBakedTextureComponentsCount();
//	LANDSCAPE_API void BuildPhysicalMaterial();
//	LANDSCAPE_API int32 GetOudatedPhysicalMaterialComponentsCount();
//	LANDSCAPE_API void BuildNanite();
//	LANDSCAPE_API bool IsGridBased() const;
//	LANDSCAPE_API void ChangeGridSize(ULandscapeInfo* LandscapeInfo, uint32 NewGridSizeInComponents);
//	LANDSCAPE_API ALandscapeProxy* FindOrAddLandscapeProxy(ULandscapeInfo* LandscapeInfo, const FIntPoint& SectionBase);
//	LANDSCAPE_API void DisplayMessages(class FCanvas* Canvas, float& XPos, float& YPos);
//	LANDSCAPE_API void MarkModifiedLandscapesAsDirty();
//	LANDSCAPE_API void SaveModifiedLandscapes();
//	LANDSCAPE_API bool HasModifiedLandscapes() const;
//	LANDSCAPE_API static bool IsDirtyOnlyInModeEnabled();
//	FLandscapeNotificationManager* GetNotificationManager() { return NotificationManager; }
//	FOnHeightmapStreamedDelegate& GetOnHeightmapStreamedDelegate() { return OnHeightmapStreamed; }
//#endif // WITH_EDITOR
//
//private:
//#if WITH_EDITOR
//	LANDSCAPE_API void ForEachLandscapeInfo(TFunctionRef<bool(ULandscapeInfo*)> ForEachLandscapeInfoFunc) const;
//#endif

	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem

	TArray<TWeakObjectPtr<URayLandComponent>> RayLandComponents;
};
