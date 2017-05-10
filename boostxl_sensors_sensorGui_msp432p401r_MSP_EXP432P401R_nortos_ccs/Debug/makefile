################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./system_msp432p401r.obj" \
"./ccs/startup_msp432p401r_ccs.obj" \
"./src/bme280.obj" \
"./src/bme280_support.obj" \
"./src/bmi160.obj" \
"./src/bmi160_support.obj" \
"./src/demo_sysctl.obj" \
"./src/i2c_driver.obj" \
"./src/main.obj" \
"./src/opt3001.obj" \
"./src/timer_a_pwm_mode.obj" \
"./src/tmp007.obj" \
"./src/uart_driver.obj" \
"../msp432p401r.cmd" \
$(GEN_CMDS__FLAG) \
-l"C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/ti/devices/msp432p4xx/driverlib/ccs/msp432p4xx_driverlib.lib" \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include ccs/subdir_vars.mk
-include src/subdir_vars.mk
-include subdir_rules.mk
-include ccs/subdir_rules.mk
-include src/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.out \

EXE_OUTPUTS__QUOTED += \
"boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.out" \

BIN_OUTPUTS += \
boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.hex \

BIN_OUTPUTS__QUOTED += \
"boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.out"

# Tool invocations
boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP432 Linker'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on -z -m"boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.map" -i"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/lib" -i"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs_linkInfo.xml" --rom_model -o "boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP432 Hex Utility'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armhex"  -o "boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "system_msp432p401r.obj" "ccs\startup_msp432p401r_ccs.obj" "src\bme280.obj" "src\bme280_support.obj" "src\bmi160.obj" "src\bmi160_support.obj" "src\demo_sysctl.obj" "src\i2c_driver.obj" "src\main.obj" "src\opt3001.obj" "src\timer_a_pwm_mode.obj" "src\tmp007.obj" "src\uart_driver.obj" 
	-$(RM) "system_msp432p401r.d" "ccs\startup_msp432p401r_ccs.d" "src\bme280.d" "src\bme280_support.d" "src\bmi160.d" "src\bmi160_support.d" "src\demo_sysctl.d" "src\i2c_driver.d" "src\main.d" "src\opt3001.d" "src\timer_a_pwm_mode.d" "src\tmp007.d" "src\uart_driver.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

