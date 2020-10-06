# leonardo-nunchuck

A simple example of how you can simulate keyboard actions with a leonardo board, using a nunchuck as gaming or input peripheral.

This should work with all 32u4 and SAMD based boards (Leonardo, Esplora, Zero, Due and MKR Family).

## connections

We use a [WiiChuck adaptor](https://www.dfrobot.com/index.php?route=product/product&filter_name=dfr0062&product_id=91) and this is how we connect it to the board :

| WiiChuck connector | Arduino pin |
| - | GND|
| + | 3V3 |
| d (SDA) | D2 |
| c (SCL) | D3 |

Thanks to @todbot who did the hardest part!
