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
|name       |footprint                                 |board name                          |quantity|
|-----------|------------------------------------------|------------------------------------|--------|
|100nF      |C_0402_1005Metric                         |C19,C8,C17,C11,C5,C6,C12,C9,C4,C7,C3|11      |
|1uF        |C_0402_1005Metric                         |C2,C13,C1,C10                       |4       |
|USBLC6-2SC6|SOT-23-6                                  |U6,U7                               |2       |
|AP2112K-3.3|SOT-23-5                                  |U3                                  |1       |
|22uF       |C_0402_1005Metric                         |C18                                 |1       |
|TPS2041B   |SOT-23-5                                  |U5                                  |1       |
|USB_A      |USB3_A_Receptacle_Wuerth_692122030100     |J2                                  |1       |
|R          |R_0402_1005Metric                         |R2,R1                               |2       |
|BOOT       |SW_SPST_TS-1088-xR025                     |SW1                                 |1       |
|1k         |R_0402_1005Metric                         |R7,R3,R4                            |3       |
|15k        |R_0402_1005Metric                         |R9,R8                               |2       |
|RUN        |SW_SPST_TS-1088-xR025                     |SW2                                 |1       |
|10k        |R_0402_1005Metric                         |R6,R5                               |2       |
|USB_A      |USB3_A_Plug_Wuerth_692112030100_Horizontal|J1                                  |1       |
|W25Q32JVSS |SOIC-8_5.3x5.3mm_P1.27mm                  |U4                                  |1       |
|15pF       |C_0402_1005Metric                         |C15,C16                             |2       |
|ABM8-272-T3|Crystal_SMD_3225-4Pin_3.2x2.5mm           |Y1                                  |1       |
|RP2040     |QFN-56-1EP_7x7mm_P0.4mm_EP3.2x3.2mm       |U1                                  |1       |

