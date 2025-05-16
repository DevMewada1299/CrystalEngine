#pragma once

namespace CE::Editor
{
    CLASS(Abstract)
    class EDITORCORE_API EditorBase : public EditorDockTab
    {
        CE_CLASS(EditorBase, EditorDockTab)
    protected:

        EditorBase();

        void Construct() override;

        void HandleEvent(FEvent* event) override;

    public: // - Public API -

        const Ref<EditorHistory>& GetHistory() const { return history; }

        bool SupportsKeyboardEvents() const override { return true; }

        virtual bool OpenEditor(Ref<Object> targetObject) { return false; }

        virtual bool CanEdit(Ref<Object> targetObject) const { return false; }

        virtual ClassType* GetTargetObjectType() const = 0;

        virtual bool AllowMultipleInstances() const { return true; }

        virtual Ref<Object> GetTargetObject() const { return nullptr; }

        void SetAssetDirty(bool dirty);

    protected: // - Internal -

        Ref<EditorHistory> history = nullptr;

        bool isAssetDirty = false;

    public: // - Fusion Properties - 

        FUSION_WIDGET;
    };
    
}

#include "EditorBase.rtti.h"
