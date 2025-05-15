#include "CrystalEditor.h"

namespace CE
{
    class CrystalEditorModule : public CE::Module
    {
    public:
        virtual void StartupModule() override
        {
			onClassReg = CoreObjectDelegates::onClassRegistered.AddDelegateInstance(MemberDelegate(&CrystalEditorModule::OnClassRegistered, this));
			onClassDereg = CoreObjectDelegates::onClassDeregistered.AddDelegateInstance(MemberDelegate(&CrystalEditorModule::OnClassDeregistered, this));

        	AssetEditorRegistry::Get()->RegisterEditor(CE::Scene::StaticClass(), SceneEditor::StaticClass());
        	AssetEditorRegistry::Get()->RegisterEditor(CE::Material::StaticClass(), MaterialEditor::StaticClass());
        	AssetEditorRegistry::Get()->RegisterEditor(CE::ProjectSettings::StaticClass(), ProjectSettingsEditor::StaticClass());
        }

        virtual void ShutdownModule() override
        {
        	AssetEditorRegistry::Get()->DeregisterEditor(CE::Scene::StaticClass());
        	AssetEditorRegistry::Get()->DeregisterEditor(CE::Material::StaticClass());
        	AssetEditorRegistry::Get()->DeregisterEditor(CE::ProjectSettings::StaticClass());

			CoreObjectDelegates::onClassRegistered.RemoveDelegateInstance(onClassReg);
			CoreObjectDelegates::onClassDeregistered.RemoveDelegateInstance(onClassDereg);
        }

        virtual void RegisterTypes() override
        {

        }

		void OnClassRegistered(ClassType* classType)
		{
			if (classType == nullptr)
				return;


		}

		void OnClassDeregistered(ClassType* classType)
		{
			if (classType == nullptr)
				return;

		}

		DelegateHandle onClassReg = 0;
		DelegateHandle onClassDereg = 0;
    };
}

#include "CrystalEditor.private.h"

CE_IMPLEMENT_MODULE(CrystalEditor, CE::CrystalEditorModule)
