STM32 Simulink Build tutorial 

Start by downloading and installing the STMCubeIDE from the link below. You need to create an account first. 
https://www.st.com/en/development-tools/stm32cubeide.html

In Matlab, click on the Add-Ons menu in the Home tab and search for the following: 

Simulink Coder Support Package for STMicroelectronics Nucleo Boards

Open the simulink model named "STM_SIMULINK_BLDC"

Make sure your Matlab working directory is the directory containing the file "STM_SIMULINK_BLDC.slx" 

In MODELING(tab) > Model Settings > Hardware Implementation > Hardware Board change the board to STM32 Nucleo F302R8. Apply and close. 

In HARDWRAE tab, DEPLOY section, select Build. 

After the Build is complete you'll get a new directory named "STM_SIMULINK_BLDC_ert_rtw". In this directory, you'll find the C code and the object files created by Matlab. 

Now Open the stm32cubeide. It asks you to select a workspace folder. Select the folder containing the "STM_CUBE_BLDC" project provided. 

In the IDE, " File> Open Projects from File System > Directory > " select the directory "STM_CUBE_BLDC"

Wait for the project to be loaded. 

On the left hand side, in Project Explorer, double click the "STM_CUBE_BLDC.ioc" file to get the cubemx view. 

This is where the device peripherals are configured. Feel free to explore but don't change anything unless you know exactly what you're doing.(improbable)

In Project Explorer, right click on the project (blue icon that says IDE)> properties > C/C++ Build > Settings> Tool Settings > MCU GCC Compiler > Inlucde paths

Add the STM_SIMULINK_BLDC_ert_rtw created earlier to the include paths. 

Now again in Tool Settings > MCU G++ Linker > Miscellaneous > Additional object files 
Add the following files from STM_SIMULINK_BLDC_ert_rtw one by one: 

rt_nonfinite.o
rtGetInf.o
STM_SIMULINK_BLDC_data.o
STM_SIMULINK_BLDC.o
rtGetNan.o

Apply and Close 

In the IDE, click the Play button to deploy the code to the board. 

Wait for deploy to finish (you'll see the LED LD1 on the board flashing red and green)

Plug the adapter into power and press the blue push button to start the motor. Change the speed by turning the blue knob with the arrow on it