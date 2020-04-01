# NL_means
根据论文用C实现了非局部均值去噪算法
我最近正在做的项目是在Vivado HLS上用C语言实现NL_means算法，然后在FPGA上运行实现算法加速。
项目在仿真阶段使用了matlab和Vivado HLS两个软件，matlab用于为图像加噪，输出COE文件，显示图像；而HLS实现算法的仿真，输出仿真数据。
算法运行在Vivado HLS 2017.4版本
图像分辨率为128*128
