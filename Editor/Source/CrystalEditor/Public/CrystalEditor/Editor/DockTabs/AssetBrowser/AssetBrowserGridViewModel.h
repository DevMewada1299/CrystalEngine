#pragma once

namespace CE::Editor
{
    class AssetBrowserItem;

    CLASS()
    class CRYSTALEDITOR_API AssetBrowserGridViewModel : public Object
    {
        CE_CLASS(AssetBrowserGridViewModel, Object)
    protected:

        AssetBrowserGridViewModel();

        void OnBeforeDestroy() override;

    public:

        virtual ~AssetBrowserGridViewModel();

        void Init();

        void SetCurrentDirectory(const Name& path);

        const Name& GetCurrentDirectory() const { return currentPath; }

        void SetData(AssetBrowserItem& item, PathTreeNode* node);

    private:
        Name currentPath;
        //PathTreeNode* currentDirectory = nullptr;

        friend class AssetBrowserTreeView;
    };
    
} // namespace CE

#include "AssetBrowserGridViewModel.rtti.h"
