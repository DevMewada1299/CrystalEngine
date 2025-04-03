#pragma once

namespace CE
{
    CLASS()
    class FUSIONCORE_API FMenuItemSeparator : public FHorizontalStack
    {
        CE_CLASS(FMenuItemSeparator, FHorizontalStack)
    protected:

        FMenuItemSeparator();

        void Construct() override;

    public: // - Public API -

        Ref<FLabel> GetTitleLabel() const { return title; }

    protected: // - Internal -

        Ref<FLabel> title;
        Ref<FStyledWidget> line;

    public: // - Fusion Properties - 

        FUSION_PROPERTY_WRAPPER2(Enabled, title, TitleEnabled);
        FUSION_PROPERTY_WRAPPER2(Text, title, Title);

        FUSION_PROPERTY_WRAPPER2(Background, line, SeparatorColor);
        FUSION_PROPERTY_WRAPPER2(Foreground, title, TitleColor);

        FUSION_WIDGET;
    };
    
}

#include "FMenuItemSeparator.rtti.h"
