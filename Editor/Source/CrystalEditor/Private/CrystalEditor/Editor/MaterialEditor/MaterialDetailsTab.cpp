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

    void MaterialDetailsTab::SetupEditor(Ref<CE::Material> material)
    {
        editorContainer->RemoveChildWidget();

        if (editor.IsValid())
        {
            editor->BeginDestroy();
            editor = nullptr;
        }

        if (material)
        {
            auto ownerEditor = GetOwnerEditor();
            editor = ObjectEditorRegistry::Get().Create(material.Get(), ownerEditor->GetHistory());

            editorContainer->AddChild(editor.Get());
        }
    }
}

