#include "CrystalEditor.h"

namespace CE::Editor
{

    MaterialDetailsTab::MaterialDetailsTab()
    {

    }

    void MaterialDetailsTab::Construct()
    {
        Super::Construct();

        (*this)
		.Title("Details")
		.Content(
		    FNew(FScrollBox)
            .VerticalScroll(true)
            .HorizontalScroll(false)
            .HAlign(HAlign::Fill)
            .FillRatio(0.7f)
            .Margin(Vec4(0, 0, 0, 0))
            (
                FAssignNew(FStyledWidget, editorContainer)
                .HAlign(HAlign::Fill)
                .VAlign(VAlign::Top)
            )
        )
		.Style("EditorMinorDockTab")
        ;
    }
    
}

