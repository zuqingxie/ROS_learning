#! /usr/bin/bash
echo "Ethenet IP is:"
ifconfig | grep 192 | awk '{print $2}'
