#pragma once

namespace CE
{
    CLASS()
    class EDITORCORE_API AssetEditorRegistry : public Object
    {
        CE_CLASS(AssetEditorRegistry, Object)
    protected:

        AssetEditorRegistry();

        virtual ~AssetEditorRegistry();

        void OnAfterConstruct() override;
        
    public:

        static Ref<AssetEditorRegistry> Get();

        void RegisterEditor(ClassType* targetObjectType, SubClass<EditorBase> editorClass);
        void DeregisterEditor(ClassType* targetObjectType);

        SubClass<EditorBase> GetEditorClass(ClassType* targetObjectType);

    private:

        HashMap<TypeId, SubClass<EditorBase>> editorClassesByTargetObjectTypeId;
    };
    
} // namespace CE

#include "AssetEditorRegistry.rtti.h"
