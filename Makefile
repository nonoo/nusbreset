all:
	gcc nusbreset.c -o nusbreset

arago:
	arm-arago-linux-gnueabi-gcc nusbreset.c -o nusbreset

imx:
	arm-linux-gcc nusbreset.c -o nusbreset
