#!/bin/bash

arrayContent=(`cat file`)
echo "Contents: " ${arrayContent[*]}
echo "Length of Content: " ${#arrayContent[*]}
echo "Lenght of Element at 3rd position: " ${#arrayContent[2]}
