<h1><b>defconUI</b></h1><br>
<i>defcon user interface [Russian/Cyrillic] for Raspberry Pi3</i>
<br><br>
requires following add-ons:
ofxGPIO
ofxJoystick
ofxTrueTypeFontUC
<br><br>
Please note that you should set your own joystick port at <i>ofxControls.cpp</i>

<br><b>UPDATE: INTERACTIVE JOYSTICK DEBOUNCE</b>
<br>
Я ввел два интерактивных параметра лимита скорости джойстика по осям и чувствительность. Возможно это позволит избежать проскакиваний.
Для изменения параметров используйте стрелки влево-вправо (debounce) и вверх-вниз (sensitivity). Значение параметров отображаются на основном интерфейсев левом верхнем углу экрана.

<br><br>ПОПРОБУЙТЕ В РЕЖИМЕ РЕАЛЬНОГО ВРЕМЕНИ СТРЕЛКАМИ ПОИЗМЕНЯТЬ ПАРАМЕТРЫ И ПОСМОТРЕТЬ КАК РЕАГИРУЕТ ДЖОЙСТИК<br><br>

По умолчанию debounce сейчас равен 4, а чувствительность как и была 0.001.

Чтобы убрать надпись с экрана просто сотрите или поставьте "//" в строке 310 в ofApp.cpp
<i>ofDrawBitmapString("joystick debouncing:" + ofToString(controls.debounceLimit) + ", sensitivity: " + ofToString(controls.joystickSensitivity), 48, 48);<i><br><br>

Чтобы жестко задать другое значение отличное от 4, меняем это значение в строке 26 и 29 в ofxControls.h
<i>int debounceLimit = 4; //joystick movement debouncing, in frames</i>
<i>float joystickSensitivity = 0.001;</i><br>

И кстати обратите внимание на колесо на джойстике под клавишами 8 и 9, возможно оно влияет так же на чувствительность 
управления.

