################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../DIO_prog.c \
../EXTI0_prog.c \
../EXTI1_prog.c \
../EXTI2_prog.c \
../GIE_prog.c \
../SEV_prog.c \
../TIMER0_prog.c \
../main.c 

OBJS += \
./ADC_prog.o \
./DIO_prog.o \
./EXTI0_prog.o \
./EXTI1_prog.o \
./EXTI2_prog.o \
./GIE_prog.o \
./SEV_prog.o \
./TIMER0_prog.o \
./main.o 

C_DEPS += \
./ADC_prog.d \
./DIO_prog.d \
./EXTI0_prog.d \
./EXTI1_prog.d \
./EXTI2_prog.d \
./GIE_prog.d \
./SEV_prog.d \
./TIMER0_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


