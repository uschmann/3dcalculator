#include <three/three.h>

#include "MainController.h"
#include "RobotoRegular_ttf.h"
#include "calc_ttf.h"

int main()
{
    App *app = App::getInstance();
    app->getAssetManager()->loadFont("defaultFont", RobotoRegular_ttf, RobotoRegular_ttf_size);
    app->getAssetManager()->loadFont("calculator", calc_ttf, calc_ttf_size);
    app->startController(new MainController());
    app->run();
	return 0;
}
