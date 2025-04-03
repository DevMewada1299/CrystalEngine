#include "FusionCore.h"

namespace CE
{
	FMenuBarStyle::FMenuBarStyle()
	{
        padding = Vec4();
        itemPadding = Vec4();
        itemFontSize = 10;
	}

	SubClass<FWidget> FMenuBarStyle::GetWidgetClass() const
	{
        return FMenuBar::StaticType();
	}

	void FMenuBarStyle::MakeStyle(FWidget& widget)
	{
        FMenuBar& menuBar = widget.As<FMenuBar>();

        menuBar
            .Background(background)
            .Border(borderColor, borderWidth)
            .BackgroundShape(FRectangle())
            .Padding(padding)
            ;

        for (int i = 0; i < menuBar.GetContainerChildCount(); ++i)
        {
            Ref<FWidget> child = menuBar.GetContainerChild(i);

            if (child->IsOfType<FMenuItem>())
            {
                FMenuItem& item = static_cast<FMenuItem&>(*child);

                FBrush itemBg = item.IsHovered() ? itemHoverBackground : itemBackground;
                if (item.GetSubMenu() != nullptr &&
                    item.GetSubMenu()->IsShown())
                {
                    itemBg = itemActiveBackground;
                }

                Color borderColor = item.IsHovered() ? this->itemBorderColor : this->itemHoverBorderColor;

                item
                    .FontSize(itemFontSize)
                    .Background(itemBg)
                    .Border(borderColor, itemBorderWidth)
                    .BackgroundShape(FRectangle())
                    .Padding(itemPadding)
                    ;
            }
        }
	}

    FMenuPopupStyle::FMenuPopupStyle()
    {
        padding = Vec4();
        itemPadding = Vec4();
    }

    SubClass<FWidget> FMenuPopupStyle::GetWidgetClass() const
    {
        return FMenuPopup::StaticType();
    }

    void FMenuPopupStyle::MakeStyle(FWidget& widget)
    {
        FMenuPopup& menu = widget.As<FMenuPopup>();

        menu
            .Background(background)
			.Border(borderColor, borderWidth)
			.BackgroundShape(FRectangle())
			.Padding(padding)
            ;

        for (int i = 0; i < menu.GetContainerChildCount(); ++i)
        {
            Ref<FWidget> child = menu.GetContainerChild(i);

            if (child->IsOfType<FMenuItem>())
            {
                FMenuItem& item = static_cast<FMenuItem&>(*child);

                FBrush itemBg = item.IsHovered() ? itemHoverBackground : itemBackground;

                Color borderColor = item.IsHovered() ? this->itemBorderColor : this->itemHoverBorderColor;

                item
                    .Background(itemBg)
                    .Border(borderColor, itemBorderWidth)
                    .BackgroundShape(FRectangle())
                    .Padding(itemPadding)
                    ;
            }
            else if (child->IsOfType<FMenuItemSeparator>())
            {
                FMenuItemSeparator& separator = static_cast<FMenuItemSeparator&>(*child);

                separator
                    .TitleColor(separatorTitleColor)
					.SeparatorColor(separatorColor)
                    ;
            }
        }
    }
    
} // namespace CE

