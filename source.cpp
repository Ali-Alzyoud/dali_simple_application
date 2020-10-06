#include <dali-toolkit/dali-toolkit.h>

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

    TextField field = TextField::New();

    window.Add(field);
  }

private:
  Application& mApplication;
};

int DALI_EXPORT_API main(int argc, char** argv)
{
  Application application = Application::New(&argc, &argv);
  SimpleApp test(application);
  application.MainLoop();

  return 0;
}

