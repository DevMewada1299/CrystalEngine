#include "FusionCore.h"

namespace CE
{

    FMenuItemSeparator::FMenuItemSeparator()
    {

    }

    void FMenuItemSeparator::Construct()
    {
        Super::Construct();

        (*this)
        .Gap(2.5f)
        .ContentHAlign(HAlign::Left)
        .ContentVAlign(VAlign::Center)
        .Padding(Vec4(10, 5, 10, 5))
        (
            FAssignNew(FLabel, title)
            .Text("")
            .FontSize(8)
            .Margin(Vec4(0, 0, 10, 0)),

            FAssignNew(FStyledWidget, line)
            .Height(1.0f)
            .FillRatio(1.0f)
        );
    }
    
}

