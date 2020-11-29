#include <dali-toolkit/dali-toolkit.h>
#include <dali-toolkit/devel-api/controls/text-controls/text-field-devel.h>
#include <dali-toolkit/devel-api/controls/text-controls/text-editor-devel.h>
#include <dali/integration-api/events/touch-event-integ.h>
#include <dali/integration-api/events/wheel-event-integ.h>

using namespace Dali;
using namespace Dali::Toolkit;

int textIndex = 4;
float size = 80.0f;
const char * text[] = {
  "example",
  "application",
  "the example",
  "H World World World",
  "   eexample",
  "   eexample",
};

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
    //window.SetBackgroundColor(Vector4(0.04f, 0.345f, 0.392f, 1.0f));

    mEditor = TextEditor::New();
    mEditor.SetProperty(Actor::Property::PARENT_ORIGIN, ParentOrigin::TOP_CENTER);
    mEditor.SetProperty(Actor::Property::ANCHOR_POINT, AnchorPoint::TOP_CENTER);
    mEditor.SetProperty(Actor::Property::POSITION, Vector3(0.f, 0.0f, 0.f));
    mEditor.SetProperty(Actor::Property::SIZE, Vector2(size, 300.0f));
    mEditor.SetProperty( TextEditor::Property::POINT_SIZE, 20) ;
    mEditor.SetBackgroundColor(Vector4(0.04f, 0.345f, 0.392f, 1.0f));
    mEditor.SetProperty(TextEditor::Property::TEXT, text[textIndex++]);
    mEditor.SetProperty( TextEditor::Property::LINE_WRAP_MODE, Text::LineWrap::HYPHENATION );

    mButton = PushButton::New();
    mButton.SetProperty(Actor::Property::PARENT_ORIGIN, ParentOrigin::CENTER);
    mButton.SetProperty(Actor::Property::ANCHOR_POINT, AnchorPoint::CENTER);
    mButton.SetProperty(Actor::Property::SIZE, Vector2(150.f, 50.0f));
    mButton.SetProperty(Actor::Property::POSITION, Vector3(0.f, 0.0f, 0.f));
    mButton.SetProperty(Button::Property::LABEL, "change");
    mButton.SetBackgroundColor(Vector4(0.5f, 0.5f, 0.5f, 1.0f));
    mButton.ClickedSignal().Connect(this, &SimpleApp::OnButtonClicked);

    mButtonInc = PushButton::New();
    mButtonInc.SetProperty(Actor::Property::PARENT_ORIGIN, ParentOrigin::CENTER);
    mButtonInc.SetProperty(Actor::Property::ANCHOR_POINT, AnchorPoint::CENTER);
    mButtonInc.SetProperty(Actor::Property::SIZE, Vector2(150.f, 50.0f));
    mButtonInc.SetProperty(Actor::Property::POSITION, Vector3(0.f, 50.0f, 0.f));
    mButtonInc.SetProperty(Button::Property::LABEL, "Inc");
    mButtonInc.SetBackgroundColor(Vector4(0.5f, 0.5f, 0.5f, 1.0f));
    mButtonInc.ClickedSignal().Connect(this, &SimpleApp::OnButtonClicked);

    mButtonDec = PushButton::New();
    mButtonDec.SetProperty(Actor::Property::PARENT_ORIGIN, ParentOrigin::CENTER);
    mButtonDec.SetProperty(Actor::Property::ANCHOR_POINT, AnchorPoint::CENTER);
    mButtonDec.SetProperty(Actor::Property::SIZE, Vector2(150.f, 50.0f));
    mButtonDec.SetProperty(Actor::Property::POSITION, Vector3(0.f, 100.0f, 0.f));
    mButtonDec.SetProperty(Button::Property::LABEL, "Dec");
    mButtonDec.SetBackgroundColor(Vector4(0.5f, 0.5f, 0.5f, 1.0f));
    mButtonDec.ClickedSignal().Connect(this, &SimpleApp::OnButtonClicked);

    window.Add(mButton);
    window.Add(mButtonInc);
    window.Add(mButtonDec);
    window.Add(mEditor);
  }

  bool OnButtonClicked(Button button)
  {
    if(button == mButton)
    {
      mEditor.SetProperty(TextEditor::Property::TEXT, text[textIndex++]);
      if (textIndex == 6)  textIndex = 0;
    }

    if(button == mButtonInc)
    {
      size += 5.0f;
      mEditor.SetProperty(Actor::Property::SIZE, Vector2(size, 300.0f));
    }

    if(button == mButtonDec)
    {
      size -= 5.0f;
      mEditor.SetProperty(Actor::Property::SIZE, Vector2(size, 300.0f));
    }
    return true;
  }

private:
  Application& mApplication;
  TextEditor mEditor;
  PushButton mButton;
  PushButton mButtonInc;
  PushButton mButtonDec;
};

int DALI_EXPORT_API main(int argc, char** argv)
{
  Application application = Application::New(&argc, &argv);
  SimpleApp test(application);
  application.MainLoop();

  return 0;
}

