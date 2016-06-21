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
Я сделал интерактивный параметр лимита скорости джойстика по осям. Возможно это позволит избежать проскакиваний.
Для изменения параметра используйте стрелки влево-вправо. Значение параметра отображается на основном интерфейсе
в левом верхнем углу экрана.

По умолчанию он сейчас равен 4.

Чтобы убрать надпись с экрана просто сотрите или поставьте "//" в строке 310 в ofApp.cpp
<i>ofDrawBitmapString("joystick debouncing limit:" + ofToString(controls.debounceLimit), 48, 48);<i><br><br>

Чтобы жестко задать другое значение отличное от 4, меняем это значение в строке 26 в ofxControls.h
<i>int debounceLimit = 4; //joystick movement debouncing, in frames</i>

И кстати обратите внимание на колесо на джойстике под клавишами 8 и 9, возможно оно влияет так же на чувствительность 
управления.

