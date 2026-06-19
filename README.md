# unnamedHid
## What and Why

A multipurpose HID middleman based on a RP2040. Anything from rubber ducky scripts to word-to-phrase replacements are supported.

After witnessing the beautiful mistakes (happy little accidents?) that Apple's autocorrect creates, I sought to implement the same on my computer.

Eventually I realized what I was making was in fact not autocorrect but a very small and versatile HID injector: thus bearing this project.

Disclaimer: This project is only for educational and legal purpose. Do not attempt to write malicious programs or keyloggers. I am not responsible for reproductions of this project being used with malintent.

## Tuff photos
<img width="1558" height="621" alt="image" src="https://github.com/user-attachments/assets/e1b71673-cb30-4801-a336-c67f0e7a5e73" />
<img width="540" height="828" alt="unzine" src="https://github.com/user-attachments/assets/83681967-2825-4620-b65f-87a79745e7ab" />
<img width="1086" height="496" alt="image" src="https://github.com/user-attachments/assets/2479a437-f7c3-47ef-9cd9-c9d32a0cacb4" />
<img width="1066" height="504" alt="image" src="https://github.com/user-attachments/assets/9d051481-2aef-47ae-87fd-edd9bea5da38" />
<img width="1476" height="952" alt="image" src="https://github.com/user-attachments/assets/f429990c-9303-4023-92d6-290283ac0ab4" />



## How it works

THe entire device is based on the RP2040 MCU. The built-in PHY connects to the host computer (important for USB programming), and the PIO bitbang interface is connected to the slave device.

The practice of using the PIO as a second USB PHY is not an original nor failproof idea. This approach, taken from Adafruit's own implementation on their Feather boards, probably won't get you the USB3.0 speeds, or even 2 reliably. However, for low speed keyboards and even mice, this approach works just fine.

## BOM
|name|quantity|cost |link                 |
|----|--------|-----|---------------------|
|PCB |1       |32.12|PCB files in reposity|
