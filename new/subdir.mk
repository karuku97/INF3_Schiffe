################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_UPPER_SRCS += \
../SHA256.C \
../SIMPLESOCKET.C \
../TASK1.C \
../TASK2.C \
../TASK3.C \
../TASK4.C \
../TASK5.C \
../client.C \
../main.C \
../mainTest.C \
../myClient.C \
../myServer.C \
../server.C 

O_SRCS += \
../SHA256.o \
../SIMPLESOCKET.o \
../TASK1.o \
../TASK2.o \
../TASK3.o \
../TASK4.o \
../TASK5.o \
../client.o \
../main.o \
../mainTest.o \
../myClient.o \
../myServer.o \
../server.o 

C_UPPER_DEPS += \
./SHA256.d \
./SIMPLESOCKET.d \
./TASK1.d \
./TASK2.d \
./TASK3.d \
./TASK4.d \
./TASK5.d \
./client.d \
./main.d \
./mainTest.d \
./myClient.d \
./myServer.d \
./server.d 

OBJS += \
./SHA256.o \
./SIMPLESOCKET.o \
./TASK1.o \
./TASK2.o \
./TASK3.o \
./TASK4.o \
./TASK5.o \
./client.o \
./main.o \
./mainTest.o \
./myClient.o \
./myServer.o \
./server.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.C
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


