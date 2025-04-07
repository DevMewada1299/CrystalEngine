#include "EditorEngine.h"

namespace CE::Editor
{
	EditorAssetManager::EditorAssetManager()
	{
		
	}

	EditorAssetManager::~EditorAssetManager()
	{
		
	}

	EditorAssetManager* EditorAssetManager::Get()
	{
		return (EditorAssetManager*)AssetManager::Get();
	}

	void EditorAssetManager::Initialize()
	{
		Super::Initialize();
		
		assetRegistry->listeners.Add(this);
	}

	void EditorAssetManager::Shutdown()
	{
		assetRegistry->listeners.Remove(this);

		Super::Shutdown();
	}

    void EditorAssetManager::Tick(f32 deltaTime)
    {
		Super::Tick(deltaTime);

		if (mainWindow == nullptr)
			mainWindow = PlatformApplication::Get()->GetMainWindow();

		
    }

    void EditorAssetManager::OnDirectoryCreated(const IO::Path& absolutePath)
    {
		assetRegistry->OnDirectoryCreated(absolutePath);
    }

    void EditorAssetManager::OnDirectoryRenamed(const Name& originalPath, const Name& newName)
    {
		assetRegistry->OnDirectoryRenamed(originalPath, newName);
    }

    void EditorAssetManager::OnAssetRenamed(const Name& originalPath, const IO::Path& newAbsolutePath, const Name& newName)
    {
		assetRegistry->OnAssetRenamed(originalPath, newAbsolutePath, newName);
    }

    void EditorAssetManager::OnDirectoryAndAssetsDeleted(const Array<Name>& paths)
    {
		assetRegistry->OnDirectoryAndAssetsDeleted(paths);
    }
} // namespace CE::Editor
