# ESP-P10-Panel
Interfacing esp8266 with P10 panel

Wiring diagram, sourced almost everything from internet 
![image](https://user-images.githubusercontent.com/28485210/212487821-5fac21cc-fef5-4b76-a0bb-d2043d537388.png)
![image](https://user-images.githubusercontent.com/28485210/212487827-e0de3301-9eb2-4ea3-aac0-5f8c0f60aa0f.png)

Connecting relays to D1 and D2 pins in NO position
![image](https://user-images.githubusercontent.com/28485210/212487855-6f6312c1-777e-4cd3-86ef-082a86d2a6ae.png)

Temperature sensor should be connected to D4 pin as input
![image](https://user-images.githubusercontent.com/28485210/212487866-045cf73a-71e5-48e2-a910-b62004c315d4.png)

Part with countdown timer:

What is entered in first 3 boxes defines hours,days and minutes for coutdown timer, when this timer reaches 0 relay must activate for time specified as last input
Also this code has timetable for shift start/end as well for brakes, when local time reaches any of that predefined times timer should stop and sound alarm on second relay.
When brake stops or shift starts timer should continue to do its thing.

![image](https://user-images.githubusercontent.com/28485210/212487941-5280ebad-ab93-46be-8043-c1d058ca794b.png)

There is a PDF called drawning with sketch for creating PCB

![PCB1](https://user-images.githubusercontent.com/28485210/212488415-e7e574da-ca52-43b8-ad65-3af49cb8ca2a.jpg)
![PCB2](https://user-images.githubusercontent.com/28485210/212488419-1acabbf8-7939-4c61-a27b-08ad741140f3.jpg)

