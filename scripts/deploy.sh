#!/bin/bash
bash scripts/build.sh

PORT=$(ls /dev/ttyACM* /dev/ttyUSB* 2>/dev/null | head -n 1)
if [ -z "$PORT" ]; then
    echo "Error: No USB connection found"
    exit 1
fi
avrdude -v -p atmega328p -c arduino -P "$PORT" -b 115200 -D -U flash:w:build/Arduino_Subwoofer.hex:i
