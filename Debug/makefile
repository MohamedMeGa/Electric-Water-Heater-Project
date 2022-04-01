################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
WaterHeater.lss \

FLASH_IMAGE += \
WaterHeater.hex \

EEPROM_IMAGE += \
WaterHeater.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: WaterHeater.elf secondary-outputs

# Tool invocations
WaterHeater.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,WaterHeater.map -mmcu=atmega32 -o "WaterHeater.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

WaterHeater.lss: WaterHeater.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S WaterHeater.elf  >"WaterHeater.lss"
	@echo 'Finished building: $@'
	@echo ' '

WaterHeater.hex: WaterHeater.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex WaterHeater.elf  "WaterHeater.hex"
	@echo 'Finished building: $@'
	@echo ' '

WaterHeater.eep: WaterHeater.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex WaterHeater.elf  "WaterHeater.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: WaterHeater.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 WaterHeater.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: WaterHeater.elf
	@echo 'Invoking: AVRDude'
	D:\Study\Embedded System\AVR\Material\00- Tools\01- SDK\IMT_SDK_Win_64\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -Uflash:w:WaterHeater.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) WaterHeater.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
