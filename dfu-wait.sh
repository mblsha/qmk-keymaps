#!/bin/bash

MCU=$1

echo -n dfu-programmer: waiting
until dfu-programmer $MCU get bootloader-version > /dev/null 2>&1; do
  echo -n "."
  sleep 1
done

