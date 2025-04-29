#pragma once

namespace CE::Editor
{
    CLASS()
    class CRYSTALEDITOR_API MaterialDetailsTab : public EditorMinorDockTab
    {
        CE_CLASS(MaterialDetailsTab, EditorMinorDockTab)
    protected:

        MaterialDetailsTab();

        void Construct() override;

    public: // - Public API -


    protected: // - Internal -

        Ref<FStyledWidget> editorContainer;

    public: // - Fusion Properties - 


        FUSION_WIDGET;
    };
    
}

#include "MaterialDetailsTab.rtti.h"
