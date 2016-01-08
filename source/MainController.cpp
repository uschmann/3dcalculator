/*
 * FirstController.cpp
 *
 *  Created on: 02.01.2016
 *      Author: andreuschmann
 */
#include <three/three.h>
#include "CalcKeyboard.h"
#include "duktape.h"
#include "MainController.h"
using namespace std;

void MainController::onCreate(App *app) {
	Controller::onCreate(app);

	// Top screen
	ViewGroup *layoutTop = new ViewGroup();
	layoutTop->setWidth(VIEW_FILL_PARENT);
	layoutTop->setHeight(VIEW_FILL_PARENT);
	layoutTop->setBackgroundColor(RGBA8(0xFF, 0xFF, 0xFF, 0xFF));

	TextView *txtTitle = new TextView();
	txtTitle->setWidth(VIEW_WRAP_CONTENT);
	txtTitle->setHeight(VIEW_WRAP_CONTENT);
	txtTitle->setText("3dCalculator");
	txtTitle->setX(10);
	txtTitle->setY(20);
	txtTitle->setFont(App::getInstance()->getAssetManager()->getFont("calculator"));
	txtTitle->setTextSize(48);
	txtTitle->setTextColor(RGBA8(0x00, 0x00, 0x00, 0xFF));
	layoutTop->addChild(txtTitle);

	TextView *txtMessage = new TextView();
	txtMessage->setWidth(VIEW_FILL_PARENT);
	txtMessage->setHeight(25);
	txtMessage->setTextSize(14);
	txtMessage->setY(0);
	txtMessage->setPadding(5, 5, 5, 10);
	txtMessage->setBackgroundColor(RGBA8(0x12, 0x34, 0x56, 0xDD));
	txtMessage->setText("Press START to return to loader");
	layoutTop->addChild(txtMessage);

	textView = new TextView();
	textView->setX(10);
	textView->setY(80);
	textView->setWidth(380);
	textView->setHeight(78);
	textView->setPadding(10);
	textView->setBackgroundColor(RGBA8(0x12, 0x34, 0x56, 0xDD));
	textView->setTextSize(48);
	textView->setBorderColor(RGBA8(0x00, 0x00, 0x00, 0x20));
	textView->setBorderWidth(1);
	textView->setTextColor(RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
	textView->setText("");
	textView->setFont(App::getInstance()->getAssetManager()->getFont("calculator"));
	layoutTop->addChild(textView);

	setTopContentView(layoutTop);

	// Bottom Screen
	CalcKeyboard *keyboard = new CalcKeyboard();
	keyboard->setWidth(VIEW_FILL_PARENT);
	keyboard->setHeight(VIEW_FILL_PARENT);
	keyboard->setKeyboardListener(this);
	setBottomContentView(keyboard);
}

void MainController::evaluate() {
	if(strcmp(textView->getText().c_str(), "") != 0) {
		duk_context *ctx = duk_create_heap_default();
		if(duk_peval_string(ctx, textView->getText().c_str()) == 0) {
			textView->setText(duk_safe_to_string(ctx, -1));
			duk_pop(ctx);
		}
		else {
			textView->setBackgroundColor(RGBA8(0xAA, 0x00, 0x00, 0xFF));
			textView->setText("ERROR");
		}
		duk_destroy_heap(ctx);
	}
}

bool MainController::onKeyPressed(KeyboardView *keyboard, const char *key) {
	if(strcmp(textView->getText().c_str(), "ERROR") == 0) {
		textView->setText("");
		textView->setBackgroundColor(RGBA8(0x12, 0x34, 0x56, 0xDD));
	}
	if(strcmp(key, "=") == 0) {
		evaluate();
		return true;
	}
	if(strcmp(key, "CE") == 0) {
		textView->setText("");
		return true;
	}
	if(strcmp(key, "C") == 0) {
		std::string str = textView->getText();
		str.pop_back();
		textView->setText(str.c_str());
		return true;
	}
	std::string str1 = textView->getText();
	str1 += key;
	textView->setText(str1.c_str());
	return true;
}
