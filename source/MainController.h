/*
 * TestController.h
 *
 *  Created on: 02.01.2016
 *      Author: andreuschmann
 */

#ifndef SOURCE_MAINCONTROLLER_H_
#define SOURCE_MAINCONTROLLER_H_

#include <three/three.h>

class MainController: public Controller, public KeyboardListener {
public:
	TextView *textView;

    void onCreate(App *app);
    bool onKeyPressed(KeyboardView *keyboard, const char *key);
    void evaluate();
};

#endif
