/*
 * CalcKeyboard.cpp
 *
 *  Created on: 08.01.2016
 *      Author: andreuschmann
 */

#include "CalcKeyboard.h"

CalcKeyboard::CalcKeyboard():VerticalLayout() {
	mListener = 0;

	HorizontalLayout *row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("(", row);
	createButton(")", row);
	createButton("CE", row);
	createButton("=", row);
	addChild(row);

	row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("7", row);
	createButton("8", row);
	createButton("9", row);
	createButton("+", row);
	addChild(row);

	row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("4", row);
	createButton("5", row);
	createButton("6", row);
	createButton("-", row);
	addChild(row);

	row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("1", row);
	createButton("2", row);
	createButton("3", row);
	createButton("*", row);
	addChild(row);

	row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("0", row);
	createButton(".", row);
	createButton("C", row);
	createButton("/", row);
	addChild(row);
}

void CalcKeyboard::createButton(const char* text, HorizontalLayout *row) {
	Button *button = new Button();
	button->setWidth(80);
	button->setHeight(48);
	button->setText(text);
	button->setClickListener(this);
	button->setBorderWidth(0);
	row->addChild(button);
}

void CalcKeyboard::setKeyboardListener(KeyboardListener *listener) {
	mListener = listener;
}

bool CalcKeyboard::onClick(View *view) {
	Button *button = (Button*)view;
	if(mListener) {
		mListener->onKeyPressed(0, button->getText());
	}
	return true;
}
