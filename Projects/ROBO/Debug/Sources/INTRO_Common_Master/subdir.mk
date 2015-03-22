################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/INTRO_Common_Master/LEDcpp.cpp 

C_SRCS += \
../Sources/INTRO_Common_Master/Application.c \
../Sources/INTRO_Common_Master/Event.c \
../Sources/INTRO_Common_Master/Keys.c \
../Sources/INTRO_Common_Master/LED.c \
../Sources/INTRO_Common_Master/Mealy.c \
../Sources/INTRO_Common_Master/Platform.c \
../Sources/INTRO_Common_Master/Timer.c 

OBJS += \
./Sources/INTRO_Common_Master/Application.o \
./Sources/INTRO_Common_Master/Event.o \
./Sources/INTRO_Common_Master/Keys.o \
./Sources/INTRO_Common_Master/LED.o \
./Sources/INTRO_Common_Master/LEDcpp.o \
./Sources/INTRO_Common_Master/Mealy.o \
./Sources/INTRO_Common_Master/Platform.o \
./Sources/INTRO_Common_Master/Timer.o 

C_DEPS += \
./Sources/INTRO_Common_Master/Application.d \
./Sources/INTRO_Common_Master/Event.d \
./Sources/INTRO_Common_Master/Keys.d \
./Sources/INTRO_Common_Master/LED.d \
./Sources/INTRO_Common_Master/Mealy.d \
./Sources/INTRO_Common_Master/Platform.d \
./Sources/INTRO_Common_Master/Timer.d 

CPP_DEPS += \
./Sources/INTRO_Common_Master/LEDcpp.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/INTRO_Common_Master/%.o: ../Sources/INTRO_Common_Master/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/James/Documents/Intro/MyTeam/Projects/ROBO/Sources" -I"C:/Users/James/Documents/Intro/MyTeam/Projects/ROBO/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/INTRO_Common_Master/%.o: ../Sources/INTRO_Common_Master/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


