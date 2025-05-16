#include "EditorCore.h"

namespace CE::Editor
{

    EditorToolBar::EditorToolBar()
    {
        m_MinHeight = 50;
    }

    void EditorToolBar::Construct()
    {
        Super::Construct();

        Child(
            FAssignNew(FStackBox, contentBox)
            .Direction(FStackBoxDirection::Horizontal)
            .VAlign(VAlign::Fill)
            .HAlign(HAlign::Left)
            .Padding(Vec4(1, 1, 1, 1) * 5)
        );
    }

    FImageButton& EditorToolBar::NewImageButton(const CE::Name& imagePath)
    {
        return
        FNewOwned(FImageButton, GetTransient(MODULE_NAME))
        .Image(FBrush(imagePath))
        .Width(24)
        .Height(24)
        .Style("Button.Icon")
        .Padding(Vec4(1, 1, 1, 1) * 8)
        .As<FImageButton>();
    }
    
}

