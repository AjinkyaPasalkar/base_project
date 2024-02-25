openocd_executable ?= H:/Embedded/xpack-openocd-0.12.0-1/bin/openocd.exe
openocd_stlink_cfg ?= H:/Embedded/xpack-openocd-0.12.0-1/openocd/scripts/interface/stlink.cfg
openocd_bluepill_cfg ?= H:/Embedded/xpack-openocd-0.12.0-1/openocd/scripts/board/stm32f103c8_blue_pill.cfg

CFLAGS  ?= -mcpu=cortex-m3
LDFLAGS ?= -Tlink.ld -nostartfiles -nostdlib --specs nosys.specs -Wl,-Map=$@.map
SOURCES = main.c
INC_DIR = ./cmsis/
OUT_DIR = ./_out/

ELF := $(OUT_DIR)firmware.elf
BIN := $(OUT_DIR)firmware.bin

.PHONY: all

all: build

build: $(BIN)

$(BIN): $(ELF)
	arm-none-eabi-objcopy -O binary $< $@

$(ELF): $(SOURCES)
	mkdir $(OUT_DIR)
	arm-none-eabi-gcc $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $@ -I$(INC_DIR)



objdump: $(ELF)
	arm-none-eabi-objdump -x $^

flash: $(BIN)
	${openocd_executable} -f $(openocd_stlink_cfg) -f $(openocd_bluepill_cfg) -c "program $(ELF) verify reset exit" -l $(OUT_DIR)flash_log.log

	
clean:
	rm -rf $(OUT_DIR)