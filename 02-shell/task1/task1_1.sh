#!/bin/bash
read -p "input a file:" filename
#请添加代码，判断文件是不是块或字符设备文件
# if [...]
if [ -b $filename -o -c $filename ]; then
	echo $filename is a char device or a block device
	#请添加代码，将文件拷贝到/dev目录下面
	sudo cp $filename /dev/
else 
	echo $filename is not char device and not block device
fi
