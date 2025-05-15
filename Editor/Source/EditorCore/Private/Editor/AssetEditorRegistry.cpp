#include "EditorCore.h"

namespace CE
{
    static WeakRef<AssetEditorRegistry> instance;

    AssetEditorRegistry::AssetEditorRegistry()
    {

    }

    AssetEditorRegistry::~AssetEditorRegistry()
    {

    }

    void AssetEditorRegistry::OnAfterConstruct()
    {
        Super::OnAfterConstruct();

        if (!IsDefaultInstance())
        {
            instance = this;
        }
    }

    Ref<AssetEditorRegistry> AssetEditorRegistry::Get()
    {
        return instance.Lock();
    }

    void AssetEditorRegistry::RegisterEditor(ClassType* targetObjectType, SubClass<EditorBase> editorClass)
    {
        if (targetObjectType == nullptr || editorClass == nullptr)
            return;

        editorClassesByTargetObjectTypeId[targetObjectType->GetTypeId()] = editorClass;
    }

    void AssetEditorRegistry::DeregisterEditor(ClassType* targetObjectType)
    {
        if (targetObjectType == nullptr)
            return;

        editorClassesByTargetObjectTypeId.Remove(targetObjectType->GetTypeId());
    }

    SubClass<EditorBase> AssetEditorRegistry::GetEditorClass(ClassType* targetObjectType)
    {
        ClassType* clazz = targetObjectType;

        while (clazz != nullptr && clazz->GetTypeId() != TYPEID(Object))
        {
            if (editorClassesByTargetObjectTypeId.KeyExists(clazz->GetTypeId()))
            {
                return editorClassesByTargetObjectTypeId[clazz->GetTypeId()];
            }

            clazz = clazz->GetSuperClass(0);
        }

        return nullptr;
    }
} // namespace CE

