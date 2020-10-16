################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/electrodomestico.c \
../src/marca.c \
../src/menu.c \
../src/parcial_electrodomestico.c \
../src/reparacion.c \
../src/servicio.c \
../src/validaciones.c 

OBJS += \
./src/electrodomestico.o \
./src/marca.o \
./src/menu.o \
./src/parcial_electrodomestico.o \
./src/reparacion.o \
./src/servicio.o \
./src/validaciones.o 

C_DEPS += \
./src/electrodomestico.d \
./src/marca.d \
./src/menu.d \
./src/parcial_electrodomestico.d \
./src/reparacion.d \
./src/servicio.d \
./src/validaciones.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


