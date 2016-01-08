/*
 * CalcKeyboard.h
 *
 *  Created on: 08.01.2016
 *      Author: andreuschmann
 */

#ifndef SOURCE_CALCKEYBOARD_H_
#define SOURCE_CALCKEYBOARD_H_

#include <three/three.h>

class CalcKeyboard: public VerticalLayout, public ClickListener {
public:
	CalcKeyboard();
	void createButton(const char* text, HorizontalLayout *row);
	void setKeyboardListener(KeyboardListener *listener);
	bool onClick(View *view);
private:
	KeyboardListener *mListener;
};

#endif /* SOURCE_CALCKEYBOARD_H_ */
