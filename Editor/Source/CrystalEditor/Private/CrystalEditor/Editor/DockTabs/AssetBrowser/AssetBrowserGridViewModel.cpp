#include "CrystalEditor.h"

namespace CE::Editor
{

    AssetBrowserGridViewModel::AssetBrowserGridViewModel()
    {

    }

    AssetBrowserGridViewModel::~AssetBrowserGridViewModel()
    {
        
    }


    void AssetBrowserGridViewModel::Init()
    {
        AssetManager* assetManager = AssetManager::Get();
        if (!assetManager)
            return;

        AssetRegistry* registry = assetManager->GetRegistry();
        if (!registry)
            return;

    }

    void AssetBrowserGridViewModel::OnBeforeDestroy()
    {
        Super::OnBeforeDestroy();

        AssetRegistry* registry = AssetManager::GetRegistry();
        if (!registry)
            return;

        
    }

    void AssetBrowserGridViewModel::SetCurrentDirectory(const Name& path)
    {
        currentPath = path;

        AssetRegistry* registry = AssetManager::GetRegistry();
        if (!registry)
            return;

        //currentDirectory = registry->GetCachedPathTree().GetNode(currentPath);
    }

    void AssetBrowserGridViewModel::SetData(AssetBrowserItem& item, PathTreeNode* node)
    {
        if (!node)
            return;

        item.SetData(node);
    }


} // namespace CE

