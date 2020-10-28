#include <dali-toolkit/dali-toolkit.h>
#include <dali-toolkit/devel-api/controls/text-controls/text-field-devel.h>
#include <dali-toolkit/devel-api/controls/text-controls/text-editor-devel.h>

using namespace Dali;
using namespace Dali::Toolkit;

class SimpleApp : public ConnectionTracker
{
public:
  SimpleApp(Application& application)
  : mApplication(application)
  {
    mApplication.InitSignal().Connect(this, &SimpleApp::Create);
  }

  void Create(Application& application)
  {
    Window window = application.GetWindow();
    window.SetBackgroundColor(Vector4(0.04f, 0.345f, 0.392f, 1.0f));

    mEditor = TextEditor::New();
    mEditor.SetProperty(Actor::Property::PARENT_ORIGIN, ParentOrigin::TOP_CENTER);
    mEditor.SetProperty(Actor::Property::ANCHOR_POINT, AnchorPoint::TOP_CENTER);
    mEditor.SetProperty(Actor::Property::POSITION, Vector3(0.f, 0.0f, 0.f));
    mEditor.SetProperty(Actor::Property::SIZE, Vector2(100.f, 100.0f));
    mEditor.SetProperty(TextEditor::Property::TEXT, "Hello\nHello\nHello\nHello\nHello\nHello");

    mButton = PushButton::New();
    mButton.SetProperty(Actor::Property::PARENT_ORIGIN, ParentOrigin::CENTER);
    mButton.SetProperty(Actor::Property::ANCHOR_POINT, AnchorPoint::CENTER);
    mButton.SetProperty(Actor::Property::SIZE, Vector2(50.f, 50.0f));
    mButton.SetProperty(Actor::Property::POSITION, Vector3(0.f, 0.0f, 0.f));
    mButton.SetProperty(Button::Property::LABEL, "click");
    mButton.ClickedSignal().Connect(this, &SimpleApp::OnButtonClicked);

    window.Add(mButton);
    window.Add(mEditor);
  }

  bool OnButtonClicked(Button button)
  {
    if(button == mButton)
    {
    }
    return true;
  }

private:
  Application& mApplication;
  TextEditor mEditor;
  PushButton mButton;
};

int DALI_EXPORT_API main(int argc, char** argv)
{
  Application application = Application::New(&argc, &argv);
  SimpleApp test(application);
  application.MainLoop();

  return 0;
}

