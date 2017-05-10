################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
src/bme280.obj: ../src/bme280.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/bme280.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bme280_support.obj: ../src/bme280_support.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/bme280_support.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bmi160.obj: ../src/bmi160.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/bmi160.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bmi160_support.obj: ../src/bmi160_support.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/bmi160_support.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/demo_sysctl.obj: ../src/demo_sysctl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/demo_sysctl.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/i2c_driver.obj: ../src/i2c_driver.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/i2c_driver.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.obj: ../src/main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/main.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/opt3001.obj: ../src/opt3001.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/opt3001.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/timer_a_pwm_mode.obj: ../src/timer_a_pwm_mode.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/timer_a_pwm_mode.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/tmp007.obj: ../src/tmp007.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/tmp007.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/uart_driver.obj: ../src/uart_driver.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Workspaces/workspace_v7/boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source" --include_path="C:/ti/tirex-content/simplelink_msp432_sdk_1_20_00_45/source/third_party/CMSIS/Include" --include_path="D:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="src/uart_driver.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


